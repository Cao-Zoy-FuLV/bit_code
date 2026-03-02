#pragma once
#include <iostream>
#include <iomanip>

class myclock
{
public:
	myclock();
	void run();
	void show();
	void tick();
private:
	int h;
	int m;
	int s;
};

