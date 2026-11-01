/* Compares two NUL-terminated u16 strings (wcscmp-like): returns 1 if a > b, 0 if equal, -1 if
 * a < b at the first difference. No locals: every *a/*b stays a memory expression, which keeps
 * the repeated andi 0xFFFF masks and the exit-path reload of *b. */
int func_004C8D08(const unsigned short *a, const unsigned short *b) {
    for (; *a != 0; a++, b++)
        if (*a != *b)
            break;
    if (*a > *b)
        return 1;
    if (*a == *b)
        return 0;
    return -1;
}
