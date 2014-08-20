#include "OVR_CAPI.h"
#include "Kernel/OVR_Math.h"
#include <iostream>
#include <unistd.h>
#include <curses.h>

class Rift{
  public:
    Rift();
    ~Rift();
    void Output();

  private:
    ovrHmd hmd;
    ovrHmdDesc hmdDesc;
    ovrFrameTiming frameTiming;
};
