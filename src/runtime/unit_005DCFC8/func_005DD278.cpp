struct Node {
    Node *unk0;
    void *unk4;
};
struct Obj {
    char pad0[4];
    Node *unk4;
};

extern "C" void func_00326798(void *, int, int, int);
extern "C" int *func_005DD870(void);
extern "C" void func_002540B8(void *, int);

extern "C" void func_005DD278(Obj *arg0) {
    Node *v0 = arg0->unk4;
    Node *s1 = v0->unk0;
    if (s1 != v0) {
        do {
            Node *s0 = s1;
            s1 = s1->unk0;
            func_002540B8((char *)s0 + 8, 2);
            func_00326798(s0, 0xC, 4, *func_005DD870());
            v0 = arg0->unk4;
            s0 = s1;
        } while (s1 != v0);
    }
    v0->unk0 = v0;
    v0 = arg0->unk4;
    v0->unk4 = v0;
}
