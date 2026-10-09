typedef unsigned short u16;
typedef signed char s8;
typedef int s32;

struct S001CF368 {
    char pad[0x48];
    u16 unk48;
    char pad2[0x140 - 0x4A];
    s8 unk140;
};

extern "C" s32 func_0038A388(s32 arg0);
extern "C" char D_00694DC0[];

extern "C" s32 func_001CF368(struct S001CF368 *arg0) {
    if ((arg0->unk48 & 1) != 0) {
        return func_0038A388(arg0->unk140);
    }
    return (s32)D_00694DC0;
}
