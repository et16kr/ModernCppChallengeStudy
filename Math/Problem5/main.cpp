#include <gsl/gsl>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool isPrime( unsigned long long input )
{
    unsigned long long max;
    if ( input < 4 )
    {
        return true;
    }

    max = sqrt(input);

    if ( input % 2 == 0 )
    {
        return false;
    }

    for( unsigned long long i = 3 ; i <= max ; i += 2 )
    {
        if ( input % i == 0 )
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[])
{
    unsigned long long input;
    unsigned long long primes[3]={0,0,0};

    if( argc != 2 )
    {
        return -1;
    }
    
    input = atol(argv[1]) ;
    
    if( input <= 6 )
    {
        cout << "Result : not found" << endl ;
        return 0;
    }
    if (( input % 2 == 0 ) &&
        ( input != 2 ))
    {
        input--;
    }
    for( unsigned long long i  = 1 ; i < 7  ; i -= 2 )
    {
        if ( isPrime(i) == true )
        {
            primes[i%3] = i;
        }
    }
    input -= 6;
    for( unsigned long long i = 7 ; i < input  ; i += 2 )
    {
        if ( isPrime(i) == true )
        {
            if( primes[i%3] == ( i - 6 ) )
            {
                cout << "[ "<<i << ", " << i + 6 << " ]" << endl;
            }
            
            primes[i%3] = i;
        }
    }
    return 0;
}
