/* push_back of a handle into the vector at +0x10 of an object (vector<Handle>::push_back inlined:
   copy-construct at finish, or _M_insert_aux func_005EC278 when full), returning a copy of it. */
typedef int s32;

struct Handle {
    s32 p;
};

struct HandleVector {
    s32 pad;
    Handle *start;
    Handle *finish;
    Handle *end_of_storage;
};

struct Obj {
    char pad0[0x10];
    HandleVector vec;
};

extern "C" void func_00309360(Handle *dst, Handle *src);
extern "C" void func_005EC278(HandleVector *v, Handle *pos, Handle *x);

extern "C" Handle *func_002EEEB0(Handle *ret, Obj *self, Handle *x)
{
    HandleVector *v = &self->vec;
    if (v->finish != v->end_of_storage) {
        if (v->finish)
            func_00309360(v->finish, x);
        v->finish++;
    } else {
        func_005EC278(v, v->finish, x);
    }
    func_00309360(ret, x);
    return ret;
}
