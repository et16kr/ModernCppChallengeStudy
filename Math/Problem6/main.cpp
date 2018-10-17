#include <gsl/gsl>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long int divisorSum( long long int input )
{
    long long int sum = 1;
    long long int max = sqrt(input) ;

    for( long long int i = 2 ; i <= max ; i++ )
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
    long long int input;

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
