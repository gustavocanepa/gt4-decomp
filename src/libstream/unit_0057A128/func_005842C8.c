/* compiler: ee-gcc2.9-991111 */
/* Classifies the range [addr, addr + size) against the system memory region D_00875878: 0 outside,
   1 crossing an edge, else the syscall stub func_0058B168 narrows the region to addr's block (2 on
   error or when the range does not fit, 3 when it does). Comparing start directly, with no copy. */
struct Region {
    unsigned int start;
    unsigned int size;
};

extern struct Region D_00875878;
extern int func_0058B168(unsigned int addr, unsigned int *start, unsigned int *size);

int func_005842C8(unsigned int addr, unsigned int size)
{
    unsigned int start, rsize, end, top;

    start = D_00875878.start;
    rsize = D_00875878.size;
    end = addr + size;
    if (start >= end)
        return 0;
    top = start + rsize;
    if (addr >= top)
        return 0;
    if (addr < start)
        return 1;
    if (end >= top)
        return 1;
    if (func_0058B168(addr, &start, &rsize) != 0)
        return 2;
    return (rsize - (addr - start) < size) ? 2 : 3;
}
