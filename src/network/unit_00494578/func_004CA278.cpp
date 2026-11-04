struct Msg { unsigned char *data; int type; };

static inline bool is_type(Msg *m) { return m->type == 0x20; }
static inline int get16(unsigned char *p) { return (p[1] << 8) | p[0]; }
/* the signed '> 0' keeps 'andi 0x80' on the whole value; '!= 0' lets combine
   narrow the test to a 'dsrl 7' of the low byte */
static inline bool valid(int v) { return (v & 0x80) > 0; }

int func_004CA278(Msg *m)
{
    if (!is_type(m)) return -1;
    int v = get16(m->data + 0x28);
    if (!valid(v)) return -1;
    return v & 0xF;
}
