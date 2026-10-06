struct Table { char pad[0xCBF8]; float value; };
struct A { int x0; Table *table; };
extern int func_003447F8(float);
int func_00344748(A *a)
{
    return func_003447F8(a->table->value);
}
