struct Entry { short delta; short index; void *fn; };
struct Src { char pad[0x10140]; Entry *vt; };
struct G { char pad[0x128]; int f128; };
struct Lic { char pad0[0x10]; Src *p10; char pad1[0x228C - 0x14]; char s228C[0x20]; unsigned w20; char pad2[0x22C0 - 0x22B0]; char s22C0[4]; };
extern char DynamicsConductorLicense__tf[], DynamicsConductor__tf[];
extern G *DisplayRText__rtext_ptrs_;
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" int func_003FA2B0(void *);
extern "C" int func_0057DA20(void *, int, int);
extern "C" void Oscillator__setCount(void *, int, int);
extern "C" void Oscillator__setCycle(void *, float, float);
extern "C" void RaceMessageDisplay__setMessage(void *, void *, float, float);
extern "C" void RaceDisplay__update_automobile_message(void *, void *);
extern "C" void RaceLicenseDisplay__update_automobile_message(Lic *o, void *a)
{
    char buf[0x80];
    void *p = 0;
    Src *s = o->p10;
    if (s) {
        Entry *e = s->vt;
        p = __dynamic_cast_2(e->fn, DynamicsConductorLicense__tf, 0, (char *)s + e->delta, DynamicsConductor__tf, s);
    }
    if (p) {
        int n = func_003FA2B0(p);
        if (n > 0) {
            char *s1 = o->s228C;
            char *s0 = o->s22C0;
            func_0057DA20(buf, DisplayRText__rtext_ptrs_->f128, n);
            *(unsigned *)(s1 + 0x20) = 0x80C8C8C8;
            Oscillator__setCount(s0, -1, 1);
            Oscillator__setCycle(s0, 1.0f, 1.0f);
            RaceMessageDisplay__setMessage(s1, buf, 0x1.999998p-3f, 0.0f);
            return;
        }
    }
    RaceDisplay__update_automobile_message(o, a);
}
