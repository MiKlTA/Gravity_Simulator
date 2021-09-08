#ifndef GLOBALVARS_H
#define GLOBALVARS_H



extern bool g_goToLeft;
extern bool g_goToRight;
extern bool g_goToUp;
extern bool g_goToDown;

extern float g_verShift;
extern float g_horShift;

extern bool g_doIncrease;
extern bool g_doDecrease;

extern float g_viewportScale;

extern int g_viewportWidth;
extern int g_viewportHeight;

#define ORTHO_WIDTH \
(g_viewportScale * (float(g_viewportWidth) / float(g_viewportHeight))) 
#define ORTHO_HEIGHT (g_viewportScale)

#define PIXEL_X_SIZE (ORTHO_WIDTH / float(g_viewportWidth))
#define PIXEL_Y_SIZE (ORTHO_HEIGHT / float(g_viewportHeight))

#define HOR_MOVE_STEP_PER_SEC (g_viewportScale * c_horMoveStepPerSec);
#define VER_MOVE_STEP_PER_SEC (g_viewportScale * c_verMoveStepPerSec);



// simulations settings



extern int g_objectsCount;

extern float g_areaSize;

extern float g_maxVelocity;

extern float g_minMass;
extern float g_maxMass;



#endif // GLOBALVARS_H
