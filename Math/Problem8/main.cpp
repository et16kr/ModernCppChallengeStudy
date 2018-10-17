#include <gsl/gsl>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int cube[10];

    for( int i = 0 ; i < 10 ; i++ )
    {
        cube[i] = i * i * i;
    }

    for( int i = 0 ; i < 1000 ; i++ )
    {
        if( i == cube[i/100] + cube[(i/10)%10] + cube[i%10] )
        {
            cout << i << endl;
        }
    }
    return 0;
}
