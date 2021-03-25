#pragma once
#include <string>
#include <regex>
#include <deque>
#include <sstream>
#include <ostream>
#include <iostream>
/// <summary>
/// ---------> PARSE SINGLE OPERATION IN MONOMI
/// </summary>
/// <param name=""></param>
/// <returns></returns>
auto degreePredicate =
[](std::string& a, std::string& b) {
	std::smatch firstMatch, secondMatch;
	std::regex_search(a, firstMatch, std::regex("[^\^]*$"));
	std::regex_search(b, secondMatch, std::regex("[^\^]*$"));
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