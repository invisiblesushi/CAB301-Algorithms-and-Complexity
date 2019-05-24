#include <iostream>
#include <algorithm>
#include <math.h>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;
using namespace std::chrono;

int *randomArr(int size);
int bruteForceMedian(int A[], int n, int *operations);
int toFile( int max_arr, long *duration, int *operations );
int randomArrayTest();
int tests();

int main() {
    randomArrayTest();
    tests();
}

int tests(){
    int *operations = new int[4];
    long *duration = new long[4];
    int *median = new int[4];

    int A[9] = {1,2,3,4,5,6,7,8,9};
    median[0] = bruteForceMedian(A, 9, &operations[0]);
    cout << "Median: " << median[0] << " Basic operations: " << operations[0] << "\n";

    int B[9] = {9,8,7,6,5,4,3,2,1};
    median[1] = bruteForceMedian(B, 9, &operations[1]);
    cout << "Median: " << median[1] << " Basic operations: " << operations[1] << "\n";

    int C[10] = {1,2,3,4,5,6,7,8,9,10};
    median[2] = bruteForceMedian(C, 10, &operations[2]);
    cout << "Median: " << median[2] << " Basic operations: " << operations[2] << "\n";

    int D[10] = {1,1,1,1,3,4,5,5,5,5};
    median[3] = bruteForceMedian(D, 10, &operations[3]);
    cout << "Median: " << median[3] << " Basic operations: " << operations[3] << "\n";

}

int randomArrayTest(){
    int max_arr = 2000;
    int max_run = 1;
    int *operations = new int[max_arr];
    long *duration = new long[max_arr];

    for (int i = 1; i <= max_arr; i++) {
        int *A = randomArr(i);


        for ( int j = 0; j < max_run; j++) {
            high_resolution_clock::time_point t1 = high_resolution_clock::now();

            bruteForceMedian(A, i, &operations[i]);

            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration[i] += duration_cast<nanoseconds>(t2 - t1).count();

        }
        duration[i] = duration[i] / max_run;
        operations[i] = operations[i] / max_run;


    }
    toFile(max_arr, duration, operations );
    return 0;
}


//Random array generator
int *randomArr(int size){
    int *A = new int[size];

    for(int i=0; i<size; i++){
        A[i] = ( rand() % 1000 ) - ( size + ( rand() % size )) ;
        if ( A[i] < 0 ){
            A[i] = A[i] * (-1);
        }
    }
    return A;
}

int bruteForceMedian(int A[], int n, int *operations){
    int k = ceil((n/2.0));
    *operations = 0;

    for(int i=0;i <= (n-1); i++) {

        int numsmaller = 0;
        int numequal = 0;

        for(int j=0; j <= (n-1); j++) {

            if( A[j] < A[i] ){
                numsmaller++;
            }
            else if( A[j] == A[i] ) {
                numequal++;
            }
            *operations = *operations + 1;

        }
        if( ( numsmaller < k ) && ( k <= ( numsmaller + numequal ) ) ) {
            k = A[i];
        }
    }
    return k;
}

int toFile(int max_arr, long *duration, int *operations) {
    ofstream csvFile ("/home/danielch/Desktop/output.csv");
    if (csvFile.is_open()){
        csvFile << "array size,nanoseconds,operations \n";

        for (int j = 0; j <= max_arr; j++){
            csvFile << j << "," << duration[j] << "," << operations[j] << "\n";
        }

        csvFile.close();
    }

}
