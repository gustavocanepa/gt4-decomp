typedef int s32;

struct S00323CD8 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 func_003166D8(s32 arg0);

extern "C" void func_00323CD8(struct S00323CD8 *arg0) {
    func_003166D8(arg0->unk8);
}
