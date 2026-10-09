typedef int s32;

struct Obj { char pad[0x39AC]; s32 unk39AC; };

extern "C" s32 func_004F48D8(Obj *arg0) {
    return arg0->unk39AC != 0;
}
