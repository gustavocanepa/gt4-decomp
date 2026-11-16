/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Looks a 64-bit id up in one of two spec tables, chosen by the id's high
   word (0 or 0x26), and converts the row found. Each arm is written in full,
   as in the original: cross-jumping merges the two copies and the two calls.
   A row that is not found falls off the end of the function, so the callee's
   zero is what comes back; only an unknown high word returns 0 itself. */
typedef long s64;
typedef unsigned long u64;

struct Table;

struct Row {
    s64 f0, f8, f10, f18, f20, f28, f30, f38;
    unsigned char flag;
};

struct Out {
    s64 f0, f8, f10, f18, f20, f28;
    unsigned char flag;
    s64 f38, f40;
};

extern Table *D_00623800;
extern Table *D_00623804;
extern "C" int SPEC_DATABASE__DatabaseTable__getRow(Table *table, int key, Row *row);

static inline void convert(Out *out, const Row &row) {
    out->f0 = row.f0;
    out->f8 = row.f8;
    out->f10 = row.f10;
    out->f18 = row.f18;
    out->f20 = row.f20;
    out->f28 = row.f28;
    out->flag = row.flag;
    out->f38 = row.f30;
    out->f40 = row.f38;
}

extern "C" int func_00448B48(u64 id, Out *out) {
    Row row;
    int hi = (s64)id >> 32;
    int lo = id & 0xFFFFFFFF;

    if (hi == 0) {
        if (SPEC_DATABASE__DatabaseTable__getRow(D_00623800, lo, &row)) {
            convert(out, row);
            return 1;
        }
    } else if (hi == 0x26) {
        if (SPEC_DATABASE__DatabaseTable__getRow(D_00623804, lo, &row)) {
            convert(out, row);
            return 1;
        }
    } else {
        return 0;
    }
}
