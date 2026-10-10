typedef int s32;

extern "C" void func_0044CC18(s32 arg0, s32 arg1, void *arg2, s32 arg3);

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_0044CBC0(s32 arg0, s32 arg1) {
    Pair local;
    local.a = 0;
    local.b = 0;
    func_0044CC18(arg0, arg1, &local, 1);
}
