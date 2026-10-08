typedef int s32;
typedef void (*FnPtr)(s32);

struct Obj {
    char pad[0xDC];
    FnPtr unkDC;
};

extern "C" void func_00251EA0(Obj *arg0, s32 arg1) {
    FnPtr temp_v0 = arg0->unkDC;
    if (temp_v0 != 0) {
        temp_v0(arg1);
    }
}
