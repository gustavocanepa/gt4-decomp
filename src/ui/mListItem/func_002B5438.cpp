typedef int s32;
typedef short s16;

struct Item_002B5438 {
    char pad[0x1C];
    s16 m1C;
};

extern "C" s32 mListBox__get_total_item_count(void *list);
extern "C" Item_002B5438 *func_002B49B8(void *list, s32 i);

extern "C" void func_002B5438(void *list, s32 i, s32 value) {
    if (i >= 0 && i < mListBox__get_total_item_count(list)) {
        func_002B49B8(list, i)->m1C = value;
    }
}
