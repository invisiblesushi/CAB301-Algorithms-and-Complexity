#include <iostream>

using namespace std;

int main()
{

    int N;
    cout  << "Enter a positive integer: "
    cin >> N;

    int result = 0;
    for (int i = 0; i < N; i++) {
        result += i + 1;
    }


    cout << "the sum of numbers from 1 to " << N << " = " << result;



    return 0;
}
