#include <iostream>
#include <fstream>

//Calculates area and perimeter for ten radii values as input and creates a csv file
int main(void){
	const int N = 10;
	const double PI = 3.14159265358979323846;
	double R[N];
	double area, perimeter;
	int i;

	for(i=0;i<N;i++){
	std::cout << "Enter radius of circle:";
	std::cin >> R[i];
	std::cout << "i=" << (i+1) << "R(i)=" << R[i] << "\n";
	}
	
	std::ofstream myfile ("areadata.csv");
	
	myfile << "i" << "," << "Radii" << "," << "Perimeter" << "," << "Area" << "\n";
	
	for(i=0;i<N;i++){
	perimeter = 2.0*PI*R[i];
	area 	  = PI*R[i]*R[i];
	myfile << (i+1) << "," << R[i] << "," <<  perimeter << "," << area << "\n";
	}
	
	myfile.close();
}
