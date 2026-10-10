typedef int s32;
typedef void (*FnVoid)(void);

extern "C" void func_0030C348(void);

extern FnVoid HOutput__Handler_;

extern "C" void func_0030C350(s32 arg0) {
    if (arg0 != 0) {
        HOutput__Handler_ = (FnVoid)arg0;
        return;
    }
    HOutput__Handler_ = func_0030C348;
}
