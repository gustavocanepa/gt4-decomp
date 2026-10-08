typedef int s32;

extern "C" void func_004F0EB8(void *arg0, s32 arg1, void *arg2);

extern "C" char D_00645570[];
extern "C" char D_00829588[];

extern "C" void *func_001F1330(s32 arg0, s32 arg1) {
    func_004F0EB8(D_00645570, arg1, D_00829588);
    return D_00829588;
}
