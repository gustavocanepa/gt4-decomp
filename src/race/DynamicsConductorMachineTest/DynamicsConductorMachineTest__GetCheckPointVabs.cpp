struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct DynamicsConductorMachineTest {
    char pad0[0x10140];
    VEntry *vt;
};

extern float D_00622490[];

extern "C" float DynamicsConductorMachineTest__GetCheckPointVabs(DynamicsConductorMachineTest *self, int gear)
{
    VEntry *e = &self->vt[42];
    int n = e->fn((char *)self + e->delta);
    if (!(gear < n - 1))
        gear = 3;
    return D_00622490[gear];
}
