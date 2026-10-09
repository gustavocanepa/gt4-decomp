typedef int s32;

struct S { char pad[0x9BC]; s32 unk9BC; };

extern "C" void func_00372080(S *arg0, s32 arg1) {
    arg0->unk9BC = arg1;
}
