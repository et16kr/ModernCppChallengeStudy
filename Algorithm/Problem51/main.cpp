#include<iostream>

using namespace std;

void convert( char* phone, const char* country )
{
    int  idx = 0;
    char output[25];
    char *phone2 = phone;
    const char *country2 = country;

    while( *country != 0 )
    {
        if (( *country == '+' ) ||
            (( *country <= '9') && ( *country >= '0')))
        {
            output[idx++] = *country;
        }
        country++;
    }

    while(( *phone2 != 0 ) &&
          ( *country2 != 0 )&&
          (idx < 25 ))
    {
        if (( *phone2 > '9') ||
            ( *phone2 < '0'))
        {
            phone2++;
            continue;
        }

        if (( *country2 > '9') ||
            ( *country2 < '0'))
        {
            country2++;
            continue;
        }

        if( *phone2 != *country2 )
        {
            break;
        }
        country2++;
        phone2++;
    }

    while( *phone2 != 0 )
    {
        if (( *phone2 <= '9') && ( *phone2 >= '0'))
        {
            output[idx++] = *phone2;
        }
        phone2 ++;
    }
    output[idx] = 0;
    cout << phone << " ==> " << output << endl;
    return ;
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
        convert(phone[i],"+44");
    }

    return 0;
}
