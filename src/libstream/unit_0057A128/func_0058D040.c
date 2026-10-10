/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;

typedef struct {
    unsigned int word;
    u8 flags;
} Status;

extern u8 D_00657ACE;

int func_0058CE48(void);
void func_005ADD50(Status *st);
int func_005ADFB0(u8 *p, int a, int b);

int func_0058D040(void)
{
    Status st;
    int ret;

    if (func_0058CE48()) {
        ret = D_00657ACE;
    } else {
        func_005ADD50(&st);
        if (((st.word >> 13) & 7) == 0) {
            ret = 0;
        } else {
            func_005ADFB0(&st.flags, 1, 1);
            ret = (st.flags >> 4) & 1;
        }
    }
    return ret;
}
