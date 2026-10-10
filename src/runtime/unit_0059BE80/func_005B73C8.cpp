/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;

extern "C" u32 *func_005B73C8(u32 *p, u32 *end, u32 v) {
    while (*p != v && p < end)
        p++;
    return p < end ? p : 0;
}
