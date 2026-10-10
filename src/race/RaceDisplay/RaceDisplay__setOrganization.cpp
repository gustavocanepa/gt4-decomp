struct Obj {
    char pad0[4];
    int unk4;
};

extern "C" void RaceDisplay__setOrganization(Obj *arg0, int arg1) {
    arg0->unk4 = arg1;
}
