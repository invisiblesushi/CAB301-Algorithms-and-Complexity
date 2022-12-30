#include <iostream>

using namespace std;

int main()
{

    int N;
    cout  << "Enter N: ";
    cin >> N;

    int result = 0;
    for (int i = 0; i < (N*2); i++) {
        if( i % 2 == 1){
            result += i;
        }
    }


    cout << "the sum of the first odd numbers is = " << N << " = " << result;



    return 0;
}
