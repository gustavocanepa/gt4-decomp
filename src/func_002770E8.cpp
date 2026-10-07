typedef int s32;

struct Obj { char pad[0x18]; s32 unk18; };

extern char D_00668508;

extern "C" void func_002770E8(Obj *arg0) {
    register s32 v1 asm("$3") = (s32)&D_00668508;
    arg0->unk18 = v1;
}
