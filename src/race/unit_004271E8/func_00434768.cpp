typedef int s32;

struct S { char pad[0x6C]; s32 unk6C; };

extern "C" void func_00434768(S *arg0) {
    arg0->unk6C = 0;
}
