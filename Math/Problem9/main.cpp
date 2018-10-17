#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{    
    unsigned long long input, max, lst;
    unsigned long long i = 3 ;
    if( argc != 2 )
    {
        return -1;
    }
    
    lst = input = atol(argv[1]) ;
    max = sqrt(input);

    while(( lst >= 2 ) && ( lst % 2 == 0 ))
    {
        lst /= 2;
        cout << " 2"; 
    }

    while(( i <= max ) &&
          ( i <= lst ))
    {
        if( lst % i == 0 )
        {
            lst /= i;
            cout << " " << i ;
        }
        else
        {
            i += 2;
        }
    }
    if (( lst > i ) &&
        ( lst < input ))
    {
        cout << " " << lst ;
    }

    cout << endl ;

    return 0;
}
