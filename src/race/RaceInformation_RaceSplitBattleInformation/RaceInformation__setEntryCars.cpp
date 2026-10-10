typedef int s32;

struct Obj {
    char pad[0x118];
    s32 unk118;
};

extern "C" void RaceInformation__setEntryCars(Obj *arg0, s32 arg1) {
    arg0->unk118 = arg1;
}
