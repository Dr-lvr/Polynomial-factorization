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
std::string polynomialGenerator() {
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
/// ---------> DECODER
/// </summary>
/// <param name="expression"></param>
/// <returns></returns>
std::vector<std::string> simpleParser(std::string expression) {
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
std::string factorization(std::string expression) {
	return "";
}
/// <summary>
/// ---------> DRIVER
/// </summary>
/// <returns></returns>
int main(){

	simpleParser(polynomialGenerator());
    //std::cout << "x^3+3x^2+4x+2" << std::endl;
	std::cin.ignore();
}