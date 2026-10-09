typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[0x81C8];
    s32 unk81C8;
};

extern "C" u32 func_006013B8(struct Obj *arg0) {
    return (u32)(~arg0->unk81C8) >> 0x1F;
}
