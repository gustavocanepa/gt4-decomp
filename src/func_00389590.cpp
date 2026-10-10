typedef int s32;

/* A function-local static object written out: guard D_00621318, object D_008440C8, its
   constructor RaceInput__structor_0 and the atexit-registered destructor stub func_0038A580. */
extern "C" s32 D_00621318;
extern "C" char D_008440C8[];
extern "C" void *RaceInput__structor_0(void *obj);
extern "C" void func_0038A580(void);
extern "C" s32 func_005A2ED0(void (*fn)(void));

extern "C" void *RaceBase__virtual_69(void) {
    if (D_00621318 == 0) {
        RaceInput__structor_0(D_008440C8);
        D_00621318 = 1;
        func_005A2ED0(func_0038A580);
    }
    return D_008440C8;
}
