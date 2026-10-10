typedef int s32;
extern char D_00689E60[];
struct Obj { s32 f0; char pad4[0x28]; s32 f2C; s32 f30; s32 f34; char *f38; };
s32 func_005782E8(s32, s32);

void func_00578048(struct Obj *o) {
    o->f38 = D_00689E60;
    o->f0 = func_005782E8(1, 1);
    o->f2C = 0;
    o->f30 = 0;
    o->f34 = 0;
}
