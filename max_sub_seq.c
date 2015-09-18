#include <stdio.h>
#include <unistd.h>

int max_sub_sequence(int data[], int len)
{
	int max = 0;
	int cur_max = 0;
	int i = 0;

	for (i = 0; i < len; i++) {
		cur_max += data[i];
		if (cur_max > max) max = cur_max;
		//if cur_max < 0, means the max sub seq should never includes it
		if (cur_max < 0) cur_max = 0;
	}

	return max;
}

int main()
{
	int data[] = {1, -3, 4, 20};
	
	printf("%d\n", max_sub_sequence(data, sizeof(data) / sizeof(data[0])));
	return 0;
}
