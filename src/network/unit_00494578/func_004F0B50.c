unsigned int func_0057F260(const char *);
int func_0060EAF0(void *, const char *, unsigned int);
void func_0060EBA0(void *, int);

typedef struct {
    int length;
    int pad;
    int used;
    char data[1];
} TextBuffer;

typedef struct {
    char pad[0x190];
    int count;
    TextBuffer *buffer;
} Writer;

void func_004F0B50(Writer *writer, const char *text) {
    TextBuffer *buffer = writer->buffer;
    if (buffer != 0) {
        unsigned int room = 0x1000 - buffer->used;
        if (room != 0) {
            unsigned int length = func_0057F260(text);
            func_0060EAF0(buffer, text, (length < room) ? length : (room - 1));
            buffer->data[buffer->length] = 0;
            func_0060EBA0(buffer, 1);
            writer->count++;
        }
    }
}
