typedef int s32;

struct S { char pad[4]; s32 unk4; };

extern "C" s32 ScenePack__isValid(S *arg0) {
    return arg0->unk4 != 0;
}
