typedef int s32;

struct Obj {
    s32 count;
    s32 pos;
    s32 unk8;
    s32 error;
};

extern "C" bool func_0057CE78(Obj *, s32);

extern "C" bool func_0057CE80(Obj *o) {
    if (o->error != 0)
        return false;
    s32 n = o->count;
    if (o->pos >= n)
        return true;
    return !func_0057CE78(o, n - 1);
}
