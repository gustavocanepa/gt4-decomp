struct Unk64 {
    short unk0;
    short pad2;
    int unk4;
};

struct Node {
    int unk0;
    char pad[0x60];
    Unk64 *unk64;
};

extern char D_005FD758[];
extern char D_005F3AE0[];

extern Node **func_001BD3B8(void);
extern int func_005C0FC8(int, void *, int, void *, void *, void *);

int func_001BD3C8(void)
{
    Node **temp_v0;
    Node *temp_v1;
    int var_v1;
    int var_v0;

    temp_v0 = func_001BD3B8();
    var_v1 = 0;
    if (temp_v0 != 0) {
        temp_v1 = *temp_v0;
        if (temp_v1 != 0) {
            Unk64 *u = temp_v1->unk64;
            var_v0 = func_005C0FC8(u->unk4, D_005FD758, 0,
                                    (char *)temp_v1 + u->unk0,
                                    D_005F3AE0, temp_v1);
        } else {
            var_v0 = 0;
        }
        var_v1 = var_v0;
    }
    return var_v1;
}
