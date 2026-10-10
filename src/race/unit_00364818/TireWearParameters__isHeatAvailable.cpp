typedef int s32;

struct S { char pad[0x69]; unsigned char flag; };

extern "C" s32 TireWearParameters__isHeatAvailable(S *arg0) {
    return arg0->flag != 0;
}
