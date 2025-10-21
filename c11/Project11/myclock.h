#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std; 
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

