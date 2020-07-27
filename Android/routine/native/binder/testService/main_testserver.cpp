#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include "ITest.h"

using namespace android;

int main()
{
	signal(SIGPIPE, SIG_IGN);

	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm(defaultServiceManager());

	sm->addService(String16("jianghao.testbinder"), new TestService());

	ProcessState::self()->startThreadPool();
}
