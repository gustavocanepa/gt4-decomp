struct Table {
    char pad0[0x16];
    unsigned short count;
};

extern "C" void ModelSet2__begin(Table *t, void *arg);
extern "C" int ModelSet2___render(Table *t, int index, void *arg);
extern "C" void ModelSet2__end(Table *t);

extern "C" void ModelSet2__render(Table *t, void *arg)
{
    int i = 0;
    ModelSet2__begin(t, arg);
    for (; i < t->count; i++)
        ModelSet2___render(t, i, arg);
    ModelSet2__end(t);
}
