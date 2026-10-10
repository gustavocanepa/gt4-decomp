typedef int s32;

struct S { char pad[0x68]; unsigned char flag; };

extern "C" s32 TireWearParameters__isWearAvailable(S *arg0) {
    return arg0->flag != 0;
}
