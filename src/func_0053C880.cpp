struct func_0053C880_Conn {
    void *session;
    int handle;
    int user;
    int pad0C;
    char request[0x1024 - 0x10];
    int code;
    char body[0x2030 - 0x1028];
    int async;
    char pad2034[0x205C - 0x2034];
    void (*callback)(void *self, int err, int user, int status);
};

struct func_0053C880_Self {
    char pad0[0x3C];
    int busy;
    int pad40;
    func_0053C880_Conn *conn;
};

struct func_0053C880_Args {
    char name[12][0x100];
    char value[12][0x100];
    unsigned int count;
};

struct func_0053C880_Iface {
    char pad0[0x18];
    void (*release)(void *session);
};

extern func_0053C880_Iface *D_0064B4B0;
extern const char *D_0064C138[];
extern char D_0086B440[];

extern "C" int func_0053BD78(func_0053C880_Self *self, int *status);
extern "C" int func_00540F10(int handle, const char *name, int a, int b);
extern "C" int func_00540F98(int handle, void *out);
extern "C" void func_00540EB0(int handle);
extern "C" char *func_005A6AB0(char *dst, const char *src, unsigned int n);
extern "C" int func_00594470(const char *a, const char *b, unsigned int n);
extern "C" void *func_005A48D8(void *dst, int c, unsigned int n);
extern "C" int func_0053C2F0(func_0053C880_Self *self, const char *action, const char *args);
extern "C" void func_0053A878(void *request);

extern "C" int func_0053C880(func_0053C880_Self *self) {
    int status = 0;
    int state = 0;
    int err = func_0053BD78(self, &status);
    if (err != 0 || status != 0) {
        if (self->conn->code == 200 && status != 0) {
            int e;
            if (self->conn->async == 0) {
                char *value = 0;
                e = func_00540F10(self->conn->handle, "", 0, 1);
                if (e == 0) {
                    e = func_00540F98(self->conn->handle, &value);
                    if (e == 0) {
                        func_005A6AB0(D_0086B440, value, 0x100);
                    }
                }
            } else {
                func_0053C880_Args *args = 0;
                e = func_00540F10(self->conn->handle, "", 0, 1);
                if (e == 0) {
                    e = func_00540F98(self->conn->handle, &args);
                    if (e == 0) {
                        unsigned int i;
                        for (i = 0; i < args->count; i++) {
                            if (func_00594470("NewConnectionStatus", args->name[i], 0x100) == 0) {
                                func_005A6AB0(D_0086B440, args->value[i], 0x100);
                            }
                        }
                    }
                }
            }
            if (e == 0) {
                unsigned int i;
                for (i = 0; D_0064C138[i] != 0 && func_00594470(D_0086B440, D_0064C138[i], 0x100) != 0; i++) {
                }
                switch (i) {
                case 0: state = 0; break;
                case 1: state = 1; break;
                case 2: state = 2; break;
                case 3: state = 3; break;
                case 4: state = 4; break;
                case 5: state = 5; break;
                }
            } else {
                err = e;
            }
        }
        func_00540EB0(self->conn->handle);
        self->conn->handle = 0;
        D_0064B4B0->release(self->conn->session);
        self->conn->session = 0;
        func_005A48D8(&self->conn->code, 0, 0x100C);
        if (self->conn->async == 0) {
            if (err != 0) {
                err = func_0053C2F0(self, "GetStatusInfo", "");
                if (err == 0) {
                    func_0053A878(self->conn->request);
                } else {
                    self->conn->callback(self, err, self->conn->user, state);
                    self->conn->callback = 0;
                    self->busy = 0;
                }
            } else {
                self->conn->callback(self, 0, self->conn->user, state);
                self->conn->callback = 0;
                self->busy = 0;
            }
        } else {
            self->conn->callback(self, err, self->conn->user, state);
            self->conn->callback = 0;
            self->busy = 0;
        }
    }
    return err;
}
