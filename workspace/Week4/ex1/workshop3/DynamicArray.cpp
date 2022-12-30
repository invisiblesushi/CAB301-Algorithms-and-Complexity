#include <iostream>

using namespace std;

int main()
{
    int n , m;

    //get user input for both dimensions of array
	
	//Declaration of a dynamic array 
    int **a = new int*[m];
    a[0] = new int[m*n];
    for ( int i = 1 ; i < m ; i++) {
        a[i] = a[i-1] + n;
    }

    //Use a[m][n] = value
    

    //Deallocate
    delete[] a[0];
    delete[] a;
}
