/* Draws one item as a quad rotated by its entry's angle (names inferred from the arithmetic).
 * The corners are the item position plus/minus the two half-diagonals
 * (cos - sin) * scale and (sin + cos) * scale; the top two bits of the entry's flags pick one of
 * the 0x20-byte records at D_006A3AB0, and the value returned by func_003E8BA8 is passed twice.
 *
 * The style index is shifted down once, before the calls, and x/y/z are read after the two
 * half-diagonals: that puts one instruction between the last z store and the first x corner in the
 * first scheduling pass, which is what lets that corner reuse z's register. */
struct Vec3 {
    float x, y, z;
};

struct Entry {
    char unk0[2];
    unsigned char flags;    /* 0x02 */
    char unk3[5];
    float scale;            /* 0x08 */
    char unkC[8];
    float angle;            /* 0x14 */
    char unk18[0x28];
};                          /* 0x40 */

struct Self {
    Entry *entries;
};

struct Item {
    float x, y, z;
    int entry;              /* 0x0C */
};

extern char D_006A3AB0[];   /* 0x20 bytes per style */

extern "C" int func_003E8BA8(Self *self, Item *item);
extern "C" void func_004A5F00(float angle, float *sinOut, float *cosOut);
extern "C" void func_003E8438(Self *self, Vec3 *corners, char *style, int colorA, int colorB, int count);

extern "C" void func_003E8610(Self *self, Item *item)
{
    Vec3 corners[4];
    float s, c;
    Entry *entry = &self->entries[item->entry];
    unsigned style = entry->flags >> 6;
    int color = func_003E8BA8(self, item);

    func_004A5F00(entry->angle, &s, &c);

    float scale = entry->scale;
    float d0 = (c - s) * scale;
    float d1 = (s + c) * scale;
    float x = item->x;
    float y = item->y;
    float z = item->z;

    corners[0].x = x + d0;
    corners[0].y = y + d1;
    corners[0].z = z;
    corners[1].x = x - d1;
    corners[1].y = y + d0;
    corners[1].z = z;
    corners[2].x = x + d1;
    corners[2].y = y - d0;
    corners[2].z = z;
    corners[3].x = x - d0;
    corners[3].y = y - d1;
    corners[3].z = z;

    func_003E8438(self, corners, &D_006A3AB0[style << 5], color, color, 4);
}
