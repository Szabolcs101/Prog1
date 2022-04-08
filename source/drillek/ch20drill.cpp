#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>  //requires Input_Iterator<Iter1>() && Output_Iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (auto i=f1; i!=e1; i++){
		*f2=*i;
		f2++;
	}
	return f2;
};

int main(){
	cout << "array= {";
	int a1[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for(int i=0; i<10; i++){
		
		/*a1[i]=a1[i]/*+2;*/;
		cout << a1[i] << ",";
	}
	cout << "}\n";

	vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "v= {";
	for(int i=0; i<10; i++){

		/*v1[i]=v1[i]/*+3;*/;
		cout << v1[i] << ",";
	}
	cout << "}\n";

	list<int> l1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "l= {";
	for(int m : l1) {

		/*m=m;*/
		cout << m << ",";
	}
	cout << "}\n";

	int a2[10] = {a1[10]}; 			//copies of array, vec, list
	cout << "array2 = {";
	
	for(int i=0; i<10; i++){
		a2[i]=a1[i]+2;
		cout << a2[i] << ",";
	}
	cout << "}\n";

	vector<int>v2 = v1;

	cout << "v2= {";
	for(int i=0; i<10; i++){
		v2[i]=v2[i]+3;
		cout << v2[i] << ",";
	}
	cout << "}\n";

	list<int>l2 = l1;

	cout << "l2= {";
	for(int n : l1) {

		n+=5;
		cout << n << ",";
	}
	cout << "}\n";
	

	my_copy(begin(a2), end(a2), begin(v2));  //copy from array2 to vector2

	cout << "a2 copied to v2= {";
	for (int i=0; i<v2.size(); i++){
		cout << v2[i] << ",";
	}
	
	cout << "}\n";

	my_copy(l2.begin(), l2.end(), begin(a2));  //copy from list2 to array2

	cout << "l2 copied to a2= {";
	for (auto x : a2){
		cout << x << ",";
	}
	
	cout << "}\n";

	//Search for values
	int el1 = 27, el2=3;


	auto val1 = find(l2.begin(), l2.end(), el1);
	if (val1 != l2.end())
		cout << "Found at: " << distance(l2.begin(), val1) << "\n";
	else
		cout << "Value not found.\n";

	auto val2 = find(v2.begin(), v2.end(), el2);
	if (val2 != v2.end())
		cout << "Found at: " << distance(v2.begin(), val2) << "\n";
	else
		cout << "Value not found.\n";

return 0;
};
