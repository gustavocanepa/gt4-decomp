/* The vowels "aiueo" (D_006B04B0) copied to a local array, then searched. */
struct Vowels {
    char c[6];
};

extern "C" const Vowels D_006B04B0;

extern "C" int func_004B8B10(int ch) {
    Vowels v = D_006B04B0;
    for (int i = 0; i < 5; i++) {
        if (v.c[i] == ch)
            return i;
    }
    return -1;
}
