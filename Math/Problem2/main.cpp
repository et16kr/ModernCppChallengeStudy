#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

unsigned long gcd1(unsigned long input1, unsigned long input2 )
{
    unsigned long res = 1 ;
    unsigned long i = 3 ;
    unsigned long max ;

    while(( input1 >= 2 ) && ( input1 % 2 == 0 ) &&
          ( input2 >= 2 ) && ( input2 % 2 == 0 ))
    {
        res *= 2;
        input1 /= 2;
        input2 /= 2;
    }

    max = ( input1 < input2 ) ? input1 : input2;
    max = sqrt( max );

    while(( i <= max ) &&
          ( i <= input1 ) &&
          ( i <= input2 ))
    {
        if(( input1 % i == 0 ) &&
           ( input2 % i == 0 ))
        {
            res *= i;
            input1 /= i;
            input2 /= i;
        }
        else
        {
            if( input1 % i == 0 )
            {
                input1 /= i;
            }

            if( input2 % i == 0 )
            {
                input2 /= i;
            }

            if ( input1 == input2 )
            {
                res *= input1;
                break;
            }

            i += 2;
        }
    }
    return res;
}

unsigned long gcd2( unsigned long input1 , unsigned long input2 )
{
    unsigned long tmp;

    while( input2 )
    {
        tmp = input1 % input2;
        input1 = input2;
        input2 = tmp;
    }
    return input1;
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

    cout << "my func   : " << gcd1(input1, input2) << endl;
    cout << "Euclidean : " << gcd2(input1, input2) << endl;

    return 0;
}
