typedef int s32;
typedef float f32;

struct Elem_003AA488 {
    char data[0x24];
};

struct Obj_003AA488 {
    char pad[0x28];
    Elem_003AA488 elems[5];
};

extern "C" void func_003AA2A8(Elem_003AA488 *e, f32 t);

extern "C" void func_003AA488(Obj_003AA488 *arg0, f32 t) {
    s32 i;
    for (i = 0; i < 5; i++) {
        func_003AA2A8(&arg0->elems[i], t);
    }
}
