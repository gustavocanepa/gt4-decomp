struct Table { char pad[0xCBF8]; float value; };
struct A { int x0; Table *table; };
extern int func_00344828(float);
int func_00344770(A *a)
{
    return func_00344828(a->table->value);
}
