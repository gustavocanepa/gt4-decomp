/* compiler: ee-gcc2.96-nogcse */
struct Node { unsigned short pos, len, x4, next; };
struct Pool { char pad[0x10]; Node *nodes; unsigned short *capacity; char pad18[8]; unsigned short *current; };

static inline int gap(int next, int pos, Node *p) {
    return next == 0xFFFF ? 0x1FFF - (pos + p->len) : next - (pos + p->len) - 1;
}
extern "C" int func_004C3B80(Pool *pool, unsigned short *outPos, unsigned short *outEnd, unsigned short *need) {
    int a = *need;
    int b = *pool->capacity;
    Node *first;
    Node *p;
    int retries;
    int found;
    int want;
    Node *nodes;
    if (b < a + 1) return -1;
    {
        if (*pool->current + a + 1 < b) {
            first = pool->nodes;
            retries = 1;
            p = first + *pool->current;
        } else {
            p = pool->nodes;
            retries = 0;
            first = p;
        }
        want = a + 1;
        found = 0;
        for (;;) {
            while ((unsigned short)gap(a = p->next, b = p->pos, p) < want) {
                if (a == 0xFFFF) goto end;
                do { nodes = first; } while (0);
                p = &nodes[p->next];
            }
            found = 1;
        end:
            if (found) break;
            if (retries <= 0) break;
        retries--;
            p = first;
        }
        if (found == 1) {
            *outPos = b;
            *outEnd = p->pos + p->len + 1;
            return 0;
        }
    }
    return -1;
}
