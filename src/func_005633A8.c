struct Slot { int id; void *buf; };
extern struct Slot D_00874340[7];
void func_005627B8(void *buf);
void *func_005A48D8(void *dst, int c, unsigned int n); /* memset */

void func_005633A8(void)
{
    int i;

    for (i = 0; i < 7; i++)
        func_005627B8(D_00874340[i].buf);
    func_005A48D8(D_00874340, 0, sizeof(D_00874340));
}
