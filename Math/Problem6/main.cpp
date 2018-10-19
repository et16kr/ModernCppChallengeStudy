#include <gsl/gsl>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

unsigned long divisorSum( unsigned long input )
{
    unsigned long sum = 1;
    unsigned long max = sqrt(input) ;

    for( unsigned long i = 2 ; i <= max ; i++ )
    {
        if( input % i == 0 )
        {
            sum += i ;
            if( (input/i) != i)
            {
                sum += (input/i);
            }
        }
    }
    return sum;
}

int main(int argc, char* argv[])
{
    unsigned long input;

    if( argc != 2 )
    {
        return -1;
    }
    
    input = atol(argv[1]) ;
 
    for( ; input > 0 ; input--)
    {
        if( divisorSum(input) > input )
        {
            cout << "Result : " << input << endl;
            return 0;
        }
    }
    cout << "Result : not found" << endl;

    return 0;
}
