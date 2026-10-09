typedef int s32;

struct Struct_00323BD0 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 D_008414C0;

extern "C" void func_00323BD0(struct Struct_00323BD0 *arg0) {
    s32 *p = &arg0->unk8;

    if (p != &D_008414C0) {
        *p = D_008414C0;
    }
}
