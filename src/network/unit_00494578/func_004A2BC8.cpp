typedef unsigned long long u64;
struct Spr {
    char pad[0x178]; short x; short pad1; short y;
    char pad2[0x1D8 - 0x17E]; u64 flags;
    char pad3[0x26C - 0x1E0]; unsigned short baseX, baseY;
    char pad4[0x2A8 - 0x270]; float sx, sy, ox, oy, px, py;
};

extern "C" void func_004A2BC8(Spr *s)
{
    float u = (s->ox + s->sx * s->px) * 16.0f;
    float v = (s->oy + s->sy * s->py) * 16.0f;
    s->flags |= 0x20002;
    int iu = (int)u;
    if (iu == 16) iu = 15;
    int iv = (int)v;
    if (iv == 16) iv = 15;
    s->x = s->baseX + iu;
    s->y = s->baseY + iv;
}
