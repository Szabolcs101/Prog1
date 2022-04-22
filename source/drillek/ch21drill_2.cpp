#include "std_lib_facilities.h"

int main(){

	map<string,int> msi;

	msi["Peter"] = 46;
	msi["Bob"] = 22;
	msi["Bill"] = 80;
	msi["Rose"] = 19;
	msi["Amanda"] = 63;
	msi["George"] = 30;
	msi["Matt"] = 57;
	msi["Kate"] = 26;
	msi["Joseph"] = 44;
	msi["Lewis"] = 70;

	for(const auto&p : msi)
		cout << p.first << ": " << p.second << "\n";

	msi.erase(msi.begin(), msi.end());

	string name;
	int age;

	for(int i=0; i<9; i++){
		cin >> name >> age;
		msi.insert(pair<string,int>(name,age));
	};


	for(const auto&p : msi)
		cout << p.first << ": " << p.second << "\n";

	cout << "Total of values: "
    const int result = accumulate(begin(msi), end(msi), 0,
                                          [](const int previous, const pair<const string, int>& p)
                                          { return previous + p.second; });
    cout << result << "\n";

    map<int,string> mis;

    for(const auto&a : msi){
    	mis[a.second] = a.first;
    }

    for(const auto&p : mis)
		cout << p.first << ": " << p.second << "\n";
}