struct Clock {
    unsigned char stat;
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char pad;
    unsigned char day;
    unsigned char month;
    unsigned char year;
};

struct Tm {
    int data[4];
};

extern "C" void func_00549708(Tm *tm, const Clock *clock);
extern "C" long long func_00579B60(Tm *tm);
extern "C" int func_0058D480(Clock *clock);
extern long long D_0064C8B0;

extern "C" void func_005524B8(void) {
    Clock clock;
    clock.stat = 0;
    clock.second = 0;
    clock.minute = 0;
    clock.hour = 9;
    clock.pad = 0;
    clock.day = 2;
    clock.month = 1;
    clock.year = 1;
    Tm base;
    func_00549708(&base, &clock);
    long long t0 = func_00579B60(&base);
    func_0058D480(&clock);
    Tm now;
    func_00549708(&now, &clock);
    long long t1 = func_00579B60(&now);
    D_0064C8B0 = t1 - t0;
}
