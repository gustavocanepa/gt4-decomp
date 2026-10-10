/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Node_005C1970 {
    char pad0[0x14];
    int pending;
    struct Node_005C1970 *next;
} Node_005C1970;

Node_005C1970 **func_005BC6E8(void);
void func_005C1668(void) __attribute__((noreturn));

void func_005C1970(void) {
    Node_005C1970 **head = func_005BC6E8();
    Node_005C1970 **pp = head;
    Node_005C1970 *n;
    for (;;) {
        n = *pp;
        if (n == 0) {
            func_005C1668();
        }
        if (n->pending != 0) {
            break;
        }
        pp = &n->next;
    }
    if (pp != head) {
        *pp = n->next;
        n->next = *head;
        *head = n;
    }
    n->pending = 0;
}
