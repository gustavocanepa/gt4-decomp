typedef int s32;

struct Node { char pad[0xC]; Node *next; };
extern "C" s32 func_003D8BE8(void *, Node *);

extern "C" Node *func_003D8C68(void *ctx, Node *n) {
    for (;;) {
        n = n->next;
        if (!n)
            return 0;
        if (func_003D8BE8(ctx, n))
            return n;
    }
}
