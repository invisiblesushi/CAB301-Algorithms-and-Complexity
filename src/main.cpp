#include <iostream>
#include <algorithm>
#include <math.h>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;
using namespace std::chrono;

int *randomArr(int size);
int minDistance(int A[], int n, int *basicOp1);
int minDistance2(int A[], int n, int *basicOp1);
int toFile(int max_arr, long *duration1, int *basicOp1, long *duration2, int *basicOp2);
int randomArrayTest();
int tests();

int main() {
    tests();
    //randomArrayTest();
}

int randomArrayTest(){
    int max_arr = 10000;
    int max_run = 1;
    int *basicOp1 = new int[max_arr];
    int *basicOp2 = new int[max_arr];
    long *duration1 = new long[max_arr];
    long *duration2 = new long[max_arr];

    for (int i = 1; i <= max_arr; i++) {
        int *A = randomArr(i);


        for ( int j = 0; j < max_run; j++) {
            high_resolution_clock::time_point t1 = high_resolution_clock::now();

            minDistance(A, i, &basicOp1[i]);

            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration1[i] += duration_cast<nanoseconds>(t2 - t1).count();

        }
        duration1[i] = duration1[i] / max_run;
        basicOp1[i] = basicOp1[i] / max_run;

        for ( int k = 0; k < max_run; k++) {
            high_resolution_clock::time_point t1 = high_resolution_clock::now();

            minDistance2(A, i, &basicOp2[i]);

            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration2[i] += duration_cast<nanoseconds>(t2 - t1).count();

        }


    }
    toFile(max_arr, duration1, basicOp1, duration2, basicOp2);
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

int minDistance(int A[], int n, int *basicOp1){
    int dmin = numeric_limits<int>::max();

    for (auto i = 0; i <= n - 1; i++) {
        for (auto j = 0; j <= n - 1; j++) {
            if (( i != j ) && ( abs(A[i] - A[j]) < dmin )) {
                dmin = abs(A[i] - A[j]);
            }
            *basicOp1 = *basicOp1 + 1;
        }
    }
    return dmin;
}

int minDistance2(int A[], int n, int *basicOp2){
    int dmin = numeric_limits<int>::max();

    for (auto i = 0; i <= n - 2; i++){
        for (auto j = i + 1; j <= n - 1; j++) {
            auto temp = abs(A[i] - A[j]);
            if (temp < dmin) {
                dmin = temp;
            }
            *basicOp2 = *basicOp2 + 1;
        }
    }
    return dmin;
}


int toFile(int max_arr, long *duration1, int *basicOp1, long *duration2, int *basicOp2) {
    ofstream csvFile ("/home/danielch/Desktop/output.csv");
    if (csvFile.is_open()){
        csvFile << "minDistance,,,minDistance2 \n";
        csvFile << "array size,nanoseconds,operations,array size,nanoseconds,operations \n";

        for (int j = 0; j <= max_arr; j++){
            csvFile << j << "," << duration1[j] << "," << basicOp1[j] << "," << j << "," << duration2[j] << "," << basicOp2[j] << "\n";
        }

        csvFile.close();
    }

}

int tests() {
    int *basicOp1 = new int[6];
    int *basicOp2 = new int[6];
    int *minDist1 = new int[6];
    int *minDist2 = new int[6];
    int arr_size;
    int test_num;

    ofstream csvFile ("/home/danielch/Desktop/tests.txt");
    if (csvFile.is_open()){

        test_num = 0;
        arr_size = 1;
        int A[arr_size] = {1};
        csvFile << "{1}" << "\n";
        minDist1[test_num] = minDistance(A, arr_size, &basicOp1[test_num]);
        csvFile << "Min distance1: " << minDist1[test_num] << " Basic operations: " << basicOp1[test_num] << "\n";
        minDist2[test_num] = minDistance2(A, arr_size, &basicOp2[test_num]);
        csvFile << "Min distance2: " << minDist2[test_num] << " Basic operations: " << basicOp2[test_num] << "\n" << "\n";

        test_num = 1;
        arr_size = 2;
        int B[arr_size] = {1,2};
        csvFile << "{1,2}" << "\n";
        minDist1[test_num] = minDistance(B, arr_size, &basicOp1[test_num]);
        csvFile << "Min distance1: " << minDist1[test_num] << " Basic operations: " << basicOp1[test_num] << "\n";
        minDist2[test_num] = minDistance2(B, arr_size, &basicOp2[test_num]);
        csvFile << "Min distance2: " << minDist2[test_num] << " Basic operations: " << basicOp2[test_num] << "\n" << "\n";

        test_num = 2;
        arr_size = 3;
        int C[arr_size] = {1, 2, 4};
        csvFile << "{1, 2, 4}" << "\n";
        minDist1[test_num] = minDistance(C, arr_size, &basicOp1[test_num]);
        csvFile << "Min distance1: " << minDist1[test_num] << " Basic operations: " << basicOp1[test_num] << "\n";
        minDist2[test_num] = minDistance2(C, arr_size, &basicOp2[test_num]);
        csvFile << "Min distance2: " << minDist2[test_num] << " Basic operations: " << basicOp2[test_num] << "\n" << "\n";

        test_num = 3;
        arr_size = 5;
        int D[arr_size] = {1,3,6,9,22};
        csvFile << "{1,3,6,9,22}" << "\n";
        minDist1[test_num] = minDistance(D, arr_size, &basicOp1[test_num]);
        csvFile << "Min distance1: " << minDist1[test_num] << " Basic operations: " << basicOp1[test_num] << "\n";
        minDist2[test_num] = minDistance2(D, arr_size, &basicOp2[test_num]);
        csvFile << "Min distance2: " << minDist2[test_num] << " Basic operations: " << basicOp2[test_num] << "\n" << "\n";

        test_num = 4;
        arr_size = 5;
        int E[arr_size] = {3,3,3,3,3};
        csvFile << "{3,3,3,3,3}" << "\n";
        minDist1[test_num] = minDistance(E, arr_size, &basicOp1[test_num]);
        csvFile << "Min distance1: " << minDist1[test_num] << " Basic operations: " << basicOp1[test_num] << "\n";
        minDist2[test_num] = minDistance2(E, arr_size, &basicOp2[test_num]);
        csvFile << "Min distance2: " << minDist2[test_num] << " Basic operations: " << basicOp2[test_num] << "\n" << "\n";

        test_num = 5;
        arr_size = 0;
        int F[arr_size] = {};
        csvFile << "{}" << "\n";
        minDist1[test_num] = minDistance(F, arr_size, &basicOp1[test_num]);
        csvFile << "Min distance1: " << minDist1[test_num] << " Basic operations: " << basicOp1[test_num] << "\n";
        minDist2[test_num] = minDistance2(F, arr_size, &basicOp2[test_num]);
        csvFile << "Min distance2: " << minDist2[test_num] << " Basic operations: " << basicOp2[test_num] << "\n" << "\n";

        test_num = 6;
        arr_size = 12;
        int G[arr_size] = {100,90,80,70,60,55,50,40,30,20,10,0};
        csvFile << "{100,90,80,70,60,55,50,40,30,20,10,0}" << "\n";
        minDist1[test_num] = minDistance(G, arr_size, &basicOp1[test_num]);
        csvFile << "Min distance1: " << minDist1[test_num] << " Basic operations: " << basicOp1[test_num] << "\n";
        minDist2[test_num] = minDistance2(G, arr_size, &basicOp2[test_num]);
        csvFile << "Min distance2: " << minDist2[test_num] << " Basic operations: " << basicOp2[test_num] << "\n" << "\n";

        csvFile.close();
    }
}