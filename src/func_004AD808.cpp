/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Owner;
struct Task { char pad[0x38]; void (*callback)(Owner *); Owner *owner; };
struct Pool { int w; };
extern "C" Task *func_005750C0(Pool *pool, int size);
extern "C" void func_004AD018(Owner *o);

struct Owner {
    char pad[0x94];
    Task *task;
    Pool pool;
    char pad2[8];
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual int v03();
};

extern "C" void func_004AD808(Owner *self)
{
    self->task = func_005750C0(&self->pool, self->v03());
    self->task->owner = self;
    self->task->callback = func_004AD018;
}
