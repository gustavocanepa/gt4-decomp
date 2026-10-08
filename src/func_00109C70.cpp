typedef int s32;

struct Obj;

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC8F0(void *arg0);
extern "C" void func_001FA3D0(struct Obj *arg0);

struct Buf {
    struct Obj *ptr;
    char pad0[0xC];
};

extern "C" void func_00109C70(s32 arg0) {
    struct Buf buf;

    if (arg0 == 0xFF1B) {
        func_001DC8F0(&buf);
        func_001FA3D0(buf.ptr);
        func_001DC5F8(&buf, 2);
    }
}
