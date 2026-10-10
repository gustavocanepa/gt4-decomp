struct Node {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Node *next;
};

extern int D_0065837C;
extern Node *D_0088D948;

extern "C" int func_005ADCE0(int sema);
extern "C" void func_005ADCC0(int sema);

extern "C" void func_005BECE0(int v, Node *n) {
    int *sema = &D_0065837C;
    n->m8 = v;
    n->m4 = 0;
    n->m0 = 0;
    n->mC = v;
    n->m10 = 0;
    func_005ADCE0(*sema);
    n->next = D_0088D948;
    D_0088D948 = n;
    func_005ADCC0(*sema);
}
