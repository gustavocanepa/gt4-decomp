/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Hands every car of the race its per-car storage inside this object: a 0x2E4-byte slot and two
 * 0xE20-byte cell blocks, then mirrors the inverted mode flag into the car (names inferred).
 *
 * dynamic_cast<RaceCarModel *>(car->model) is written out as gcc 2.96's own runtime call, as in
 * func_004AD168: a real dynamic_cast would name the type-info functions by their mangled names.
 *
 * `slot` is stepped in the loop header and then re-derived from the index in the body. The step is
 * dead, but it is one more instruction for the loop pass: with it the two type-info address halves
 * are hoisted in the second pass only (after the cell pointer's start value) and the 0x2E4 factor
 * of the multiply stays inside the loop, as in the original. */
struct VEntry {
    short delta;
    short pad;
    void *fn;
};

struct VehicleModel {
    int unk0[2];
    VEntry *vtbl;           /* 0x08 */
};

struct Slot {
    char unk0[0x2E4];
};

struct Cells {
    char unk0[0xE20];
};

struct RaceCarModel {
    Slot *slot;             /* 0x0000 */
    int unk4;
    VEntry *vtbl;           /* 0x0008 */
    char unkC[0x1660 - 0xC];
    Cells *cellsA;          /* 0x1660 */
    Cells *cellsB;          /* 0x1664 */
};

struct Car {
    char unk0[0x2880];
    VehicleModel *model;    /* 0x2880 */
    char unk2884[0x2898 - 0x2884];
    bool flag;              /* 0x2898 (bool is four bytes with this compiler) */
};

struct CarList {
    int count;
    int unk4;
    Car **items;            /* 0x08 */
};

struct Race {
    char unk0[0x60];
    CarList *cars;          /* 0x60 */
};

struct Self {
    char unk0[0x6C];
    Race *race;             /* 0x6C */
    char unk70[0x23454 - 0x70];
    Slot slots[6];          /* 0x23454 */
    int unk245AC;
    Cells cellsA[6];        /* 0x245B0 */
    Cells cellsB[6];        /* 0x29A70 */
    bool mode;              /* 0x2EF30 */
};

extern "C" void RaceCarModel__tf(void);
extern "C" void VehicleModel__tf(void);
/* __dynamic_cast_2 */
extern "C" void *__dynamic_cast_2(void *tf, void (*target)(void), int require_public, void *address,
                               void (*source)(void), void *subptr);

extern "C" void func_003C8668(Self *self)
{
    int i;
    Slot *slot = self->slots;

    for (i = 0; i < self->race->cars->count; i++, slot++) {
        Car *car = self->race->cars->items[i];
        VehicleModel *model = car->model;
        RaceCarModel *rc;

        if (model == 0)
            rc = 0;
        else
            rc = (RaceCarModel *)__dynamic_cast_2(model->vtbl[0].fn, RaceCarModel__tf, 0,
                                               (char *)model + model->vtbl[0].delta,
                                               VehicleModel__tf, model);

        slot = &self->slots[i];
        rc->slot = slot;

        /* virtual call through vtable entry 16 */
        VEntry *entry = &rc->vtbl[16];
        ((void (*)(void *))entry->fn)((char *)rc + entry->delta);

        rc->cellsA = &self->cellsA[i];
        rc->cellsB = &self->cellsB[i];
        car->flag = !self->mode;
    }
}
