struct Table {
    int v[4];
};

extern const Table D_00693EF0;

/* Value for the lowest set bit of mask (5 when none). The original loops over 9 bits of a
   4-entry table copy (reads past it for bits 4..8). */
extern "C" int func_001C93F0(int mask)
{
    Table t = D_00693EF0;
    for (int i = 0; i < 9; i++) {
        if ((mask >> i) & 1)
            return t.v[i];
    }
    return 5;
}
