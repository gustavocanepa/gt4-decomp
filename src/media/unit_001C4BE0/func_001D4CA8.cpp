extern "C" void func_001D4C68(void *a, unsigned int from, void *c, unsigned int to, int n);

extern "C" void func_001D4CA8(void *a, unsigned int from, void *c, unsigned int to, float t)
{
    func_001D4C68(a, from, c, to, (int)(t * (float)(from - to)));
}
