typedef int s32;

struct Obj {
    void *vtbl;
    char pad[0x17C];
    s32 m180;
    s32 sub;
};

extern char D_0067AB70[];
extern "C" Obj *func_00378AE0(Obj *);
extern "C" void func_003EBB90(s32 *);

extern "C" void func_0037D288(Obj *self) {
    s32 *p = &self->m180;
    func_00378AE0(self);
    self->vtbl = D_0067AB70;
    func_003EBB90(&self->sub);
    *p = 0;
}
