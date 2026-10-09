typedef int s32;

struct Obj002768A8 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_0054C7E0(s32 arg0);

extern "C" s32 mStorageMC__virtual_52(struct Obj002768A8 *arg0) {
    return func_0054C7E0(arg0->unk10 - 1);
}
