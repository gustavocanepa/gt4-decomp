struct Item {
    char pad[0x1C];
};

struct Obj {
    char pad[0x68];
    Item items[16];
};

extern "C" void func_0055B2D8(Item *);

extern "C" void func_00611F80(Obj *self) {
    for (int i = 0; i < 16; i++)
        func_0055B2D8(&self->items[i]);
}
