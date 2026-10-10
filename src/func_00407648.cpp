typedef int s32;

struct Obj_00407648 {
    char pad0[0x10];
    void *m10;
    char pad14[0x24 - 0x14];
    s32 m24;
};

extern "C" void *func_003A1E10(const char *name);
extern "C" void func_003BE318(Obj_00407648 *obj, s32 arg);
extern "C" char D_006A4338[];

extern "C" void func_00407648(Obj_00407648 *arg0, s32 arg1) {
    if (arg0->m10 == 0) {
        arg0->m10 = func_003A1E10(D_006A4338);
        arg0->m24 = 0;
    }
    func_003BE318(arg0, arg1);
}
