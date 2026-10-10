struct Event { int level; int pad; int kind; };
inline int clamp(int x, int lo, int hi) { return x < lo ? lo : (hi < x ? hi : x); }
extern "C" unsigned int RaceDisplayInformationEvent__virtual_01(Event *e, unsigned int flags)
{
    union { unsigned int raw; struct { unsigned int level : 4; unsigned int kind : 4; } b; } u; u.raw = flags; u.b.level = clamp(e->level, 0, 15); u.b.kind = e->kind; return u.raw;
}
