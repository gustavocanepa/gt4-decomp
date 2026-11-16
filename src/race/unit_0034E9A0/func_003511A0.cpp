#include "types.h"

/* Refreshes the four entry values of a car controller from the car's setup record
   (func_00359510): clears two accumulators, picks the state update (func_00351178 when
   func_00368398 accepts the car's sub-object at +0x234, func_00350FB8 otherwise), then, for each
   of the record's entries, scales the entry's base by the car's table value for its slot, adds the
   car's bonus to the entries flagged negative, and packs whether the value and x48 are zero into
   the entry's state byte. Field meanings are inferred from the code. */

struct SetupRecord {
    u8 pad0;
    u8 count;
    char pad2[0x12];
    u8 slot[0x28];
    s8 flag[0x10];
    u8 slotAt(u32 i) const {
        int r = 0;
        if ((int)i < count) r = slot[i];
        return r;
    }
    int negative(u32 i) const {
        int r = 0;
        if ((int)i < count) r = flag[i] < 0;
        return r;
    }
};

struct Car {
    char pad0[0x234];
    char sub234[0x12];
    u8 mode;
    char pad247[0x1010 - 0x247];
    f32 table[2];
    f32 bonus;
};

struct Entry {
    char pad0[0x46];
    u8 state;
    char pad47;
    f32 x48;
    char pad4C[0x64 - 0x4C];
    f32 base;
    char pad68[0x78 - 0x68];
    f32 value;
    char pad7C[0xEC - 0x7C];
};

struct Control {
    char pad0[0x60];
    Entry entries[4];
    char pad410[0x490 - 0x410];
    f32 gain;
    char pad494[0x50C - 0x494];
    f32 f50C;
    f32 f510;
    char pad514[0x522 - 0x514];
    u8 f522;
};

struct Owner {
    char pad0[0x10];
    Car *car;
    char pad14[0x104 - 0x14];
    Control control;
};

extern "C" SetupRecord *func_00359510(Car *);
extern "C" int func_00368398(void *);
extern "C" void func_00351178(Control *);
extern "C" void func_00350FB8(Owner *);

extern "C" void func_003511A0(Owner *self) {
    Control *control = &self->control;
    Car *car = self->car;
    SetupRecord *setup = func_00359510(car);
    f32 zero;
    u32 i;

    control->f510 = zero = 0.0f;
    control->f50C = zero;
    if (func_00368398(car->sub234))
        func_00351178(control);
    else
        func_00350FB8(self);
    if (self->car->mode == 4)
        control->f522 = 1;

    for (i = 0; i < setup->count; i++) {
        Entry *e = &self->control.entries[i];
        e->value = e->base * car->table[setup->slotAt(i)];
    }
    {
        f32 add = control->gain * car->bonus;
        for (i = 0; i < setup->count; i++) {
            if (setup->negative(i)) {
                Entry *e = &self->control.entries[i];
                e->value += add;
            }
        }
    }
    for (u32 j = 0; j < setup->count; j++) {
        Entry *e = &self->control.entries[j];
        int state = 0;
        if (e->value != 0.0f)
            state = 2;
        if (e->x48 == 0.0f)
            state |= 1;
        e->state = state;
    }
}
