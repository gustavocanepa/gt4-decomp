/* compiler: ee-gcc2.9-991111 */
struct Block {
    struct Block *next;
    unsigned int used : 1;
    unsigned int start : 31;
    unsigned int flag : 1;
    unsigned int size : 31;
};
struct Heap { int id; struct Block head; };
extern struct Heap *D_00875884;

struct Block *func_005851F0(unsigned int addr)
{
    struct Block *b;

    for (b = &D_00875884->head; b; b = b->next) {
        if (addr >= b->start << 8 && addr < (b->start + b->size) << 8)
            break;
    }
    return b;
}
