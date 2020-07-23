#include <utils/threads.h>
#include <utils/misc.h>
#include <utils/Log.h>
#include <stdlib.h>

#undef LOG_TAG
#define LOG_TAG "ThreadRoutine"

using namespace android;

sp<Thread> gA, gB, gC;

class A : public Thread {
	bool threadLoop();
	status_t readyToRun();
};

bool A::threadLoop() {
	ALOGE("A: I'm A");
	sleep(1);
	return true;			//返回ture该threadLoop循环调用, 返回false只调用一次
}

status_t A::readyToRun() {	//线程开始执行初始化动作的好地方
	ALOGE("A tid: %d", getTid());
	ALOGE("A do something for init at begining of threadLoop");
	return OK;
}

class B : public Thread {
	bool threadLoop();
};

bool B::threadLoop() {
	sleep(10);
	ALOGE("B request A exit and wait for it");
	ALOGE("B tid: %d, A tid: %d", getTid(), gA->getTid());
	gA->requestExitAndWait();
	ALOGE("B wait done, B exit!");
	return false;
}

class C : public Thread {
	bool threadLoop();
};

bool C::threadLoop() {
	ALOGE("C exit until A exit");
	gA->join();
	ALOGE("C exit!");
	return false;
}


int main()
{
	gA = new A;
	gB = new B;
	gC = new C;						//构造了thread对象,但线程并没有开始运行

	gA->run("threadRoutineA");	    //创建线程并执行线程函数的地方
	gB->run("threadRoutineB");
	gC->run("threadRoutineC");

	gC->join();						//主线程等待C退出

	return 0;
}
