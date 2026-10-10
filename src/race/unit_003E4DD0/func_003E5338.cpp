struct Mgr {
    char pad0[0x10];
    int sema;
};

struct Node {
    Node *next;
};

struct Obj {
    int pad0[2];
    Node *first;
};

extern Mgr *D_006D6054;
extern int D_00621D0C;
extern int D_00621D10;

extern "C" void ModelSet2__begin(int sema, int a);
extern "C" void ModelSet2__end(int sema);
extern "C" void func_003E4A28(Node *n);

extern "C" void func_003E5338(Obj *o) {
    if (D_006D6054) {
        D_00621D0C = -1;
        D_00621D10 = -1;
        ModelSet2__begin(D_006D6054->sema, 0);
        for (Node *n = o->first; n; n = n->next)
            func_003E4A28(n);
        ModelSet2__end(D_006D6054->sema);
    }
}
