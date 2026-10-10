typedef int s32;
typedef long long s64;

struct Info { s32 pad[5]; s32 m14; s32 pad2[0x1A]; };
struct Mgr { char pad[0x1E0]; s32 m1E0; };
struct Self { char pad[0x38]; s64 id; };
extern Mgr D_006235A8;
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Mgr *, s64, Info *);
extern "C" void func_00449CD8(s32, s32);

extern "C" void func_00445FB8(Self *self) {
    Info info;
    Mgr *m = &D_006235A8;
    SPEC_DATABASE__DatabaseStorage__getRow(m, self->id, &info);
    func_00449CD8(m->m1E0, info.m14);
}
