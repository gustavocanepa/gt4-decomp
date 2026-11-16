/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Binds a database table to its file header: the entry array follows the
   header, and when the header's flag bit 0 is set two size-prefixed chunks
   (a 0x200-byte index, then the strings) follow the entries. The end of the
   entries is written out again in the else arm, as in the original: the
   recomputed sum survives until after register allocation, which is what
   gives the register copy in the branch delay slot. */
struct Entry { int key; int value; };

struct Header {
    int magic;
    unsigned short flags;
    unsigned short pad6;
    int count;
    int padC;
    Entry entries[1];
};

struct Chunk { int size; };

struct Table {
    Header *header;
    int unk4;
    Entry *entries;
    Chunk *index;
    char *indexData;
    char *indexEnd;
    Chunk *strings;
    char *stringData;
    char *end;
};

extern "C" void func_004490F8(Table *self, Header *h) {
    Entry *e = h->entries;
    self->header = h;
    int n = h->count;
    self->entries = e;
    if ((unsigned short)(h->flags & 1)) {
        char *p = (char *)(e + n);
        self->index = (Chunk *)p;
        self->indexData = p + 8;
        self->indexEnd = p + 0x208;
        Chunk *s = (Chunk *)(p + ((Chunk *)p)->size);
        self->strings = s;
        self->stringData = (char *)s + 8;
        self->end = (char *)s + s->size;
    } else {
        self->end = (char *)(e + n);
    }
}
