typedef int s32;

struct S_00238F70 { char pad[0x100]; s32 unk100; };

extern "C" void func_00238F70(S_00238F70 *arg0, s32 arg1) {
    arg0->unk100 = arg1;
}
