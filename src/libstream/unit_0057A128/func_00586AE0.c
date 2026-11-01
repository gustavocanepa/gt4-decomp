/* compiler: ee-gcc2.9-991111 */
/* Checks a module header (either magic word) and counts its import stubs (pairs of words ending in
   0): each needs a 'j' (opcode 9) second word and a jr $ra (0x3E00008), 0x4D or jump first word,
   else -2. Testing p[0] and reloading code = p[0] in the body gives the load plus delay-slot copy. */
typedef unsigned int u32;
struct Hdr { u32 magic; u32 magic2; int p8; int pc; int p10; int p14; u32 *stubs; };
int func_00586AE0(struct Hdr *h)
{
    u32 *p;
    u32 code;
    int n;
    if (h->magic != 0x73587245 && h->magic2 != 0x427554)
        return -1;
    p = h->stubs;
    n = 0;
    while (*p) {
        code = *p;
        if ((p[1] >> 26) != 9 || (code != 0x4D && code != 0x3E00008 && (code >> 26) != 2))
            return -2;
        p += 2;
        n++;
    }
    return n;
}
