#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include "complex"

void out_sqrt(){
	int val;
	cin >> val;

	if(val < 0) error("Invalid sqrt");
	else
		cout << sqrt(val) << "\n";
}

int main(){

	cout << "Sizes of: \n"
		 << "char: " << sizeof(char) << "\n"
		 << "short: " << sizeof(short) << "\n"
		 << "int: " << sizeof(int) << "\n"
		 << "long: " << sizeof(long) << "\n"
		 << "float: " << sizeof(float) << "\n"
		 << "double: " << sizeof(double) << "\n"
		 << "int*: " << sizeof(int*) << "\n"
		 << "double*: " << sizeof(double*) << "\n";

	Numeric_lib::Matrix<int>a(10);
	Numeric_lib::Matrix<int>b(100);
	Numeric_lib::Matrix<double>c(10);
	Numeric_lib::Matrix<int,2>d(10,10);
	Numeric_lib::Matrix<int,3>e(10,10,10);

	cout << "Sizes of:\n"
		 << "Matrix<int>a(10): " << sizeof(a) << "\n"
		 << "Matrix<int>b(100): " << sizeof(b) << "\n"
		 << "Matrix<double>c(10): " << sizeof(c) << "\n"
		 << "Matrix<int,2>d(10,10): " << sizeof(d) << "\n"
		 << "Matrix<int,3>e(10,10,10): " << sizeof(e) << "\n";

	cout << "Number of elements:\n"
		 << "Matrix<int>a(10): " << a.size() << "\n"
		 << "Matrix<int>b(100): " << b.size() << "\n"
		 << "Matrix<double>c(10): " << c.size() << "\n"
		 << "Matrix<int,2>d(10,10): " << d.size() << "\n"
		 << "Matrix<int,3>e(10,10,10): " << e.size() << "\n";
    
    cout << "Enter an int to see its square root: \n";
    out_sqrt();

    cout << "Enter 10 float numbers: \n";
    Numeric_lib::Matrix<double>f(10);
    for(int i=0; i<f.size(); i++){
    	cin >> f[i];
    }
    cout << f << "\n";

    cout << "Enter 10 complex doubles:\n";
    Numeric_lib::Matrix<complex<double>>g(10);
    for(int i=0; i<g.size(); i++){
    	cin >> g[i];
    }
    cout << g << "\n";

    cout << "Sum of values: "
    	 << accumulate(g.data(), g.data()+g.size(),
    	 	complex<double>{});

    cout << "Enter six ints into a 2*3 Matrix:\n";
    Numeric_lib::Matrix<int,2>k(2,3);

    for(int i=0; i<k.dim1(); i++)
    	for(int j=0; j<k.dim2(); j++)
    		cin >> k[i][j];

    cout << k;

}