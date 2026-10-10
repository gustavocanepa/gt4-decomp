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

extern "C" void func_002B5188(void *, void *, s32);
extern "C" s32 func_002B5498(void *, s32);
extern "C" void func_002B5500(void *, s32, s32);

struct func_002B5270_arg0 {
    char pad0[0x108];
    s32 unk108;
    char pad10C[0x18];
    s32 unk124;
    char pad128[0x4];
    s32 unk12C;
    char pad130[0x1C];
    s32 unk14C;
};

extern "C" void func_002B5270(s32 *arg0, void *arg1) {
    func_002B5188(arg0, arg1, 0);
    if (((struct func_002B5270_arg0 *)arg0)->unk12C >= 0) {
        if (((struct func_002B5270_arg0 *)arg0)->unk124 != ((struct func_002B5270_arg0 *)arg0)->unk12C) {
            if (func_002B5498(arg0, ((struct func_002B5270_arg0 *)arg0)->unk12C) != 0) {
                func_002B5500(arg0, ((struct func_002B5270_arg0 *)arg0)->unk12C, 0);
            }
            if (((struct func_002B5270_arg0 *)arg0)->unk124 >= 0) {
                func_002B5500(arg0, ((struct func_002B5270_arg0 *)arg0)->unk124, ((struct func_002B5270_arg0 *)arg0)->unk108);
            }
            ((struct func_002B5270_arg0 *)arg0)->unk14C = 0x1;
        }
    }
    ((struct func_002B5270_arg0 *)arg0)->unk12C = -0x1;
}
