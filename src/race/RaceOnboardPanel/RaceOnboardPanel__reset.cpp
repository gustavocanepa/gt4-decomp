typedef unsigned char u8;

struct Obj003A3F80;

extern "C" void RaceDigitalSpeedmeter__reset(struct Obj003A3F80 *arg0);

extern "C" void RaceOnboardPanel__reset(void *arg0) {
    void *s0 = (char *)arg0 + 0xA20;

    RaceDigitalSpeedmeter__reset((struct Obj003A3F80 *)((char *)arg0 + 0x9E8));

    *((u8 *)s0 + 0x55) = *((u8 *)s0 + 0x54);
}
