typedef int s32;
typedef unsigned int u32;

struct Item { char pad[0x10]; u32 flags; char pad14[0xC]; };

extern "C" s32 func_00435958(Item *items, s32 i) {
    for (i++; i < 1000; i++) {
        if (items[i].flags & 1)
            return i;
    }
    return i;
}
