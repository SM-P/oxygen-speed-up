#pragma once
#include "oxygine-include.h"

#define ADRIEN

namespace oxygine
{
    class UpdateState
    {
    public:
#if defined(ADRIEN)
        UpdateState(): time(0), dt(0), iteration(0), dtf(0), prev_time(0), prev_dt(0), prev_iteration(0), prev_dtf(0) {}   
#else
        UpdateState(): time(0), dt(0), iteration(0), dtf(0) {}
#endif
        /**local time in  milliseconds*/
        timeMS time;

        /**local time in  seconds*/
        float timef;

        /**delta time since last update in milliseconds*/
        timeMS dt;

        /*delta time since last update in seconds*/
        float dtf;

        /**current iteration, used with fixed Clock update */
        int iteration;

#if defined (ADRIEN)
        timeMS prev_time;

        /**local time in  seconds*/
        float prev_timef;

        /**delta time since last update in milliseconds*/
        timeMS prev_dt;

        /*delta time since last update in seconds*/
        float prev_dtf;

        /**current iteration, used with fixed Clock update */
        int prev_iteration;
#endif
    };
}