#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("%zi", read(-28, NULL, 0));
}
