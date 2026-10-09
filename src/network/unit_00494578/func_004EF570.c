void *func_00575E60(int, int);
int func_0056F9B8(void *, int, int, int);
void func_0056FB10(void *, void *);

typedef struct {
    char data[0x3C];
} Codec;

typedef struct {
    int started;
    Codec in;
    Codec out;
    void *in_buffer;
    void *out_buffer;
    int size;
    int param1;
    int param2;
} Stream;

int func_004EF570(Stream *s) {
    if (s->started) {
        return 0;
    }
    s->started = 1;
    s->in_buffer = func_00575E60(0x40, s->size);
    s->out_buffer = func_00575E60(0x40, s->size);
    func_0056F9B8(&s->in, s->size, s->param1, s->param2);
    func_0056F9B8(&s->out, s->size, s->param1, s->param2);
    func_0056FB10(&s->in, s->in_buffer);
    return 1;
}
