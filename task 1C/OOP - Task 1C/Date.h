#ifndef DateH
#define DateH
//---------------------------------------------------------------------------
//Date: class declaration
//---------------------------------------------------------------------------

#include <ctime>	
#include <iomanip>	
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Date {
public:
	Date();	//default constructor
	Date(int, int, int);	//constructor
	int getDay() const;		//return a data member value, day_
	int getMonth() const;		//returns a data member value, month_
	int getYear() const;		//returns a data member value, year_
	void setDate(int, int, int);	//sets new values for date
	bool operator ==(const Date&) const;  	//equality operator
	bool operator !=(const Date&) const;  	//non-equality operator
	operator string() const;	//cast operator (to string)
	ostream& putDataInStream(ostream& os) const;	//sends Date info into an output stream
	istream& getDataFromStream(istream& is);		//receives Date info from an input stream
	static const Date now();  	// returns system date - static function
private:
	int day_, month_, year_;
};

ostream& operator<<(ostream&, const Date&);	//output operator
istream& operator>>(istream&, Date&);		//input operator

#endif
