/* compiler: ee-gcc2.96-nosched1 */
typedef unsigned char u8;
void func_004A2980(int mask, int g, int b, int a);

/* Channel func_005AE268 mask from four enable bytes (r, g, b, a), passed on with the bytes. */
void func_004A2930(int r, int g, int b, int a) {
    int mask = 0;
    if (r & 0xFF) mask = 0xFF;
    g &= 0xFF;
    b &= 0xFF;
    if (g) mask |= 0xFF00;
    a &= 0xFF;
    if (b) mask |= 0xFF0000;
    if (a) mask |= 0xFF000000;
    func_004A2980(mask, g, b, a);
}
