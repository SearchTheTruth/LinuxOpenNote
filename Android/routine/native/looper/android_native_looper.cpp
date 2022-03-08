#include <utils/Thread.h>
#include <utils/Log.h>
#include <utils/Looper.h>
#include <private/gui/BitTube.h>

//一共三个thread, looper, default event, other event
using namespace android;

enum {
    DEF_EVENT_MSG,
};

class defaultHandler : public MessageHandler {
    void handleMessage(const Message &msg)
    {
        switch (msg.what) {
        case DEF_EVENT_MSG:
            ALOGE("handler DEF_EVENT_MSG");
        break;
        default:
            ALOGE("handler DEFAULT_MSG");
        break;
        }
    }
};

class defaultEvent : public Thread {
public:
    defaultEvent(sp<Looper> looper, sp<MessageHandler> handler) :
        mlooper(looper), mhandler(handler) { }

private:
    bool threadLoop() {
        mlooper->sendMessage(mhandler, Message(DEF_EVENT_MSG));
        ALOGE("Thread 2 send event DEF_EVENT_MSG");
        sleep(3);
        return true;
    }

    status_t readyToRun() {
        ALOGE("Thread 2 will start after 5s...");
        sleep(5);
        return 0;
    }

    sp<Looper> mlooper;
    sp<MessageHandler> mhandler;
};

class otherEvent : public Thread {
public:
    otherEvent(gui::BitTube &tube) : mtube(tube) { }
private:
    bool threadLoop() {
        uint8_t const str[] = "I'm tube";
        gui::BitTube::sendObjects(&mtube, str, sizeof(str));
        ALOGE("Thread 3 send string out");
        sleep(2);
        return true;
    }

    status_t readyToRun() {
        ALOGE("Thread 3 will start after 5s...");
        sleep(5);
        return 0;
    }

    gui::BitTube &mtube;
};

int main()
{

    sp<Looper> looper = new Looper(true);
    sp<MessageHandler> handler = new defaultHandler();
    gui::BitTube other_event(gui::BitTube::DefaultSize);

    ALOGE("BitTube init status %d", other_event.initCheck());

    looper->addFd(other_event.getFd(), 0, Looper::EVENT_INPUT,
        [](int fd, int events, void *data) {
            uint8_t buf[10] = {0};
            gui::BitTube *tube = reinterpret_cast<gui::BitTube*>(data);
            gui::BitTube::recvObjects(tube, buf, 10);
            ALOGE("other thread handler receive msg %s", buf);
            return 1; //keep register
        }, &other_event);

    //Thread 2, send default event
    sp<defaultEvent> defevent = new defaultEvent(looper, handler);
    defevent->run("def_event_thread");

    //Thread 3, send other event via fd
    sp<otherEvent> othevent = new otherEvent(other_event);
    othevent->run("other_event_thread");

    //Thread 1, looper thread, wait for events
    while (true) {
        int ret;
        ret = looper->pollOnce(-1);
        ALOGE("pollOnce ret value: %d", ret);
    }

    return 0;
}
