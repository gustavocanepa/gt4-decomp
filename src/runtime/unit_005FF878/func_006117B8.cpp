struct Voice {
    char data[0x70];
};

extern char D_00655340[];
extern "C" void func_00576100(void *mutex);
extern "C" void func_00576140(void *mutex);
extern "C" void func_0055AB98(Voice *v);

extern "C" void func_006117B8(void *self, Voice *voices, int count)
{
    func_00576100(D_00655340);
    for (int i = 0; i < count; i++)
        func_0055AB98(voices++);
    func_00576140(D_00655340);
}
