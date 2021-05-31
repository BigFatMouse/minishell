#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int id = fork(); 
	int n;
	
	
	// if (id == 0)
	// {
	// 	printf("child proccess id = %d\n", id);
	// 	int id2 = fork();
	// 	if (id2 == 0)
	// 		printf("child proccess id = %d\n", id2);
	// 	else 
	// 		printf("main proccess id = %d\n", id2);
	// }
	// else 
	// 	printf("main proccess id = %d\n", id);

	if (id == 0)
		n = 1;
	else 
	{
		n = 6;
		wait();
	}

	int i;
	for(i = n; i < n + 5; i++)
	{
		//char c = i + 48;
		//write(1, &c, 1);
		printf("%d ", i);
		fflush(stdout);
	}
	//printf("\n");
	return(0);
}