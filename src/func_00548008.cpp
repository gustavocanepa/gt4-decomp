typedef int s32;

struct Server {
    s32 sema;
    char pad4[0x3C];
    s32 arg;
};

extern Server D_0086CA40;
extern "C" void func_00578500(s32 sema);
extern "C" void func_00578168(Server *s, s32 cmd, s32 a, s32 b, s32 c);

extern "C" void func_00548008(s32 arg) {
    Server *s = &D_0086CA40;
    func_00578500(s->sema);
    s->arg = arg;
    func_00578168(s, 9, 0, 0, 0);
}
