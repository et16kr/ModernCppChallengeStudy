#include<iostream>

using namespace std;

bool check( const char* phone, const char* country )
{
    while(( *phone != 0 ) &&
          ( *country != 0 ))
    {
        if (( *phone > '9') ||
            ( *phone < '0'))
        {
            phone++;
            continue;
        }

        if (( *country > '9') ||
            ( *country < '0'))
        {
            country++;
            continue;
        }

        if( *phone != *country )
        {
            return false;
        }
        country++;
        phone++;
    }
    return true;
}

int main(int argc, char* argv[])
{
    int count = 24;
    char phone[24][25] = {{"07555 123456"},
                          {"07555123456"},
                          {"+44 7555 123456"},
                          {"44 7555 123456"},
                          {"7555 123456"},
                          {"447555 123456"},
                          {"82 7555 123456"},
                          {"+44 7555 123456"},
                          {"44 7555 123456"},
                          {"7555 123456"},
                          {"447555 123456"},
                          {"82 7555 123456"},
                          {"+02 07555 123456"},
                          {"07555123456"},
                          {"+82 7555 123456"},
                          {"02 7555 123456"},
                          {"7555 123456"},
                          {"027555 123456"},
                          {"82 7555 123456"},
                          {"+82 7555 123456"},
                          {"051 7555 123456"},
                          {"7555 123456"},
                          {"031 447555 123456"},
                          {"82 7555 123456"}};

    for( int i = 0 ; i < count ; i++ )
    {
        if ( check(phone[i],"+44") == true )
        {
            cout << phone[i] << endl;
        }
    }

    for( int i = 0 ; i < count ; i++ )
    {
        if ( check(phone[i],"+82") == true )
        {
            cout << phone[i] << endl;
        }
    }

    for( int i = 0 ; i < count ; i++ )
    {
        if ( check(phone[i],"+02") == true )
        {
            cout << phone[i] << endl;
        }
    }
    return 0;
}
