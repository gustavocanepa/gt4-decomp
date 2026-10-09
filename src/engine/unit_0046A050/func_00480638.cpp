typedef int s32;

struct Obj { char pad[0x68]; s32 unk68; s32 unk6C; };

extern "C" void func_00480638(Obj *arg0, s32 arg1) {
    arg0->unk68 = arg1;
    arg0->unk6C = 0;
}
