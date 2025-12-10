#include "myclock.h"

myclock::myclock()
{
	time_t t = time(NULL);
	struct tm ti =* localtime(&t);
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
	cout << setw(2) << setfill('0') << h << ":";
	cout << setw(2) << setfill('0') << m << ":";
	cout << setw(2) << setfill('0') << s ;
}

void myclock::tick()
{
	Sleep(1);
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
