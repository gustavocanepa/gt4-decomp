typedef int s32;

struct Struct_0046A050 {
    char pad0[8];
    s32 *unk8;
};

extern "C" s32 func_0046A050(Struct_0046A050 *arg0, s32 arg1) {
    s32 *temp_v1;

    temp_v1 = arg0->unk8;
    if (temp_v1 == 0) {
        return 0;
    }
    return temp_v1[arg1];
}
