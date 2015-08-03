#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

int main() {
	int NPrimeNumbers = 200, PrimeFound;
	int NumberToCheckForPrime, i, j;
	bool PrimeIsFound;
	std::vector<int> PrimeNumberList;

	std::cout	<< "Please input the number of prime numbers you want to calculate." << std::endl 
		<< "Type a positive integer number and press enter:" << std::endl;
	
	std::cin >> NPrimeNumbers;

	NumberToCheckForPrime = 2;
	
	for (int NumberOfPrimes = 1; NumberOfPrimes <= NPrimeNumbers; NumberOfPrimes++) {
		PrimeIsFound = false;
		do
		{
			for (i = 1; i <= NumberToCheckForPrime; i++) {
				if (i == NumberToCheckForPrime) {
					PrimeIsFound = true;
					PrimeFound = NumberToCheckForPrime;
					break;
				}
				if ((NumberToCheckForPrime % i == 0) && (i != 1)) {
					PrimeIsFound = false;
					NumberToCheckForPrime++;
					break;
				}
			}
		} while (PrimeIsFound == false);
		NumberToCheckForPrime++;
		PrimeNumberList.push_back(PrimeFound);
	}

	std::cout << "n\t:\tp(n)\t:\tn*ln( p(n) )/p(n))" << std::endl;
	j = 0;
	for each (int Number in PrimeNumberList)
	{
		j++;
		double Ratio = j * log(Number) / Number;
		std::cout << j << "\t:\t" << Number << "\t:\t" << Ratio << std::endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}