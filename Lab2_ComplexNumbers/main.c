#include <stdio.h>
#include "complexNumber.h"

int main(void)
{
    printf("Doing stuff with complex numbers!\n\n");

    struct ComplexNumber* test_ComplexNumber;

    test_ComplexNumber = complexNumberConstructor(3.1415f, 3.1415f);

    printf(
           "Made a complex number with a real part [ %f ] and an imag part [ %f ] \n\r",
           complexNumber_GetReal(test_ComplexNumber),
           complexNumber_GetImag(test_ComplexNumber)
           );

    printf(
           "it has an magnitude of [ %f ] and an angle of [ %f rads ] \n\r",
           complexNumber_GetMag(test_ComplexNumber),
           complexNumber_GetAngle(test_ComplexNumber)
           );

    complexNumber_Display(test_ComplexNumber);
	printf("\n");


	printf("\nPRESS ANY KEY TO CONTINUE\n");
	getch();
    return 0;
}
