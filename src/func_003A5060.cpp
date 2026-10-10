/* compiler: ee-gcc2.96-no-strict-aliasing */
struct ItemBase {
    char pad0[0xC];
    float value;
    char pad10[4];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void update();
};

struct Item : ItemBase {
    char pad18[0x150 - 0x18];
};

struct Panel {
    char pad0[0xC];
    float value;
    char pad10[0x40];
    Item items[8];
};

extern "C" void func_003A5060(Panel *p) {
    Item *item = p->items;
    for (int i = 0; i < 8; i++) {
        item->value = p->value;
        item->update();
        item++;
    }
}
