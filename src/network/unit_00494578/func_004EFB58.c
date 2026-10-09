int func_004EFA68(void);
void func_00577F80(void);
void func_00574D78(void *);
void func_00574DA8(void *, int);
void func_00574EB0(void *);
void func_00574EE8(void *);
void func_00576788(void *);
void func_005767C0(void *);

extern int D_006454DC;

typedef struct Waiter {
    struct Waiter *next;
    char event[0x3C];
} Waiter;

typedef struct {
    char pad[0x38];
    char event[0x30];
    char lock[0x30];
    Waiter *waiters;
    char pad9C[0x214 - 0x9C];
    int running;
} Device;

void func_004EFB58(Device *dev) {
    int ok = 1;

    while (!func_004EFA68()) {
        if (!dev->running) {
            ok = 0;
            break;
        }
        func_00577F80();
    }
    if (ok) {
        Waiter waiter;
        int queued = 0;

        func_00574D78(waiter.event);
        func_00576788(dev->lock);
        if (dev->running) {
            waiter.next = dev->waiters;
            dev->waiters = &waiter;
            queued = 1;
            func_00574EE8(dev->event);
        }
        func_005767C0(dev->lock);
        D_006454DC = 0;
        if (queued) {
            func_00574EB0(waiter.event);
        }
        func_00574DA8(waiter.event, 2);
    }
}
