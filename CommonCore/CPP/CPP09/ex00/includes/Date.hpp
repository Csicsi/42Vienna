#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <cstdlib>

class Date {
private:
	int _day;
	int _month;
	int _year;

	Date();
public:
	Date(std::string dateStr);
	~Date();
	Date(const Date &other);
	Date &operator=(const Date &other);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool isValid() const;
	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;
	bool operator<(const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator>=(const Date &other) const;
};

std::ostream &operator<<(std::ostream &os, const Date &date);

#endif
