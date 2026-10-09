typedef int s32;

struct Obj { char pad[4]; s32 unk4; };

extern "C" s32 func_00359A18(Obj *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    return 1;
}
