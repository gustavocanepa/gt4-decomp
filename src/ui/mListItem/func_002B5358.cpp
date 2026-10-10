struct Item {
    char pad[0x1C];
    unsigned int lo : 16;
    unsigned int on : 1;
    unsigned int hi : 15;
};
extern "C" int mListBox__get_total_item_count(void *list);
extern "C" Item *func_002B49B8(void *list, int i);

extern "C" void func_002B5358(void *list, int i, int on)
{
    if (i >= 0 && i < mListBox__get_total_item_count(list)) {
        Item *it = func_002B49B8(list, i);
        it->on = on != 0;
    }
}
