typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x258];
    s32 unk258;
};

extern "C" void mGTShirtPS2__virtual_69(Obj *arg0, f32 arg1) {
    arg0->unk258 = (s32)(arg1 * 30.0f);
}
