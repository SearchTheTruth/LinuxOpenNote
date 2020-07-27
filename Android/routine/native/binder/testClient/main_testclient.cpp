#include "../testService/ITest.h"
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <utils/Log.h>

#undef LOG_TAG
#define LOG_TAG "jh_testclient"

int main()
{
	int size;
	sp<IBinder> binder = defaultServiceManager()->getService(String16("jianghao.testbinder"));
	sp<ITest> test = interface_cast<ITest>(binder);
	test->getListSize(&size);
	ALOGE("list size = %d", size);

	test->setListContent(0, String16("1th hello"));
	test->setListContent(1, String16("2th world"));
	test->setListContent(0, String16("3th beauty"));

	test->getListSize(&size);
	ALOGE("list size = %d", size);

	test->removeList(1);

	test->getListSize(&size);
	ALOGE("list size = %d", size);
}

