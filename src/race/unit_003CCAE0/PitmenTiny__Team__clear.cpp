typedef int s32;

struct Item { char pad[0x74]; };
extern "C" void PitmenTiny__Entity__clear(Item *);

extern "C" void PitmenTiny__Team__clear(Item *items) {
    s32 i;
    for (i = 3; i >= 0; i--) {
        PitmenTiny__Entity__clear(items++);
    }
}
