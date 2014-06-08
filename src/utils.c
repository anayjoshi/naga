#include "utils.h"

void itos(const unsigned int num, char* s)
{
    int i = 0;
    int tenpower = 1;
	if(num > 0)
    {
		while(num >= tenpower) 
        {
            tenpower = 10*tenpower;
            i = i+1;
	    }
        int a = 0;
        int b = 0;
        int c = 0;
        int j = 0;
        tenpower = tenpower/10;
		while(j < i) 
        {
            a = (num/tenpower);
            c = (num/tenpower) - b;
            tenpower = tenpower/10;
            b = a*10;
            s[j] = (char)(((int)'0')+c);
            j++;
		}
	}
	else 
    {
        s[0] = '0';
	}
}
