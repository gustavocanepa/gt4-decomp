/* compiler: ee-gcc2.9-991111 */
int func_005B0568(char **pp, int *left, int c) {
    if (*left == 0) {
        return 1;
    }
    if (c < 0x100) {
        if (*left == 1) {
            c = 0;
        }
        *(*pp)++ = c;
        (*left)--;
        return 1;
    }
    **pp = 0;
    return 0;
}
