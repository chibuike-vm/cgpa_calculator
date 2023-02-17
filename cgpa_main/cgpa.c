#include <stdio.h>
#include "../cgpa_header/cgpa.h"
/**
 * main - Program Entry Point.
 *
 * Description: This is the program entry point function. Here, the program
 * requests for the nYrs int data type value.  Together with the cgpaFptr
 * function pointer, both are passed as arguements when calling the
 * cgpaGraduation function. The cgpaGraduation further calls back the cgpa
 * function (as a callback function) to execute its task.
 *
 * Return: This program returns the zero exit status upon successful execution.
 */
int main(void)
{
	printf("\n\n------UNIVERISTY CGPA CALCULATOR (GLOBAL STANDARD)-------\n");
	int nYrs;

	putchar('\n');
	printf(" Please, (in figures only) kindly enter the duration\n");
	printf(" of your university degree programme: ");
	scanf("%d", &nYrs);
	putchar('\n');

	if (nYrs >= 1 && nYrs <= 6)
	{
		/* float (*cgpaFptr)(int nYrs) = cgpa; */
		float (*cgpaFptr)(int nYrs);

		/**
		 * The use of "&" operator in function pointer is not
		 * neccessary as they are implicitly present/used just
		 * like in arrays where "&" operator are also implictly
		 * used.
		 */
		cgpaFptr = cgpa;

		cgpaGraduation(nYrs, cgpaFptr);
	}
	else
	{
		printf(" Please, try again and enter a valid year of study\n between ");
		printf(" 1 - 6.\n\n Thank you.\n\n");
		printf("\n-------CREATED BY @chibuike-vm (GITHUB USERNAME)--------\n");
	}

	return (0);
}

