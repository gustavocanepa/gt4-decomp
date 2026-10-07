typedef int s32;

struct Struct_00426C50 {
    char pad[0x148];
    s32 *unk148;
};

extern void func_00346138(s32 *);

extern "C" void func_00426C50(Struct_00426C50 *arg0) {
    s32 *temp_v0;

    temp_v0 = arg0->unk148;
    if (temp_v0 != 0) {
        func_00346138((s32 *)((char *)temp_v0 + 8));
    }
}
