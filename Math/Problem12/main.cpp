#include <gsl/gsl>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    unsigned long long   input, count, maxcount, maxnum;

    maxcount = 0;
    maxnum = 0;

    for( int i = 2 ; i<=1000000 ; i++ )
    {
        input = i;
        count = 0;
        while( input != 1 )
        {
            count++;
            if( (input % 2 ) == 0 )
            {
                input >>= 1;
            }
            else
            {
                input = input * 3 + 1;
            }
        }
        if( maxcount < count )
        {
            maxcount = count;
            maxnum = i;
        }
    }

    cout << maxnum << " " << maxcount << endl;
    return 0;
}