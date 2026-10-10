struct Node { char pad[0xC]; Node *next; };
struct List { char pad[0x18]; Node *first; };
struct Owner { char pad[0x60]; List *list; };
struct Obj { char pad[0xC]; Owner *owner; };
extern "C" int func_003D8BE8(Obj *self, Node *n);

extern "C" Node *func_003D8D60(Obj *self)
{
    Node *n = self->owner->list->first; for (;;) { if (!n) return 0; if (func_003D8BE8(self, n)) return n; n = n->next; }
}
