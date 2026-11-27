/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
/* One run of glyph records collected by func_004C25E0 (same layout as in func_004C25E0.cpp). */
struct Run { char kind; char pad1[3]; void *entries; u16 count; short pad2; Run *next; };
/* Same object as `S` in func_004C3480.cpp, with its real size (0x2C) so it can be indexed. */
struct Font { int pad; u8 *data; u8 *items; char gap[8]; u8 *base; char rest[0x14]; };
struct Obj { char pad[0x24]; Font *fonts; };
extern "C" int func_004C3480(Font *, u16 *, u8 **, u8 **, u8 **);
extern "C" void func_004C3160(u8 *, u8 *, u16 *); /* func_004C3160.c types all three as s32 */
extern "C" int func_004C8DB8(const u16 *, const u16 *, int);
extern "C" int func_004C9580(unsigned int *, int);
/* func_004C25E0.cpp types the object and the filter as int and the records as a 6-byte struct. */
extern "C" int func_004C25E0(Obj *, Run **, int, int, u8 *, u8 *, u8 *, unsigned int *, u8, int);

enum { FONT_COUNT = 1, RECORD_SIZE = 6 };

static inline u8 *current(u8 *record) { return record; }

extern "C" int func_004C2830(Obj *self, u16 *key, int limit, unsigned int *filter, Run **ret) {
    /* `count` is declared before `i`: the two tie in global-alloc priority and the lower
       pseudo number takes the lower saved register. */
    int count;
    u8 i;
    for (i = 0; i < FONT_COUNT; i++) {
        u16 name[16];
        u8 *p;
        u8 *end;
        u8 *suffix;
        int result;
        /* The presence test walks the `data` members directly (a pointer to the first
           font's member, stepped by one font), the rest goes through the font pointer. */
        u8 **data = &self->fonts->data;
        if (data[i * (sizeof(Font) / sizeof(u8 *))] == 0) continue;
        Font *font = &self->fonts[i];
        result = func_004C3480(font, key, &p, &end, &suffix);
        if (result < 0) return result;
        if (p == end) continue;
        u8 *items = font->items;
        u8 *start = 0;
        u8 *last = 0;
        int prev = 0;
        count = 0;
        int lastId = -1;
        int match = 0;
        int first = 0;
        while (p < end) {
            int type = p[3] & 0xF;
            int cmp;
            if (type >= 3) {
                if (first == 0) first = 1;
                else suffix += p[3] >> 4;
            }
            if (limit < type) { p += RECORD_SIZE; continue; }
            cmp = 0;
            if (type >= 3) {
                if (suffix != 0) func_004C3160(suffix, p, name);
                cmp = func_004C8DB8(name, key + 2, type - 2);
                if (cmp > 0) break;
            }
            if (cmp == 0) {
                int id = ((p[4] & 0x3F) << 3) | (p[5] >> 5);
                if (id != lastId) {
                    match = func_004C9580(filter, id);
                    lastId = id;
                }
                if (match == 1) {
                    if (start == 0) start = current(p);
                    if (prev != 0 && type != prev) {
                        result = func_004C25E0(self, ret, count, prev, start, last, items, filter, i, 0);
                        if (result < 0) return result;
                        start = p;
                        count = 0;
                    }
                    prev = type;
                    count++;
                    last = p;
                }
            }
            p += RECORD_SIZE;
        }
        if (count > 0) {
            result = func_004C25E0(self, ret, count, prev, start, last, items, filter, i, 0);
            if (result < 0) return result;
        }
    }
    count = 0;
    for (Run *run = *ret; run != 0; run = run->next) count += run->count;
    return count;
}
