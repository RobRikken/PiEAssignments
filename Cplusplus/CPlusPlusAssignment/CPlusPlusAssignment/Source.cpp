#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <exception>

//Functions for excersize 1
std::vector<int> PrimeNumberCalculator();
void SavePrimeNumbersToFile(std::vector<int> PrimeNumberList);
//Functions for excersize 2
int CheckForOperatorAndCalculate(char Operator, std::vector<int> NumberVector);

double VectorSum(std::vector<int> VectorToBeSummed);
double VectorDifference(std::vector<int> VectorToBeDivided);
double VectorMultiplication(std::vector<int> VectorToBeMultiplicated);
double VectorDivision(std::vector<int> VectorToBeDivided);


int main() {
	//Excersize 1, prime numbers
	std::vector<int> PrimeNumbers;

	PrimeNumbers = PrimeNumberCalculator();
	SavePrimeNumbersToFile(PrimeNumbers);

	//Excersize 2, Reverse Polish Notation
	std::string RPNString = InputRPNString()


	return EXIT_SUCCESS;
}

std::string InputRPNString() {
	std::string RPNUserInput;
	std::cout << "Please input your calculation in RPN (Reverse Polish Notation)." << endl;
	std::cin >> RPNUserInput;
}

void ParseRPNString(std::string RPNString) {
	std::string::size_type  PreviousPosition;
	std::string::size_type  Position;
	std::string TemporalString;
	do{
		Position = RPNString.find_first_of(' ', PreviousPosition);
		TemporalString = RPNString.substr(PreviousPosition, Position);
		if ((iss >> num).fail()) {
			//If convert to number fails, call operator.
		}
		else {
			//Add the number to the vector.
		}
		
		PreviousPosition = Position;
	}while(Position != std::string::npos)


}

int CheckForOperatorAndCalculate(char Operator, std::vector<int> NumberVector) {
	int Result;
	switch ( Operator )
	{
	case '+': Result = VectorSum(NumberVector);
		break;
	case '-': Result = VectorDifference(NumberVector);
		break;
	case '*': Result = VectorMultiplication(NumberVector);
		break;
	case '/': Result = VectorDivision(NumberVector);
		break;
	default:
		std::cerr << "Undefined operator used in RPN calculaton!" << std::endl;
	} 
	return Result;
}

double VectorSum(std::vector<int> VectorToBeSummed) {
	int SumOfVector = 0;
	for each (int Number in VectorToBeSummed)
	{
		SumOfVector += Number;
	}
	return SumOfVector;
}

double VectorDifference(std::vector<int> VectorToBeDivided) {
	int DifferenceOfVector = 0;
	for each (int Number in VectorToBeDivided)
	{
		DifferenceOfVector -= Number;
	}
	return DifferenceOfVector;
}

double VectorMultiplication(std::vector<int> VectorToBeMultiplicated) {
	int MultiplicationOfVector = 0;
	for each (int Number in VectorToBeMultiplicated)
	{
		MultiplicationOfVector *= Number;
	}
	return MultiplicationOfVector;
}

double VectorDivision(std::vector<int> VectorToBeDivided) {
	int DivisionOfVector = 0;
	for each (int Number in VectorToBeDivided)
	{
		DivisionOfVector /= Number;
	}
	return DivisionOfVector;
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
}8