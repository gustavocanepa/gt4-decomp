typedef int s32;

struct Obj00594120 {
    char pad[0x50];
    void *unk50;
};

extern char D_0068A0B0[];
extern "C" s32 func_00594FB8(Obj00594120 *arg0);

extern "C" s32 func_00594120(Obj00594120 *arg0) {
    arg0->unk50 = D_0068A0B0;
    return func_00594FB8(arg0);
}
