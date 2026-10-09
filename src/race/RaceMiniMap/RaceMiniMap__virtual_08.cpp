typedef signed char s8;

struct Obj {
    char pad1;
    s8 unk1;
    s8 unk2;
};

extern "C" void RaceMiniMap__virtual_08(Obj *arg0, s8 arg1, s8 arg2) {
    arg0->unk1 = arg1;
    arg0->unk2 = arg2;
}
