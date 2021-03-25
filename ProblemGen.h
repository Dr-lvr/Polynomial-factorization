#pragma once
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <random>
/// <summary>
/// ---------> PROBLEM GENERATOR
/// </summary>
/// <returns></returns>
auto polynomialGenerator()->std::string {
	//the math teacher : string of expressions
	std::random_device randomDevice;
	std::mt19937 gen(randomDevice());
	std::uniform_int_distribution<> sign(0, 1);
	std::uniform_int_distribution<> degree(0, 5);
	std::uniform_int_distribution<> coefficent(0, 100);
	std::uniform_int_distribution<> expressionLength(1, 10);
	std::uniform_int_distribution<> vectorLength(1, 10);
	std::unordered_map <int, std::string> operators_vMap = { {0, "-"},{1, "+"} };

	std::stringstream retObj;
	std::stringstream streamObj;
	std::vector<std::string> expressionVector;

	for (int i = 0; i < vectorLength(gen); ++i) {
		for (int i = 0; i < expressionLength(gen); ++i) {
			streamObj
				<< operators_vMap[sign(gen)]
				<< std::to_string(coefficent(gen))
				<< "x^"
				<< std::to_string(degree(gen));
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