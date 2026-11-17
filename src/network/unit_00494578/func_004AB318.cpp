typedef unsigned char u8;
typedef unsigned long u64;

/* Copies the entries selected by mask: one 64-bit word and its tag byte per set bit. */
extern "C" u64 *func_004AB318(u64 *out, u64 mask, const u8 *tags, const u64 *words) {
    words++;
    if (mask % 2) {
        u64 word = words[-1];
        u64 tag = *tags;
        do { out += 2; out[-2] = word; out[-1] = tag; } while (0);
    }
    if ((mask >> 1) != 0) return func_004AB318(out, mask >> 1, tags + 1, words);
    return out;
}
