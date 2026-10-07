typedef int s32;

struct Obj00494520 {
    char pad[0x98C];
    void *unk98C;
};

extern char D_00688B58[];
extern "C" s32 func_00494578(struct Obj00494520 *arg0);

extern "C" s32 func_00494520(struct Obj00494520 *arg0) {
    arg0->unk98C = D_00688B58;
    return func_00494578(arg0);
}
