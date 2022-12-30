/*
 * PrimeSieve.cpp
 * Calculates the prime numbers up to MAXIMUM.
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int MAXIMUM = 20;

/* Function Prototypes */

int main() {

	int countPrimes = 0;
	
	// declare prime array

	// initialise indexes 0 and 1 to false and all others to true

	// loop from 2 to MAXIMUM by 1

		// if current is prime

			// loop from next to MAXIMUM by step

				// set current to not prime


	// output results
	for (int i = 0; i <= MAXIMUM; i++) {
		if (prime[i]) {
			countPrimes++;
			cout << setw(6) << i;
			if (countPrimes % 20 == 0) {
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "There are " << countPrimes << " prime numbers between 0 and " << MAXIMUM << endl;
 
	return 0;
}
