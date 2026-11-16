/* compiler: ee-gcc2.96-nogcse */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* One channel record (44 bytes). An entry's time stamp is split between a word table (upper
   12 bits of each word) and a table of 16-bit halves; the entry count sits behind a pointer. */
struct ChannelTimes { u16 *high; int unk4; u16 *count; };
struct Channel { char pad[0x1C]; u32 *low; ChannelTimes times; };
struct Self { char pad[0xC]; u32 *now; char pad10[0x14]; u8 *channels; };

/* Returns the index of the entry of channel c that is furthest behind the current time
   (28-bit time stamps, compared modulo 0x10000000). The channel table pointer is read again
   on every pass, as the original does. */
extern "C" int func_004C3850(Self *self, u8 c) {
    u32 best = 0;
    u16 i;
    int index = 0;
    u8 *channels = self->channels;
    u32 channel_offset = c * 44;
    u32 times_offset = channel_offset + 0x20;
    u16 *count = ((ChannelTimes *)(channels + times_offset))->count;
    for (i = 0; i < *count; i++) {
        u32 now = *self->now;
        channels = self->channels;
        u32 stamp = (((Channel *)(channels + channel_offset))->low[i] >> 20)
                  + (((ChannelTimes *)(channels + times_offset))->high[i] << 12);
        u32 age = now - stamp + (now < stamp) * 0x10000000;
        if (best < age) {
            best = age;
            index = i;
        }
    }
    return index;
}
