typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_00659A08;
extern char D_006D30F8[];
extern char D_0068A370[];

extern "C" struct S00659988 *func_005C13D8(void) {
    if (D_00659A08.unk0 == 0) {
        D_00659A08.unk0 = D_006D30F8;
        D_00659A08.unk4 = D_0068A370;
    }
    return &D_00659A08;
}
