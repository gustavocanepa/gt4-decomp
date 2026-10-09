typedef int s32;

extern "C" void func_00578968(s32 arg0, void *arg1, s32 arg2);

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_00575098(s32 arg0, s32 arg1) {
    Pair local;
    local.a = 0;
    local.b = 0;
    func_00578968(arg0, &local, arg1);
}
