#pragma once

class Timer
{
	unsigned long ticks;
public:
	Timer(void);
	~Timer(void);

	void start();
	unsigned int getSec();
	unsigned int getMSec();
};

