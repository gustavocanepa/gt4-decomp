int func_0057F238(const char *, const char *);

typedef struct {
    int pad;
    int enabled;
    char pad2[0xB8];
    char name[0x10];
    char id[0x100];
} Entry;

typedef struct {
    char pad[0x48];
    Entry *entries;
    int pad2[3];
    int count;
} Table;

int func_004EE458(Table *table, const char *id) {
    int i;

    for (i = 0; i < table->count; i++) {
        if (func_0057F238(table->entries[i].id, id) == 0) {
            return table->entries[i].enabled != 0;
        }
    }
    return 0;
}
