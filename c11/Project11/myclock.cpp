#define _HAS_STD_BYTE 0
#include <windows.h>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "myclock.h"
myclock::myclock()
{
	std::time_t t = std::time(NULL);
	struct std::tm ti =* std::localtime(&t);
	h = ti.tm_hour;
	m = ti.tm_min;
	s = ti.tm_sec;	
}

void myclock::run()
{
	while (true)
	{
		show();//显示
		tick();//数据更新
	}
}

void myclock::show()
{
	system("cls");
	std::cout <<"时间";
	std::cout << std::setw(2) << std::setfill('0') << h << ":";
	std::cout << std::setw(2) << std::setfill('0') << m << ":";
	std::cout << std::setw(2) << std::setfill('0') << s << std::endl;
	std::cout.flush();
}

void myclock::tick()
{
	Sleep(1000);
	
	if (++s==60)
	{
		s = 0;
		if (++m==60)
		{
			m = 0;
			if (++h==24)
			{
				h = 0;
			}
		}
	}
}
