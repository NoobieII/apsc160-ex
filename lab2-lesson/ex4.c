//Example 4 (Example 2 with switch statement)

//A program that prompts the user for number of the month
//and prints the name of the month

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int month_number;
	
	printf("Enter a number between 1-12: ");
	scanf("%d", &month_number);
	
	//print the name of the month
	if(month_number > 0 && month_number < 13){
		printf("The name of the month is ");
	}
	
	switch(month_number){
	case 1: printf("January");
		break;
	case 2: printf("February");
		break;
	case 3: printf("March");
		break;
	case 4: printf("April");
		break;
	case 5: printf("May");
		break;
	case 6: printf("June");
		break;
	case 7: printf("July");
		break;
	case 8: printf("August");
		break;
	case 9: printf("September");
		break;
	case 10: printf("October");
		break;
	case 11: printf("November");
		break;
	case 12: printf("December");
		break;
	default: printf("This month %d does not exist.", month_number);
		break;
	}
	printf("\n");
	
	return 0;
}
	