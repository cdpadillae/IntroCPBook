#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<cstdlib>

//Constant angular velocity circular motion, set center or circle, radii and omega, at t=0, the particle is at theta=0.

int main(){

  //Declaration of variables 
  double x0, y0, R, x, y, vx, vy, t, t0, tf, dt;
  double theta, omega;
  const double PI = 3.1415926535897932;
  std::string buf;

  //Ask user for input initial conditions and other needed parameters
  std::cout << "Enter omega:\n";
  std::cin  >> omega;          getline(std::cin,buf); 

  std::cout << "Enter center coordinates for the circle (x0,y0) and its radius R:\n";
  std::cin  >> x0 >> y0 >> R;  getline(std::cin,buf);

  std::cout << "Enter t0, tf and dt:\n";
  std::cin  >> t0 >> tf >> dt; getline(std::cin,buf);

  std::cout << "Omega= " <<  omega << std::endl;
  std::cout << "x0= " << x0 << "," << "y0= " << y0 << std::endl;
  std::cout << "R= " << R << std::endl;
  std::cout << "t0= " << t0 << "," << "tf= " << tf << std::endl;
  std::cout << "dt= " << dt << std::endl;

  //Initialize

  if(R <=0.0){
    std::cerr << "Illegal value of R\n";
    exit(1);
  }
  if(omega <=0.0){
    std::cerr << "Illegal value of Omega\n";
    exit(1);
  }
  std::cout << "T=" << 2.0*PI/omega << std::endl;
  std::ofstream myfile ("CircleMotionData.dat");
  myfile.precision(17);

  //Compute the equations of motion
  t = t0;
  while (t <= tf){
      theta = omega*(t-t0);
      x  = x0 + R*std::cos(theta);
      y  = y0 + R*std::sin(theta);
      vx = -omega*R*std::sin(theta);
      vy =  omega*R*std::cos(theta);
      myfile << t << " " << x << " " << y << " " << vx << " " << vy << std::endl;     
    t += dt;
  }


}
