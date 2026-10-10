/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libgcc frame-dwarf2.c search_fdes: find the FDE whose range holds pc. */
typedef unsigned int uword;
typedef int sword;
typedef unsigned int uaddr;

typedef struct dwarf_fde {
    uword length;
    sword CIE_delta;
    void *pc_begin;
    uaddr pc_range;
} __attribute__ ((packed, aligned (__alignof__ (void *)))) fde;

static inline fde *next_fde(fde *f)
{
    return (fde *)((char *)f + f->length + sizeof(f->length));
}

fde *func_005BEF28(fde *this_fde, void *pc)
{
    for (; this_fde->length != 0; this_fde = next_fde(this_fde)) {
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;
        if ((uaddr)((char *)pc - (char *)this_fde->pc_begin) < this_fde->pc_range)
            return this_fde;
    }
    return 0;
}
