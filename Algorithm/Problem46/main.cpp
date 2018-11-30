#include <iostream>
#include <cstring>

using namespace std;

class circularBuffer
{
public:

    circularBuffer()
    {
        mQueue = NULL;
        mMaxCount = 0;
    };
    circularBuffer( int nodeSize, int nodeCount )
    {
        initialize( nodeSize, nodeCount );
    };
    ~circularBuffer()
    {
        if( mQueue != NULL )
        {
            for(int i = 0 ; i < mMaxCount ; i++ )
            {
                if( mQueue[i] == NULL )
                {
                    break;
                }
                delete mQueue[i];
            }
            delete mQueue;
        }
    };

    void initialize( int nodeSize, int nodeCount );

    void  add( void * nodeData );
    char* removeOldest();
    bool  empty() { return ( mNodeCount == 0 ) ;};
    bool  full() { return ( mNodeCount == mMaxCount ) ; };
    int   size(){ return mNodeSize;};
    int   capacity(){ return mNodeCount; };
private:

    unsigned int mMaxCount;
    unsigned int mNodeCount;
    unsigned int mNodeSize;
    unsigned int mBegin;
    unsigned int mEnd;
    char ** mQueue;

};

void circularBuffer::initialize( int nodeSize, int nodeCount )
{
    mQueue = (char**) new long long [nodeCount];
    mNodeSize  = nodeSize;
    mMaxCount  = nodeCount;
    mNodeCount = 0;
    mBegin = 0;
    mEnd   = 0;

    for(int i = 0 ; i< mMaxCount ; i++)
    {
        mQueue[i] = NULL;
    }
}

void circularBuffer::add( void * nodeData )
{
    int nodePos = mEnd % mMaxCount;

    if ( mQueue[ nodePos ] == NULL )
    {
        mQueue[ nodePos ] = new char [mNodeSize];
    }

    memcpy( mQueue[nodePos],
            (char*)nodeData,
            mNodeSize );

    mEnd++;

    if( mNodeCount < mMaxCount )
    {
        mNodeCount++;
    }
    else
    {
        mBegin++;
    }
}

char* circularBuffer::removeOldest()
{
    mNodeCount--;
    return mQueue[ mBegin++ % mMaxCount ];
}


int main(int argc, char* argv[])
{
    circularBuffer cb( 4, 10 );

    for( int i = 0 ; i < 12 ; i++ )
    {
        cb.add( &i );
        cout << '[' << i << "] " << cb.capacity() << " "  << cb.size() << " "
             << cb.full() << " "  << cb.empty() << endl ;
    }

    while( !cb.empty() )
    {
        cout << *(int*)cb.removeOldest() << endl;
    }

    return 0;
}
