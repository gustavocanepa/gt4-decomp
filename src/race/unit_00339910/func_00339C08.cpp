/* Down-casts the object at +0x2880 of top from VehicleModel to RaceCarModel and runs setup on the result: GT4MC::FileGT4GameData::loadInstance
 * is called here with the argument shape of an old-ABI dynamic_cast (type_info taken from the object's vtable, target type RaceCarModel,
 * source type VehicleModel; inferred from the arguments, the symbol name is a GT HD guess). It then calls two virtual methods of the
 * result (+0xE8 and +0xF0, the second with floatArg) and, when the fields at +0x1670 / +0x1674 are nonzero, runs 00339AD0 on two pairs of
 * sub-blocks (indices 0 and 1). The calls on raceCar come before its null test, exactly as in the original code. */
#include "types.h"
struct Ent { short delta; short pad; void *fn; };
struct Obj { char p0[8]; char *vt; char p1[0x1670 - 12]; s32 f1670; s32 f1674; };
struct Top { char p0[0x2880]; Obj *mid; };
extern char RaceCarModel__tf[];
extern char VehicleModel__tf[];
extern "C" void func_00339AD0(s32 a0, void *a1, void *a2, s32 a3);
extern "C" void *__dynamic_cast_2(s32 a0, void *a1, s32 a2, void *a3, void *a4, void *a5);
typedef void (*F1)(void *);
typedef void (*F2)(void *, s32, s32, float);
extern "C" void func_00339C08(s32 target, Top *top, float floatArg) {
    float floatArgCopy = floatArg;
    Obj *raceCar = 0;
    Obj *vehicle = top->mid;
    if (vehicle != 0) {
        Ent *e = (Ent *)vehicle->vt;
        raceCar = (Obj *)__dynamic_cast_2((s32)e->fn, RaceCarModel__tf, 0, (char *)vehicle + e->delta, VehicleModel__tf, vehicle);
    }
    {
        Ent *e = (Ent *)(raceCar->vt + 0xE8);
        ((F1)e->fn)((char *)raceCar + e->delta);
    }
    {
        Ent *e = (Ent *)(raceCar->vt + 0xF0);
        ((F2)e->fn)((char *)raceCar + e->delta, 0, 0, floatArgCopy);
    }
    if (raceCar != 0) {
        if (raceCar->f1670 != 0) {
            func_00339AD0(target, (char *)raceCar + 0x5F0, (char *)raceCar + 0xDC0, 0);
        }
        if (raceCar->f1674 != 0) {
            func_00339AD0(target, (char *)raceCar + 0xE30, (char *)raceCar + 0x1600, 1);
        }
    }
}
