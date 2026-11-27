/* RaceSolitaire::prepareLogger: gives the input logger its buffer once (size still 0).
 * Normal builds take the buffer from the logger stream itself; with the debug switch
 * RaceSolitaire__disable_logger_ set, the size is the smallest of three free-memory readings and the buffer
 * sits at the fixed address 0x1C2000. The three readings are sorted in place (three
 * compare-and-swap steps) and the first one is used: the third step only orders values
 * nobody reads, but it keeps the swap temporaries alive until register allocation, which
 * is why retail has real branches (sltu + bnel + move) instead of conditional moves. */
struct Stream { char b[0x80]; };
struct Log { char b[0x1E0]; };
struct Self {
    char pad0[0xE84C];
    Log logA;               /* 0xE84C */
    Log logB;               /* 0xEA2C */
    char padEC0C[0xF058 - 0xEC0C];
    Stream stream;          /* 0xF058 */
    int argA;               /* 0xF0D8 */
    int padF0DC;
    int argB;               /* 0xF0E0 */
    int padF0E4[2];
    unsigned size;          /* 0xF0EC */
    void *addr;             /* 0xF0F0 */
};
extern int RaceSolitaire__disable_logger_;
extern "C" void *func_003BDA98(Stream *);
extern "C" unsigned func_00578CB0(void *);
extern "C" unsigned func_003ED9F0(void);   /* declared unsigned here: the readings are compared unsigned (sltu) */
extern "C" void func_003BDAB0(Stream *, unsigned, void *);
extern "C" void func_003EA068(Log *, int);

extern "C" void RaceSolitaire__prepareLogger(Self *self)
{
    if (self->size != 0)
        return;
    if (RaceSolitaire__disable_logger_ == 0) {
        self->addr = func_003BDA98(&self->stream);
        self->size = func_00578CB0(self->addr);
    } else {
        unsigned a = func_003ED9F0();
        unsigned b = func_003ED9F0();
        unsigned c = func_003ED9F0();
        unsigned t;
        if (b < a) { t = a; a = b; b = t; }
        if (c < a) { t = a; a = c; c = t; }
        if (c < b) { t = b; b = c; c = t; }
        self->size = a;
        self->addr = (void *)0x1C2000;
    }
    func_003BDAB0(&self->stream, self->size, self->addr);
    func_003EA068(&self->logA, self->argA);
    func_003EA068(&self->logB, self->argB);
}
