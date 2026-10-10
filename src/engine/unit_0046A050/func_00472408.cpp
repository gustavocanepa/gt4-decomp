struct func_00472408_Blend {
    int a;
    int b;
    int c;
    int d;
    int e;
};

extern "C" void func_00472408(func_00472408_Blend *s, unsigned int mode) {
    switch (mode) {
    case 1:
    case 8:
    case 9:
    case 10:
        s->a = 0;
        s->b = 0;
        s->c = 0;
        s->d = 0;
        s->e = 0;
        break;
    case 2:
        s->a = 1;
        s->b = 1;
        s->c = 1;
        s->e = 1;
        s->d = 0;
        break;
    case 3:
        s->c = 0;
        s->d = 0;
        s->a = 1;
        s->b = 2;
        s->e = 3;
        break;
    case 4:
        s->d = 1;
        s->a = 0;
        s->b = 3;
        s->c = 0;
        s->e = 3;
        break;
    case 5:
        s->b = 0;
        s->c = 0;
        s->d = 3;
        s->e = 3;
        s->a = 0;
        break;
    case 6:
        s->a = 0;
        s->c = 0;
        s->b = 5;
        s->d = 2;
        s->e = 3;
        break;
    case 7:
    case 11:
        s->b = 5;
        s->a = 0;
        s->c = 0;
        s->d = 0;
        s->e = 3;
        break;
    case 0:
    default:
        s->a = 0;
        s->d = 0;
        s->b = 4;
        s->c = 2;
        s->e = 0;
        break;
    }
}
