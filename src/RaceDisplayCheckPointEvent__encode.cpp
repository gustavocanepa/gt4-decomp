struct Event {
    int lap;
    int pad4;
    int time;
    int point;
};

static inline int clamp(int v, int lo, int hi) { return v < lo ? lo : (v > hi ? hi : v); }

struct Packed {
    unsigned int lap : 4;
    unsigned int point : 4;
    unsigned int time : 10;
    unsigned int rest : 14;
};

union Word {
    Packed p;
    unsigned int w;
};

extern "C" unsigned int RaceDisplayCheckPointEvent__encode(Event *e, int unused, unsigned int w) {
    Word u;
    u.w = w;
    int lap = clamp(e->lap, 0, 15);
    u.p.lap = lap;
    int point = clamp(e->point, 0, 15);
    u.p.point = point;
    int time = clamp(e->time, 0, 999);
    u.p.time = time;
    return u.w;
}
