struct Wheel {
    char data[0x74];
};

struct Effects {
    char data[0x14C];
};

struct Car {
    Wheel wheels[4];
    Effects effects;
    int count;
};

extern "C" void func_003D36B0(Wheel *w);
extern "C" void func_00409988(Effects *e);

extern "C" void func_003D4B80(Car *car)
{
    Wheel *w = car->wheels;
    int n = 4;
    while (n--) {
        func_003D36B0(w);
        w++;
    }
    func_00409988(&car->effects);
    car->count = 0;
}
