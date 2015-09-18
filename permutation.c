#include <stdio.h>
#include <unistd.h>

int array[256];

void recurse_permutation(int cur, int max)
{
    int i;
    int j;

    if(cur > max) {
        for (i = 0; i < max; i++) printf("%d ", array[i]);
        printf("\n");
        return;
    }

    for(i = 0; i < cur; i++) {
        for(j = cur; j > i ; j--) {
            array[j] = array[j - 1];
        }
        array[i] = cur;
        recurse_permutation(cur + 1, max);
        for(j = i; j < cur; j++) {
            array[j] = array[j + 1];
        }
    }
}

int main()
{
    recurse_permutation(1, 10);
    return 0;
}
