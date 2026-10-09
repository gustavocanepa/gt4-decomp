typedef int s32;

struct Struct_00320108 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" void HTryCatchFrame__structor_0(s32 arg0, s32 arg1);

extern "C" void mTryCatch__virtual_08(struct Struct_00320108 *arg0, s32 arg1) {
    HTryCatchFrame__structor_0(arg1, arg0->unk8);
}
