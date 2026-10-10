extern "C" int func_00438340(int table, int key);

struct Obj {
    int m0;
    int table;
    int m8;
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual int v08(int entry, int arg);
};

extern "C" int func_00438588(Obj *self, int key, int arg)
{
    return self->v08(func_00438340(self->table, key), arg);
}
