typedef short s16;

struct Obj {
    char pad[0x4];
    s16 unk4;
    s16 unk6;
};

extern "C" void RaceDisplayObjectBase__setLocation(Obj *arg0, s16 arg1, s16 arg2) {
    arg0->unk4 = arg1;
    arg0->unk6 = arg2;
}
