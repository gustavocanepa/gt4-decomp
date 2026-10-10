struct Sub { int w; };
struct Item { char pad[0x54]; Sub sub; };
extern "C" char D_006A1458[];
extern "C" void RaceMessageDisplay__setMessage(Item *self, const char *name, float x, float y);
extern "C" void RaceMessageDisplay__show(Item *self, float a, float b);
extern "C" void AutomaticFader__reset(Sub *s);

extern "C" void RaceMessageDisplay__clear(Item *self)
{
    RaceMessageDisplay__setMessage(self, D_006A1458, 0.0f, 0.0f);
    RaceMessageDisplay__show(self, -1.0f, 0.0f);
    AutomaticFader__reset(&self->sub);
}
