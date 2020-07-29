#include <android/hardware/newlife/1.0/INewlife.h>
#include <hidl/LegacySupport.h>

using android::hardware::newlife::V1_0::INewlife;
using android::hardware::defaultPassthroughServiceImplementation;

int main()
{
    return defaultPassthroughServiceImplementation<INewlife>();
}
