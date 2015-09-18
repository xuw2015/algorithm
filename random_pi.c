#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	float pi;
	float x, y;
	int count = 9999999;
	int i;
	int in_count;

	srandom(getpid());

	i = in_count = 0;

	for ( i = 0; i < count; i++) {
		x = random() / (float)RAND_MAX;
		y = random() / (float)RAND_MAX;
		
		if (x*x + y*y <= (float)1.0)
			in_count++;
	}

	printf("%5.8f\n", in_count * (float )4.0 / count);

	return 0;
}
