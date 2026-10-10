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

extern "C" void func_0049AC70(void *);
extern "C" s32 func_00105830(void *);
extern "C" void func_0049AC98(void *, s32, s32, s32, s32);
extern "C" void func_0049AF00(void *, s32, s32);
extern "C" void func_0049B148(void *, s32, s32, s32);
extern "C" void func_0049AFD0(void *, s32, s32);

struct func_00105930_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

extern "C" void func_00105930(s32 *arg0, void *arg1) {
    func_0049AC70(arg1);
    func_0049AC98(arg1, 0, *(s32 *)(char *)arg0, ((struct func_00105930_arg0 *)arg0)->unk4, func_00105830(arg0));
    func_0049AF00(arg1, ((struct func_00105930_arg0 *)arg0)->unk18, ((struct func_00105930_arg0 *)arg0)->unk1C);
    func_0049B148(arg1, 0, ((struct func_00105930_arg0 *)arg0)->unk10, (((struct func_00105930_arg0 *)arg0)->unk10 + ((struct func_00105930_arg0 *)arg0)->unk18) - 0x1);
    func_0049B148(arg1, 0x1, ((struct func_00105930_arg0 *)arg0)->unk14, (((struct func_00105930_arg0 *)arg0)->unk14 + ((struct func_00105930_arg0 *)arg0)->unk1C) - 0x1);
    func_0049AFD0(arg1, 0x4, 0x2);
    func_0049AFD0(arg1, 0x5, 0x2);
}
