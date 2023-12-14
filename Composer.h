#pragma once
#include <iostream>
#include <string>
using namespace std;

class Composer
{
private:
	string name;
	int date;
public:
	Composer();
	Composer(string n, int d);
	Composer(string n);
	~Composer();

	bool operator<(const Composer& right) const;
	bool operator>(const Composer& right) const;
	bool operator==(const Composer& right) const;
	bool operator!=(const Composer& right) const;

	friend ostream& operator<<(ostream& out, const Composer& right);
	
};

