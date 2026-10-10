struct Table {
    char pad0[0x16];
    unsigned short count;
};

extern "C" void func_00455370(Table *t, void *arg);
extern "C" int func_00455708(Table *t, int index, void *arg);
extern "C" void func_004554D0(Table *t);

extern "C" void func_00455528(Table *t, void *arg)
{
    int i = 0;
    func_00455370(t, arg);
    for (; i < t->count; i++)
        func_00455708(t, i, arg);
    func_004554D0(t);
}
