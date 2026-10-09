void func_005A48D8(void *, int, int);
int func_004EEC58(void *, const char *, int *);
int func_004EF730(void *, int, int, void *, int);

int func_004EEDE8(void *self, const char *name, void *buffer, int size) {
    int id;

    func_005A48D8(buffer, 0, size);
    if (func_004EEC58(self, name, &id) == 0) {
        return 0;
    }
    return func_004EF730(self, id, 3, buffer, size) >= 0;
}
