//---------------------------------------------------------------------------
//Date: class implementation
//---------------------------------------------------------------------------
#include "Date.h"

//____public member functions

//____constructors & destructors
Date::Date() {		//default constructor
	*this = now();
}
Date::Date(int d, int m, int y) 	//constructor
	: day_(d), month_(m), year_(y)
{}

//____other public member functions
int Date::getDay() const {
	return day_;
}
int Date::getMonth() const {
	return month_;
}
int Date::getYear() const {
	return year_;
}
void Date::setDate(int d, int m, int y) {
	day_ = d;
	month_ = m;
	year_ = y;
}

//____operator overloading functions 
bool Date::operator==(const Date& rhs) const { //equality operator
	return ((day_ == rhs.day_) &&
		(month_ == rhs.month_) &&
		(year_ == rhs.year_));
}
bool Date::operator!=(const Date& rhs) const {  	//non-equality operator
	return !(*this == rhs);
}
Date::operator string() const {
	ostringstream os;
	os << setfill('0');
	os << setw(2) << day_ << "/";
	os << setw(2) << month_ << "/";
	os << setw(4) << year_;
	return os.str();
}
ostream& Date::putDataInStream(ostream& os) const {
	//date formatted output (DD/MM/YY)
	os << setfill('0');
	os << setw(2) << day_ << "/";
	os << setw(2) << month_ << "/";
	os << setw(4) << year_;
	return os;
}
istream& Date::getDataFromStream(istream& is) {
	//read in date as DD/MM/YY
	char ch;			//(any) colon field delimiter
	is >> day_ >> ch >> month_ >> ch >> year_;
	return is;
}


//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& aDate) {
	return (aDate.putDataInStream(os));
}
istream& operator>>(istream& is, Date& aDate) {
	return (aDate.getDataFromStream(is));
}


//---------------------------------------------------------------------------
//static functions
//---------------------------------------------------------------------------

const Date Date::now() {  	// returns system date
	time_t now = time(0);
	struct tm t;
	localtime_s(&t, &now);
	return Date(static_cast<int>(t.tm_mday),
		static_cast<int>(t.tm_mon + 1),
		static_cast<int>(t.tm_year + 1900));
}