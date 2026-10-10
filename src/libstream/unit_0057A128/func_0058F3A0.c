/* compiler: ee-gcc2.9-991111 */
typedef struct Buf {
    char pad[0x7C];
    int stamp;
} Buf;

typedef struct Slot {
    char pad[0x10];
    Buf *bufs;
    char pad2[0x334 - 0x14];
} Slot;

extern Slot D_0087FA80[];
extern void func_005AE598(void *start, void *end);

Buf *func_0058F3A0(int i)
{
    Buf *b[2];

    b[0] = D_0087FA80[i].bufs;
    b[1] = (Buf *)((char *)b[0] + 0x80);
    func_005AE598(b[0], (char *)b[0] + 0xFF);
    return b[b[0]->stamp < b[1]->stamp];
}
