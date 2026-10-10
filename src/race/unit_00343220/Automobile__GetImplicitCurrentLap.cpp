typedef short s16;

struct Obj {
    char pad[0x5B0];
    s16 unk5B0;
};

extern "C" s16 Automobile__GetImplicitCurrentLap(struct Obj *arg0) {
    return arg0->unk5B0;
}
