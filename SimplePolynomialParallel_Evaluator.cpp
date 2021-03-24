#include <unordered_map>
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <random>
#include <deque>

/// <summary>
/// ---------> PROBLEM GENERATOR
/// </summary>
/// <returns></returns>
auto polynomialGenerator()->std::string{
	//the math teacher : string of expressions
	std::random_device randomDevice;
	std::mt19937 gen(randomDevice());
	std::uniform_int_distribution<> sign(0, 1);
	std::uniform_int_distribution<> grade(0, 5);
	std::uniform_int_distribution<> coefficent(0, 100);
	std::uniform_int_distribution<> expressionLength(1, 10);
	std::uniform_int_distribution<> vectorLength(1, 10);
	std::unordered_map <int, std::string> operators_vMap = {{0, "-"},{1, "+"}};

	std::stringstream retObj;
	std::stringstream streamObj;
	std::vector<std::string> expressionVector;

	for (int i = 0; i < vectorLength(gen); ++i) {
		for (int i = 0; i < expressionLength(gen); ++i) {
			streamObj
				<< operators_vMap[sign(gen)]
				<< std::to_string(coefficent(gen))
				<< "x^"
				<< std::to_string(grade(gen));
		}
		streamObj << ";";
		expressionVector.push_back(streamObj.str());
		retObj << streamObj.str();
		streamObj.str("");
	}
	for (auto& cc : retObj.str()) {
		std::cout << cc;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return retObj.str();
}
/// <summary>
/// ---------> DECODE THE BIG STRING
/// </summary>
/// <param name="expression"></param>
/// <returns></returns>
auto parseCompleteString(std::string expression)->std::vector<std::string>{
	//expressions parser : vector of expressions
	std::stringstream streamObj;
	std::vector<std::string> expressionVector;
	for (auto& c : expression) {
		if (c != ';') {
			streamObj << c;
		}
		else {
			expressionVector.push_back(streamObj.str());
			streamObj.str("");
		}
	}
	for (auto& cc : expressionVector) {
		std::cout << cc << std::endl;
	}
	return expressionVector;
}
/// <summary>
/// ---------> PARSE SINGLE OPERATION IN MONOMI
/// </summary>
/// <param name=""></param>
/// <returns></returns>
auto parse_inMonomi(std::string expression)->std::deque<std::string> {
	std::stringstream streamObj;
	std::deque<std::string> parsedExpression;
	std::reverse(expression.begin(), expression.end());
	for (auto& c : expression) {
		if (c != ';') {
			streamObj << c;
			if (c == '+' || c == '-') {
				parsedExpression.push_front(streamObj.str());
				std::reverse(parsedExpression.front().begin(), parsedExpression.front().end());
				streamObj.str("");
			}
		}
	}
	std::cout << "----------------" << std::endl;
	for (auto& cc : parsedExpression) {
		std::cout << cc << std::endl;
	}
	std::cout << "----------------" << std::endl;
	return parsedExpression;
}
/// <summary>
/// ---------> COLLECT CABLES AND RESOLVE
/// </summary>
/// <param name="_Right"></param>
/// <returns></returns>
auto resolution(std::string expression)->std::string{
	std::vector<std::string> expressionVector = parseCompleteString(expression);
	for (auto& cc : expressionVector) {
		parse_inMonomi(cc);
	}
	return "";
}
/// <summary>
/// ---------> DRIVER
/// </summary>
/// <returns></returns>
auto main()->int{

	std::cout << resolution("+24x^3-26x^2+x^1-1x^0;+24x^3-26x^2+x^1-1x^0;+24x^3-26x^2+x^1-1x^0;") << std::endl;

	parseCompleteString(polynomialGenerator());
	std::cin.ignore();
}