typedef struct Range {
    int start;
    int index;
    int count;
} Range;

extern void func_0045B490(Range *r, int a);
extern void func_0045B310(Range *r, int b);

Range func_0045B4D8(int a, int b)
{
    Range r;
    r.index = -1;
    r.count = 0;
    r.start = 0;
    func_0045B490(&r, a);
    func_0045B310(&r, b);
    return r;
}
