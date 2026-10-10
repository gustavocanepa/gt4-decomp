/* compiler: ee-gcc2.9-991111 */
int func_00585AA0(int *hdr)
{
    int n;
    unsigned int *p;
    unsigned int v;

    if (!hdr || hdr[0] != 0x4C785265 || hdr[1] != 0x41004269)
        return 0x81059039;
    n = 0x20;
    p = (unsigned int *)(hdr + 8);
    do {
        v = *p;
        n += 4;
        p++;
    } while (v != 0xFFFFFFFF);
    return n;
}
