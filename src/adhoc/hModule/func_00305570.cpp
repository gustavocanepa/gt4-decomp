typedef int s32;

struct S00305570 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003166D8(s32 arg0);

extern "C" void func_00305570(struct S00305570 *arg0) {
    func_003166D8(arg0->unk10);
}
