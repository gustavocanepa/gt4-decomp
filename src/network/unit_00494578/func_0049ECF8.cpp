/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Rebuilds the owner's list of active channels and its summary flags (inferred: names and
 * meaning are guesses from the data flow). Each of the 8 channels (0xD0 bytes from 0x3E0) gets
 * its slot reset; active ones are pushed on the list at 0xB18 and counted at 0xB1C. A channel
 * with a nonzero offset or rotation vector is "changing": with a nonzero weight it sets flag
 * 0x20, with weight 0 it takes one of the first 4 slots; any rotation sets flag 0x10. Before
 * the scan the flags start from the sign-extended low byte, with 0x06 set and 0x31 cleared. */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

struct Channel {
    Channel *next;
    char pad4[4];
    u8 active;
    s8 slot;
    char padA[0x20 - 0xA];
    s32 offset[3];
    char pad2C[0x40 - 0x2C];
    s32 rotation[3];
    char pad4C[0x6C - 0x4C];
    float weight;
    char pad70[0xD0 - 0x70];
};

struct ChannelSet {
    char pad0[0x48];
    u16 flags;
    char pad4A[0x3E0 - 0x4A];
    Channel channels[8];
    char padA60[0xB18 - 0xA60];
    Channel *active;
    u16 activeCount;
    s16 slotCount;
};

extern "C" void func_0049ECF8(ChannelSet *set) {
    s16 flags = (s8)set->flags;
    s32 slots = 0;
    set->active = 0;
    set->activeCount = 0;
    flags |= 7;
    flags &= ~0x31;
    Channel *ch = set->channels;
    for (s32 i = 0; i < 8; i++, ch++) {
        ch->slot = -1;
        if (ch->active) {
            ch->next = set->active;
            set->active = ch;
            set->activeCount++;
            s32 moves = (ch->offset[0] | ch->offset[1] | ch->offset[2]) != 0;
            s32 turns = (ch->rotation[0] | ch->rotation[1] | ch->rotation[2]) != 0;
            s32 unweighted = ch->weight == 0.0f;
            if (!unweighted && (moves || turns))
                flags |= 0x20;
            if (turns)
                flags |= 0x10;
            if (slots < 4 && (moves || turns) && unweighted) {
                ch->slot = slots;
                slots++;
            }
        }
    }
    set->slotCount = slots;
    set->flags = flags;
}
