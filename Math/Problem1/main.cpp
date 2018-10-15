#include <gsl/gsl>
#include <iostream>

using namespace std;

long long int sum1toNum( long long int input )
{
    return (1 + input) * (input/2) + ((input%2)*(input/2+1));
}

long long int sumUnderMultiples( long long int max , long long int by)
{
    return sum1toNum( max / by ) * by ;
}

int main(int argc, char* argv[])
{
    long long int input,sum;

    if ( argc != 2 )
    {
        return -1;
    }

    input = atoi(argv[1]);

    sum = sumUnderMultiples( input, 5 ) + sumUnderMultiples( input, 3 ) - sumUnderMultiples( input, 15 );
    cout << "Result : " << sum << endl;

    return 0;
}
