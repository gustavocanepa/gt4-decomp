extern char D_00645570[];
extern int func_001F6A30(void *);
extern char *func_004F9F18(void *, int);
extern unsigned int func_004FB1E8(void *);

int func_001F7460(void *ctx)
{
    int i = 0;
    int max_count = 0;
    unsigned int max_value = 0;
    int n = func_001F6A30(ctx);

    for (; i < n; i++) {
        char *entry = func_004F9F18(D_00645570, i);
        if (entry == 0) {
            return 0;
        }
        int count = entry[0x37];
        unsigned int value = *(unsigned int *)entry;
        if (max_value < value) {
            max_value = value;
        }
        if (max_count < count) {
            max_count = count;
        }
    }
    if (max_count <= 0) {
        return 0;
    }
    if (n < max_count) {
        return 0;
    }
    return max_value < func_004FB1E8(D_00645570);
}
