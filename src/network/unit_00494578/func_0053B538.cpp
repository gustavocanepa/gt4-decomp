/* func_0053B538, a strtok_r-like scan: returns the token at *save, NUL-terminates it at the first delimiter and
 * advances *save past it (*save = 0 at the end of the string). It works through *save rather than
 * a local cursor, as retail does: a local pointer changes the register homes and block layout. */
char *func_0053B538(char **save, const char *delim) {
    char *start = *save;
    const char *d;
    if (start == 0)
        return 0;
    if (delim == 0)
        return start;
    while (**save) {
        for (d = delim; *d; d++) {
            if (**save == *d) {
                **save = 0;
                (*save)++;
                return start;
            }
        }
        (*save)++;
    }
    *save = 0;
    return start;
}
