typedef int s32;

struct Obj {
    char pad[0xAC];
    s32 unkAC;
};

extern "C" void func_001AAB28(Obj *arg0) {
    if (arg0->unkAC == 2) {
        arg0->unkAC = 1;
    }
}
