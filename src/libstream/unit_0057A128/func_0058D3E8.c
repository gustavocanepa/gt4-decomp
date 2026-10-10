/* compiler: ee-gcc2.9-991111 */
struct Time { unsigned char h, d, min; };
void func_0058D160(struct Time *);
void func_0058D390(struct Time *);
void func_0058D3C0(struct Time *);
void func_0058D1C8(struct Time *);

void func_0058D3E8(struct Time *t, int d)
{
    int m;
    func_0058D160(t);
    m = t->min + d;
    if (m >= 0) {
        while (m >= 60) {
            func_0058D390(t);
            m -= 60;
        }
    } else {
        while (m < 0) {
            m += 60;
            func_0058D3C0(t);
        }
    }
    t->min = m;
    func_0058D1C8(t);
}
