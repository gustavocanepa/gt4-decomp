/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Fills table entry i (44 bytes, from offset 0x1020): copies the 32-byte name and the id from
   src and opens the range to 0x7FFFFFFF on both ends. Name is a char array, so the copy is
   unaligned ldl/ldr and sdl/sdr pairs. */
struct Name { char c[32]; };
struct Src { int x0; int x4; int id; Name name; };
struct Entry { Name name; int id; int lo; int hi; };
struct Self { char pad[0x1020]; Entry e[1]; };

extern "C" void func_004F8EE8(Self *s, Src *src, int i) {
    s->e[i].name = src->name;
    s->e[i].id = src->id;
    s->e[i].lo = 0x7FFFFFFF;
    s->e[i].hi = 0x7FFFFFFF;
}
