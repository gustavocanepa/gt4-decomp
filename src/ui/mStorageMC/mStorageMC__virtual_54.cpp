typedef int s32;

struct Struct_002768C8 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_0054C730(s32 arg0);

extern "C" s32 mStorageMC__virtual_54(struct Struct_002768C8 *arg0) {
    return func_0054C730(arg0->unk10 - 1) == 0;
}
