typedef int s32;

/* A function-local static object written out: guard D_00619CA0, object D_0083F5B8, its
   constructor func_0030BB18 and the atexit-registered destructor stub func_0030C238. */
extern "C" s32 D_00619CA0;
extern "C" char D_0083F5B8[];
extern "C" void *func_0030BB18(void *obj);
extern "C" void func_0030C238(void);
extern "C" s32 func_005A2ED0(void (*fn)(void));

extern "C" void *mLoggerControl__virtual_12(void) {
    if (D_00619CA0 == 0) {
        func_0030BB18(D_0083F5B8);
        D_00619CA0 = 1;
        func_005A2ED0(func_0030C238);
    }
    return D_0083F5B8;
}
