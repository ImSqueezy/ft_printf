#include "printf.h"

void print_memory(const void *addr, size_t size)
{
    size_t printed = 0;
    size_t i;
    const unsigned char* pc = addr;
    for (i=0; i<size; ++i)
    {
        int  g;
        g = (*(pc+i) >> 4) & 0xf;
        g += g >= 10 ? 'a'-10 : '0';
        putchar(g);
        printed++;

        g = *(pc+i) & 0xf;
        g += g >= 10 ? 'a'-10 : '0';
        putchar(g);
        printed++;
        if (printed % 32 == 0) putchar('\n');
        else if (printed % 4 == 0) putchar(' ');
    }
}

int main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	print_memory(tab, sizeof(tab)); return (0);
    return 0;
}