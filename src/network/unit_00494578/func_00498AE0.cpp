/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Relocates a loaded table in place: every entry's offset moves by the distance between the
   table's new address and the base it was saved with, then the base becomes the table itself.
   The relocation is a do-while(0) macro; its loop notes keep the add's schedule as in retail. */
#define RELOCATE(field, delta) do { (field) += (delta); } while (0)
struct Ent { int off; int x; };
struct H { H *base; char pad4[6]; unsigned short n; char padc[4]; Ent e[1]; };
extern "C" H *func_00498AE0(H *h) {
    int d = (char *)h - (char *)h->base;
    int i;
    h->base = h;
    for (i = 0; i < h->n; i++)
        RELOCATE(h->e[i].off, d);
    return h;
}
