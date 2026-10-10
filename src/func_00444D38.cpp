typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Six {
    u8 b[6];
};

struct Info {
    char pad0[0xA];
    Six six;
    char pad10[0x10];
};

struct Obj {
    char pad0[0xB0];
    s64 id;
    char padB8[0x7B];
    Six six;
};

extern "C" s32 func_00443F40(Global *g, s64 id);
extern "C" s32 func_00443ED0(Global *g, s64 id, Info *info);
extern "C" u8 func_004452A8(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_00444D38(Obj *self) {
    s64 id = self->id;
    if (func_00443F40(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    func_00443ED0(&D_006235A8, id, &info);
    self->six.b[0] = info.six.b[0];
    self->six.b[1] = info.six.b[1];
    self->six.b[2] = info.six.b[2];
    self->six.b[3] = info.six.b[3];
    self->six.b[4] = info.six.b[4];
    self->six.b[5] = info.six.b[5];
    return 1;
}
