typedef int s32;

extern "C" void func_00575098(void *arg0, s32 arg1);

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_00575070(s32 arg0) {
    Pair local;
    local.a = 0;
    local.b = 0;
    func_00575098(&local, arg0);
}
