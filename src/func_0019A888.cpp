typedef int s32;

struct Inner {
    char pad[0xC];
    s32 unkC;
};

struct Obj {
    char pad[0xA0];
    Inner *unkA0;
};

extern "C" void func_0019A888(Obj *arg0, s32 arg1) {
    arg0->unkA0->unkC = arg1;
}
