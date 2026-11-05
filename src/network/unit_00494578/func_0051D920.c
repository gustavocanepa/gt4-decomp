/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Creates an entry in the first free slot of a global table, growing the table by 10 slots when it
   is full, and gives it one slot object (two for type 1). Writes the index to *out. Returns 0, 2 for
   bad arguments, 100 when a slot object cannot be made, or the first allocation or size error.
   Names are provisional, inferred from the code. */
struct Slot { int kind; int pad[2]; void *owner; };
struct Entry {
    unsigned int index;
    unsigned int type;
    int ready;
    int pad0[21];
    void *handle;
    int pad1[5];
    struct Slot *first;
    struct Slot *second;
};
extern unsigned int D_0064AE10;
extern struct Entry **D_0064AE14;
extern int func_00538BF8(void *out, unsigned long long size);
extern void func_00538C68(void *p);
extern void func_005A4724(void *dst, const void *src, unsigned int n);
extern void *func_0051BDF8(void);
extern struct Slot *func_0051D838(unsigned int index, unsigned int a, unsigned int b);
extern int func_0051FD80(unsigned int n);

int func_0051D920(unsigned int *out, unsigned int type, unsigned int sizeA, unsigned int sizeB)
{
    struct Entry **table = 0;
    struct Entry *entry;
    struct Slot *slot;
    unsigned int i = 0;
    unsigned int grown;
    int status = 2;

    if (type < 2 && sizeA != 0 && sizeB != 0) {
        if (D_0064AE10 != 0) {
            for (i = 0; i < D_0064AE10; i++) {
                if (D_0064AE14[i] == 0) break;
            }
        } else {
            /* Redundant, but this else is what leaves the original's branch over it after the loop. */
            i = 0;
        }
        if (i == D_0064AE10) {
            grown = i + 10;
            table = 0;
            /* These two checks jump to the shared exit, so status is not a constant there and its
               initial 2 stays at the top of the function in $v0. */
            status = func_00538BF8(&table, (unsigned long long)(grown * 4));
            if (status != 0) goto done;
            if (D_0064AE14 != 0) {
                func_005A4724(table, D_0064AE14, D_0064AE10 * 4);
                func_00538C68(&D_0064AE14);
            }
            D_0064AE10 = grown;
            D_0064AE14 = table;
        }
        status = func_00538BF8(&entry, 0x9C);
        if (status != 0) goto done;
        D_0064AE14[i] = entry;
        entry->index = i;
        entry->type = type;
        entry->handle = func_0051BDF8();
        entry->ready = 0;
        if (type == 1) {
            sizeA >>= 1;
            sizeB >>= 1;
        }
        if (sizeA < 0x248) sizeA = 0x248;
        if (sizeB < 0x248) sizeB = 0x248;
        if (type < 2) {
            slot = func_0051D838(i, sizeA, sizeB);
            if (slot == 0) return 100;
            slot->kind = 0;
            slot->owner = entry->handle;
            entry->first = slot;
        }
        if (type == 1) {
            slot = func_0051D838(i, sizeA, sizeB);
            if (slot == 0) return 100;
            slot->kind = type;
            slot->owner = entry->handle;
            entry->second = slot;
        }
        status = func_0051FD80(sizeA);
        if (status != 0) return status;
        status = func_0051FD80(sizeB);
        if (status != 0) return status;
        *out = i;
        entry->ready = 1;
        return status;
    }
done:
    return status;
}
