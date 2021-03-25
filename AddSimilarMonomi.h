#pragma once
#include <string>
#include <regex>
#include <deque>
#include <ranges>
#include <iostream>
#include <numeric>
//std::regex pattern2(".+?(?=x)");
auto add_similarMonomi(std::deque<std::string> expression)->std::deque<std::string> {
	int a = 0;
	std::smatch fncMatch;
	std::stringstream streamObj;
	std::deque<std::string> simplifiedExpression;
	for (int i = 100; i >= 0; --i) {
		if (std::any_of(expression.begin(), expression.end(), [&i](std::string& a) {
			std::smatch lambdaMatch;
			std::regex_search(a, lambdaMatch, std::regex("[^\^]*$"));
			return std::stoi(lambdaMatch.str()) == i;
			})) {
			for (std::string monomio : expression | std::views::filter([&i](std::string& a) {
				std::smatch lambdaMatch;
				std::regex_search(a, lambdaMatch, std::regex("[^\^]*$"));
				return std::stoi(lambdaMatch.str()) == i;
				})) {
				//std::cout << monomio << std::endl;
				if (std::regex_search(monomio, fncMatch, std::regex(".+?(?=x)"))) {
					a += std::stoi(fncMatch.str());
				}
			}
			streamObj
				<< a
				<< "x^"
				<< i;
			simplifiedExpression.push_back(streamObj.str());
			streamObj.str("");
			a = 0;
		}
	}
	for (auto& m : simplifiedExpression) {
		std::cout << m << std::endl;
	}
	return {};
}