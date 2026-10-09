char *strcpy(char *, const char *);
void *func_00575E60(int, int);
void func_00571D60(void *);

typedef struct {
    char ifc[0x100];
    char dev[0x100];
    char rest[0x1340 - 0x200];
} __attribute__((aligned(8))) NetcnfFiles;

typedef struct {
    NetcnfFiles *files;
} Netcnf;

/* Declared int with no return statement (as the original must have been): with void, the
   register allocator picks other registers for the inlined string copies. */
int func_004EE7C8(Netcnf *self) {
    self->files = func_00575E60(0x40, 0x1340);
    func_00571D60(self->files);
    strcpy(self->files->ifc, "ifc000.cnf");
    strcpy(self->files->dev, "dev000.cnf");
}
