struct Pt { float v[6]; };
struct Shape { char pad[2]; signed char nLines; char pad3; Pt pts[24]; signed char lines[1][2]; };
extern "C" void func_004A70E8(Pt *, Pt *);

extern "C" void func_00457568(Shape *s)
{
    for (int i = 0; i < s->nLines; i++)
        func_004A70E8(&s->pts[s->lines[i][0]], &s->pts[s->lines[i][1]]);
}
