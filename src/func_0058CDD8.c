/* compiler: ee-gcc2.9-991111 */
/* Reads a 14-byte version string from a file once and caches it. */
extern char D_00657AD0[];
extern const char D_006CF2C8[];

int func_005B2DF0(const char *path, int mode);
int func_005B3438(int fd, void *buf, int size);
int func_005B3080(int fd);

char *func_0058CDD8(void)
{
    int fd;

    if (D_00657AD0[0] == 0) {
        fd = func_005B2DF0(D_006CF2C8, 1);
        if (fd >= 0) {
            func_005B3438(fd, D_00657AD0, 14);
            func_005B3080(fd);
        }
    }
    return D_00657AD0;
}
