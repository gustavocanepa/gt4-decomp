typedef float f32;

struct Dst {
    f32 unk0;
    f32 unk4;
};

struct Src {
    char pad[0x80];
    f32 unk80;
    f32 unk84;
};

extern "C" Dst *func_00267D70(Dst *arg0, Src *arg1) {
    arg0->unk0 = arg1->unk80;
    arg0->unk4 = arg1->unk84;
    return arg0;
}
