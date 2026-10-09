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

extern int func_005C2A50(void *, int, int, int);

void **func_005EB048(void **arg0, struct Mid *arg1, int arg2)
{
    struct Node *s1 = (struct Node *)arg1->unk4;
    struct Node *s0 = *(struct Node **)((char *)s1 + 4);

    if (s0 != 0) {
        void *a0 = (char *)s0 + 0x10;
        do {
            if (func_005C2A50(a0, arg2, 0, -1) >= 0) {
                s1 = s0;
                s0 = *(struct Node **)((char *)s1 + 8);
            } else {
                s0 = *(struct Node **)((char *)s0 + 0xC);
            }
            a0 = (char *)s0 + 0x10;
        } while (s0 != 0);
    }

    *arg0 = (void *)s1;
    return arg0;
}
