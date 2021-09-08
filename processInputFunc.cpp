#include "processInputFunc.h"



void processInput()
{
    if (g_goToLeft)
    {
        g_horShift -= HOR_MOVE_STEP_PER_SEC;
    }
    else if (g_goToRight)
    {
        g_horShift += HOR_MOVE_STEP_PER_SEC;
    }
    if (g_goToUp)
    {
        g_verShift += VER_MOVE_STEP_PER_SEC;
    }
    else if (g_goToDown)
    {
        g_verShift -= VER_MOVE_STEP_PER_SEC;
    }
    if (g_doIncrease)
    {
        g_viewportScale *= c_incDecStepPerSec;
    }
    else if (g_doDecrease)
    {
        g_viewportScale /= c_incDecStepPerSec;
    }
}
