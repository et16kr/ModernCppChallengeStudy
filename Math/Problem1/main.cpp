#include <gsl/gsl>
#include <iostream>

using namespace std;

unsigned long sum1toNum( unsigned long input )
{
    return (1 + input) * (input/2) + ((input%2)*(input/2+1));
}

unsigned long sumUnderMultiples( unsigned long max , unsigned long by)
{
    return sum1toNum( max / by ) * by ;
}

int main(int argc, char* argv[])
{
    unsigned long input,sum;

    if ( argc != 2 )
    {
        return -1;
    }

    input = atol(argv[1]);

    sum = sumUnderMultiples( input, 5 ) + sumUnderMultiples( input, 3 ) - sumUnderMultiples( input, 15 );
    cout << "Result : " << sum << endl;

    return 0;
}
