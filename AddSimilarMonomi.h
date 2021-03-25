#pragma once
#include <string>
#include <regex>
#include <deque>
#include <ranges>
#include <iostream>
#include <numeric>

//std::regex pattern2(".+?(?=x)");
auto pred =
[](std::string& a) {
	std::smatch firstMatch;
	std::regex_search(a, firstMatch, std::regex("[^\^]*$"));
	return std::stoi(firstMatch.str()) == 2;
};
auto add_similarMonomi(std::deque<std::string> expression)->std::deque<std::string> {
	std::smatch firstMatch;
	std::deque<std::string> simplifiedExpression;
	int a = 0;
	for (std::string ok : expression | std::views::filter(pred)) {
		std::cout << ok << std::endl;
		if (std::regex_search(ok, firstMatch, std::regex(".+?(?=x)"))) {
			a += std::stoi(firstMatch.str());
		}
	}
	std::cout << a << std::endl;
	return {};
}