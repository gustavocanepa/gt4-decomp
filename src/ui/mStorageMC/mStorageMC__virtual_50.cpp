typedef int s32;

struct Struct_00276880 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_0054C7B0(s32 arg0);

extern "C" s32 mStorageMC__virtual_50(struct Struct_00276880 *arg0) {
    return func_0054C7B0(arg0->unk10 - 1) == 2;
}
