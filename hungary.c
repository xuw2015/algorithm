#include <stdio.h>
#include <unistd.h>
#include <string.h>

int state[1024];
int result[1024];
int data[1024][1024];
int l,r;

int find(int l_pos)
{
	int j;

	for (j = 0; j < r; j++) {

		if (state[j]) continue;

		if (!data[l_pos][j]) continue;

		state[j] = 1;

		if (result[j] == -1 ||
			find(result[j])) {
			result[j] = l_pos;
			return 1;
		} else {
			printf("no find for %d\n", l_pos);
		}
	}

	return 0;
}

int hungary(void)
{
	int i;
	int lines;

	lines = 0;
	for (i = 0; i < l; i++) {
		bzero(state, sizeof(state));
		if (find(i)) {
			lines++;
		}
	}

	return lines;
	
}

void init(void)
{
	l=r=3;
	int template[3][3] = {
		{1, 0, 0},
		{1, 0, 0},
		{0, 0, 1}
	};

	int i,j;

	for (i = 0; i < l; i++)
		for (j = 0; j < r; j++)
			data[i][j] = template[i][j];

	for (i = 0; i < 1024; i++)
		result[i] = -1;
}

int main()
{
	init();
	printf("%d\n", hungary());
	return 0;
}
