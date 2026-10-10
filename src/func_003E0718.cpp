typedef int s32;

struct Node { char pad[0x10]; Node *next; s32 id; };
struct List { char pad[0x14]; Node *head; };
struct Other { char pad[0x60]; List *list; };
struct Self { s32 m0; s32 id; };

extern "C" s32 func_003E0718(Self *self, Other *o) {
    Node *n;
    s32 i = 0;
    for (n = o->list->head; n != 0; n = n->next) {
        if (n->id == self->id) return i;
        i++;
    }
    return -1;
}
