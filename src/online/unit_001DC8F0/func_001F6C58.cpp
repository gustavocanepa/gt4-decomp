/* compiler: ee-gcc2.96-hilo */
extern char D_00645570[];
extern const char *D_00618DE0[];
extern char *func_004F9F70(void *);
extern void func_004FA048(void *, char *);
extern "C" char *strcpy(char *, const char *);
extern "C" char *func_005A609C(char *, const char *);

void func_001F6C58(void *ctx, int unused, char *style)
{
    char *entry = func_004F9F70(D_00645570);
    if (entry) {
        int index = entry[0x35];
        if (index <= 0) {
            func_005A609C(style, D_00618DE0[index]);
        } else {
            strcpy(style, "style_error(illegal index)");
        }
    } else {
        strcpy(style, "style_error(nobody)");
    }
    func_004FA048(D_00645570, entry);
}
