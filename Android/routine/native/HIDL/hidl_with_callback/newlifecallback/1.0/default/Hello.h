// FIXME: your file license if you have one

#pragma once

#include <android/hardware/newlifecallback/1.0/IHello.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace newlifecallback {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Hello : public IHello {
	public:
		// Methods from ::android::hardware::newlifecallback::V1_0::IHello follow.
    	Return<void> init() override;
    	Return<void> release() override;
    	Return<void> setCallback(const sp<::android::hardware::newlifecallback::V1_0::IHelloCallback>& cb) override;

    	// Methods from ::android::hidl::base::V1_0::IBase follow.
};

// FIXME: most likely delete, this is only for passthrough implementations
extern "C" IHello* HIDL_FETCH_IHello(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace newlifecallback
}  // namespace hardware
}  // namespace android
