struct Channel {
    unsigned char program;
    char pad[0x13];
    char *patch;
    char *data;
};

struct Seq {
    char pad[0x30];
    void *bank;
    int status;
    char pad2[0x20];
    unsigned char *pc;
    char pad3[0xC];
    Channel ch[16];
};

extern "C" char *func_00559B10(void *bank, int program);

extern "C" void func_0055B828(Seq *s)
{
    int c = *s->pc++;
    Channel *ch = &s->ch[s->status & 0xF];
    ch->program = c;
    char *p = func_00559B10(s->bank, c);
    ch->patch = p;
    ch->data = p ? p + 8 : 0;
}
