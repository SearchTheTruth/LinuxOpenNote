#include <android/hardware/newlifecallback/1.0/IHello.h>
#include <hidl/LegacySupport.h>

using android::hardware::newlifecallback::V1_0::IHello;
using android::hardware::defaultPassthroughServiceImplementation;

int main()
{
	return defaultPassthroughServiceImplementation<IHello>();
}

