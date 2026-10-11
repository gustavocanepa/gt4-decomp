typedef int s32;

extern "C" s32 malloc(s32 arg0);
extern "C" void mCarGarage__structor_2(s32 arg0, s32 arg1);
extern "C" void func_00309348(s32 arg0, s32 *arg1);

extern "C" void func_001480E0(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    s32 s1 = arg1;
    s32 s2 = malloc(0x190);
    mCarGarage__structor_2(s2, s1);
    s32 local = s2;
    func_00309348(s0, &local);
}
