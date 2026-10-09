extern char D_00645570[];
extern char *func_004F9F70(void *);
extern void func_004FA048(void *, char *);
extern "C" char *func_005A609C(char *, const char *);

void func_001F6F68(void *ctx, int unused, char *name, int *value)
{
    char *entry = func_004F9F70(D_00645570);
    if (entry) {
        func_005A609C(name, entry + 0x39);
        *value = (signed char)entry[0x79];
    } else {
        *value = -1;
    }
    func_004FA048(D_00645570, entry);
}
