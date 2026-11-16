/* Block header of the stream pool: 0x40 bytes in front of every block's payload. */
struct Block {
    int used;
    int unk4;
    int free;
    int size;
    char pad10[0x2C];
    int next;
};

/* Format a buffer as one empty block. Returns 2 when the buffer is missing or too small.
 * (The second size test is dead after the first; the original kept both.) */
extern "C" int func_00571850(Block *buffer, unsigned int bytes) {
    Block *block = 0;

    if (buffer == 0)
        return 2;
    if (bytes < 0x80)
        return 2;
    if (bytes < 0x40)
        return 2;
    block = buffer;
    block->free = bytes - 0x40;
    block->size = bytes - 0x40;
    block->unk4 = 0;
    block->used = 0;
    block->next = 0;
    return 0;
}
