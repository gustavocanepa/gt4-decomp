typedef unsigned long u64;
struct Regs {
    char pad[0x158];
    union {
        u64 d;
        struct { unsigned char b0, b1, b2, b3, b4, b5, b6, b7; } b;
    } r158;
    char pad2[0x1A8 - 0x160];
    u64 r1A8;
    u64 r1B0;
    u64 r1B8;
    u64 r1C0;
    u64 r1C8;
    u64 r1D0;
    u64 r1D8;
};

extern "C" void func_004A0228(Regs *r)
{
    r->r158.b.b0 = 0;
    r->r158.b.b4 = 0x80;
    r->r1C8 = 0;
    r->r1D0 = 0;
    r->r1A8 = 0;
    r->r158.d &= ~0x8000UL;
    r->r1C0 = 0x400000000UL;
    r->r1B8 = 0x60;
    r->r1B0 = 0x2000000001300000UL;
    r->r1D8 |= 0x801E801E80UL;
}
