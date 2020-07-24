#include <utils/threads.h>
#include <utils/misc.h>
#include <utils/Log.h>
#include <utils/Looper.h>
#include <stdlib.h>

#undef LOG_TAG
#define LOG_TAG "LooperRoutine"

using namespace android;

sp<Looper> gLooper;
int gType;

enum {
	TYPE_A,
	TYPE_B,
};

class HandlerA : public MessageHandler {
	public:
		void handleMessage(const Message& message);
};

void HandlerA::handleMessage(const Message &msg)
{
	ALOGE("A Handler, do something");
}

class HandlerB : public MessageHandler {
	public:
		void handleMessage(const Message& message);
};

void HandlerB::handleMessage(const Message &msg)
{
	ALOGE("B Handler, do something");
}

class Sender : public Thread {
	bool threadLoop();
};

bool Sender::threadLoop()
{
	const Message dummyMessage;
	sp<MessageHandler> hA = new HandlerA;
	sp<MessageHandler> hB = new HandlerB;
	sp<MessageHandler> handler;

	if (gType == TYPE_A) {
		handler = hA;
	} else {
		handler = hB;
	}

	ALOGE("Type %d, sendmsg", gType);
	gLooper->sendMessage(handler, dummyMessage);
	return false;
}

class Receiver : public Thread {
	bool threadLoop();
	status_t readyToRun();
};

bool Receiver::threadLoop()
{
	gLooper->pollOnce(-1);
	return true;
}

status_t Receiver::readyToRun()
{
	ALOGE("rcv ready to poll message");
	return OK;
}


int main()
{
	gLooper = new Looper(true);
	sp<Thread> sender = new Sender;
	sp<Thread> rcver = new Receiver;

	ALOGE("Start");

	rcver->run("LooperRoutineRcv");		//创建一个线程开始pollmessage

	gType = TYPE_A;
	sender->run("LooperRoutineSnd");		//线程中发送A类消息

	gType = TYPE_B;
	sender->run("LooperRoutineSnd");		//线程中发送B类消息

	ALOGE("End");
	return 0;
}
