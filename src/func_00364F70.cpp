typedef short s16;

struct Inner {
    char pad[0x12];
    s16 unk12;
};

struct Obj {
    Inner *ptr;
};

extern "C" s16 func_00364F70(Obj *arg0) {
    return arg0->ptr->unk12;
}
