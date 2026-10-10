struct Display;
struct Face {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(int arg); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual Display *v24(int id);
};

struct Display : Face {
    int id;
};

extern "C" void RaceSplitDisplay__virtual_13(Display *self, int arg)
{
    self->v24(self->id)->v13(arg);
}
