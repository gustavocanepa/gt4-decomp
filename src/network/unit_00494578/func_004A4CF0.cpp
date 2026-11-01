/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds the BITBLTBUF/TRXPOS/TRXREG/TRXDIR A+D packet for a GS transfer of w x ht pixels and
   returns its size in qwords by pixel format (0 for unknown formats: no packet). Twin of
   func_004ABB88 with the do { } while (0) SET32 macro; the last entry is written value first. */
typedef unsigned long long u64;
struct Entry { union { u64 value; struct { unsigned int lo, hi; } w; } d; u64 reg; };
struct Header { unsigned int base:24; unsigned int psm:8; };
#define SET64(dst, val, addr) do { u64 data = (val); u64 reg = (addr); (dst)->reg = reg; (dst)->d.value = data; } while (0)
#define SET32(dst, low, high, addr) do { Entry *p = (dst); p->d.w.lo = (low); p->d.w.hi = (high); p->reg = (addr); } while (0)
extern "C" int func_004A4CF0(Entry *out, Header *h, int x, int y, int w, int ht) {
    int n = w * ht;
    switch (h->psm) {
    case 0: n = (n * 4 + 15) >> 4; break;
    case 1: n = (n * 3 + 15) >> 4; break;
    case 2: case 10: n = (n * 2 + 15) >> 4; break;
    case 19: case 27: n = (n + 15) >> 4; break;
    case 20: case 36: case 44: n = (n + 31) >> 5; break;
    }
    if (n) {
        out->d.value = 0x1000000000000004ULL;
        out->reg = 14;
        SET32(out + 1, 0, *(unsigned int *)h, 0x50);
        SET32(out + 2, 0, (y << 16) | x, 0x51);
        SET32(out + 3, w, ht, 0x52);
        Entry *p4 = out + 4;
        p4->d.value = 0;
        p4->reg = 0x53;
    }
    return n;
}
