#pragma once
#include <string>
#include <regex>
#include <deque>
#include <ranges>
#include <iostream>
#include <algorithm>

//std::regex pattern2("[^\^]*$");
auto similarPredicate =
[](std::string& a, std::string& b) {
	std::smatch firstMatch, secondMatch;
	std::regex_search(a, firstMatch, std::regex("[^\^]*$"));
	std::regex_search(b, secondMatch, std::regex("[^\^]*$"));
	return 
		std::stoi(firstMatch.str()) == 
		std::stoi(secondMatch.str());
};
//std::regex pattern2("^.[0-9][^x]");
auto addPredicate =
[](std::string& a, std::string& b) {
	std::smatch firstMatch, secondMatch;
	std::regex_search(a, firstMatch, std::regex("^.[0-9][^x]"));
	std::regex_search(b, secondMatch, std::regex("^.[0-9][^x]"));
	return 
		std::stoi(firstMatch.str()) > 
		std::stoi(secondMatch.str());
};
auto add_similarMonomi(std::deque<std::string> expression)->std::deque<std::string> {

	std::deque<std::string> expression2;
	
	std::accumulate();
	return {};
}