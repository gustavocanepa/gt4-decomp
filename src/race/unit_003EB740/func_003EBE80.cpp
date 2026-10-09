typedef int s32;

extern char D_003EBE28;

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_00474130(s32 arg0, Pair *arg1);

extern "C" void func_003EBE80(s32 arg0) {
    if (arg0 != 0) {
        Pair local;
        local.b = 0;
        local.a = (s32)&D_003EBE28;
        func_00474130(arg0, &local);
    }
}
