typedef int s32;

extern "C" void ModelSet2__registerExternalTexSet(s32 arg0, s32 arg1);
extern "C" void func_004AB040(s32 arg0);

extern "C" void func_00156920(void) {
    func_004AB040(0x15);
    func_004AB040(0xF);
    ModelSet2__registerExternalTexSet(0, 0);
}
