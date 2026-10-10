typedef int s32;
typedef long long s64;

struct Global;
extern Global D_006235A8;

struct Obj {
    s64 ref;
    char pad8[0x90];
    s64 cur;
};

extern "C" s32 func_00443F40(Global *g, s64 id);
extern "C" s32 func_00443ED0(Global *g, s64 id, void *info);
extern "C" void func_004470C0(Obj *self);
extern "C" s32 func_00447238(Obj *self, s64 ref);

extern "C" s32 func_004470E8(Obj *self, s64 id) {
    if (self->cur == id) {
        return 1;
    }
    if (func_00443F40(&D_006235A8, id) == 0) {
        return 0;
    }
    func_004470C0(self);
    func_00443ED0(&D_006235A8, id, self);
    self->cur = id;
    if (self->ref != -1 && func_00447238(self, self->ref) == 0) {
        return 0;
    }
    return 1;
}
