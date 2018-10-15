#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>

using namespace std;

long long int gcd1(long long int input1, long long int input2 )
{
    long long int res = 1 ;
    long long int i = 3 ;
    long long int max ;

    if(( input1 >= 2 ) && ( input1 % 2 == 0 ) &&
       ( input2 >= 2 ) && ( input2 % 2 == 0 ))
    {
        res = 2;
        input1 /= 2;
        input2 /= 2;
    }

    max = ( input1 < input2 ) ? input1 : input2;

    while( i <= max )
    {
        if(( input1 % i == 0 ) &&
           ( input2 % i == 0 ))
        {
            res *= i;
            input1 /= i;
            input2 /= i;
            max /= i;
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
            max = ( input1 < input2 ) ? input1 : input2;
        }
    }
    return res;
}

long long int gcd2( long long int input1 , long long int input2 )
{
    long long int tmp;

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
    long long int input1, input2  ;

    if ( argc != 3 )
    {
        return -1;
    }

    input1 = atoi(argv[1]);
    input2 = atoi(argv[2]);

    cout << "my func   : " << gcd1(input1, input2) << endl;
    cout << "Euclidean : " << gcd2(input1, input2) << endl;

    return 0;
}
