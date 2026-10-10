typedef struct Node {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    struct Node *next;
} Node;

extern "C" int D_0065837C;
extern "C" Node *D_0088D948;
extern "C" int func_005ADCE0(int sema);
extern "C" int func_005ADCC0(int sema);

extern "C" void func_005BEC48(int value, Node *n)
{
    n->m8 = value;
    n->m4 = 0;
    n->m0 = 0;
    n->mC = 0;
    n->m10 = 0;
    func_005ADCE0(D_0065837C);
    n->next = D_0088D948;
    D_0088D948 = n;
    func_005ADCC0(D_0065837C);
}
