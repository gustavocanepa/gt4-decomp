extern "C" void func_00577F80(void);
extern "C" int func_005B7198(int id);
extern "C" int func_005B7148(void);

extern "C" void func_00577A30(void *self, int id)
{
    while (!func_005B7198(id))
        func_00577F80();
    while (!func_005B7148())
        func_00577F80();
}
