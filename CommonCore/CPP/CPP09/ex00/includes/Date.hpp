#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date {
private:
	int _day;
	int _month;
	int _year;

	Date();
public:
	Date(int day, int month, int year);
	~Date();
	Date(const Date &other);
	Date &operator=(const Date &other);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;
	bool operator<(const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator>=(const Date &other) const;
};

std::ostream &operator<<(std::ostream &os, const Date &date);

#endif
