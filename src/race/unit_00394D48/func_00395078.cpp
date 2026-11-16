/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Opens the course's ".ad" file (path built from the race spec of `id`) and
   copies the five words after its header into the object. The data pointer
   is read through the file handle again for every word, as in the original:
   without strict aliasing the reloads survive until after register
   allocation (postreload removes them), and those extra references are what
   give the handle pointer the lower saved register. */
typedef unsigned long u64;

struct Spec { char pad[0xB0]; };
struct Data { int f0; int v[5]; };
struct File { Data *data; char pad[0xC]; };
struct Obj { char pad[0x8C]; File file; int v[5]; };

extern char D_006A0340[];
extern "C" void func_00446F90(Spec *spec);
extern "C" int SPEC_DATABASE__RaceSpec__setCourse(Spec *spec, u64 id);
extern "C" int func_00447730(Spec *spec);
extern "C" char *func_00397868(u64 course, char *path);
extern "C" char *func_005A5DC8(char *dst, const char *src);
extern "C" int func_00407348(File *file, char *path, int a2, int a3);
extern "C" void func_00446FC8(Spec *spec, int flags);

extern "C" void func_00395078(Obj *self, u64 id) {
    Spec spec;
    char path[0x80];

    func_00446F90(&spec);
    SPEC_DATABASE__RaceSpec__setCourse(&spec, id);
    func_00397868((u64)(unsigned int)func_00447730(&spec), path);
    func_005A5DC8(path, D_006A0340);
    File *f = &self->file;
    func_00407348(f, path, 0, 0);
    self->v[0] = f->data->v[0];
    self->v[1] = f->data->v[1];
    self->v[2] = f->data->v[2];
    self->v[3] = f->data->v[3];
    self->v[4] = f->data->v[4];
    func_00446FC8(&spec, 2);
}
