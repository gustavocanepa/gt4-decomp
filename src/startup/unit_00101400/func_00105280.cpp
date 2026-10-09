struct S { int unk0; char pad4[0x34 - 4]; int unk34; };

extern "C" void func_004AA6B8(int arg0);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_00105280(S *arg0, int arg1) {
    if (arg0->unk34 != 0) {
        func_004AA6B8(arg0->unk0);
    }
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
