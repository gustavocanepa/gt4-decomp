struct Item {
    char pad0[0x1C];
    unsigned int low : 18;
    unsigned int flag18 : 1;
    unsigned int high : 13;
};

struct mListBox;
extern "C" int mListBox__get_total_item_count(mListBox *lb);
extern "C" Item *func_002B49B8(mListBox *lb, int index);

extern "C" void func_002B55E8(mListBox *lb, int index, int on) {
    if (index >= 0 && index < mListBox__get_total_item_count(lb))
        func_002B49B8(lb, index)->flag18 = on != 0;
}
