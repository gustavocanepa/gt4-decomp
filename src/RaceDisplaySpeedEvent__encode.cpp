struct Event {
    int lap;
    int pad4;
    float speed;
};

static inline int clamp(int v, int lo, int hi) { return v < lo ? lo : (v > hi ? hi : v); }

struct Packed {
    unsigned int lap : 4;
    unsigned int speed : 14;
    unsigned int rest : 14;
};

union Word {
    Packed p;
    unsigned int w;
};

extern "C" unsigned int RaceDisplaySpeedEvent__encode(Event *e, int unused, unsigned int w) {
    Word u;
    u.w = w;
    int lap = clamp(e->lap, 0, 15);
    u.p.lap = lap;
    int speed = clamp((int)(e->speed * 10.0f), 0, 9999);
    u.p.speed = speed;
    return u.w;
}
