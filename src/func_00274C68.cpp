typedef int s32;

extern "C" void func_005A6AB0(void *arg0, void *arg1, s32 arg2);

extern "C" void func_00274C68(void *arg0, void *arg1) {
    func_005A6AB0((char *)arg0 + 0x270, arg1, 0x100);
}
