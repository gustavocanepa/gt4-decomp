/* compiler: ee-gcc2.9-991111 */
typedef unsigned long u64;
typedef struct Node {
    struct Node *next;
    struct Node *prev;
    int pad[2];
    u64 m10;
    u64 m18;
    u64 m20;
} Node;
struct List { char pad[0x18]; Node *head; };
extern struct List D_006592F0;

void func_005B8098(Node *n)
{
    u64 key = n->m20 + n->m10 - n->m18;
    Node *prev = 0;
    Node *cur;
    for (cur = D_006592F0.head; cur != 0; cur = cur->next) {
        if (key < cur->m20 + cur->m10 - cur->m18) break;
        prev = cur;
    }
    n->prev = prev;
    n->next = cur;
    if (cur) cur->prev = n;
    if (prev) prev->next = n;
    else D_006592F0.head = n;
}
