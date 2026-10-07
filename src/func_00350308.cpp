typedef int s32;
typedef signed char s8;

struct Sub {
    char pad[0x608];
    s32 unk608;
    char pad2[0x60C - 0x608 - 4];
    s8 unk60C;
};

struct Obj {
    char pad[0x104];
    Sub sub;
};

extern "C" void func_00350308(Obj *arg0) {
    Sub *temp_a0 = &arg0->sub;
    if (temp_a0->unk60C != 2) {
        temp_a0->unk608 = 0;
    }
}
