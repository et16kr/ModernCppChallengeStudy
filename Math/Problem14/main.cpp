#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    int   result;
    char * input;

    if( argc != 2 )
    {
        return -1;
    }
    
    input = argv[1] ;
    result = 0;

    for(int i = 0, j = 10 ; i < 9 ; i++,j-- )
    {
        if( (unsigned int)(input[i]-'0') >= 10 )
        {
            cout << "invalid ISBN-10" << endl;
            return 0;
        }
        result += (input[i] - '0') * j;
    }
    
    if(( input[9] == 'X' ) ||
       ( input[9] == 'x' ))
    {
        result += 10;
    }
    else if( (unsigned int)(input[9]-'0') < 10 )
    {
        result += input[9]-'0';
    }
    else
    {
        result = 1;
    }
    
    if( result % 11 == 0 )
    {
        cout << "valid ISBN-10" << endl;
    }
    else
    {
        cout << "invalid ISBN-10" << endl;
    }

    return 0;
}
