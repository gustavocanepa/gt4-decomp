struct Node {
    Node *unk0;
    void *unk4;
};
struct Obj {
    char pad0[4];
    Node *unk4;
};

extern "C" void func_00326798(void *, int, int, int);
extern "C" int *func_005EC1E8(void);
extern "C" void func_002F2A08(void *, int);

extern "C" void func_005EB3D0(Obj *arg0) {
    Node *v0 = arg0->unk4;
    Node *s1 = v0->unk0;
    if (s1 != v0) {
        do {
            Node *s0 = s1;
            s1 = s1->unk0;
            func_002F2A08((char *)s0 + 8, 2);
            func_00326798(s0, 0xC, 4, *func_005EC1E8());
            v0 = arg0->unk4;
            s0 = s1;
        } while (s1 != v0);
    }
    v0->unk0 = v0;
    v0 = arg0->unk4;
    v0->unk4 = v0;
}
