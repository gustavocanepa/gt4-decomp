struct Range {
    unsigned char first;
    unsigned char last;
    short base;
};

struct CodeTable {
    unsigned char *rows;
    Range *ranges;
    unsigned short *codes;
};

extern "C" unsigned short func_004B94A8(CodeTable *t, int code) {
    int hi = (code >> 8) & 0xFF;
    int lo = code & 0xFF;
    int first = t->rows[0];
    int last = t->rows[1];
    if (hi >= first && hi <= last) {
        Range *r = &t->ranges[hi - first];
        int rfirst = r->first;
        int rlast = r->last;
        int base = r->base;
        if (lo >= rfirst && lo <= rlast)
            return t->codes[lo + base];
    }
    return 0;
}
