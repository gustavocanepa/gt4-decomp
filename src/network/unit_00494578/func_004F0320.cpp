extern "C" {
void func_004EFCC0(void *);
void func_004F8790(void *);
void free(void *);
void *func_005A48D8(void *, int, unsigned int);
void func_004F94F8(void *);
void func_004F8CC8(void *);
int func_00579358(void);
void func_004F8D00(void *);
void func_004FAE18(void *);
}

/* The polymorphic 0x1010-byte log object of func_004F0F50 (constructor func_0060EBF0). */
struct func_0060EBF0 {
    char data[0x100C];
    func_0060EBF0();
    virtual ~func_0060EBF0();
};

struct Queue {
    int head;
    int tail;
    int count;
};

#define FIELD(type, off) (*(type *)((char *)s + (off)))

extern "C" void func_004F0320(char *s) {
    Queue *q;
    Queue *r;

    FIELD(int, 0x3C) = 0;
    func_004EFCC0(s + 0x40);
    FIELD(int, 0x150) = 0;
    FIELD(int, 0x154) = 0;
    FIELD(int, 0x158) = 0;
    FIELD(int, 0x15C) = 0;
    FIELD(int, 0x164) = 0;
    FIELD(int, 0x160) = 0;
    FIELD(int, 0x168) = 0;
    func_004F8790(s);
    FIELD(int, 0x188) = 0;
    FIELD(int, 0x18C) = 0;
    FIELD(int, 0x190) = 0;
    if (FIELD(func_0060EBF0 *, 0x194) != 0) {
        delete FIELD(func_0060EBF0 *, 0x194);
        FIELD(func_0060EBF0 *, 0x194) = 0;
    }
    if (FIELD(void *, 0x5A8) != 0) {
        free(FIELD(void *, 0x5A8));
        FIELD(void *, 0x5A8) = 0;
    }
    func_005A48D8(s + 0x5AC, 0, 0x38);
    func_005A48D8(s + 0x5E4, 0, 0x454);
    func_005A48D8(s + 0xA38, 0, 0xC0);
    FIELD(char, 0xAF8) = 0;
    FIELD(int, 0xBA8) = -1;
    func_004F94F8(s);
    func_004F8CC8(s);
    func_005A48D8(s + 0xF64, 0, 0x54);
    FIELD(int, 0xF6C) = func_00579358();
    func_005A48D8(s + 0xFB8, 0, 0x24);
    func_005A48D8(s + 0xFDC, 0, 0x44);
    FIELD(int, 0xFDC) = -1;
    func_004F8D00(s);
    q = (Queue *)(s + 0x39A4);
    r = (Queue *)(s + 0x3BF4);
    q->head = 0;
    q->tail = 0;
    q->count = 0;
    r->head = 0;
    r->tail = 0;
    r->count = 0;
    func_004FAE18(s);
    FIELD(int, 0x3F3C) = 0;
    func_005A48D8(s + 0x3984, 0, 0x20);
    FIELD(int, 0x3F20) = 0;
    FIELD(int, 0x3FA0) = -1;
    FIELD(int, 0x3FA4) = -1;
    FIELD(int, 0x3F24) = 0;
    FIELD(char, 0x3F28) = 0;
    FIELD(int, 0x3F44) = 0;
    FIELD(int, 0x3F68) = 0;
    FIELD(int, 0x3F9C) = 0;
    FIELD(int, 0x3FA8) = -1;
}
