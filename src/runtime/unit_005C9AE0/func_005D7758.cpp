struct Node {
    char pad8[8];
    int unk8;
    char pad10[16 - 0xC];
    int unkC;
};

struct Mid {
    char pad0[4];
    struct Node *unk4;
};

extern int func_005C2A50(int, void *, int, int);

struct func_005D7758_s1 {
    char pad0[0x4];
    struct Node *unk4;
    struct Node *unk8;
};
struct func_005D7758_s0 {
    char pad0[0xC];
    struct Node *unkC;
};

void **func_005D7758(void **arg0, struct Mid *arg1, int arg2)
{
    struct Node *s1 = (struct Node *)arg1->unk4;
    struct Node *s0 = ((struct func_005D7758_s1 *)s1)->unk4;

    if (s0 != 0) {
        void *a1 = (char *)s0 + 0x10;
        do {
            if (func_005C2A50(arg2, a1, 0, -1) < 0) {
                s1 = s0;
                s0 = ((struct func_005D7758_s1 *)s1)->unk8;
            } else {
                s0 = ((struct func_005D7758_s0 *)s0)->unkC;
            }
            a1 = (char *)s0 + 0x10;
        } while (s0 != 0);
    }

    *arg0 = (void *)s1;
    return arg0;
}
