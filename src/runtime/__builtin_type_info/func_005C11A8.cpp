typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_006599B8;
extern char D_006D30A8[];
extern char __builtin_type_info__vtable[];

extern "C" struct S00659988 *func_005C11A8(void) {
    if (D_006599B8.unk0 == 0) {
        D_006599B8.unk0 = D_006D30A8;
        D_006599B8.unk4 = __builtin_type_info__vtable;
    }
    return &D_006599B8;
}
