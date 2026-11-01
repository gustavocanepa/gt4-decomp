/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Eight-entry id cache: looks id up from the rotating position (entries with a stamp), else takes
   the next slot round-robin (or the spare ninth entry when all eight are in use); the entry gets
   the next clock stamp and the id. */
typedef int s32;
struct Ent { s32 x0; s32 id; char pad[0x40]; s32 stamp; };
struct Cache { char pad[0x228]; Ent e[9]; s32 head; s32 pos; s32 count; s32 clock; };
extern "C" Ent *func_005560C8(Cache *c, s32 id) {
    Ent *e;
    if (id) {
        for (s32 i = 0, pos = c->pos; i < c->count; i++) {
            e = &c->e[pos];
            if (++pos == 8) pos = 0;
            if (e->stamp && e->id == id) goto found;
        }
    }
    if (c->count < 8) {
        s32 *h = &c->head;
        s32 hv = *h;
        e = &c->e[hv];
        *h = ++hv;
        if (hv == 8) *h = 0;
        c->count++;
    } else {
        e = &c->e[8];
    }
found:
    e->stamp = c->clock++;
    e->id = id;
    return e;
}
