typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Slot {
    u16 id;
    char pad[0xE];
} Slot;

typedef struct Table {
    int unk0;
    Slot slots[16];
    int count;
} Table;

extern Table D_00867FF8;
extern void *func_005A48D8(void *, int, unsigned int); /* memset */

/* Release the slot registered under 'id'. Returns 0, or 2 when the id is 0 or unknown.
 * The slot is addressed by its byte offset, computed before the test; the cleared address
 * is written as an integer sum (offset + base), which is the order the original adds in. */
int func_0052D2F8(u16 id) {
    Table *t = &D_00867FF8;
    u32 i;

    if (id == 0)
        return 2;
    for (i = 0; i < 16; i++) {
        u32 offset = i * sizeof(Slot);
        Slot *slot = (Slot *)((char *)t->slots + offset);
        if (id == slot->id) {
            func_005A48D8((Slot *)(offset + (u32)t->slots), 0, sizeof(Slot));
            t->count--;
            return 0;
        }
    }
    return 2;
}
