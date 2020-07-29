// FIXME: your file license if you have one

#include "Newlife.h"

namespace android {
namespace hardware {
namespace newlife {
namespace V1_0 {
namespace implementation {

// Methods from ::android::hardware::newlife::V1_0::INewlife follow.
Return<void> Newlife::helloWorld(const hidl_string& name, helloWorld_cb _hidl_cb) {
    // TODO implement
    char buf[100];
    ::memset(buf, 0, 100);
    ::snprintf(buf, 100, "Hello World, %s", name.c_str());
    hidl_string result(buf);

    _hidl_cb(result);
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

INewlife* HIDL_FETCH_INewlife(const char* /* name */) {
    return new Newlife();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace newlife
}  // namespace hardware
}  // namespace android
