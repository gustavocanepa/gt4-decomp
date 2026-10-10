/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long func_00536158_Addr __attribute__((aligned(4)));

struct func_00536158_Slot {
    unsigned char state;
    char pad1[3];
    func_00536158_Addr addr;
    int port;
    char timer[8];
    int user;
    void (*callback)(int code, char *name, int user);
};

struct func_00536158_Net {
    char pad0[0x28];
    int (*handle)(void);
    char pad2C[0x38 - 0x2C];
    int (*poll)(int *result, func_00536158_Addr addr, int port);
};

struct func_00536158_Util {
    char pad0[0x7C];
    void (*format)(char *buf, func_00536158_Addr addr);
};

extern int D_0064B4EC;
extern func_00536158_Net *D_0064B4A8;
extern func_00536158_Util *D_0064B4B0;
extern func_00536158_Slot D_00868848[];

extern "C" int func_00535780(int handle);
extern "C" int func_0053A878(void *timer);
extern "C" int func_0053A890(void *timer, unsigned int *elapsed);

extern "C" int func_00536158(int notify) {
    func_00536158_Slot *s;
    unsigned int i;
    int r;
    if (D_0064B4EC == 0) return 0;
    r = func_00535780(D_0064B4A8->handle());
    if (r != 0) return r;
    s = D_00868848;
    for (i = 0; i < 0x100; i++, s++) {
        char name[16];
        int result;
        unsigned int elapsed;
        int done = 0;
        int code = 0;
        D_0064B4B0->format(name, s->addr);
        switch (s->state) {
        case 0:
            break;
        case 1: {
            result = 0;
            if (D_0064B4A8->poll(&result, s->addr, s->port) == 0 && result == 1) {
                func_0053A878(s->timer);
                s->state = 2;
            }
            break;
        }
        case 2: {
            func_0053A890(s->timer, &elapsed);
            if (elapsed <= 10000) break;
            s->state = 4;
        }
        case 4:
            if (notify) {
                s->user = 0;
                code = 14;
                done = 1;
            }
            break;
        case 3:
            if (notify) {
                code = 0;
                done = 1;
            }
            break;
        default:
            s->state = 0;
            break;
        }
        if (done) {
            if (s->callback != 0) {
                s->callback(code, name, s->user);
                s->callback = 0;
            }
            s->state = 0;
        }
    }
    return 0;
}
