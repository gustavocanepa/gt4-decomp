typedef int s32;

struct Obj {
    char pad[0x94];
    s32 unk94;
    s32 unk98;
};

extern "C" void func_003DA058(Obj *arg0) {
    s32 temp_v0 = arg0->unk94;
    if (temp_v0 <= 0) {
        arg0->unk94 = 2;
    } else {
        arg0->unk94 = temp_v0 - 1;
    }
    arg0->unk98 = 1;
}
