struct VEntry {
    short delta;
    short index;
    unsigned int (*fn)(void *);
};

struct Saver {
    VEntry *vt;
};

extern Saver *D_00622F4C;
extern "C" unsigned int func_001CE578(void);

/* Memory card footprint: kind 2, size in 1 KB clusters of the header-padded data plus the icon. */
extern "C" void func_001CDFA8(void *self, int *kind, unsigned int *clusters)
{
    *kind = 2;
    Saver *s = D_00622F4C;
    VEntry *e = &s->vt[2];
    unsigned int size = e->fn((char *)s + e->delta);
    *clusters = (((size + 0x47) & ~0x3F) + 0x3FF) >> 10;
    *clusters += (func_001CE578() + 0x3FF) >> 10;
}
