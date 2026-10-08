typedef int s32;
typedef float f32;

struct C;

struct Obj002CADC0 {
    char pad0[0xF8];
    s32 unkF8;
    f32 unkFC;
};

extern "C" f32 func_0025B370(struct C *arg0);
extern "C" void func_002A2408(struct Obj002CADC0 *arg0);

extern "C" void func_002CADC0(struct Obj002CADC0 *arg0) {
    f32 temp_f0;

    func_002A2408(arg0);
    temp_f0 = func_0025B370((struct C *)arg0);
    arg0->unkF8 = 0;
    arg0->unkFC = temp_f0;
}
