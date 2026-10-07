typedef int s32;

struct S00574D78 {
    char pad[0x28];
    s32 unk28;
    s32 unk2C;
};

extern "C" void func_005763B8();

extern "C" void func_00574D78(S00574D78 *arg0) {
    func_005763B8();
    arg0->unk28 = 0;
    arg0->unk2C = 0;
}
