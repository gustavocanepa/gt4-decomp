typedef int s32;

struct Obj { char pad[0x9BC]; s32 unk9BC; };

extern "C" void func_003744C0(Obj *arg0, s32 arg1) {
    *(s32 *)((char *)arg0 + arg0->unk9BC * 0x19C + 0x19C) = arg1;
}
