/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): add_fdes (frame-dwarf2.c, with frame.c's
 * fde_insert and next_fde inlined).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef unsigned int uword;
typedef int sword;
typedef unsigned int uaddr;
typedef unsigned int size_t;

struct dwarf_fde {
    uword length;
    sword CIE_delta;
    void *pc_begin;
    uaddr pc_range;
} __attribute__((packed, aligned(__alignof__(void *))));

typedef struct dwarf_fde fde;

typedef struct fde_vector {
    fde **array;
    size_t count;
} fde_vector;

typedef struct fde_accumulator {
    fde_vector linear;
    fde_vector erratic;
} fde_accumulator;

static inline void fde_insert(fde_accumulator *accu, fde *this_fde) {
    if (accu->linear.array)
        accu->linear.array[accu->linear.count++] = this_fde;
}

static inline fde *next_fde(fde *p) {
    return (fde *)(((char *)p) + p->length + sizeof(p->length));
}

void func_005BEE98(fde *this_fde, fde_accumulator *accu, void **beg_ptr, void **end_ptr) {
    void *pc_begin = *beg_ptr;
    void *pc_end = *end_ptr;

    for (; this_fde->length != 0; this_fde = next_fde(this_fde)) {
        /* Skip CIEs and linked once FDE entries.  */
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;

        fde_insert(accu, this_fde);

        if (this_fde->pc_begin < pc_begin)
            pc_begin = this_fde->pc_begin;
        if (this_fde->pc_begin + this_fde->pc_range > pc_end)
            pc_end = this_fde->pc_begin + this_fde->pc_range;
    }

    *beg_ptr = pc_begin;
    *end_ptr = pc_end;
}
