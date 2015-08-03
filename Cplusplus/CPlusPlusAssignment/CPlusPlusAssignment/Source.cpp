#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>

std::vector<int> PrimeNumberCalculator();
void SavePrimeNumbersToFile(std::vector<int> PrimeNumberList);

int main() {
	std::vector<int> PrimeNumbers;

	PrimeNumbers = PrimeNumberCalculator();
	SavePrimeNumbersToFile(PrimeNumbers);

	return EXIT_SUCCESS;
}

void SavePrimeNumbersToFile(std::vector<int> PrimeNumberList) {
	int i = 1;
	std::ofstream outs ( "PrimeNumbersList");
	
	for each (int PrimeNumber in PrimeNumberList)
	{
		outs << PrimeNumber << "\t";
		if (i % 8 == 0 ) {
			outs << '\n';
		}
		i++;
	}
	outs.close();
}

std::vector<int> PrimeNumberCalculator() {
	int NumberToCheckForPrime, PrimeFound, i, j, NPrimeNumbers;
	bool PrimeIsFound;
	std::vector<int> PrimeNumberList;

	std::cout << "Please input the number of prime numbers you want to calculate." << std::endl
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

	return PrimeNumberList;
}