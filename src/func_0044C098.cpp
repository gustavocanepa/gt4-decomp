typedef unsigned char u8;
typedef unsigned int u32;

struct BigNum {
    u8 *data;
    u32 size;
};

extern "C" BigNum *func_0044C098(BigNum *self, const BigNum *o) {
    u32 carry = 0;
    for (u32 i = 0; i < self->size; i++) {
        u32 sum = carry + self->data[i] + o->data[i];
        self->data[i] = sum;
        carry = sum >> 8;
    }
    return self;
}
