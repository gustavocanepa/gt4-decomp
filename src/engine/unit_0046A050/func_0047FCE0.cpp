typedef int s32;

struct Obj {
    char pad[0x64];
    s32 unk64;
    s32 unk68;
};

extern "C" void func_0047FCE0(Obj *arg0) {
    s32 temp_v1 = arg0->unk68;
    arg0->unk68 = -1;
    arg0->unk64 = temp_v1;
}
