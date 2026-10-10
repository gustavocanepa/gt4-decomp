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

extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

struct hInt__virtual_41_arg0 {
    u8 pad0[0x10];
    s32 unk10;
};

extern "C" void hInt__virtual_41(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 v_s0;
    func_002FE278(buf0, ((struct hInt__virtual_41_arg0 *)arg0)->unk10);
    ((struct hInt__virtual_41_arg0 *)arg0)->unk10 = ((struct hInt__virtual_41_arg0 *)arg0)->unk10 - 0x1;
    if ((char *)arg1 != (char *)buf0) {
        v_s0 = buf0[0];
        if (v_s0 != 0) {
            func_003285A8(v_s0);
        }
        if (*(s32 *)(char *)arg1 != 0) {
            func_003285F8(*(s32 *)(char *)arg1);
        }
        *(s32 *)(char *)arg1 = v_s0;
    }
    func_002FC870(buf0, 0x2);
}
