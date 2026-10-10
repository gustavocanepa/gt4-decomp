typedef int s32;

struct Self { s32 m0; s32 m4; s32 m8; };
extern char D_00845C40[];
extern "C" s32 func_0057B1E8(char *, s32, s32);

extern "C" void func_0042FBB0(Self *self, s32 x) {
    s32 v = func_0057B1E8(D_00845C40, x, 0);
    self->m4 = self->m8;
    self->m8 = v;
}
