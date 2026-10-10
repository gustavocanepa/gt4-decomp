typedef int s32;
typedef long long s64;
extern "C" void *func_002E0A20(void *);
extern "C" void func_002E09C8(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct Obj {
    char pad0[0x10];
    s64 bits;
};
struct A {
    Obj *p;
    s32 pad[3];
};

extern "C" void MStorageEntry__isDirectory(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    A a;
    s32 b4[4];
    func_002E0A20(&a);
    s32 *b = b4;
    func_002FE278(b, (s32)(a.p->bits >> 9) & 1);
    if (arg0 != b) {
        s32 newVal = b[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        s32 oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(b, 2);
    func_002E09C8(&a, 2);
}
