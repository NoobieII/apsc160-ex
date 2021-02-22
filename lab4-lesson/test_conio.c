//find the values returned by getch

#include <stdio.h>
#include <stdlib.h>

#include <conio.h>

int main(void){
	int input;
	
	while(true){
		input = getch();
		printf("%d\n", input);
	}
	
	return 0;
}
