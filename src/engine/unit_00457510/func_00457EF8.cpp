struct Obj {
    char pad0[0x14];
    void *items[5];
};

extern "C" void func_00457D08(void *item, void *arg, int flag);

extern "C" void func_00457EF8(Obj *self, void *arg)
{
    for (int i = 0; i < 5; i++)
        func_00457D08(self->items[i], arg, i == 2 || i == 3);
}
