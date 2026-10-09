/* compiler: ee-gcc2.96-nosib */
/* The engine's allocation entry (440 callers): 4-byte aligned blocks go to the engine heap,
 * func_00326588, which takes only the size (align and name stay in $a1/$a2 untouched); any
 * other alignment goes to memalign (func_00575E60). */
void *func_00326588(unsigned int size);
void *func_00575E60(int align, unsigned int size);

void *func_00326750(unsigned int size, int align, const char *name)
{
    if (size == 0)
        return 0;
    if (align == 4)
        return func_00326588(size);
    return func_00575E60(align, size);
}
