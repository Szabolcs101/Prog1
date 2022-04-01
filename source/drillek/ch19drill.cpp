#include "std_lib_facilities.h"

template<typename T> 

struct S
{
private:

	T val; 

public:

	S (T t):val{t} {}

	S& operator=(const T& t) {val=t; return *this; }

	T& get() {return val;}

	const T& get_const() const {return val;}

};

template<typename T>

void read_val(T& v) {cin>>v;}


int main(){

	S<int> s_int(2);
	cout << s_int.get() << "\n";

	S<char> s_char('k');
	cout << s_char.get() << "\n";

	S<double> s_double(0.634);
	cout << s_double.get() << "\n";

	S<string> s_string("Hey");
	cout << s_string.get() << "\n";

	S<vector<int>>s_vector({2,4,8,16,32});
	vector<int>A=s_vector.get();
	for(auto x:A)
		cout << x << " " << "\n";

	cout << "Enter a char: ";
	read_val(s_char.get());
	cout << s_char.get() << "\n";

	cout << "Enter a string: ";
	read_val(s_string.get());
	cout << s_string.get() << "\n";

	cout << "Enter a double: ";
	read_val(s_double.get());
	cout << s_double.get() << "\n";

	return 0;
}