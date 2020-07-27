#ifndef _ITEST_H
#define _ITEST_H
#include <utils/Errors.h>
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <list>

#undef LOG_TAG
#define LOG_TAG "jianghao_testservice"

using namespace android;
using std::list;

enum {
	SET,
	GET,
	REMOVE,
};

class ITest : public IInterface {
	public:
		DECLARE_META_INTERFACE(Test);

		virtual status_t getListSize(int *size) = 0;
		virtual status_t setListContent(const int pos, const String16 &txt) = 0;
		virtual status_t removeList(const int pos) = 0;
};

class BpTest : public BpInterface<ITest> {
	public:
		explicit BpTest(const sp<IBinder>& impl) :
			BpInterface<ITest>(impl) {};

		status_t getListSize(int *size) override {
			Parcel data, reply;
			data.writeInterfaceToken(ITest::getInterfaceDescriptor());
			remote()->transact(GET, data, &reply);
			status_t err = reply.readInt32();
			*size = reply.readInt32();
			return err;
		}

		status_t setListContent(const int pos, const String16 &txt) override {
			Parcel data, reply;
			data.writeInterfaceToken(ITest::getInterfaceDescriptor());
			data.writeInt32(pos);
			data.writeString16(txt);
			remote()->transact(SET, data, &reply);
			return reply.readInt32();
		}

		status_t removeList(const int pos) override {
			Parcel data, reply;
			data.writeInterfaceToken(ITest::getInterfaceDescriptor());
			data.writeInt32(pos);
			remote()->transact(REMOVE, data, &reply);
			return reply.readInt32();
		}
};

class BnTest : public BnInterface<ITest> {
	public:
		virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t /*flags*/);
};

class TestService : public BnTest {
	public:
		virtual status_t getListSize(int *size);
		virtual status_t setListContent(const int pos, const String16 &txt);
		virtual status_t removeList(const int pos);
	private:
		void print(void);
		list<String16> textList;
};

#endif
