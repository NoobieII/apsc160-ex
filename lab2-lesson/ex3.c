//Example 3 (Example 1 with a switch statement)

//move a coordinate in one direction according to the key pressed.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
	char input;
	int success = 1;
	int x = 0;
	int y = 0;
	
	printf("Your current coordinate is (%d, %d).\n", x, y);
	printf("Press one of W, A, S or D to move the point.\n");
	
	//this function reads a key press in the console window.
	//warning: this code is not portable!
	input = getch();
	
	//move up, left, down or right, respectively
	switch(input){
	case 'w': y -= 10;
		break;
	case 'a': x -= 10;
		break;
	case 's': y += 10;
		break;
	case 'd': x += 10;
		break;
	default: success = 0;
		break;
	}
	
	if(success){
		printf("Your coordinate is now (%d, %d).\n", x, y);
	}
	else{
		printf("An invalid key was pressed.\n");
	}
	
	return 0;
}
