typedef int s32;

struct S002A6C98 {
    char pad0[0x168];
    s32 unk168;
};

extern "C" void func_004B6C60(void *arg0, s32 arg1);

extern "C" void func_002A6C98(struct S002A6C98 *arg0, s32 arg1) {
    arg0->unk168 = arg1;
    func_004B6C60((char *)arg0 + 0x578, arg1);
}
