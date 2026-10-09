int func_0057F238(const char *, const char *);

typedef struct {
    char pad[0xC0];
    char name[0x10];
    char id[0x100];
} Entry;

char *func_004EE578(void *self, Entry *entries, int count, const char *name) {
    int i;
    for (i = 0; i < count; i++) {
        if (func_0057F238(entries[i].name, name) == 0) {
            return entries[i].id;
        }
    }
    return 0;
}
