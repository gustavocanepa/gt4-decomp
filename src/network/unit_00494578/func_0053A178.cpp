typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

/* The slot table of this unit. Both tables are kept as integer addresses, as its twin
   func_0053A228 reads them. */
extern u8 D_0064C0F4;   /* 1 once the tables exist */
extern s32 D_0064C0FC;  /* address of the slots: D_0086B3DC rows of D_0086B3D8 values */
extern s32 D_0064C100;  /* address of the per-row counts of slots in use */
extern u32 D_0086B3DC;  /* rows */
extern u32 D_0086B3D8;  /* slots per row */

/* Appends `value` to row `row` and returns the index of the slot it took through `*out`.
   Returns 5 without tables, 2 for a bad argument, 0x3EB when the row is already past its limit.

   `n` is first the address of the counts and then the count read from the row: one variable
   for both, as the original has it (the count stays in that variable's register while the
   limit test uses the value just loaded). The slot address is formed before `*out` is written,
   which is why the two table words are read again ahead of that store. */
extern "C" s32 func_0053A178(s32 *out, u32 row, s32 value) {
    u32 n;
    s32 *count;
    s32 *slot;

    if (D_0064C0F4 != 1) return 5;
    if (D_0064C0FC == 0) return 5;
    n = D_0064C100;
    if (n == 0) return 5;
    if (out == 0) return 2;
    if (row >= D_0086B3DC) return 2;
    count = (s32 *)(row * 4 + n);
    if (D_0086B3D8 < (u32)*count) return 0x3EB;
    n = (*count)++;
    slot = (s32 *)((row * D_0086B3D8 + n) * 4 + (u32)D_0064C0FC);
    *out = n;
    *slot = value;
    return 0;
}
