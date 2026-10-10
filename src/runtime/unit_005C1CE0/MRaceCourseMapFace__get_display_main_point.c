/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0068E760;
extern void func_005C4A40(int a0, int a1, int a2, int a3, Pmf m);

void MRaceCourseMapFace__get_display_main_point(int a0, int a1, int a2, int a3) {
    func_005C4A40(a0, a1, a2, a3, D_0068E760);
}
