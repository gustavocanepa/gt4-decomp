struct Attr { unsigned int mask; int pad[3]; int m10; short m14, m16; int m18; int m1C; int m20; };
struct Obj {
    char pad[0x1F]; unsigned char dirty;
    char pad2[0xC]; unsigned char dirty2;
    char pad3[7]; int m34;
    char pad4[0x14]; int m4C;
    char pad5[0x14]; short m64, m66; int m68;
    char pad6[8]; int m74;
};


extern "C" void func_0055AB00(Obj *o, Attr *a)
{
    unsigned int m = a->mask;
    if (m & 1) { o->m4C = a->m18; o->dirty = 1; }
    if (m & 2) { short x = a->m14, y = a->m16; o->m64 = x; o->m66 = y; o->dirty = 1; }
    if (m & 4) { o->m68 = a->m1C; o->dirty = 1; }
    if (m & 8) { o->m74 = a->m20; o->dirty2 = 1; }
    if (m & 0x10) o->m34 = a->m10;
}
