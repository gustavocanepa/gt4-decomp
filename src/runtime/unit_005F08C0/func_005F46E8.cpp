/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair8 { int a, b; };
typedef bool (*Cmp)(const Pair8 &, const Pair8 &);

extern "C" void func_005F46E8(Pair8 *last, Pair8 val, Cmp comp)
{
    Pair8 *next = last;
    --next;
    while (comp(val, *next)) {
        *last = *next;
        last = next;
        --next;
    }
    *last = val;
}
