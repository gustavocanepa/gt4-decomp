extern void write(int, char *, int);
struct S { int a; char *p; int b; int c; };
void func_0057DBA0(struct S *s) {
    int n = s->c;
    if (n != 0) {
        s->p[n] = 0;
        write(1, s->p, s->c);
        s->c = 0;
    }
}
