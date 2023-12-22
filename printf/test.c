#include <stdarg.h>
#include <stdio.h>

int	addnum(int n, ...)
{
	int 	sum = 0;
	va_list ptr;

	va_start(ptr, n);
	for (int i = 0; i < n; i++)
	{
		// printf("\nsum = %d arg = %d \n",sum , va_arg(ptr, int));
		sum+= va_arg(ptr, int);
	}
	va_end(ptr);

	return sum;
}

int main()
{
    printf("\n\n Variadic functions: \n");
 
    // Variable number of arguments
    printf("\n 1 + 2 = %d ",
           addnum(2, 1, 2));
 
    printf("\n 3 + 4 + 5 = %d ",
           addnum(3, 3, 4, 5));
 
    printf("\n 6 + 7 + 8 + 9 = %d ",
           addnum(4, 6, 7, 8, 9));
 
    printf("\n");
 
    return 0;
}