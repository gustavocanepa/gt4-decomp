/* Plays sequence (int)t % n (clamped to the last one) through func_00474828,
   passing the frame and t on. The body is an inline with its own self and tab
   parameters: their copies give the original's $v0 = this and the mov.s of t. */
struct Entry;
struct Ctx;
struct Seq { short *str; int len; };
struct SeqList { Seq *arr; int size; int n; };
struct Anim { Entry *tab; char p4[0x14]; SeqList seqs; };

extern "C" short *func_00474828(Entry **tab, Ctx *c, int lim, short *cur, short *end, int x, float t);

static inline void play(Anim *self, Entry **tab, Ctx *c, float t) {
    if (self->seqs.n > 0) {
        SeqList *l = &self->seqs;
        int x = (int)t;
        int i;
        Seq *s;
        x %= self->seqs.n;
        i = x < l->size ? x : l->size - 1;
        s = &l->arr[i];
        func_00474828(tab, c, 0x7FFFFFFF, s->str, s->str + s->len, x, t);
    }
}

extern "C" void func_00474568(Anim *a, Ctx *c, float t) {
    play(a, &a->tab, c, t);
}
