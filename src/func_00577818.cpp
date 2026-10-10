extern "C" int func_005B68D0(const char *name);
extern "C" int func_005777D8(int fd, void *buf, int size);

extern "C" int func_00577818(const char *name, void *buf, int size) {
    int fd = func_005B68D0(name);
    if (fd < 0)
        return -1;
    return func_005777D8(fd, buf, size);
}
