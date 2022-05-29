//copy tiltalasa a nodefaultban, a nodefault-ban alapertelmezett konstruktor.

#include <iostream>
#include <string>
using namespace std;

class Auto {
	public:
		string nev;
		Auto(){};

		//tiltás, másolást nem engedem meg
		Auto(const Auto&) = delete;
		void operator=(const Auto&) = delete;

		Auto(const string n){
			nev = n;
		}
		void kiir();
};

void Auto::kiir(){
	cout << "Név: " << nev << endl;
}

int main(){

	Auto a1("string");
	a1.kiir();

	Auto a2 = a1;
	a2.kiir();

	return 0;
}