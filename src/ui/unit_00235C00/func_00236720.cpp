struct Unk64 {
    short unk0;
    short pad2;
    int unk4;
};

struct NodeB {
    int unk0;
    Unk64 *unk64;
};

extern char mScaleBar__tf[];
extern char RefCounter__tf[];

extern void *func_005C0FC8(int, void *, int, void *, void *, void *);
extern void func_003285A8(void *);
extern void func_003285F8(void *);

int func_00236720(void **arg0, NodeB **arg1)
{
    NodeB *temp_v1;
    void *var_s0;
    int var_v0;

    var_s0 = 0;
    temp_v1 = *arg1;
    if (temp_v1 != 0) {
        Unk64 *u = temp_v1->unk64;
        var_s0 = func_005C0FC8(u->unk4, mScaleBar__tf, 0,
                                (char *)temp_v1 + u->unk0,
                                RefCounter__tf, temp_v1);
    }
    if (var_s0 != 0) {
        func_003285A8(var_s0);
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = var_s0;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
