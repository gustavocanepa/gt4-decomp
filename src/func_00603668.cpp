typedef int s32;
typedef short s16;

struct Obj00603668 {
    char pad0[0x2C];
    s16 unk2C;
};

extern "C" s32 func_00603668(struct Obj00603668 *arg0) {
    return arg0->unk2C * 0x64;
}
