typedef unsigned short u16;
typedef int s32;

struct Entry {
    char pad[0x10];
    s32 unk10;
};

extern "C" u16 func_004501F0(s32 arg0, s32 arg1) {
    Entry *entry = (Entry *)(arg1 * 4 + arg0);
    return *(u16 *)(arg0 + entry->unk10);
}
