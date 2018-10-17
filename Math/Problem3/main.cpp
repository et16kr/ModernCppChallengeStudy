#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>

using namespace std;

long long int calc1(long long int a , long long int b)
{
    long long int res1 = a;
    long long int res2 = b;

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

long long int calc2(long long int input1 , long long int input2 )
{
    long long int res = 1;

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

    for( long long int i = 3 ;
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
    return res;
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

    cout << "Result : " << calc2(input1, input2) << endl;

    return 0;
}

