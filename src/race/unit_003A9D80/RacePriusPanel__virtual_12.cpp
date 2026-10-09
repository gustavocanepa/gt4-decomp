typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad[0x6E];
    s16 unk6E;
};

extern "C" void RacePriusPanel__virtual_12(struct Obj *arg0, f32 fparg0) {
    arg0->unk6E = (s16)(s32)(fparg0 + 0.5f);
}
