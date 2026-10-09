typedef int s32;

struct Obj { char pad[0x84]; s32 unk84; char pad2[0x90-0x84-4]; s32 unk90; };

extern "C" void func_00490F90(Obj *arg0) {
    arg0->unk90 = arg0->unk84 + 1;
}
