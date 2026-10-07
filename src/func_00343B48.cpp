typedef short s16;

struct Obj {
    char pad[0x5B0];
    s16 unk5B0;
};

extern "C" s16 func_00343B48(struct Obj *arg0) {
    return arg0->unk5B0;
}
