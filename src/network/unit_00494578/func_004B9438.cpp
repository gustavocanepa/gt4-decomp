typedef unsigned short u16;

/* Length of a zero-terminated UTF-16 string, in code units. */
static inline int length16(const u16 *text) {
    int n = 0;
    while (text[n]) n++;
    return n;
}

/* Converts the hiragana of a UTF-16 string to katakana in place: the hiragana block
   U+3040..U+309F maps onto the katakana block 0x60 code points above it. */
extern "C" void func_004B9438(u16 *text) {
    int n = length16(text);
    for (int i = 0; i < n; i++) {
        if (text[i] >= 0x3040 && text[i] <= 0x309F)
            text[i] += 0x60;
    }
}
