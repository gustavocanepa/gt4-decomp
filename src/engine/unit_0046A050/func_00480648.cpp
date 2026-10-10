struct Obj {
    char pad0[0x60];
    void *table;
};

extern "C" int func_00474A40(void *table, const char *name);
extern "C" void func_00480638(Obj *self, int index);
extern "C" void func_0057D9C0(const char *fmt, ...);
extern const char D_006ADDD8[];

extern "C" void func_00480648(Obj *self, const char *name)
{
    int index = func_00474A40(self->table, name);
    if (index < 0)
        return func_0057D9C0(D_006ADDD8, name);
    func_00480638(self, index);
}
