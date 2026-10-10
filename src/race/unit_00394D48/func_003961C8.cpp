/* Static initialisation and destruction of a global object (derived from a base whose
   constructor/destructor are out of line): construct + own vtable, or destroy. */
struct Obj {
    char pad0[0x18];
    void *vt;
};

extern Obj RaceCourse__model_arena_;
extern char D_0067E228[];
extern "C" Obj *_UnitArenaBase__structor_1(Obj *o);
extern "C" void _UnitArenaBase__structor_0(Obj *o, int in_chrg);

extern "C" void func_003961C8(int initialize, int priority)
{
    if (priority == 0xFFFF) {
        if (initialize == 1) {
            Obj *o = &RaceCourse__model_arena_;
            _UnitArenaBase__structor_1(o);
            o->vt = D_0067E228;
        }
        if (initialize == 0)
            _UnitArenaBase__structor_0(&RaceCourse__model_arena_, 0);
    }
}
