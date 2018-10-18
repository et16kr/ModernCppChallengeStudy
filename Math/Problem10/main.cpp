#include <gsl/gsl>
#include <iostream>
#include <stdlib.h>

using namespace std;

void setNum( char * input, int num )
{
    for(int i = 0 ; i < 5 ; i++)
    {
        input[i] = (num>>(4-i)) % 2 + '0';
    }
    return ;
}
void toGray( char * input )
{
    for(int i = 4 ; i > 0 ; i--)
    {
        input[i] = (input[i] != input[i-1]) + '0';
    }
    return ;
}

void toBi( char * input )
{
    for(int i = 1 ; i < 5 ; i++)
    {
        input[i] = (input[i] != input[i-1]) + '0';
    }
    return ;
}

int main(int argc, char* argv[])
{
    char input[6] ;
    
    input[5] = 0;
    
    for( int i = 0 ; i < 0b100000 ; i ++ )
    {
        setNum(input,i);
        cout << "[" << i << "] " << input << " ";
        toGray( input );
        cout << input << " ";
        toBi( input );
        cout << input << endl;
    }

    return 0;
}
