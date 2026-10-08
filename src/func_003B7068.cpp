typedef int s32;

struct S003B7068 {
    char pad[0x18];
    void *unk18;
};

extern "C" char D_0067FC28[];
extern "C" s32 func_003B70E0(S003B7068 *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_003B7068(S003B7068 *arg0) {
    arg0->unk18 = D_0067FC28;
    return func_003B70E0(arg0, 0x64, 0x64);
}
