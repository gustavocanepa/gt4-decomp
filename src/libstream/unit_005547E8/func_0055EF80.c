/* compiler: ee-gcc2.96-nsa-nosib */
typedef unsigned short u16;

extern void *func_005A48D8(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);

void func_0055EF80(void *dst, u16 *src) {
    func_005A48D8(dst, 0, 0x42);
    memcpy(dst, src, *src);
}
