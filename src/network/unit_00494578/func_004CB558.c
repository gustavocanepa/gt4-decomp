/* Checks a file name: no leading space, no control or reserved characters, at most one dot. */
int func_004CB558(const char *name)
{
    char first = *name;
    int c;
    const char *p;
    int dots;
    int next;

    c = *(const unsigned char *)name;
    if (first == ' ') {
        return -22;
    }
    p = name;
    dots = 0;
    if (first != 0) {
        for (;;) {
            char x = c;
            if (x == '.') {
                dots++;
            }
            if (x < 0x20 || x == '"' || (unsigned char)(c - '*') < 3 || (unsigned char)(c - ':') < 6 || (unsigned char)(c - '[') < 3 || x == '|') {
                return -22;
            }
            p++;
            next = (unsigned char)*p;
            if (next == 0) {
                break;
            }
            /* a copy in its own block keeps c's bits unknown to combine, which keeps the andi */
            c = next;
        }
    }
    return dots < 2 ? 0 : -22;
}
