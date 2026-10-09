typedef int s32;

extern "C" void RaceNetRallyBattle__virtual_87(void);
extern "C" void func_004FB030(void *arg0);

extern s32 D_00645570;

extern "C" void RaceNetBattle__virtual_87(void) {
    RaceNetRallyBattle__virtual_87();
    func_004FB030(&D_00645570);
}
