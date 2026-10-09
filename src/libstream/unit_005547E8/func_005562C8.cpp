typedef int s32;

struct S005562C8 {
    char pad0[0x3C];
    s32 unk3C;
};

extern "C" void func_005613E0(s32 arg0);

extern "C" void func_005562C8(void *arg0, S005562C8 *arg1) {
    func_005613E0(arg1->unk3C);
}
