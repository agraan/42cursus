#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *ptr = malloc(1);
	printf("%-100p\n", ptr);
}
