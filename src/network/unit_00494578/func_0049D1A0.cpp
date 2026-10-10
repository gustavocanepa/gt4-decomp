/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned int u128 __attribute__((mode(TI)));

union func_0049D1A0_QW {
    u128 q;
    u32 w[4];
};

struct func_0049D1A0_Cmd {
    int pad0;
    float value;
    unsigned char kind;
};

struct func_0049D1A0_Obj {
    char pad0[0x30];
    func_0049D1A0_QW tag;
    u32 x40;
    char pad1[0x48 - 0x44];
    unsigned short x48;
    char pad2[0x1F8 - 0x4A];
    u32 *packet;
    char pad3[0xC30 - 0x1FC];
    u32 xc30;
};

extern "C" {
void func_0049EB90(func_0049D1A0_Obj *self, float v);
void func_0049EA80(func_0049D1A0_Obj *self, float v);
}

extern "C" int func_0049D1A0(func_0049D1A0_Obj *self, func_0049D1A0_Cmd *cmd, int n) {
    unsigned int count = cmd->kind >> 5;
    switch (cmd->kind & 0x1F) {
    case 4:
        if (self->x48 & 7)
            n = 2;
        if (n == 2)
            func_0049EB90(self, cmd->value);
        break;
    case 1:
        if (self->x48 & 7)
            n = 2;
        if (n == 2)
            func_0049EA80(self, cmd->value);
        break;
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
        break;
    }
    if (n != 0 && self->tag.w[0] != 0) {
        n--;
        *(u128 *)self->packet = self->tag.q;
        self->packet += 4;
    }
    switch ((int)count) {
    case 1:
    case 2: {
        u32 *p = self->packet;
        *p++ = 0x10000001;
        *p++ = 0;
        *p++ = 0x20000000;
        *p++ = 0x3F3F3F3F;
        *p++ = 0x7001C0F2;
        *p++ = self->xc30;
        *p++ = 0x20000000;
        *p++ = self->x40;
        self->packet = p;
        }
    }
    return n;
}
