struct Tag { char c[8]; };
struct Desc {
    Tag type;
    Tag group;
    Tag name;
    int id;
    int m1C;
    int m20;
    int active;
};
extern "C" Tag D_00655878;
extern "C" Tag D_00655880;

extern "C" void func_005772E8(Desc *d, int id, const Tag *name)
{
    d->type = D_00655878;
    d->group = D_00655880;
    d->name = *name;
    d->active = 1;
    d->id = id;
    d->m20 = 0;
    d->m1C = 0;
}
