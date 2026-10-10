typedef int s32;

struct Str { char *p; };
struct Node;
extern "C" Str *func_0047DD18(Node *n);

/* Defined under a member name and recursing through the plain symbol, so gcc does not see the
   self-call and keeps the sibling jump (j func_0047DD18) instead of turning it into a loop. */
struct Node {
    char pad[0x54];
    Str name;
    Node *parent;
    Str *findName();
};

Str *Node::findName() {
    Str *s = &name;
    if (((s32 *)s->p)[-4] == 0) {
        Node *p = parent;
        if (p != 0) return func_0047DD18(p);
        return s;
    }
    return s;
}
