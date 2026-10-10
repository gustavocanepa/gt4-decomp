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

extern "C" void RacePriusHybridDisplay__apply_patch(void *, void *, s32, s32, s32);
extern "C" void RacePriusHybridDisplay__apply_level_patch(void *, s32, s32, s32, s32, s32, f32);

struct RacePriusHybridDisplay__virtual_10_arg0 {
    char pad0[0x20];
    f32 unk20;
};

extern "C" void RacePriusHybridDisplay__DMAsafe(s32 *arg0) {
    RacePriusHybridDisplay__apply_patch(arg0, (char *)arg0 + 0x28, 0xd, 0, 0x8);
    RacePriusHybridDisplay__apply_patch(arg0, (char *)arg0 + 0x4c, 0xc, 0, 0x8);
    RacePriusHybridDisplay__apply_patch(arg0, (char *)arg0 + 0x70, 0xb, 0, 0x8);
    RacePriusHybridDisplay__apply_patch(arg0, (char *)arg0 + 0x94, 0xa, 0x1, 0x1);
    RacePriusHybridDisplay__apply_patch(arg0, (char *)arg0 + 0xb8, 0xa, 0, 0x1);
    RacePriusHybridDisplay__apply_level_patch(arg0, 0x9, 0, 0x8, 0x8000e3fa, 0x80202020, ((struct RacePriusHybridDisplay__virtual_10_arg0 *)arg0)->unk20);
}
