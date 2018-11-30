#include <iostream>
#include <cstring>

using namespace std;


void quickSort( int arr[], int left, int right )
{
      int i = left, j = right;
      int pivot = arr[(left + right) / 2];
      int temp;
      do
      {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i<= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
      } while (i<= j);

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);

    if (i < right)
        quickSort(arr, i, right);
}

struct node
{
    int num;
    int count;
};

void solve( int * start, int size )
{
    int max = 1;
    node * num = new node [size];
    int idx = 0;
    quickSort( start, 0, size - 1);

    num[idx].num   = start[0];
    num[idx].count = 1;

    for(int i = 1 ; i < size ; i++)
    {
        if ( num[idx].num == start[i] )
        {
            num[idx].count++;
            if(  num[idx].count > max )
            {
                max = num[idx].count;
            }
        }
        else
        {
            num[++idx].num = start[i];
            num[idx].count   = 1;
        }
    }

    for(int i = 0 ; i <= idx ; i++ )
    {
        if ( num[i].count == max )
        {
            cout << "{" << num[i].num << ", " << num[i].count << "}" << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[] = {1,1,3,5,8,13,3,5,8,8,5};
    solve(arr,11);
    return 0;
}
