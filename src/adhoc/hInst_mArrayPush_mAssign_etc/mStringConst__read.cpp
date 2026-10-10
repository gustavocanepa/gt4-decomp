typedef int s32;

extern "C" void func_002FFA40(s32 arg0, void *arg1);

extern "C" void mStringConst__read(void *arg0, s32 arg1) {
    func_002FFA40(arg1, (char *)arg0 + 8);
}
