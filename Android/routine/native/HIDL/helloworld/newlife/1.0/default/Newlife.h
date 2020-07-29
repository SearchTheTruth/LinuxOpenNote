// FIXME: your file license if you have one

#pragma once

#include <android/hardware/newlife/1.0/INewlife.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace newlife {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Newlife : public INewlife {
    // Methods from ::android::hardware::newlife::V1_0::INewlife follow.
    Return<void> helloWorld(const hidl_string& name, helloWorld_cb _hidl_cb) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
extern "C" INewlife* HIDL_FETCH_INewlife(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace newlife
}  // namespace hardware
}  // namespace android
