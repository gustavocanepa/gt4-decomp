/* Copies a three-float vector from a to b, last component first. */
void func_005F5040(float *a, float *b)
{
    int i = 2;
    b[i] = a[i]; i--;
    b[i] = a[i]; i--;
    b[i] = a[i];
}
