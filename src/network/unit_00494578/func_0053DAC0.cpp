/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long func_0053DAC0_Addr __attribute__((aligned(4)));

struct func_0053DAC0_Conn {
    char pad0[0xC];
    unsigned int state;
    char pad10[0x203C - 0x10];
    int small;
    int retried;
};

struct func_0053DAC0_Self {
    char pad0[0x18];
    int arg;
    func_0053DAC0_Addr addr;
    int port;
    char pad28[0x44 - 0x28];
    func_0053DAC0_Conn *conn;
};

typedef void (*func_0053DAC0_Cb)(void);

extern "C" void func_0053DD68(void);
extern "C" void func_0053DDC8(void);
extern "C" void func_0053DE18(void);
extern "C" void func_0053DE78(void);
extern "C" void func_0053DED0(void);
extern "C" void func_0053DF20(void);
extern "C" void func_0053DF70(void);
extern "C" int func_0053E380(func_0053DAC0_Self *self, func_0053DAC0_Cb cb);
extern "C" int func_0053E588(func_0053DAC0_Self *self, int size, func_0053DAC0_Cb cb);
extern "C" int func_0053E810(func_0053DAC0_Self *self, int size, func_0053DAC0_Cb cb);
extern "C" int func_0053E8D0(func_0053DAC0_Self *self, int size, func_0053DAC0_Cb cb);
extern "C" int func_0053E990(func_0053DAC0_Self *self, int size, func_0053DAC0_Cb cb);
extern "C" int func_0053EA50(func_0053DAC0_Self *self, int size, int arg, func_0053DAC0_Cb cb);
extern "C" int func_0053ECE8(func_0053DAC0_Self *self, func_0053DAC0_Addr addr, int port, func_0053DAC0_Cb cb);

extern "C" int func_0053DAC0(func_0053DAC0_Self *self) {
    int err = 0;
    switch (self->conn->state) {
    case 0:
    case 1:
        break;
    case 2:
        err = func_0053E380(self, func_0053DD68);
        if (err == 0) self->conn->state = 1;
        else self->conn->state = 8;
        break;
    case 3:
        if (self->conn->small == 0) err = func_0053E588(self, 0x1000, func_0053DDC8);
        else err = func_0053E588(self, 0x800, func_0053DDC8);
        if (err == 0) self->conn->state = 1;
        else self->conn->state = 8;
        break;
    case 4:
        if (self->conn->small == 0) err = func_0053E810(self, 0x1000, func_0053DE18);
        else err = func_0053E810(self, 0x800, func_0053DE18);
        if (err == 0) self->conn->state = 1;
        else self->conn->state = 8;
        break;
    case 5:
        if (self->conn->small == 0) err = func_0053E8D0(self, 0x1000, func_0053DE78);
        else err = func_0053E8D0(self, 0x800, func_0053DE78);
        if (err == 0) self->conn->state = 1;
        else self->conn->state = 8;
        break;
    case 6:
        if (self->conn->small == 0) err = func_0053E990(self, 0x1000, func_0053DED0);
        else err = func_0053E990(self, 0x800, func_0053DED0);
        if (err != 0) self->conn->state = 8;
        else self->conn->state = 1;
        break;
    case 7:
        if (self->conn->small == 0) err = func_0053EA50(self, 0x1000, self->arg, func_0053DF20);
        else err = func_0053EA50(self, 0x800, self->arg, func_0053DF20);
        if (err != 0) {
            func_0053DAC0_Conn *c = self->conn;
            if (c->retried == 0) {
                c->state = 6;
                c->retried = 1;
            } else {
                c->state = 8;
            }
        } else {
            self->conn->state = 1;
        }
        break;
    case 8:
        err = func_0053ECE8(self, self->addr, self->port, func_0053DF70);
        if (err == 0) {
            self->conn->state = 1;
        } else {
            if (self->conn != 0) self->conn->state = 0;
        }
        break;
    }
    return err;
}
