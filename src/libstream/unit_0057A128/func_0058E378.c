/* compiler: ee-gcc2.9-991111 */
extern char D_0087EA40[];
extern int D_00657AF8;
unsigned int func_0057F260(const char *s);
void *memcpy(void *dst, const void *src, unsigned int n);
void func_005ADCD0(int sema);

#define UNCACHED(p) ((char *)((unsigned int)(p) | 0x20000000))

void func_0058E378(char *dst) {
    if (dst) {
        unsigned int n = func_0057F260(UNCACHED(D_0087EA40)) < 0x400 ? func_0057F260(UNCACHED(D_0087EA40)) : 0x3FF;
        memcpy(dst, UNCACHED(D_0087EA40), n);
        dst[n] = 0;
    }
    func_005ADCD0(D_00657AF8);
}
