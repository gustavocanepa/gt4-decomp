/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec { u16 h0, h2; u8 bytes[6]; u16 hA, hC; u8 len1, len2; u32 tail; u16 h14; u16 pad16; u8 *p18, *p1c; };
struct Ent { u32 p; u32 size; u16 flag, a, b; char padE[2]; };
struct TblA { char pad0[0x40]; Ent e[16]; };
struct TblB { char pad0[0x50]; Ent e[16]; };
extern "C" void func_004BC818(u16 *, u8 *, int) throw();
extern "C" u16 func_004BC8A0(Rec *) throw();
extern "C" u8 *func_004C0508(char *, int, u16);
#define ENT(tbl, id, off) ((Ent *)((u32)(tbl) + (((id) & 0xFF) * 16 + (off))))
/* First address past a track's data area. */
#define END(tbl, id) (((id) & 0xFF00) == 0x200 \
    ? ((TblA *)(tbl))->e[(id) & 0xFF].p + ((TblA *)(tbl))->e[(id) & 0xFF].size \
    : ((TblB *)(tbl))->e[(id) & 0xFF].p + ((TblB *)(tbl))->e[(id) & 0xFF].size)
static inline u32 destination(u32 base, u32 off, u32 count) { base += off; base += count * 6; base += 6; return base; }
/* Reads record rec->h0 of a track into *rec (inverse of func_004BCC50). Returns 0 for an empty
   record, -1 for a bad index, payload span or (when check is set) checksum, 1 otherwise. */
extern "C" int func_004BC978(char *tbl, u16 id, Rec *rec, int check) {
    int index = rec->h0;
    int limit;
    u32 off;
    u32 pos;
    u8 *src;
    u8 *p;
    int n1, n2;
    u16 *h14;
    if ((id & 0xFF00) == 0x200) limit = ((TblA *)tbl)->e[id & 0xFF].a;
    else { Ent *e = ENT(tbl, id, 0x50); limit = e->a + e->b; }
    if (index >= limit + 1) return -1;
    off = index * 20;
    if ((id & 0xFF00) == 0x200) {
        Ent *e = ENT(tbl, id, 0x40);
        pos = destination(e->p, off, e->a);
    } else {
        Ent *e = ENT(tbl, id, 0x50);
        pos = destination(e->p, off, e->a + e->b);
    }
    src = (u8 *)pos;
    func_004BC818(&rec->h2, src, 2);
    if (rec->h2 == 0) return 0;
    h14 = &rec->h14;
    rec->bytes[0] = src[2]; rec->bytes[1] = src[3]; rec->bytes[2] = src[4];
    rec->bytes[3] = src[5]; rec->bytes[4] = src[6]; rec->bytes[5] = src[7];
    func_004BC818(&rec->hA, src + 8, 2);
    func_004BC818(&rec->hC, src + 10, 2);
    rec->len1 = src[12]; rec->len2 = src[13];
    rec->tail = (src[14] << 24) | (src[15] << 16) | (src[16] << 8) | src[17];
    func_004BC818(h14, src + 18, 2);
    p = func_004C0508(tbl, id, *h14);
    rec->p18 = p;
    if (p == 0 || (u32)p >= END(tbl, id) - 1) return -1;
    n1 = rec->len1; n2 = rec->len2; p = rec->p18;
    if (END(tbl, id) - n1 - n2 - 1 < (u32)p) return -1;
    rec->p1c = p + n1;
    if (check && func_004BC8A0(rec) != rec->h2) return -1;
    return 1;
}
