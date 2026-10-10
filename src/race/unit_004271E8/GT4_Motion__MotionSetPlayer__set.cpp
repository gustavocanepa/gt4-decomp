struct Obj {
    int unk0;
    int unk4;
};

extern "C" void GT4_Motion__MotionSetPlayer__set(Obj *arg0, int arg1, int arg2) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
}
