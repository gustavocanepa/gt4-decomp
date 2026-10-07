typedef int s32;

struct Obj00471F30 {
    s32 unk0;
    char pad1[4];
    s32 unk8;
    char pad2[4];
    s32 unk10;
};

extern "C" s32 func_00471F30(struct Obj00471F30 *arg0) {
    s32 a = arg0->unk0;
    s32 b = arg0->unk8;
    s32 c = arg0->unk10;
    s32 v0 = (b < a) ? b : a;
    return (c < v0) ? c : v0;
}
