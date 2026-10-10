# Hardware map: the layer a native port replaces (tools/hwmap.py, 2026-10-10)

Functions whose own instructions touch the PS2 hardware, by category (31,164 functions scanned):

| category | functions | what |
|---|---|---|
| spr | 201 | scratchpad RAM (0x70000000) |
| syscall | 166 | kernel calls (almost all in the SDK block at 0x59BE80) |
| sync | 146 | sync / ei / di / cache control |
| hwreg | 137 | EE hardware registers (DMA, VIF, GIF, timers at 0x1000xxxx; GS at 0x1200xxxx) |
| vu0 | 119 | VU0 macro-mode instructions (COP2) |

622 functions (2%) touch the hardware directly; the biggest cluster is one unit, `unit_00494578`
(196 scratchpad, 99 register, 77 VU0, 64 sync functions: the rendering back end), then the SDK's
kernel-call block (unit_0059BE80) and the network/IO libraries. Everything else reaches the
hardware only through these, so a port replaces a small, contiguous layer: the render back end
(VU0 maths can become plain C/SIMD), the SDK's kernel/SIF/DMA calls, and the scratchpad buffers
(ordinary memory on a PC). Run `python tools/hwmap.py --list vu0` (or another category) for the list.
