typedef int s32;

struct Obj {
    s32 unk0;
    void (*unk4)(s32);
};

extern "C" void func_00567E90(struct Obj *arg0) {
    arg0->unk4(arg0->unk0);
}
