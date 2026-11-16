/* Finds the first item of type 4 or 7 and stores its index in *out (0xFFFE when there is none).
   Returns 2 for a missing argument, 0 otherwise. */
struct Item { int type; char pad[0x40]; };
struct Owner { char pad[0x84]; Item *items; char pad88[0x14]; unsigned short count; };

extern "C" int func_00523DA8(Owner *self, unsigned short *out) {
    unsigned short i;
    unsigned short n;
    int type;
    if (out == 0) return 2;
    *out = 0xFFFE;
    if (self == 0) return 2;
    /* The search is one do { } while (0) block scanned with gotos, as the original's code shows:
       the block gives the compiler a loop region to move the "found" exit out of, while the scan
       itself is left untouched by the loop optimiser (items is read again for every entry). */
    do {
        i = 0;
        n = self->count;
        goto test;
    next:
        i++;
    test:
        if (i >= n) break;
        type = self->items[i].type;
        if (type == 4) {
            *out = i;
            break;
        }
        if (type != 7) goto next;
        *out = i;
    } while (0);
    return 0;
}
