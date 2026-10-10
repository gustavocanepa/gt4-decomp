/* Static initialisation and destruction of a global object (derived from a base whose
   constructor/destructor are out of line): construct + own vtable, or destroy. */
struct Obj {
    char pad0[0x18];
    void *vt;
};

extern Obj D_006214B0;
extern char D_0067E228[];
extern "C" Obj *func_004637F0(Obj *o);
extern "C" void func_00463790(Obj *o, int in_chrg);

extern "C" void func_003961C8(int initialize, int priority)
{
    if (priority == 0xFFFF) {
        if (initialize == 1) {
            Obj *o = &D_006214B0;
            func_004637F0(o);
            o->vt = D_0067E228;
        }
        if (initialize == 0)
            func_00463790(&D_006214B0, 0);
    }
}
