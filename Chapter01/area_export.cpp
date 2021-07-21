#include <iostream>
#include <fstream>
//Returns area and diameter of ten circles with input radius, using a function. Exports a csv file.
const double PI = 3.1415926535897932;

void area_of_circle(const double& R, double& D, double& A);

void area_of_circle(const double& R, double& D, double& A){
	D = 2.0*PI*R;
	A = PI*R*R;
}


int main(void){
	const int N = 10;
	double    R[N];
	double    area, perimeter;
	int       i;

	for(i=0;i<N;i++){
		std::cout << "Enter radius of circle:";
		std::cin  >> R[i];
		std::cout << "i=" << (i+1) << "R(i)=" << R[i] << std::endl;
	}

        std::ofstream myfile ("areadata.csv");
	myfile << "i" << "," << "Radii" << "," << "Perimeter" << "," << "Area" << "\n";
	for(i=0;i<N;i++){
		area_of_circle(R[i], perimeter , area);
		myfile << (i+1) << "," << R[i] << "," << perimeter << "," <<  area << std::endl;

	}
	myfile.close();
} 
