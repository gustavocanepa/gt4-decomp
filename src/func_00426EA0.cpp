struct Pad {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05();
    virtual int v06(int port);
};
struct RaceInput {
    char pad[0xCC];
    int buttons;
    char pad2[0xC4];
    Pad *pad_dev;
    char pad3[0x30];
    int paused;
    int active;
};

extern "C" void RaceInput__virtual_05(RaceInput *self, int port)
{
    if (!self->paused && self->active && self->pad_dev)
        self->buttons = self->pad_dev->v06(port);
}
