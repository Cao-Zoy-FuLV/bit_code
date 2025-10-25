#include <stdio.h>
int main() {
	float a = 0; float b = 0;
	while (1)
	{
		printf("体重/kg=");
		fflush(stdout);
		scanf("%f", &a);
		printf("身高/cm=");
		fflush(stdout);
		scanf("%f", &b);
		float blm = a / (b / 100.0) / (b / 100.0);
		printf("%f\n", blm);
		fflush(stdout);
	}
	return 0;
}