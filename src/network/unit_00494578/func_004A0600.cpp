
extern int func_004A02A0(volatile unsigned long arg0);
int func_004A0600(void)
{
  int a0 = 0x70000000;
  a0 |= 0x2000;
  return func_004A02A0(a0);
}
