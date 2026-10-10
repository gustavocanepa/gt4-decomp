/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Source {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void *find(int id);
};

struct Ref {
    Source *src;
    int id;
    void *item;
};

extern "C" void func_004B2388(Ref *r, Source *s, int id)
{
    r->src = s;
    r->id = -1;
    r->item = 0;
    r->item = s->find(id);
    if (r->item)
        r->id = id;
}
