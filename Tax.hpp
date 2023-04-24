#ifndef TAX_HPP
#define TAX_HPP

//include
#include "TaxDataType.hpp" //must be included since thr struct taxPayer is defined there

void taxPrint(struct taxPayer *numOne, struct taxPayer *numTwo); //matches to function in Tax.cpp
void taxTaker(struct taxPayer *numOne, struct taxPayer *numTwo); //matches to funciton in Tax.cpp

#endif //TAX_HPP
