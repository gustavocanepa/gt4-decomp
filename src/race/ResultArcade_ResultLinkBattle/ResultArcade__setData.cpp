struct func_003DFEB0_Auto {
    char pad0[0x6CC];
    float distance;
    char pad6D0[0x718 - 0x6D0];
    int time;
};

struct func_003DFEB0_Car {
    char pad0[0x14];
    int slot;
    func_003DFEB0_Auto *automobile;
    char pad1C[0x1B0 - 0x1C];
    int bestLap;
};

struct func_003DFEB0_Gas {
    char pad0[0x10];
    int mileage;
    float consumption;
};

struct func_003DFEB0_Entry {
    char pad0[0xA8];
    func_003DFEB0_Gas gas;
};

struct func_003DFEB0_Self {
    char pad0[0x2C];
    int done[9];
    unsigned int mode;
    char pad54[0x68 - 0x54];
    func_003DFEB0_Entry entries[1];
};

extern "C" int Automobile__GetExplicitCurrentLap(func_003DFEB0_Auto *a);
extern "C" int ToyotaPrius_GetAverageGasMileage10(func_003DFEB0_Auto *a);
extern "C" float ToyotaPrius_GetGasConsumption(func_003DFEB0_Auto *a);
extern "C" void func_003E0030(func_003DFEB0_Self *self, int index, int time, int lap);
extern "C" void func_003E00B0(func_003DFEB0_Self *self, int index, int time, int lap);
extern "C" float func_003FA920(func_003DFEB0_Auto *a);
extern "C" void func_003E02C8(func_003DFEB0_Entry *e, float v);
extern "C" void func_003E0490(func_003DFEB0_Entry *e, float v);

extern "C" void ResultArcade__setData(func_003DFEB0_Self *self, int index, func_003DFEB0_Car *car) {
    if (self->done[car->slot] != 0) return;
    func_003DFEB0_Auto *a = car->automobile;
    int lap = Automobile__GetExplicitCurrentLap(a);
    switch (self->mode) {
    case 3:
        self->entries[index].gas.mileage = ToyotaPrius_GetAverageGasMileage10(a);
        self->entries[index].gas.consumption = ToyotaPrius_GetGasConsumption(a) * 1000.0f;
    case 0:
        func_003E0030(self, index, a->time, lap);
        break;
    case 1:
        func_003E00B0(self, index, a->time, lap);
        break;
    case 2:
        func_003E02C8(&self->entries[index], func_003FA920(a));
        break;
    case 4:
        func_003E0490(&self->entries[index], a->distance);
        break;
    case 5:
        func_003E0030(self, index, car->bestLap, lap);
        break;
    }
}
