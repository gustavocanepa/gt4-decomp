typedef int s32;
typedef long long s64;

struct Mgr {
    char pad[0x1E0];
    s32 f1E0;
};

struct Obj {
    char pad[0x38];
    s64 key;
};

extern Mgr D_006235A8;
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Mgr *, s64, s32 *);
extern "C" void func_00449CD8(s32, s32);

extern "C" void func_00445FF8(Obj *self) {
    s32 buf[32];
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->key, buf);
    func_00449CD8(D_006235A8.f1E0, buf[0]);
}
