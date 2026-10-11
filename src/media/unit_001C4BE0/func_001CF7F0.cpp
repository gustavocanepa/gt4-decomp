extern "C" void free(void *p);

struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
};

struct Buffer {
    Alloc alloc;
    char *start;
    char *finish;
    char *end_of_storage;
    Buffer(const Alloc &a = Alloc()) : alloc(a), start(0), finish(0), end_of_storage(0) {}
    ~Buffer() { if (start) free(start); }
    unsigned int size() const { return finish - start; }
};

extern "C" void func_001CF8D0(int arg0, int arg1, Buffer *buf);

extern "C" unsigned int func_001CF7F0(int arg0, int arg1) {
    Buffer buf;
    func_001CF8D0(arg0, arg1, &buf);
    return (buf.size() + 0x3FF) >> 10;
}
