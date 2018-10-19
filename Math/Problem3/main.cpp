#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>

using namespace std;

unsigned long calc1(unsigned long a , unsigned long b)
{
    unsigned long res1 = a;
    unsigned long res2 = b;

    while(res1 != res2 )
    {
        if( res1 > res2 )
        {
            res2 += b;
        }
        else
        {
            res1 += a;
        }
    }
    return res1;
}

unsigned long calc2(unsigned long input1 , unsigned long input2 )
{
    unsigned long res = 1;

    while(( input1 % 2 == 0 )||
          ( input2 % 2 == 0 ))
    {
        res *= 2;
        if ( input1 % 2 == 0 )
        {
            input1 /= 2;
        }
        if ( input2 % 2 == 0 )
        {
            input2 /= 2;
        }
    }

    for( unsigned long i = 3 ;
         ( input1 != 1 ) && ( input2 != 1 ) ;
         i += 2 )
    {
        while(( input1 % i == 0 )||
              ( input2 % i == 0 ))
        {
            res *= i;
            if ( input1 % i == 0 )
            {
                input1 /= i;
            }
            if ( input2 % i == 0 )
            {
                input2 /= i;
            }
        }
    }
    return res * input1 * input2;
}


int main(int argc, char* argv[])
{
    unsigned long input1, input2  ;

    if ( argc != 3 )
    {
        return -1;
    }

    input1 = atol(argv[1]);
    input2 = atol(argv[2]);

    cout << "Result : " << calc1(input1, input2) << endl;
    cout << "Result : " << calc2(input1, input2) << endl;

    return 0;
}

