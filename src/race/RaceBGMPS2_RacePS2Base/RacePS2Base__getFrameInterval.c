extern void PlayStation3__RenderLoopGetFlipCycle(void);
void RacePS2Base__getFrameInterval(void)
{
    PlayStation3__RenderLoopGetFlipCycle();
}
