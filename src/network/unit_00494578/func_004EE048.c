int func_0057F238(const char *, const char *);
int func_004EE6B8(void *, int);
int func_004EE6F0(void *, int);
int func_004EDB50(void *, int, int, int, int);

typedef struct {
    char pad[0x40];
    char name[0x30];
} Entry;

typedef struct {
    char pad[0x44];
    Entry *entries;
    int pad48[3];
    int count;
} Netcnf;

int func_004EE048(Netcnf *n, int mode, const char *name, int arg) {
    int i;

    for (i = 0; i < n->count; i++) {
        if (func_0057F238(n->entries[i].name, name) == 0) {
            int first = func_004EE6B8(n, i);
            int second = func_004EE6F0(n, i);
            int result = func_004EDB50(n, 2, mode, second, second);
            if (result < 0) {
                return result;
            }
            return func_004EDB50(n, 1, mode, first, arg);
        }
    }
    return -1;
}
