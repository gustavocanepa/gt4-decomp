typedef long s64;

struct Key {
    s64 id;
    s64 pad[3];
};

struct Row {
    s64 f[26];
};

struct Spec {
    s64 f[0x28];
};

extern char D_006235A8[];
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(void *db, s64 key, void *out);
extern "C" int SPEC_DATABASE__DatabaseStorage__IsExistID(void *db, s64 id);

/* Compares a spec with the stored row of its id. Every path returns 0: the comparisons survive only
   as branches to the shared exit. The last three tests leave no code at all (each jump pass before
   flow drops the then-last test, whose two arms are equal) and the test of f[32] keeps just its
   load; their operands other than f[32] are therefore not recoverable, only their number is.
   The 64-bit return type matters: with the same width as IsExistID's result, cse forwards the
   zero result instead of emitting the explicit `return 0` block. */
extern "C" s64 func_00445B88(Spec *self) {
    Key key;
    Row row;

    SPEC_DATABASE__DatabaseStorage__getRow(D_006235A8, self->f[0], &key);
    if (key.id == -1) return 0;
    if (!SPEC_DATABASE__DatabaseStorage__IsExistID(D_006235A8, key.id)) return 0;
    SPEC_DATABASE__DatabaseStorage__getRow(D_006235A8, key.id, &row);
    if (self->f[4] != row.f[0]) return 0;
    if (self->f[5] != row.f[1]) return 0;
    if (self->f[6] != row.f[5]) return 0;
    if (self->f[7] != row.f[11]) return 0;
    if (self->f[8] != row.f[9]) return 0;
    if (self->f[9] != row.f[10]) return 0;
    if (self->f[10] != row.f[2]) return 0;
    if (self->f[11] != row.f[23]) return 0;
    if (self->f[14] != row.f[8]) return 0;
    if (self->f[15] != row.f[7]) return 0;
    if (self->f[16] != row.f[6]) return 0;
    if (self->f[17] != row.f[14]) return 0;
    if (self->f[18] != row.f[15]) return 0;
    if (self->f[19] != row.f[16]) return 0;
    if (self->f[20] != row.f[17]) return 0;
    if (self->f[21] != row.f[12]) return 0;
    if (self->f[22] != row.f[13]) return 0;
    if (self->f[23] != row.f[21]) return 0;
    if (self->f[24] != row.f[20]) return 0;
    if (self->f[25] != row.f[22]) return 0;
    if (self->f[26] != row.f[19]) return 0;
    if (self->f[27] != row.f[18]) return 0;
    if (self->f[28] != row.f[3]) return 0;
    if (self->f[29] != row.f[4]) return 0;
    if (self->f[31] != -1) return 0;
    if (self->f[32] != -1) return 0;
    if (self->f[33] != -1) return 0;
    if (self->f[34] != -1) return 0;
    if (self->f[35] != -1) return 0;
    return 0;
}
