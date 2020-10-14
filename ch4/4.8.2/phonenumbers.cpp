#include <cassert>
#include <iostream>
#include <map>

int main() {

	std::map<std::string, unsigned long> phonenumbers = { {"bob", 9123123123}, {"bill", 12345}, {"ben", 19842190}, {"frank", 1029384576} };

	std::map<std::string, unsigned long>::iterator itr = phonenumbers.find("frank");
	for (auto& p : phonenumbers) {
		std::cout << p.first << ":" << p.second << std::endl;
	}

	if (itr != phonenumbers.end()) {
		std::cout << "WE FOUND " << itr->first << " AND HIS NUMBER IS" << itr->second << std::endl;
	}
	else {
		std::cout << "That person doesn't exist in the map" << std::endl;
	}

	std::map<std::string, unsigned long>::iterator itr2 = phonenumbers.find("Me");
	if (itr2 != phonenumbers.end()) {
		std::cout << "WE FOUND " << itr2->first << " AND HIS NUMBER IS" << itr2->second << std::endl;
	}
	else {
		std::cout << "That person doesn't exist in the map" << std::endl;
	}
	//Too long swiching to Auto

	auto byVal = std::find_if(phonenumbers.begin(), phonenumbers.end(), [](const auto& res) { return res.second == 12345; });

	if (byVal != phonenumbers.end()) {
		std::cout << "WE FOUND " << byVal->first << " AND HIS NUMBER IS" << byVal->second << std::endl;
	}
	else {
		std::cout << "That person doesn't exist in the map" << std::endl;
	}

	//Non-Existing

	auto byVal2 = std::find_if(phonenumbers.begin(), phonenumbers.end(), [](const auto& res) { return res.second == 1010101; });
	if (byVal2 != phonenumbers.end()) {
		std::cout << "WE FOUND " << itr->first << " AND HIS NUMBER IS" << itr->second << std::endl;
	}
	else {
		std::cout << "That person doesn't exist in the map" << std::endl;
	}

	//Because I'm also reading a C++17 book now. Heres Structred Bindings:
	//auto [n, p] = *byVal2;
}