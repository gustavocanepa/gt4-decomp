/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Row { u8 b[20]; };
struct Ent { u8 *data; char pad4[6]; u16 a, b; char padE[2]; };
struct Field { u16 index; char pad2[4]; u16 type; char pad8[2]; signed char tag; char padB; u8 half; };
struct Item { u32 flags; union { u8 *ptr; Field f; u8 b[13]; } u; };
extern "C" u32 func_004C9330(u8 *);
#define ENT(tbl, id) ((Ent *)((u32)(tbl) + (((id) & 0xFF) * 16 + 0x50)))
/* A table is (a + b) 6-byte records followed by 20-byte rows. The big-endian pairs read their
   high byte through the row array and their low byte from the row offset first, records
   skipped in the index: the original computes both sums. */
static inline Row *rows(Ent *t) { return (Row *)(t->data + (t->a + t->b) * 6); }
static inline u8 *row(u8 *base, int i) { return base + i * 20; }
#define RB(t, i, k) (rows(t)[i].b[k])
extern "C" void func_004BF938(char *tbl, Item *item, u8 *text, u8 *len, u8 *rest, u16 *kind) {
    switch (item->flags & 0xFFF00000) {
    case 0x100000:
        *len = item->u.b[0];
        *rest = func_004C9330(text) - item->u.f.half * 2;
        *kind = 8;
        break;
    case 0x400000: {
        u16 id = item->u.f.tag | 0x300;
        Field *f = &item->u.f;
        int mode = f->type >> 14;
        switch (mode) {
        case 1:
        case 2: {
            Ent *t = ENT(tbl, id);
            *len = RB(t, f->index, 9);
            *rest = RB(t, f->index, 11);
            *kind = (RB(t, f->index, 16) << 8) | row(t->data, f->index)[(t->a + t->b) * 6 + 17];
            break;
        }
        case 0: {
            Ent *t = ENT(tbl, id);
            *len = RB(t, f->index, 8);
            *rest = RB(t, f->index, 10);
            *kind = (RB(t, f->index, 14) << 8) | row(t->data, f->index)[(t->a + t->b) * 6 + 15];
            break;
        }
        }
        break;
    }
    case 0x800000: {
        u16 id = item->u.f.tag | 0x300;
        Ent *t = ENT(tbl, id);
        *len = RB(t, item->u.f.index, 12);
        *rest = func_004C9330(text) - item->u.f.half * 2;
        *kind = 0x2B;
        break;
    }
    default: {
        u8 *p = item->u.ptr;
        *len = p[3] & 0xF;
        *rest = func_004C9330(text) - item->u.f.half * 2;
        *kind = ((p[4] & 0x3F) << 3) | (p[5] >> 5);
        break;
    }
    }
}
