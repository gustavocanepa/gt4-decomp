struct Slot {
    char data[0x34];
};

extern char D_00655340[];
extern "C" void func_00576100(void *mutex);
extern "C" void func_00576140(void *mutex);
extern "C" void func_00559EB0(Slot *slot);

extern "C" void func_0055A430(Slot *slots)
{
    func_00576100(D_00655340);
    for (int i = 0; i < 48; i++)
        func_00559EB0(&slots[i]);
    func_00576140(D_00655340);
}
