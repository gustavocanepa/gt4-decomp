int func_004EF708(void *, int *, int);
int func_004EF8C0(void *, int *, int);
int func_004EF730(void *, int, int, void *, int);
int func_0057F238(const char *, const char *);

int func_004EF330(void *dev, const char *name) {
    int ids[4];
    char label[0x10];
    int count;
    int result;
    int i;
    int *id;

    result = func_004EF708(dev, ids, 2);
    if (result < 0) {
        return result;
    }
    count = func_004EF8C0(dev, ids, 2);
    if (count < 0) {
        return count;
    }
    for (i = 0; i < count; i++) {
        if (func_004EF730(dev, ids[i], 0, label, 0x10) >= 0) {
            if (func_0057F238(label, name) == 0) {
                return ids[i];
            }
        }
    }
    return -1;
}
