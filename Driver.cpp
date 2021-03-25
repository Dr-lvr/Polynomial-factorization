#include "SimplePolynomialParallel_Evaluator.h"

/// <summary>
/// ---------> DRIVER
/// </summary>
/// <returns></returns>
auto main()->int {

	std::cout << resolution(polynomialGenerator()) << std::endl;
	//add_similarMonomi(parse_inMonomi("+24x^3-26x^2+9x^2-1x^0;"));
	/*
	std::cout << resolution("+24x^3-26x^2+9x^1-1x^0;") << std::endl;

	parseCompleteString(polynomialGenerator());
	*/
	std::cin.ignore();
}