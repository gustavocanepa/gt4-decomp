/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>

struct Entry {
    int a;
    int b;
} __attribute__((aligned(8)));

struct EntryList {
    Entry items[400];
    int count;
};

extern "C" void func_001D12D8(EntryList *list, int index)
{
    if (index >= 0 && index < list->count) {
        copy(list->items + index + 1, list->items + list->count, list->items + index);
        list->count--;
    }
}
