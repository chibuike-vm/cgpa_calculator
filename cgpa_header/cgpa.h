#ifndef _CGPA_H_
#define _CGPA_H_

/**
 * nYrsInputValidator - Int nYrs variable validator.
 *
 * Description: This function basically validates the value of the nYrs
 * variable by making sure the that only integer values are copied into the
 * nYrs variable especially in the case where the user enters a string literal
 * following the requested integer value.
 *
 * Return: This function returns the validated integer value of the nYrs
 * variable to the calling function scope upon successful execution.
 */
int nYrsInputValidator(void)
{
	int nYrs, num_copied;
	char *fgetsInput = (char *)malloc(50 * sizeof(char));

	if (fgetsInput != NULL)
	{
		printf(" \n Please, (in figures only) kindly enter the duration\n");
		printf(" of your university degree programme: ");
		fgets(fgetsInput, 50, stdin);
		putchar('\n');

		num_copied = sscanf(fgetsInput, "%d", &nYrs);

		/* Conditional Ternary Operator */
		(num_copied == 1) ? num_copied : (nYrs = 0);
	}
	else
	{
		printf("\n\nMemory allocation was unsuccesful!\n\n");
	}

	free(fgetsInput);
	fgetsInput = NULL;

	return (nYrs);
}

/**
 * gpInputValidator - Float gp variable validator.
 *
 * Description: This function basically validates the value of the gp varaible
 * by amking sure that only floating integers are copied into the gp variable
 * especially when a user enters a string literal following the requested
 * floating point number value.
 *
 * Return: This function returns the validated floating point number value of
 * the gp variable to the calling function scope upon successful execution.
 */
float gpInputValidator(void)
{
	float gp;
	int num_copied;
	char *fgetsInput = (char *)malloc(50 * sizeof(char));

	if (fgetsInput != NULL)
	{
		fgets(fgetsInput, 50, stdin);
		num_copied = sscanf(fgetsInput, "%f", &gp);

		/* Conditional Ternary Operator */
		(num_copied == 1) ? num_copied : (gp = 0);
	}
	else
	{
		printf("\n\nMemory allocation was unsuccesful!\n\n");
	}

	free(fgetsInput);
	fgetsInput = NULL;

	return (gp);
}

/**
 * cgpa - Function for Calculating the TOTAL CGPA.
 * @nYrs: Provides the value for the iteration that will generate the totalGp.
 *
 * Description: This function basically collects an int parameter type value
 * then uses it for iterations that will generate the totalGp then with some
 * tweaking with conditional statements.
 *
 * Return: This function returns the calculated totalGP upon successful
 * execution.
 */
float cgpa(int nYrs)
{
	int i;
	float gp, totalGp = 0;
	char arr[6][4] = {{"1st"}, {"2nd"}, {"3rd"}, {"4th"}, {"5th"}, {"6th"}};

	for (i = 0; i < nYrs; i++)
	{
		printf(" Please, enter your %s year CGPA: ", arr[i]);
		gp = gpInputValidator();
		putchar('\n');

		if (gp > 0 && gp <= 4)
		{
			totalGp += gp;
		}
		else
		{
			totalGp = 0;
			break;
		}
	}
	return (totalGp);
}

/**
 * cgpaGraduation - Function for graduation Average CGPA
 * @nYrs: This int parameter data type value is being passed as an arguement
 * into the cgpa function when calling back the cgpa function inside the
 * cgpaGraduation function.
 * @cgpaFptr: This parameter is a function pointer passed as an arguement into
 * the cgpaGraduation function where it was used to call back the cgpa function
 * (callback function) inside the cgpaGraduation function to execute its task.
 *
 * Description: This function basically calls back the cgpa function using its
 * function pointer and then calulates the graduation cgpa after taking the
 * average of the cgpas where the duration of the university degree programme
 * of study serves as the divisor.
 */
void cgpaGraduation(int nYrs, float (*cgpaFptr)(int nYr))
{
	float retTotalGp = (*cgpaFptr)(nYrs), cgpa;

	cgpa = (retTotalGp / nYrs);

	if (cgpa >= 1.00 && cgpa <= 1.99)
	{
		printf(" Here is your graduation CGPA: %.3f\n", cgpa);
		printf("\n Congratulations! You made a THIRD CLASS HONOURS.\n");
	}
	else if (cgpa >= 2.00 && cgpa <= 2.99)
	{
		printf(" Here is your graduation CGPA: %.3f\n", cgpa);
		printf("\n Congratulations! You made a SECOND CLASS HONOURS.\n");
		printf("\t\t\t\t (LOWER DIVISION)\n");
	}
	else if (cgpa >= 3.00 && cgpa <= 3.49)
	{
		printf(" Here is your graduation CGPA: %.3f\n", cgpa);
		printf("\n Congratulations! You made a SECOND CLASS HONOURS.\n");
		printf("\t\t\t\t (UPPER DIVISION)\n");
	}
	else if (cgpa >= 3.5 && cgpa <= 4.00)
	{
		printf(" Here is your graduation CGPA: %.3f\n", cgpa);
		printf("\n Congratulations! You made a FIRST CLASS HONOURS.\n");
	}
	else if (cgpa > 0 && cgpa < 1.00)
	{
		printf(" Here is your graduation CGPA: %.3f\n", cgpa);
		printf(" Sorry, you did not qualify to be awarded a DEGREE.\n");
	}
	else if (cgpa == 0)
	{
		printf("\n Failed to calculate CGPA! The value(s) entered must");
		printf("\n be greater than 0 and less than 4 for each year.\n\n");
		printf(" Please, try again...\n");
	}
	printf("\n\n--------CREATED BY @chibuike-vm (GITHUB USERNAME)--------\n");
		printf("\n\n");
}
#endif /* _CGPA_H_ */
