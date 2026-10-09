struct Table { char pad[0xCBF8]; float value; };
struct A { int x0; Table *table; };
extern int func_00344798(float);
int func_00344720(A *a)
{
    return func_00344798(a->table->value);
}
