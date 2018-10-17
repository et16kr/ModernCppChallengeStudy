#include <gsl/gsl>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long int calc( long long int input )
{
    if ( input < 4 )
    {
        return input;
    }

    if ( input % 2 == 0 )
    {
        input--;
    }

    for( long long int i = 3 ; i <= sqrt(input) ; i += 2 )
    {
        if ( input % i == 0 )
        {
            i = 1; // +2
            input -= 2;
        }
    }

    return input;
}
int main(int argc, char* argv[])
{
    long long int input;
    if( argc != 2 )
    {
        return -1;
    }
    input = atol(argv[1]);
    cout << "Result : " << calc( input ) << endl ;
    return 0;
}
