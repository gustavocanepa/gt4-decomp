struct Result { int status; int m4; int m8; int mC; int m10; int m14; };
struct VEntry { short delta; short index; void (*fn)(Result *, void *, int); };
struct Key { int m0; int id; };
struct Entry { int m0; int m4; int m8; unsigned char name[1]; };
struct Mgr { char pad[0xA4]; char *vtbl; char pad2[0xB0 - 0xA8]; int quiet; };
extern "C" void func_004B18B0(Mgr *, unsigned char *);

extern "C" Entry *func_004B1A00(Mgr *m, Key *k, Entry *e)
{
    Entry *ret = 0;
    Result r;
    VEntry *v = (VEntry *)(m->vtbl + 0xC8);
    v->fn(&r, (char *)m + v->delta, k->id);
    if (r.status == 0) {
        ret = e;
        ret->m4 = r.m14;
        ret->m8 = r.m8;
        ret->name[0] = 0;
        if (!m->quiet) func_004B18B0(m, ret->name);
    }
    return ret;
}
