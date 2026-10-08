typedef int s32;

struct S_002320F0;

struct Obj_002320F0 {
    char pad[0x1D58];
    struct S_002320F0 *unk1D58;
};

extern "C" s32 func_002C5920(struct S_002320F0 *arg0);

extern "C" s32 func_002320F0(struct Obj_002320F0 *arg0) {
    return func_002C5920(arg0->unk1D58) == (s32)arg0;
}
