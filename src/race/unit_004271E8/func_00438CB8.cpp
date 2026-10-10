typedef int s32;

struct Obj {
    char pad[0x44];
    s32 index;
};

extern s32 D_00622E78[5];

extern "C" s32 func_00438CB8(Obj *self) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (self->index == i)
            return D_00622E78[i];
    }
    return 0;
}
