#include <gsl/gsl>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

unsigned long calc( unsigned long input )
{
    unsigned long max;
    if ( input < 4 )
    {
        return input;
    }

    max = sqrt(input);

    if ( input % 2 == 0 )
    {
        input--;
    }

    for( unsigned long i = 3 ; i <= max ; i += 2 )
    {
        if ( input % i == 0 )
        {
            i = 1; // +2
            input -= 2;
            max = sqrt(input);
        }
    }

    return input;
}
int main(int argc, char* argv[])
{
    unsigned long input;
    if( argc != 2 )
    {
        return -1;
    }
    input = atol(argv[1]);
    cout << "Result : " << calc( input ) << endl ;
    return 0;
}
