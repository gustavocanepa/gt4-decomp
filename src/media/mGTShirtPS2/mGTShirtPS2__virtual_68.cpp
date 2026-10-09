typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x254];
    s32 unk254;
};

extern "C" void mGTShirtPS2__virtual_68(Obj *arg0, f32 arg1) {
    arg0->unk254 = (s32)(arg1 * 60.0f);
}
