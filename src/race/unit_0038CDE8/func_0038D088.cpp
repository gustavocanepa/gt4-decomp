typedef int s32;

struct Obj_0038D088 {
    char pad[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_00450FB0(void **arg0);

extern "C" void func_0038D088(Obj_0038D088 *arg0, void **arg1, s32 arg2) {
    arg0->unk4 = arg2;
    arg0->unk8 = func_00450FB0(arg1);
}
