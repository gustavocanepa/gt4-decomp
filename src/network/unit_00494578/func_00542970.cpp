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

extern "C" void func_00538C68(void *);

struct func_00542970_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" void func_00542970(s32 *arg0) {
    s32 buf0[4];
    buf0[0] = (s32)arg0;
    if (arg0 != 0) {
        if (((struct func_00542970_arg0 *)arg0)->unkC != 0) {
            func_00538C68((char *)arg0 + 0xc);
        }
        if (((struct func_00542970_arg0 *)arg0)->unk18 != 0) {
            func_00538C68((char *)arg0 + 0x18);
        }
        if (((struct func_00542970_arg0 *)arg0)->unk10 != 0) {
            func_00538C68((char *)arg0 + 0x10);
        }
        if (((struct func_00542970_arg0 *)arg0)->unk14 != 0) {
            func_00538C68((char *)arg0 + 0x14);
        }
        func_00538C68(buf0);
    }
}
