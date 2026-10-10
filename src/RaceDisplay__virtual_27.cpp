struct func_0039D7C8_Oscillator {
    char pad0[4];
};

struct func_0039D7C8_Message {
    char pad0[0x20];
    unsigned int color;
    char pad24[0x34 - 0x24];
    func_0039D7C8_Oscillator blink;
};

struct func_0039D7C8_Self {
    char pad0[0x228C];
    func_0039D7C8_Message message;
};

extern const char **D_00621870;
extern "C" void Oscillator__setCount(func_0039D7C8_Oscillator *self, int count, int a);
extern "C" void Oscillator__setCycle(func_0039D7C8_Oscillator *self, float a, float b);
extern "C" void Oscillator__setWaveform(func_0039D7C8_Oscillator *self, float a, float b);
extern "C" void RaceMessageDisplay__setMessage(func_0039D7C8_Message *self, const char *name, float a, float b);
extern "C" void func_0039D9D8(func_0039D7C8_Self *self, const char *text, int flag);

extern "C" int RaceDisplay__virtual_27(func_0039D7C8_Self *self, int message) {
    switch (message) {
    case 1:
    case 2:
    case 3:
    case 13:
    case 14: {
        func_0039D7C8_Message *m = &self->message;
        func_0039D7C8_Oscillator *o = &self->message.blink;
        m->color = 0x80FFFFFF;
        Oscillator__setCount(o, 5, 0);
        Oscillator__setCycle(o, 0x1.9999980000000p-3f, 0x1.3333320000000p-2f);
        Oscillator__setWaveform(o, 0x1.9999980000000p-5f, 0x1.9999980000000p-4f);
        RaceMessageDisplay__setMessage(m, "@GT4_meter_texture_wrongway", 0x1.9999980000000p-3f, 0.0f);
        break;
    }
    case 4:
        func_0039D9D8(self, D_00621870[84], 0);
        break;
    case 5:
        func_0039D9D8(self, D_00621870[85], 0);
        break;
    case 6:
        func_0039D9D8(self, D_00621870[86], 0);
        break;
    case 7:
        func_0039D9D8(self, D_00621870[87], 1);
        break;
    case 8:
        func_0039D9D8(self, D_00621870[88], 1);
        break;
    case 9:
        func_0039D9D8(self, D_00621870[89], 1);
        break;
    case 10:
        func_0039D9D8(self, D_00621870[90], 0);
        break;
    case 11:
        func_0039D9D8(self, D_00621870[91], 1);
        break;
    case 12:
        func_0039D9D8(self, D_00621870[92], 1);
        break;
    case 15:
        func_0039D9D8(self, D_00621870[5], 0);
        break;
    case 0:
    default:
        break;
    }
}
