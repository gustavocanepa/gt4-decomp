typedef int s32;

struct Struct_0013A548 {
    char pad0[0x2A4];
    s32 unk2A4;
};

extern void func_00154208(s32);

extern "C" void func_0013A650(Struct_0013A548 *arg0) {
    s32 temp_v0 = arg0->unk2A4;
    if (temp_v0 != 0) {
        func_00154208(temp_v0);
    }
}
