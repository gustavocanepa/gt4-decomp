/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Block_005723D8 {
    int m0;
    char *end;
    struct Block_005723D8 *prev;
    struct Block_005723D8 *next;
} Block_005723D8;

typedef struct {
    char pad0[0xC];
    Block_005723D8 *buckets[1];
} Heap_005723D8;

int func_00572438(Heap_005723D8 *heap, int size);

void func_005723D8(Heap_005723D8 *heap, Block_005723D8 *b) {
    int i = func_00572438(heap, b->end - (char *)b);
    Block_005723D8 *prev = b->prev;
    Block_005723D8 *next = b->next;
    if (prev != 0) {
        prev->next = next;
    } else {
        heap->buckets[i] = next;
    }
    if (next != 0) {
        next->prev = prev;
    }
}
