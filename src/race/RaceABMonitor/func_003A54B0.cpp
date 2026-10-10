typedef int s32;

struct Item { char pad[0x30]; };
struct Self { char pad[0x20]; Item items[2]; };
extern "C" void func_003AB450(Item *);

extern "C" void func_003A54B0(Self *self) {
    Item *p = self->items;
    s32 i;
    for (i = 1; i >= 0; i--) {
        func_003AB450(p++);
    }
}
