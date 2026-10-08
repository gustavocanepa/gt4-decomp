typedef int s32;
typedef signed char s8;

struct Obj005C44B8 {
    char pad[0x3B4];
    s8 unk3B4;
};

extern "C" Obj005C44B8 *D_006187A8;

extern "C" void func_005C44B8(s32 arg0, s32 arg1) {
    Obj005C44B8 *temp_v0 = D_006187A8;

    if (temp_v0 != 0) {
        temp_v0->unk3B4 = arg1;
    }
}
