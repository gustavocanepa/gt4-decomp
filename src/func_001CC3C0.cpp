/* Memory card usage of a directory: one cluster per started KB of each file plus one per two
   entries plus one. */
struct McDirEntry {
    unsigned char created[8];
    unsigned char modified[8];
    unsigned int size;
    unsigned short attr;
    unsigned short reserved1;
    unsigned int reserved2;
    unsigned int pdaApp;
    unsigned char name[32];
};

extern "C" int func_001CC230(void *a, void *b, McDirEntry *entries);

extern "C" int func_001CC3C0(void *a, void *b) {
    McDirEntry entries[18];
    int n = func_001CC230(a, b, entries);
    if (n < 0)
        return -1;
    int total = 0;
    for (int i = 0; i < n; i++)
        total += (entries[i].size + 1023) >> 10;
    total += (n + 1) / 2;
    return total + 1;
}
