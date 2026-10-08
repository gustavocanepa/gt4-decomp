typedef int s32;

struct Obj_0032FC98 {
    char pad0[0xD80];
    s32 unkD80;
};

extern "C" void func_0033CCF0(Obj_0032FC98 *arg0);

extern "C" void func_0032FC98(Obj_0032FC98 *arg0) {
    func_0033CCF0(arg0);
    arg0->unkD80 = 1;
}
