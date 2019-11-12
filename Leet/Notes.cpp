// Str to const char * and vice versa

#include <iostream>
using namespace std;

int main() {
	string s;
	
	const char * myArray = "Sample String";
	s = myArray;
	
	cout << s << endl;
	cout << s[0] << endl;
	
	string s1(myArray);
	cout << s1 << endl;
	
	string s2 = "Hello World !";
	myArray = s2.data();
	cout << myArray << endl; 
	cout << myArray[0] << endl;
	
	return 0;
}

/*
O/p : 
Sample String
S
Sample String
Hello World !
H
*/

// Floating point with fixed preceision

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float fix_precision(float x, int prec){
    float down = floor(x);
    float rem = x - down;
    rem *= pow(10, prec);
    rem = floor(rem);
    rem /= pow(10, prec);
    return down+rem;
}

int main() {
	float x = 3.141595646464;
	cout << fixed << setprecision(3) << x << endl;
	x = fix_precision(x,3);
	cout << to_string(x) << endl;
	return 0;
}

/* 
O/p :
3.142
3.141000
*/