typedef int s32;

struct Key {
    s32 a;
    s32 b;
    Key(s32 x, s32 y) : a(x), b(y) {}
};

struct Result {
    s32 err;
    s32 pad[3];
    s32 value;
    s32 pad2[3];
    Result();
    Result(const Result &);
};

extern "C" const char *func_0048EDA0(s32);
extern "C" void *func_00103CB8(void *str, const char *name);
extern "C" Result func_004AE370(void *, Key *, s32);
extern "C" void func_00498B28(s32);

extern s32 D_0061830C;
extern s32 D_00618310;
extern s32 D_00618314;

extern "C" void func_00103F18(s32 arg0)
{
    char path[0x80];

    D_0061830C = 0;
    if (D_00618310 == 0) {
        return;
    }
    func_00103CB8(path, func_0048EDA0(arg0));
    Key key(D_00618314, D_00618310);
    const Result &res = func_004AE370(path, &key, 1);
    if (res.err == 0) {
        D_0061830C = res.value;
        func_00498B28(res.value);
    }
}
