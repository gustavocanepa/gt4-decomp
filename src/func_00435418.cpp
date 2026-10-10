struct Item {
    char pad[8];
    unsigned long flags;
    char pad2[0x10];
};
struct Obj {
    char pad[8];
    Item items[(0x81C8 - 8) / 0x20];
    char pad2[0x81C8 - 8 - ((0x81C8 - 8) / 0x20) * 0x20];
    int sel;
    char pad3[0x81F4 - 0x81CC];
    int active;
};
extern "C" void func_00435388(Obj *o, int a, int b);

extern "C" void func_00435418(Obj *o, int a, int b)
{
    if (o->active) {
        int i = o->sel;
        if (i >= 0) {
            Item *it = &o->items[i];
            it->flags &= ~2;
        }
    }
    func_00435388(o, a, b);
    o->active = 0;
}
