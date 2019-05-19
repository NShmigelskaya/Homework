#include "Time.h"
#include <iostream>

namespace engine
{
    float Time::dTime = 0;

    std::chrono::time_point<std::chrono::_V2::system_clock> Time::prevTime = std::chrono::system_clock::now();

    Time::Time()
    {
    }

    void Time::update()
    {
        auto currentTime = std::chrono::system_clock::now();
        dTime = (currentTime - prevTime).count();
        prevTime = currentTime;
    }
}
