#include <utils/Thread.h>
#include <utils/Log.h>

using namespace android;

class First : public Thread {
    bool threadLoop() {
        for (int i = 0; i < 10; i++) {
            ALOGE("Thread A loop %d", i);
            sleep(1);
        }
        return false;  //exit
    }

    status_t readyToRun() {
        ALOGE("Thread A init");
        return 0;
    }
};

class Second : public Thread {
    bool threadLoop() {
        for (int i = 0; i < 10; i++) {
            ALOGE("Thread B loop %d", i);
            sleep(1);
        }
        return true;  //continue loop
    }

    status_t readyToRun() {
        ALOGE("Thread B init");
        return 0;
    }
};

int main()
{
    sp<First> f_td = new First();
    sp<Second> s_td = new Second(); 

    f_td->run("first_thread");
    s_td->run("second_thread");

    sleep(20);
    s_td->requestExitAndWait();
    return 0;
}