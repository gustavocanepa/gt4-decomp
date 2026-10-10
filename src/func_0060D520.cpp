struct Obj {
    char pad0[0x78];
    void *vt;
};

extern char D_00689518[];
extern "C" void func_004CB7B0(Obj *self, int in_chrg);
extern "C" void func_005C1628(void *p);

/* Destructor body: own vtable, base destructor (in_chrg 0), operator delete when bit 0 of in_chrg is set. */
extern "C" void func_0060D520(Obj *self, int in_chrg)
{
    self->vt = D_00689518;
    func_004CB7B0(self, 0);
    if (in_chrg & 1)
        return func_005C1628(self);
}
