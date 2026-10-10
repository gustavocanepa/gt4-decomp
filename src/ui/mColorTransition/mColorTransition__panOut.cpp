typedef int s32;

struct Obj002872C8 {
    char pad[0x20];
    s32 unk20;
};

extern "C" void mTransition__panOut(Obj002872C8 *arg0);

extern "C" void mColorTransition__panOut(Obj002872C8 *arg0) {
    mTransition__panOut(arg0);
    arg0->unk20 = 0;
}
