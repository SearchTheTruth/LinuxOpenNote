// FIXME: your file license if you have one

#define LOG_TAG "NewlifeCallback"

#include "Hello.h"
#include <log/log.h>
#include <utils/threads.h>

namespace android {
namespace hardware {
namespace newlifecallback {
namespace V1_0 {
namespace implementation {

bool mExit = false;
sp<IHelloCallback> mCallback = nullptr;

class HelloThread : public Thread {
	public:
		HelloThread() = default;
		~HelloThread() = default;
	private:
		virtual bool threadLoop();
};

bool HelloThread::threadLoop()
{
	static int32_t count = 0;
	HalEvent event;

	while (!mExit) {
		::sleep(1);
		event.value = ++count;
		if (mCallback != nullptr) {
			mCallback->onNotify(event);
		}
	}

	ALOGD("threadLoop exit");

	return false;
}

// Methods from ::android::hardware::newlifecallback::V1_0::IHello follow.
Return<void> Hello::init() {
    // TODO implement
	mExit = false;
	sp<HelloThread> loop = new HelloThread();
	loop->run("hello-thread", PRIORITY_BACKGROUND);
    return Void();
}

Return<void> Hello::release() {
    // TODO implement
	mCallback = nullptr;
	mExit = true;
    return Void();
}

Return<void> Hello::setCallback(const sp<::android::hardware::newlifecallback::V1_0::IHelloCallback>& cb) {
    // TODO implement
	mCallback = cb;
	if (mCallback != nullptr)
		ALOGD("setCallback: done");
    return Void();
}
// Methods from ::android::hidl::base::V1_0::IBase follow.

IHello* HIDL_FETCH_IHello(const char* /* name */) {
    return new Hello();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace newlifecallback
}  // namespace hardware
}  // namespace android
