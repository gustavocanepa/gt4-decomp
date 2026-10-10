typedef unsigned int u32;

/* the ELF (PJW) string hash */
extern "C" u32 func_00494460(const unsigned char *name) {
    u32 h = 0;
    u32 g;
    unsigned char c;
    while ((c = *name++) != 0) {
        h = (h << 4) + c;
        if ((g = h & 0xF0000000) != 0)
            h ^= g >> 24;
        h &= ~g;
    }
    return h;
}
