typedef int s32;

struct Obj {
    char pad0[0x164];
    signed char flags[6];
};

extern "C" s32 func_00382C58(Obj *self) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (self->flags[i] != 0) {
            return 1;
        }
    }
    return 0;
}
