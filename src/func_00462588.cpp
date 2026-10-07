typedef int s32;

struct Obj00462588 {
    s32 unk0;
    char pad[0x10 - 4];
    s32 unk10;
};

extern s32 D_00623A38;

extern "C" s32 func_00462588(struct Obj00462588 *arg0) {
    return (arg0->unk0 == 0) ? D_00623A38 : arg0->unk10;
}
