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

#define SKIP_ARR_SIZE (7)
#define END_NUM (1000000)

int main(int argc, char* argv[])
{
    long long int i,j ;
    long long int skip[SKIP_ARR_SIZE]={0,0,0,0,0,0,0};

    for( i = 1 ; i <= END_NUM ; i++ )
    {
        if(skip[i%SKIP_ARR_SIZE] != i)
        {
            j = divisorSum( i );
            if(( j <= END_NUM ) &&
               ( j > i ) &&
               ( divisorSum( j ) == i ))
            {
                cout << i << ", " << j << endl;
                skip[j%SKIP_ARR_SIZE] = j;
            }
        }
    }

    return 0;
}
