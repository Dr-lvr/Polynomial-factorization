#pragma once
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <random>
#include <deque>
#include <regex>

#include "ProblemGen.h"
/// <summary>
/// ---------> DECODE THE BIG STRING
/// </summary>
/// <param name="expression"></param>
/// <returns></returns>
auto parseCompleteString(std::string expression)->std::vector<std::string> {
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
auto degreePredicate =
[](std::string& a, std::string& b) {
	std::smatch firstMatch;
	std::smatch secondMatch;
	std::regex pattern("[^\^]*$");
	std::regex_search(a, firstMatch, pattern);
	std::regex_search(b, secondMatch, pattern);
	return
		std::stoi(firstMatch.str()) >
		std::stoi(secondMatch.str());
};
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
	std::sort(parsedExpression.begin(), parsedExpression.end(), degreePredicate);
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
auto resolution(std::string expression)->std::string {
	std::vector<std::string> expressionVector = parseCompleteString(expression);
	for (auto& cc : expressionVector) {
		parse_inMonomi(cc);
	}
	return "";
}