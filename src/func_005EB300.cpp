typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
};

struct Val {
    Str first;
    char second[4];
};

struct Node {
    s32 color;
    Node *parent;
    Node *left;
    Node *right;
    Val v;
};

extern "C" void func_003041B8(void *arg0, int arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" struct S00659988 *func_005EC198(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

static inline void destroy(Val *v) {
    func_003041B8(v->second, 2);
    str_release(&v->first);
}

extern "C" void func_005EB300(void *self, Node *x) {
    while (x != 0) {
        Node *y;
        func_005EB300(self, x->right);
        y = x->left;
        destroy(&x->v);
        func_00326798(x, 0x18, 4, func_005EC198()->name);
        x = y;
    }
}
