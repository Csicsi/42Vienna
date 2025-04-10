#include "Date.hpp"

Date::Date() : _day(1), _month(1), _year(1970) {}

Date::Date(int day, int month, int year) : _day(day),
	_month(month), _year(year) {}

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
