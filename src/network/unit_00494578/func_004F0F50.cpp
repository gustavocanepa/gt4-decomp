/* compiler: ee-gcc2.96-nsa-nosib */
extern "C" {
void func_00576788(void *);
void func_005767C0(void *);
void *func_005A48D8(void *, int, unsigned int);
}

/* A 0x5B44-byte work area. */
struct WorkArea {
    char data[0x5B44];
};

/* A polymorphic 0x1010-byte object (vtable pointer last); its constructor is func_0060EBF0, named
   after it so the mangled __13func_0060EBF0 resolves. */
struct func_0060EBF0 {
    char data[0x100C];
    func_0060EBF0();
    virtual ~func_0060EBF0();
};

struct Session {
    int pad0[2];
    char lock[0x160];
    int enabled;
    char pad16C[0x190 - 0x16C];
    int log_count;
    func_0060EBF0 *log;
    char pad198[0x5A8 - 0x198];
    WorkArea *work;
};

extern "C" void func_004F0F50(Session *self, int enabled) {
    func_00576788(self->lock);
    self->enabled = enabled;
    if (enabled) {
        if (self->work == 0) {
            self->work = new WorkArea;
            func_005A48D8(self->work, 0, sizeof(WorkArea));
        }
        if (self->log == 0) {
            self->log = new func_0060EBF0;
            self->log_count = 0;
        }
    } else {
        if (self->work != 0) {
            delete self->work;
            self->work = 0;
        }
        if (self->log != 0) {
            delete self->log;
            self->log = 0;
        }
    }
    func_005767C0(self->lock);
}
