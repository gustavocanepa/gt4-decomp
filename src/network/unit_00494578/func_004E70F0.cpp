/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Destructor of a network-library object (pdistd-http region): ten string members (gcc 2.96
 * basic_string Rep release), three SGI-STL-style rb_trees (clear() + header put_node) and a list,
 * then `delete this` on flags & 1. free (the deallocator, free() next to memalign at
 * 0x575E60) is declared throw() as the C library headers declare it to C++ (__THROW): its calls are
 * nothrow, which changes reorg's delay-slot fills (knowledge/ee-gcc-2.96.md). */
typedef int s32;

extern "C" void free(void *) throw();
extern "C" void func_005C1628(void *);

struct Rep {
    s32 len; s32 res; s32 ref; s32 selfish;
    void release() { if (--ref == 0) free(this); }
};
struct String {
    char *dat;
    Rep *rep() const { return ((Rep *)dat) - 1; }
    void destroy() { rep()->release(); }
};
struct Node { s32 color; Node *parent; Node *left; Node *right; };
struct Tree;
extern "C" void func_0060D830(Tree *, Node *);
struct Tree {
    s32 cmp; Node *header; s32 count;
    Node *&root() const { return header->parent; }
    Node *&leftmost() const { return header->left; }
    Node *&rightmost() const { return header->right; }
    void clear() {
        if (count != 0) {
            func_0060D830(this, root());
            leftmost() = header;
            root() = 0;
            rightmost() = header;
            count = 0;
        }
    }
    void destroy() { clear(); free(header); }
};
struct List;
extern "C" void func_0060D8E0(List *);
struct List {
    s32 pad; void *node;
    void destroy() { func_0060D8E0(this); free(node); }
};

struct Obj {
    char pad0[0xC];
    String s0C;
    char pad10[0x54 - 0x10];
    String s54;
    Tree t58;
    char pad64[0x68 - 0x64];
    List l68;
    Tree t70;
    char pad7C[0x80 - 0x7C];
    Tree t80;
    char pad8C[0x94 - 0x8C];
    String s94, s98, s9C;
    char padA0[4];
    String sA4;
    char padA8[4];
    String sAC, sB0, sB4;
    char padB8[4];
    String sBC, sC0, sC4;
};

extern "C" void func_004E70F0(Obj *self, s32 flags) {
    self->sC4.destroy();
    self->sC0.destroy();
    self->sBC.destroy();
    self->sB4.destroy();
    self->sB0.destroy();
    self->sAC.destroy();
    self->sA4.destroy();
    self->s9C.destroy();
    self->s98.destroy();
    self->s94.destroy();
    self->t80.destroy();
    self->t70.destroy();
    self->l68.destroy();
    self->t58.destroy();
    self->s54.destroy();
    self->s0C.destroy();
    if (flags & 1) {
        return func_005C1628(self);
    }
}
