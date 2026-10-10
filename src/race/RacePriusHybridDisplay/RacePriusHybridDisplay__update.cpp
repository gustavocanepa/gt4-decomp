typedef int s32;
typedef float f32;

struct Elem_003AA488 {
    char data[0x24];
};

struct Obj_003AA488 {
    char pad[0x28];
    Elem_003AA488 elems[5];
};

extern "C" void PaletteFlowAnimation__update(Elem_003AA488 *e, f32 t);

extern "C" void RacePriusHybridDisplay__update(Obj_003AA488 *arg0, f32 t) {
    s32 i;
    for (i = 0; i < 5; i++) {
        PaletteFlowAnimation__update(&arg0->elems[i], t);
    }
}
