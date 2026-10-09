
extern int func_00538B08();
extern void func_005A48D8(int arg0, int arg1, long long arg2);
extern int func_00538BF8(int *arg0, int arg1)
{
  long long new_var;
  int var_v0 = 0x64;
  new_var = arg1;
  if (arg0 != 0)
  {
    *arg0 = 0;
    var_v0 = func_00538B08();
    if (var_v0 == 0)
    {
      int temp_v0 = *arg0;
      if (temp_v0 != 0)
      {
        long long se = (long long) ((int) new_var);
        func_005A48D8(temp_v0, 0, se);
        return 0;
      }
      var_v0 = 0x64;
    }
  }
  return var_v0;
}
