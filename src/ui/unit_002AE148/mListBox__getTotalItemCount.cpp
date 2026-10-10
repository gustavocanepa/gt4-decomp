typedef int s32;

struct Obj {
    char pad[0x11C];
    s32 unk11C;
};

extern "C" s32 mListBox__get_total_item_count(char *arg0);

extern "C" s32 mListBox__getTotalItemCount(Obj *arg0) {
    s32 v0 = mListBox__get_total_item_count((char *)arg0);
    return v0 + (arg0->unk11C != 0);
}
