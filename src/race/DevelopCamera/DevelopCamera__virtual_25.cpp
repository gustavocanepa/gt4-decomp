typedef int s32;
typedef float f32;

struct Obj_00372018 {
    char pad[0x184];
    f32 unk184;
};

struct Elem_00372018 {
    Obj_00372018 *ptr;
    char pad[0x19C - 4];
};

extern "C" void DevelopCamera__virtual_25(char *arg0, f32 fparg0) {
    Elem_00372018 *p = (Elem_00372018 *)(arg0 + 0x158);
    Obj_00372018 *obj;
    s32 i;

    for (i = 0; i < 6; i++) {
        obj = p->ptr;
        p++;
        obj->unk184 = fparg0;
    }
}
