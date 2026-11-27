/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Collects, over every font, the records of `key` that pass `filter` (func_004C9580 == 1) and
   whose name type equals the key's length class (func_004C8ED0), hands each font's range to
   func_004C25E0 (which appends runs to `list`), then copies all runs into one array of 16-byte
   entries returned through *ret. Returns the number of entries, the first negative result of a
   callee, or 0x80000325 when the array cannot be allocated; the run list is always released
   with func_004C8BB0. Sibling of func_004C2830 (same Run/Font/Obj layouts and callee
   prototypes); Out only gives the 16-byte stride of the output entries.
   Shape notes (each one is needed for the match):
   - the presence test walks the `data` members directly, as in func_004C2830, so the font
     address is a block-local temporary copied into `font` after the branch;
   - both error exits are written in the loop (loop.c moves them behind the loop, jump2 merges
     them);
   - `last = start = p; ` in the first-record arm followed by the unconditional `last = p;`
     keeps the arm at two insns, so it stays a branch instead of a conditional move;
   - locals are declared C89 style at the top: spilled pseudos get their frame slots in
     declaration order (items, count, last, total). */
typedef unsigned char u8;
typedef unsigned short u16;
struct Run { char kind; char pad1[3]; void *entries; u16 count; short pad2; Run *next; };
struct Font { int pad; u8 *data; u8 *items; char gap[8]; u8 *base; char rest[0x14]; };
struct Obj { char pad[0x24]; Font *fonts; };
struct Out { char b[16]; };
extern "C" int func_004C3480(Font *, u16 *, u8 **, u8 **, u8 **);
extern "C" void func_004C3160(u8 *, u8 *, u16 *);
extern "C" int func_004C8D08(const u16 *, const u16 *);
extern "C" int func_004C8ED0(u16 *);
extern "C" int func_004C9580(unsigned int *, int);
extern "C" int func_004C25E0(Obj *, Run **, int, int, u8 *, u8 *, u8 *, unsigned int *, u8, int);
extern "C" Out *func_004C8C20(Obj *, int);
extern "C" void func_004C8BB0(Obj *, Run *);
extern "C" void *func_004C4070(void *, const void *, unsigned);

enum { FONT_COUNT = 1, RECORD_SIZE = 6 };

extern "C" int func_004C2048(Obj *self, u16 *key, unsigned int *filter, Out **ret) {
    u16 name[16];
    u8 *p;
    u8 *end;
    u8 *suffix;
    Run *list;
    u8 *items;
    int count;
    u8 *last;
    int total;
    u8 i;
    int len;
    int result;

    list = 0;
    len = func_004C8ED0(key);
    count = 0;
    total = 0;
    for (i = 0; i < FONT_COUNT; i++) {
        u8 **data = &self->fonts->data;
        if (data[i * (sizeof(Font) / sizeof(u8 *))] == 0) continue;
        Font *font = &self->fonts[i];
        result = func_004C3480(font, key, &p, &end, &suffix);
        if (result < 0) {
                func_004C8BB0(self, list);
                return result;
            }
        if (p == end) continue;
        u8 *start = 0;
        items = font->items;
        int first = 0;
        count = 0;
        last = 0;
        while (p < end) {
            int type = p[3] & 0xF;
            if (type >= 3) {
                if (first == 0) first = 1;
                else suffix += p[3] >> 4;
            }
            if (start != 0) {
                if (len != type) break;
                if (len >= 3 && name[0] != key[2]) break;
            }
            if (func_004C9580(filter, ((p[4] & 0x3F) << 3) | (p[5] >> 5)) == 1) {
                if (type >= 3 && suffix != 0) func_004C3160(suffix, p, name);
                if (type == len) {
                    if (len < 3 || func_004C8D08(name, key + 2) == 0) {
                        if (start == 0) last = start = p;
                        last = p;
                        count++;
                    }
                }
            }
            p += RECORD_SIZE;
        }
        if (count > 0) {
            result = func_004C25E0(self, &list, count, len, start, last, items, filter, i, 0);
            if (result < 0) {
                func_004C8BB0(self, list);
                return result;
            }
            total += result;
        }
    }
    if (total > 0) {
        Out *out = func_004C8C20(self, total * 16);
        if (out == 0) {
            func_004C8BB0(self, list);
            return 0x80000325;
        }
        *ret = out;
        for (Run *run = list; run != 0; run = run->next) {
            if (run->entries != 0 && run->count != 0) {
                func_004C4070(out, run->entries, run->count * 16);
                out += run->count;
            }
        }
        func_004C8BB0(self, list);
        count = total;
    }
    return count;
}
