typedef int s32;

struct Pair_0048ECC8 {
    s32 a;
    s32 b;
};

struct Init_0048ECC8 {
    s32 index;
    Pair_0048ECC8 value;
};

extern "C" volatile s32 D_00624970;
extern "C" Pair_0048ECC8 D_00849678[];
extern "C" Init_0048ECC8 D_006AE3F8[12];

extern "C" void func_0048ECC8(void) {
    if (D_00624970 == 0) {
        s32 i;
        for (i = 0; i < 12; i++) {
            D_00849678[D_006AE3F8[i].index] = D_006AE3F8[i].value;
        }
        D_00624970 = 1;
    }
}
