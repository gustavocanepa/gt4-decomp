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

extern "C" void func_0043FF90(void *, s32);

struct func_00440430_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_00440430_v_s0 {
    char pad0[0xB0];
    s64 unkB0;
    char padB8[0x7B];
    s8 unk133;
    s8 unk134;
    s8 unk135;
    s8 unk136;
    s8 unk137;
    s8 unk138;
};

extern "C" void func_00440430(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    v_s0 = (char *)arg0 + (((((((struct func_00440430_arg0 *)arg0)->unk490 << 1) + ((struct func_00440430_arg0 *)arg0)->unk490) << 4) - ((struct func_00440430_arg0 *)arg0)->unk490) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    ((struct func_00440430_v_s0 *)v_s0)->unkB0 = (s64)arg1;
    func_0043FF90(arg0, arg2);
    ((struct func_00440430_v_s0 *)v_s0)->unk133 = (s8)*(u8 *)((char *)arg2 + 0x7a);
    ((struct func_00440430_v_s0 *)v_s0)->unk134 = (s8)*(u8 *)((char *)arg2 + 0x7b);
    ((struct func_00440430_v_s0 *)v_s0)->unk135 = (s8)*(u8 *)((char *)arg2 + 0x7c);
    ((struct func_00440430_v_s0 *)v_s0)->unk136 = (s8)*(u8 *)((char *)arg2 + 0x7d);
    ((struct func_00440430_v_s0 *)v_s0)->unk137 = (s8)*(u8 *)((char *)arg2 + 0x7e);
    ((struct func_00440430_v_s0 *)v_s0)->unk138 = (s8)*(u8 *)((char *)arg2 + 0x7f);
}
