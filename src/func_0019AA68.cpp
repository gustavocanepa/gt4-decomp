typedef int s32;

struct Obj {
    char pad[0xBC];
    s32 unkBC;
    s32 unkC0;
};

extern "C" void func_0019AA68(Obj *arg0, s32 arg1) {
    arg0->unkC0 = (s32)(arg1 != 0);
    arg0->unkBC = 1;
}
