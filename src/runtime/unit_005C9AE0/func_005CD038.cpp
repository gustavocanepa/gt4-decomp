typedef int s32;

struct S005CD038 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_00438CF8(s32 arg0);

extern "C" void func_005CD038(struct S005CD038 *arg0) {
    func_00438CF8(arg0->unk10 + 0x1344);
}
