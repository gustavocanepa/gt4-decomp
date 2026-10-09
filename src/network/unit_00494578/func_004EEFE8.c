void func_004EF9F0(void *, int);
int func_004EF6B0(void *, int);
int func_004EF708(void *, void *, int);
int func_004EF9A0(void *, int);

typedef struct {
    int open;
    int pad[0x24];
    int state;
    int busy;
} Device;

int func_004EEFE8(Device *dev, int mode) {
    char reply[0x10];

    if (dev->open == 0) {
        return 0;
    }
    if (dev->busy != 0) {
        return 1;
    }
    func_004EF9F0(dev, 0);
    if (func_004EF6B0(dev, mode) < 0) {
        return 0;
    }
    if (func_004EF708(dev, reply, 2) < 0) {
        return 0;
    }
    if (func_004EF9A0(dev, 0) < 0) {
        return 0;
    }
    dev->state = 0;
    return 1;
}
