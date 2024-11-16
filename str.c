// C program for the above approach
 
#include <stdarg.h>
#include <stdio.h>

//va_start enables access to variadic function arguments
//va_arg inisialize the last fixed argument to the pointer

int	LargestNumber(int n, ...);
{
	int		max;
	va_list	p;

	va_start(p, n);
	max = n;
	while (p)
	{
		*p = va_arg();
	}
	return (max);
}

// Driver Code
int main()
{
    printf("\n\n Variadic functions: \n");
 
    // Variable number of arguments
    printf("\n %d ",
           LargestNumber(2, 1, 2));
 
    printf("\n %d ",
           LargestNumber(3, 3, 4, 5));
 
    printf("\n %d ",
           LargestNumber(4, 6, 7, 8, 9));
 
    printf("\n");
 
    return 0;
}