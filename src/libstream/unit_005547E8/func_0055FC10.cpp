typedef short s16;

struct Run {
    s16 pad;
    s16 first;      /* index of the run's first entry */
};

struct Entry {
    s16 v0, v2, v4, v6;
};

struct RunTable {
    int x0;
    int x4;
    struct Run *runs;
    struct Entry *entries;
};

/* An entry with all four fields zero ends a run. */
static inline int entry_used(const struct Entry *e) {
    int a = e->v0, b = e->v2, c = e->v4, d = e->v6;
    return (a | c) | (d | b);
}

/* Records where each zero-terminated run of entries starts; an empty run ends the list. */
extern "C" void func_0055FC10(struct RunTable *t, int x0, int x4, struct Run *runs, struct Entry *entries)
{
    struct Run *run;
    struct Entry *e;
    int i, next;

    t->x0 = x0;
    t->x4 = x4;
    t->runs = runs;
    t->entries = entries;
    run = runs;
    i = 0;
    do {
        next = i + 1;
        run->first = i;
        do {
            e = (struct Entry *)(i * 8 + (int)entries);
            i++;
        } while (entry_used(e));
        run++;
    } while (i != next);
}
