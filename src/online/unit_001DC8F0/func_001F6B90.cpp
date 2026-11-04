extern char D_00645570[];
extern char *func_004F9F70(void *);
extern void func_004FA048(void *, char *);
extern "C" char *func_005A609C(char *, const char *);

void func_001F6B90(void *ctx, int unused, char *name)
{
    char *entry = func_004F9F70(D_00645570);
    if (entry) {
        func_005A609C(name, entry + 4);
    } else {
        /* dead store: the empty-looking else gives the join block a second
           predecessor, so only the lui of D_00645570 is kept in s2 */
        name = 0;
    }
    func_004FA048(D_00645570, entry);
}
