struct Rec {
    long a[6];
};

struct List {
    int f0;
    int f4;
    Rec recs[10];
};

extern "C" void func_00433028(List *l, Rec *r, int idx)
{
    for (int i = 9; i > idx; i--) {
        l->recs[i] = l->recs[i - 1];
    }
    l->recs[idx] = *r;
}
