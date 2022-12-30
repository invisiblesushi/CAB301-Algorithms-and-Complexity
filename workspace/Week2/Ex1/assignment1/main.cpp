#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
int A[] = {2,3,4,7,8,9,10,12,15};

int n = ( sizeof(A) / sizeof(A[0]) );
int k = (n/2);

for(int i=0;i <= (n-1); i++){
    int numsmaller = 0;
    int numequal = 0;

    for(int j=1;j <= (n-1); j++){
        if(A[j]<A[i])
        {
            numsmaller = numsmaller + 1;
        }
        else if(A[j]==A[i])
        {
            numequal = numequal + 1;
        }
    }

    if(((numsmaller < k)&&(k<=(numsmaller + numequal))))
    {
        k = A[i];
        cout << k;
        return 0;
    }
}
return 0;
}
