typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_00659A00;
extern char D_006D30F0[];
extern char D_0068A370[];

extern "C" struct S00659988 *func_005C13A0(void) {
    if (D_00659A00.unk0 == 0) {
        D_00659A00.unk0 = D_006D30F0;
        D_00659A00.unk4 = D_0068A370;
    }
    return &D_00659A00;
}
