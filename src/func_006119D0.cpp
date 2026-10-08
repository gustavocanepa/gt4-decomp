typedef float f32;

struct Obj {
    char pad[0x44];
    f32 unk44;
    f32 unk48;
};

extern "C" void func_006119D0(struct Obj *arg0) {
    arg0->unk44 = arg0->unk44 + arg0->unk48;
}
