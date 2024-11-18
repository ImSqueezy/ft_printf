#include "printf.h"

 print_bytes(char *ptr, int count)
 {
   int i;
   char string[1024];
   string[0] = 0;
   for(i = 0; i < count; i++)
   {
     sprintf(string,"%s %2x", string, *(ptr+i));
   }
   puts(string);
 }

int main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

 print_bytes("hello world", 3); return (0);
    return 0;
}