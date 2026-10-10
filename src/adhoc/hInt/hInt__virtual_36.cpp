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

extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

struct func_002FD398_arg0 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void hInt__virtual_36(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_002FE278(buf0, (0 - ((struct func_002FD398_arg0 *)arg0)->unk10));
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *(s32 *)arg1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *(s32 *)arg1 = newVal;
    }
    func_002FC870(buf0, 0x2);
}
