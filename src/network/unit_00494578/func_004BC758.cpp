/* Finds the position after the entry of key m->key in the row of id and, unless it is the
   row's last one, hands it to func_004C0668; 0 when the key is missing or nothing follows.
   The table is indexed as 16-byte rows from its start: ids of kind 0x200 use row slot + 4, the
   others slot + 5. The final call goes through an inline wrapper, which keeps it a jal. */
struct Row { char *start; int size; short x8; unsigned short n; unsigned short m; short xE; };
struct Table { Row rows[256]; };
struct Msg { char pad[0xE]; unsigned char lenE, lenF; char pad10[4]; unsigned short key; };
extern "C" char *func_004C0508(Table *, unsigned short, unsigned short);
extern "C" int func_004C0668(Table *, unsigned short, char *);
static inline int step(Table *t, unsigned short id, char *pos) { return func_004C0668(t, id, pos); }
extern "C" int func_004BC758(Table *t, unsigned short id, Msg *m) {
    char *pos = func_004C0508(t, id, m->key);
    if (pos == 0) return 0;
    pos += m->lenE + m->lenF;
    char *end;
    if ((id & 0xFF00) == 0x200) end = t->rows[(id & 0xFF) + 4].start + t->rows[(id & 0xFF) + 4].size - 1;
    else end = t->rows[(id & 0xFF) + 5].start + t->rows[(id & 0xFF) + 5].size - 1;
    if (pos >= end) return 0;
    return step(t, id, pos);
}
