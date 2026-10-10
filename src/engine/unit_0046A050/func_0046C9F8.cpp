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

extern "C" void func_0046F378(void *, s32);
extern "C" void func_0046F300(void *, s32);

struct func_0046C9F8_arg1 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

struct func_0046C9F8_arg2 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};
struct func_0046C9F8_arg3 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

extern "C" void func_0046C9F8(s32 *arg0, struct func_0046C9F8_arg1 *arg1, s32 arg2, char **arg3) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x85c;
    func_0046F378(v_s0, (0 | 0xffc0));
    func_0046F378(v_s0, 0x11);
    func_0046F300(v_s0, arg1->unkC);
    func_0046F378(v_s0, arg1->unk4);
    func_0046F378(v_s0, *(s32 *)(char *)arg1);
    func_0046F300(v_s0, 0x3);
    func_0046F300(v_s0, 0);
    func_0046F300(v_s0, ((*(s32 *)(char *)arg2 << 4) | ((struct func_0046C9F8_arg2 *)arg2)->unk4));
    func_0046F300(v_s0, *(s32 *)(char *)arg3);
    func_0046F300(v_s0, 0x1);
    func_0046F300(v_s0, ((((struct func_0046C9F8_arg2 *)arg2)->unk8 << 4) | ((struct func_0046C9F8_arg2 *)arg2)->unkC));
    func_0046F300(v_s0, ((struct func_0046C9F8_arg3 *)arg3)->unk4);
    func_0046F300(v_s0, 0x2);
    func_0046F300(v_s0, ((((struct func_0046C9F8_arg2 *)arg2)->unk10 << 4) | ((struct func_0046C9F8_arg2 *)arg2)->unk14));
    func_0046F300(v_s0, ((struct func_0046C9F8_arg3 *)arg3)->unk8);
}
