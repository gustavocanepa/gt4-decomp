/* Copies the 10-byte name of database row `id` (func_004478B8) into out[] as
   ints, at most max and stopping at the first 0 byte; returns the count. The
   loop must test i < 10 in the for and the rest in an if/else break. */
struct Name { unsigned long long a; unsigned short b; };
extern "C" int func_004478B8(unsigned long long id, Name *out);
extern "C" int func_004478F8(unsigned long long id, int *out, int max) {
    Name row;
    if (out == 0) return 0;
    if (!func_004478B8(id, &row)) return 0;
    {
        union { Name n; unsigned char c[10]; } name;
        int n = 0;
        int i = 0;
        name.n.a = row.a;
        name.n.b = row.b;
        for (; i < 10; i++) {
            if (i < max && name.c[i]) {
                out[i] = name.c[i];
                n++;
            } else {
                break;
            }
        }
        return n;
    }
}
