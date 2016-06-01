#include <stdio.h>
#include <unistd.h> 

void ProgressBar()
{
	char arr[102] = {'\0'};
	char *imag = "|/-\\";
	int n = 100, i = 0;
	while (i <= n)
	{
		arr[i] = '=';
		printf("[%-100s][%d%%][%c]\r", arr, i, imag[i % 4]);
		fflush(stdout);
		i++;
		usleep(100000);
	}
	printf("\n");
}

int main()
{
	ProgressBar();

	return 0;
}
