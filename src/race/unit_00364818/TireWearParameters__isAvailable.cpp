typedef int s32;

extern "C" s32 TireWearParameters__isWearAvailable(void *);
extern "C" s32 TireWearParameters__isHeatAvailable(void *);

extern "C" s32 TireWearParameters__isAvailable(void *o) {
    s32 r = 0;
    if (TireWearParameters__isWearAvailable(o) || TireWearParameters__isHeatAvailable(o))
        r = 1;
    return r;
}
