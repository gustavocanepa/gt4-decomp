typedef int s32;

struct Obj { char pad[0x38]; s32 *unk38; };

extern "C" s32 func_0022FB50(Obj *arg0) {
    return *arg0->unk38;
}
