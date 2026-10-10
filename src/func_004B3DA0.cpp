/* __static_initialization_and_destruction_0 of one global with an inline constructor/destructor
   (vtable D_006893F0; the destructor chains to the base destructor func_004B3698). */
struct Obj {
    void *vtbl;
};

extern Obj D_00851188;
extern char D_006893F0[];
extern "C" void func_004B3698(Obj *self, int in_chrg) throw();

static inline void construct(Obj *const self) {
    self->vtbl = D_006893F0;
}

static inline void destruct(Obj *const self) {
    self->vtbl = D_006893F0;
    func_004B3698(self, 0);
}

extern "C" void func_004B3DA0(int init, int prio) {
    if (prio == 0xFFFF && init == 1)
        construct(&D_00851188);
    if (prio == 0xFFFF && init == 0)
        destruct(&D_00851188);
}
