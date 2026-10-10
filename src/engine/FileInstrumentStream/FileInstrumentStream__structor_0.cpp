/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

/* the base, named after its constructor so that __13func_004AFBF8 resolves */
struct func_004AFBF8 {
    char pad[0x18];
    func_004AFBF8();
};

extern "C" void func_0044D540();

struct Callback {
    void (*fn)();
    s32 arg;
    Callback() {}
    Callback(void (*f)(), s32 a) : fn(f), arg(a) {}
};

struct FileInstrumentStream : func_004AFBF8 {
    Callback cb;
    FileInstrumentStream();
    virtual ~FileInstrumentStream();
};

FileInstrumentStream::FileInstrumentStream() {
    cb = Callback(func_0044D540, 0);
}
