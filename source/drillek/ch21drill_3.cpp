#include "std_lib_facilities.h"

class Less_than{

	double v;
public:
	Less_than(double vv) : v{vv} {}

	bool operator()(const double val) {return val < v;}
};


int main(){

	const string iname {"floats.txt"};
	ifstream ifs {iname};
	if (!ifs) throw runtime_error("Could not read from file: " + iname);

	vector<double> vd;
	for (double i; ifs >> i;)
		vd.push_back(i);

	cout << "Elements of vd: \n";
	for(int i=0; i<vd.size(); i++)
		cout << vd[i] << "\n";

	vector<int> vi (vd.size());
	copy(vd.begin(), vd.end(), vi.begin());

	cout << "cout vd, vi pairs: \n";
	for(int i=0; i<vd.size(); i++)
		cout << vd[i] << " , " << vi[i] << "\n";

	/*double total = 0;
	cout << "Sum of elements in vd: ";
	for(int i=0; i<vd.size(); i++)
		total += vd[i];
	cout << total;*/

	cout << "Sum of elements in vd: ";
	double double_sum = accumulate(vd.begin(), vd.end(), 0.0);
	cout << double_sum << "\n";

	cout << "Difference between sum of vd and vi: ";
	double double_sum2 = accumulate(vi.begin(), vi.end(), 0.0);

	double difference = double_sum-double_sum2;
	cout << difference << "\n";

	cout << "Reversed elements of vd: ";
	reverse(vd.begin(), vd.end());
	
	for(int i=0; i<vd.size(); i++)
		cout << vd[i] << "\n";

	cout << "Mean value of elements: ";
	double mean_value = double_sum/vd.size();

	cout << mean_value << "\n"; 

	cout << "Copy from vd to vd2 if vd2[i]>vd[i]:\n";

	vector<double>vd2 (vd.size());

	auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(mean_value));

	for(int i=0; i<vd.size(); i++)
		if (vd2[i] > 0)                   //Because vd2 == vd.size(), so there are more elements
			cout << vd2[i] << "\n";

	sort(vd.begin(), vd.end());

	cout << "Elements of vd sorted: \n";
	for(int i=0; i<vd.size(); i++)
		cout << vd[i] << "\n";

}