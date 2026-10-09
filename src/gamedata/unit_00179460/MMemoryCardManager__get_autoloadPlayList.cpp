typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_001792D8(void *);
extern "C" void func_00179280(void *, s32);
extern "C" void mMemoryCardFile__structor_0(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_001740F0(void *, s32);

extern "C" void MMemoryCardManager__get_autoloadPlayList(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    func_001792D8(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x24);
    func_00179280(buf0, 0x2);
    if (v_s0 != 0) {
        mMemoryCardFile__structor_0(buf0, v_s0);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_001740F0(buf0, 0x2);
    }
}
