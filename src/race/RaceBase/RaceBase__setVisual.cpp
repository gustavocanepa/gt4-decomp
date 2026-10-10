typedef int s32;

struct Obj {
    char pad[0xCD0];
    s32 unkCD0;
};

extern s32 RaceCarSound__visual_;

extern "C" void RaceBase__setVisual(Obj *arg0, s32 arg1) {
    arg0->unkCD0 = arg1;
    RaceCarSound__visual_ = arg1;
}
