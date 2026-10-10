typedef unsigned char u8;

struct Obj_003A77B8 {
    char pad0[0x54];
    u8 f54;
    u8 f55;
};

extern "C" void RaceDigitalSpeedmeter__reset(void *arg0);

extern "C" void RaceSimplePanel__reset(char *arg0) {
    RaceDigitalSpeedmeter__reset((void *)(arg0 + 0x48));

    struct Obj_003A77B8 *self = (struct Obj_003A77B8 *)(arg0 + 0x124);
    self->f55 = self->f54;
}
