/* compiler: ee-gcc2.96-as2004 */
struct Slot {
    char pad[0x2C];
};

struct Board {
    Slot slots[10];
    int colors[16];
};

extern "C" void func_00431DF0(Slot *s);

extern "C" void func_00431D80(Board *b)
{
    unsigned int c = 0x157529FF;
    for (int i = 15; i >= 0; i--)
        b->colors[i] = c;
    for (int i = 0; i < 10; i++)
        func_00431DF0(&b->slots[i]);
}
