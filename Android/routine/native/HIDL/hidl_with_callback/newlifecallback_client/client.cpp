#include <android/hardware/newlifecallback/1.0/IHelloCallback.h>
#include <android/hardware/newlifecallback/1.0/IHello.h>
#include <android/hardware/newlifecallback/1.0/types.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <utils/misc.h>
#include <hidl/HidlSupport.h>
#include <log/log.h>

#undef  LOG_TAG
#define LOG_TAG "NewlifeCallback"


using android::hardware::newlifecallback::V1_0::IHelloCallback;
using android::hardware::newlifecallback::V1_0::IHello;
using android::hardware::newlifecallback::V1_0::HalEvent;
using android::sp;
using android::hardware::hidl_string;
using android::hardware::Return;
using android::hardware::Void;


class HelloCallback : public IHelloCallback {
	public:
		HelloCallback() = default;
		~HelloCallback() = default;
		Return<void> onNotify(const HalEvent& event) {
			ALOGD("onNotify: value = %d", event.value);
			return Void();
		}
};

int main()
{
	sp<IHello> service = IHello::getService();
	if (service == nullptr) {
		ALOGE("Failed to get service\n");
		return -1;
	}

	sp<IHelloCallback> callback = new HelloCallback();
	service->setCallback(callback);
	service->init();

	::sleep(10);
	service->release();

	return 0;
}
