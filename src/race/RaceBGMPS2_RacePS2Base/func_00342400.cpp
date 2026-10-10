struct Buffer {
    char data[0x3C];
};

struct DoubleBuffer {
    Buffer buf[2];
    int cur;
};

extern DoubleBuffer D_0061850C;
extern "C" void func_003423B0(Buffer *b, void *arg);

extern "C" void func_00342400(void *arg)
{
    DoubleBuffer *db = &D_0061850C;
    func_003423B0(&db->buf[db->cur], arg);
    func_003423B0(&db->buf[1 - db->cur], arg);
}
