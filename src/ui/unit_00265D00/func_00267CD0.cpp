typedef float f32;

struct Dst {
    f32 unk0;
    f32 unk4;
};

struct Src {
    char pad[0x6C];
    f32 unk6C;
    f32 unk70;
};

extern "C" Dst *func_00267CD0(Dst *arg0, Src *arg1) {
    arg0->unk0 = arg1->unk6C;
    arg0->unk4 = arg1->unk70;
    return arg0;
}
