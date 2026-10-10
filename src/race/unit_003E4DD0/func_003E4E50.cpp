extern "C" void *func_003E4F30(void *self, int *key);
extern "C" void func_003E2710(void *item, int *key);
struct Obj { char pad[0x10]; int max; };
extern "C" void *func_003E4E50(Obj *self, int *key)
{
    void *item = func_003E4F30(self, key);
    if (item == 0)
        return 0;
    func_003E2710(item, key);
    if (self->max < *key)
        self->max = *key;
    return item;
}
