typedef short s16;

struct Obj { char pad[0x2]; s16 unk2; };

extern "C" s16 func_003F7168(Obj *arg0) {
    return arg0->unk2;
}
