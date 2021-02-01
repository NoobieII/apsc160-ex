/*PUT YOUR COMMENTS HERE SUCH AS YOUR NAME AND THE DATE!
 *
 *Convert inches to metres
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	float a1, a2;
	
	printf("Enter the number of inches to convert to metres: ");
	scanf("%f", &a1);
	
	a2 = a1 * 25.4 / 1000.0;
	printf("%.2f inches = %.3f metres.\n", a1, a2);
	
	return 0;
}
