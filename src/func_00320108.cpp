typedef int s32;

struct Struct_00320108 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" void func_00318E00(s32 arg0, s32 arg1);

extern "C" void func_00320108(struct Struct_00320108 *arg0, s32 arg1) {
    func_00318E00(arg1, arg0->unk8);
}
