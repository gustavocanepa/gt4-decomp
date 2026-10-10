/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
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
