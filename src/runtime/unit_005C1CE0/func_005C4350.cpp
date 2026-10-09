typedef int s32;

struct Obj005C4350 {
    char pad[0x46C];
    s32 unk46C;
};

extern "C" Obj005C4350 *D_006187A8;

extern "C" void func_005C4350(s32 arg0, s32 arg1) {
    Obj005C4350 *temp_v0 = D_006187A8;

    if (temp_v0 != 0) {
        temp_v0->unk46C = arg1;
    }
}
