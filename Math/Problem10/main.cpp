#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void print( int count , char roman )
{
    for(int i = 0 ; i<count ; i++ )
    {
        cout << roman;
    }
}

int printRoman( int input, int idx )
{
    const char roman[4][2] = {{'I','V'},{'X','L'},{'C','D'},{'M',0}};
    const int grade[4] = {1,10,100,1000};
    int num = input / grade[idx];

    switch(num)
    {
        case 9:
           {
                cout << roman[idx][0] ;
                cout << roman[idx+1][0] ;
            }
            break;
        case 8:
        case 7:
        case 6:
        case 5:
            {
                print( 1, roman[idx][1] );
                print( num-5, roman[idx][0] );
            }
            break;
        case 4:
            {
                cout << roman[idx][0] ;
                cout << roman[idx][1] ;
            }
            break;
        case 3:
        case 2:
        case 1:
            print( num, roman[idx][0] );
        default:
            break;
    }

    return input % grade[idx]; 
}


int main(int argc, char* argv[])
{
    unsigned long long input;

    if( argc != 2 )
    {
        return -1;
    }
    
    input = atol(argv[1]) ;

    if ( input >= 4000 )
    {
        return -1;
    }

    for(int i = 3 ; i >= 0 ; i--)
    {
        input = printRoman( input , i );
    }

    return 0;
}
