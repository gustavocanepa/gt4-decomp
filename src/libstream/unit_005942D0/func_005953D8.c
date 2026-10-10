/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_005953D8.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Node;

struct Owner {
    char pad0[0x30];
    struct Node *head;
};

struct Node {
    struct Node *next;
    struct Owner *owner;
};

void func_005953D8(struct Node *n) {
    struct Node **pp = &n->owner->head;
    while (*pp != 0) {
        if (*pp == n) {
            *pp = n->next;
            return;
        }
        pp = &(*pp)->next;
    }
}
