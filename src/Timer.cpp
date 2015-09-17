#include "Timer.h"
#include <time.h>

Timer::Timer(void)
{
	ticks = 0;
}

Timer::~Timer(void)
{

}

void Timer::start()
{
	ticks = (unsigned int)clock();
	
}

unsigned int Timer::getSec()
{
	return (unsigned int)((unsigned int)clock() - ticks)/CLOCKS_PER_SEC;
}

unsigned int Timer::getMSec()
{
	unsigned long now = (unsigned int)clock() - ticks;
	double d = (double)now / CLOCKS_PER_SEC;
	unsigned int n = (unsigned int)(d * 1000);
	return n;
}
