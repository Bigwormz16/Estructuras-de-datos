#include <iostream>
#include <string>
using namespace std;
class Vehicle {
	protected : 
		string license ; 
		int year ;
		string year1;
		public :
			string stringify(int year){
				year1=static_cast<ostringstream*>(&(ostringstream() << year))->str();
				return year1;
			}
			Vehicle( const string &myLicense, const int myYear): license(myLicense), year(myYear) {}
			const string getDesc() {
				return license + " from " + stringify(&year);
			}
			const string &getLicense() const {
				return license;
			} 
			const int getYear() const {
				return year;
			} 
			
};
class Car : public Vehicle{
	string style ;
public :
	Car( const string &myLicense, const int myYear, const string &myStyle): Vehicle(myLicense, myYear), style(myStyle) {} 
	const string getDesc(){return stringify(year) + " " + style + ": " + license
				;}
	const string &getStyle() {return style;} 
};

