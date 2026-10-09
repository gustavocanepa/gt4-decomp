int func_0057F238(const char *, const char *);

typedef struct {
    char pad[0xC0];
    char name[0x10];
    char id[0x100];
} Entry;

char *func_004EE5F8(void *self, Entry *entries, int count, const char *name) {
    int i;
    for (i = 0; i < count; i++) {
        if (func_0057F238(entries[i].id, name) == 0) {
            return entries[i].name;
        }
    }
    return 0;
}
