#include "Date.hpp"

Date::Date() : _day(1), _month(1), _year(1970) {}

Date::Date(std::string dateStr) {
	if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
		throw std::invalid_argument("Invalid date format");
	}
	for (size_t i = 0; i < dateStr.length(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!isdigit(dateStr[i])) {
			throw std::invalid_argument("Invalid date format");
		}
	}
	_year = atoi(dateStr.substr(0, 4).c_str());
	_month = atoi(dateStr.substr(5, 2).c_str());
	_day = atoi(dateStr.substr(8, 2).c_str());
	if (!isValid()) {
		throw std::invalid_argument("Invalid date");
	}
}

Date::~Date() {}

Date::Date(const Date &other) : _day(other._day),
	_month(other._month), _year(other._year) {}

Date &Date::operator=(const Date &other) {
	if (this != &other) {
		_day = other._day;
		_month = other._month;
		_year = other._year;
	}
	return *this;
}

bool Date::isValid() const {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (_month < 1 || _month > 12 || _day < 1)
		return false;
	int maxDay = daysInMonth[_month - 1];
	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))) {
		maxDay = 29;
	}
	if (_day > maxDay)
		return false;
	return true;
}

int Date::getDay() const {
	return _day;
}

int Date::getMonth() const {
	return _month;
}

int Date::getYear() const {
	return _year;
}

bool Date::operator==(const Date &other) const {
	return (_day == other._day && _month == other._month && _year == other._year);
}

bool Date::operator!=(const Date &other) const {
	return !(*this == other);
}

bool Date::operator<(const Date &other) const {
	if (_year != other._year)
		return _year < other._year;
	if (_month != other._month)
		return _month < other._month;
	return _day < other._day;
}

bool Date::operator<=(const Date &other) const {
	return (*this < other || *this == other);
}

bool Date::operator>(const Date &other) const {
	return !(*this <= other);
}

bool Date::operator>=(const Date &other) const {
	return !(*this < other);
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
	return os;
}
