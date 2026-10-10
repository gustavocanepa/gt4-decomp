typedef int s32;

struct Obj {
    char pad[0x12C0];
    s32 v[2];
};

extern "C" s32 func_003D5660(Obj *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (self->v[i] < 0)
            return 0;
    }
    return 1;
}
