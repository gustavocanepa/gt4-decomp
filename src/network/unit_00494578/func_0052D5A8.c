/* Appends a packet's pieces to a ring-buffer message queue: into the current message when it is
 * empty, otherwise as a new chained message. The size-check failure is a goto to a label after the
 * final return: an inline `return 0x12D` makes sched1 hoist the $v0 store above the compare. */
struct Piece { void *data; int len; };
struct Pkt { struct Piece p[8]; unsigned int total; int count; };
struct Msg { unsigned int len; struct Msg *next; char data[1]; };
struct Q { int x0; int pos; int size; int xC; char *base; int x14; };
int func_0052E188(struct Q *, unsigned int *);
int func_0052E230(struct Q *, struct Msg **, unsigned int);
void *func_005A4724(void *, const void *, int);

static inline void copy(char *dst, struct Pkt *pkt) {
    int i;
    for (i = pkt->count - 1; i >= 0; i--) {
        if (pkt->p[i].data && pkt->p[i].len) {
            func_005A4724(dst, pkt->p[i].data, pkt->p[i].len);
            dst += pkt->p[i].len;
        }
    }
}

int func_0052D5A8(struct Q *q, struct Msg *out, struct Pkt *pkt) {
    unsigned int room = 0;
    int r;
    if (q == 0 || q->base == 0 || q->x14 == 0 || q->size == 0)
        return 2;
    if (out == 0)
        return 2;
    if (pkt == 0)
        return 2;
    if (pkt->total == 0)
        return 2;
    if (out->len == 0) {
        r = func_0052E188(q, &room);
        if (r != 0)
            return r;
        {
            unsigned int t = pkt->total;
            if (room < t)
                goto toobig;
            out->len = t;
        }
        out->next = 0;
        copy(out->data, pkt);
        q->pos += (pkt->total + 3) & ~3;
        q->xC += (pkt->total + 3) & ~3;
    } else {
        struct Msg *m;
        r = func_0052E230(q, &out, pkt->total + 8);
        if (r != 0)
            return r;
        m = (struct Msg *)(q->base + q->pos);
        m->len = pkt->total;
        m->next = out->next;
        copy(m->data, pkt);
        out->next = m;
        q->pos += ((pkt->total + 3) & ~3) + 8;
        q->xC += ((pkt->total + 3) & ~3) + 8;
    }
    if (q->pos == q->size)
        q->pos = 0;
    return 0;
toobig:
    return 0x12D;
}
