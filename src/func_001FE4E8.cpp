typedef int s32;

struct Obj {
    char pad[0xAC];
    s32 unkAC;
};

extern "C" void func_001FE4B0(Obj *arg0);

extern "C" void func_001FE4E8(Obj *arg0, s32 arg1) {
    arg0->unkAC = arg1;
    if (arg1 != 0) {
        func_001FE4B0(arg0);
    }
}
