#include "TaxConstants.hpp"
#include "Tax.hpp"
#include <iostream>
#include <iomanip>

void taxPrint(struct taxPayer *numOne, struct taxPayer *numTwo)
{
	std::cout << "\n\nTaxes due for this year:\n\n";
	std::cout << "Tax Payer #1: $ " << std::fixed << std::setprecision(2) << numOne->taxes << std::endl;
	std::cout << "Tax Payer #2: $ " << std::fixed << std::setprecision(2) << numTwo->taxes << std::endl;

}
void taxTaker(struct taxPayer *numOne, struct taxPayer *numTwo)
{
	bool check = false;

	while (check == false)
	{
		std::cout << "Annual income \n";
		std::cin >> numOne->income;
		std::cout << "Tax rate for the first person \n";
		std::cin >> numOne->taxRate;
		if (numOne->income > 0 && numOne->taxRate > 0.01 && numOne->taxRate < 9.9)
			check = true;
	}
	check = false;

	while (check == false)
	{
		std::cout << "Annual income \n";
		std::cin >> numTwo->income;
		std::cout << "Tax rate for the second person \n";
		std::cin >> numTwo->taxRate;
		if (numTwo->income > 0 && numTwo->taxRate > 0.01 && numTwo->taxRate < 9.9)
			check = true;
	}
	check = false;
	

	//making the calculations
	numOne->taxes = numOne->income * (numOne->taxRate / 100);
	numTwo->taxes = numTwo->income * (numTwo->taxRate / 100);

}