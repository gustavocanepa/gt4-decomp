/* Opens (insert > 0) or closes a gap at index idx in one two-byte column (byte offset off) of
   a track's six-byte records: shifts the column's values up from the end, or down over idx and
   clears the last one. Tracks of kind 0x200 use the row of their slot, the others the next. */
struct Rec { unsigned char b[6]; };  /* three two-byte columns */
struct Row { Rec *data; int pad4; unsigned short count; char padA[6]; };
struct Table { char pad[0x40]; Row rows[1]; };
extern "C" int func_004BD378(Table *t, unsigned short id, int off, int idx, int insert) {
    int count;
    int i;
    unsigned char *cur;
    unsigned char *next;
    if ((id & 0xFF00) == 0x200) count = t->rows[id & 0xFF].count;
    else count = t->rows[(id & 0xFF) + 1].count;
    if (insert > 0) {
        int o = count * 6;
        if ((id & 0xFF00) == 0x200) next = (unsigned char *)t->rows[id & 0xFF].data + o + off;
        else next = (unsigned char *)t->rows[(id & 0xFF) + 1].data + o + off;
        for (i = count; i >= idx; i--) {
            cur = next - 6;
            next[0] = cur[0];
            next[1] = cur[1];
            next = cur;
        }
    } else {
        int o = idx * 6;
        if ((id & 0xFF00) == 0x200) cur = (unsigned char *)t->rows[id & 0xFF].data + o + off;
        else cur = (unsigned char *)t->rows[(id & 0xFF) + 1].data + o + off;
        for (i = idx; i < count - 1; i++) {
            next = cur + 6;
            cur[0] = next[0];
            cur[1] = next[1];
            cur = next;
        }
        cur[0] = 0;
        cur[1] = 0;
    }
    return 0;
}
