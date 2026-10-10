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

extern s32 D_006184F0;
extern char D_006244D8[];
extern "C" void func_004A0BE0(s32, s32);
extern "C" s32 func_004390D0(void *);
extern "C" void func_00472528(void *, s32);
extern "C" void func_00439888(void *);
extern "C" void func_00460AF8(s32);

struct func_004365B8_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x8];
    s32 unk18;
    s32 unk1C;
    char pad20[0x1090];
    s32 unk10B0;
};
struct func_004365B8_v_s1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

extern "C" void func_004365B8(s32 *arg0) {
    char *v_s1;
    s32 t1;
    v_s1 = (char *)&D_006244D8;
    func_004A0BE0((((struct func_004365B8_arg0 *)arg0)->unk18 << 1), (((struct func_004365B8_arg0 *)arg0)->unk1C << 1));
    t1 = func_004390D0((char *)arg0 + 0x24);
    D_006184F0 = t1;
    func_00472528(v_s1, ((struct func_004365B8_arg0 *)arg0)->unkC);
    *(s32 *)(char *)v_s1 = (s32)*(u8 *)((char *)arg0 + 0x10);
    ((struct func_004365B8_v_s1 *)v_s1)->unk4 = (s32)*(u8 *)((char *)arg0 + 0x11);
    ((struct func_004365B8_v_s1 *)v_s1)->unk8 = (s32)*(u8 *)((char *)arg0 + 0x12);
    func_00439888((char *)arg0 + 0x1650);
    func_00460AF8(((struct func_004365B8_arg0 *)arg0)->unk10B0);
}
