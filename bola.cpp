#include <iostream>
#include <cmath>

constexpr double dT = 1e-4;
const double PI = 3.1415;

struct Vektor {
	double x;
	double y;
};

double Mutlak(double x){
	if (x>=0) {
		x = x;
	} else {
		x = x * (-1);
	}
	return x;
}


//Vektor add(Vektor v1, Vektor v2) {
//	Vektor v;
//	v.x = v1.x + v2.x
//	v.y = v1.y + v2.y
//	return V;
//}

//Vektor Mul(Vektor v, double k) {
//	Vektor Kali;
//	Kali.x = v.x * k;
//	Kali.y = v.y * k;
//	return Kali;
//}

//Vektor Proyeksi (double v, double k) {
//	Vektor Hasil;
//	Hasil.x = v * cos(k);
//	Hasil.y = v * sin(k);
//	return Hasil;
//}

// Vektor Calc( Vektor r, Vektor v, Vektor a, double w, double t ) {
//	for (double t1=0; t1<t; t1+=dT) {
//		r = add(r, mul(v,dT));
//		v = add(v, mul(a,dT));
//	}
//	return(r);
//}


Vektor Calc(double w, double a_resultan, double t){
	Vektor r,v,a;
	double sudut;
	r.x = 0;
	r.y = 0;
	v.x = 0;
	v.y = 0;
	sudut = PI/2;
	for (double t1=0; t1<t; t1+=dT) {
		sudut = sudut + w*dT;
		a.x = Mutlak(a_resultan * cos(sudut));
		a.y = Mutlak(a_resultan * sin(sudut));
		v.x = v.x + a.x * dT;
		v.y = v.y + a.y * dT;
		if (sin(sudut)>=0 && (cos(sudut)>=0)){				// Berdasar analisis di kuadran I nilai r.x berkurang sedangkan r.y bertambah
			r.x = r.x - Mutlak(v.x * dT);
			r.y = r.y + Mutlak(v.x * dT);
		}else if (sin(sudut)>=0 && (cos(sudut)<=0)){		// Berdasar analisis di kuadran II nilai r.x berkurang sedangkan r.y berkurang
			r.x = r.x - Mutlak(v.x * dT);
			r.y = r.y - Mutlak(v.x * dT);
		}else if (sin(sudut)<=0 && (cos(sudut)<=0)){		// Berdasar analisis di kuadran III nilai r.x bertambah sedangkan r.y berkurang
			r.x = r.x + Mutlak(v.x * dT);
			r.y = r.y - Mutlak(v.x * dT);
		}else if (sin(sudut)<=0 && (cos(sudut)>=0)){		// Berdasar analisis di kuadran IV nilai r.x bertambah sedangkan r.y bertambah
			r.x = r.x + Mutlak(v.x * dT);
			r.y = r.y + Mutlak(v.x * dT);
		}
	}
	return r;	
}

int main(){
	Vektor target,r;
	double w,a,t;
	std::cin >> target.x >> target.y >> t;
	r.x = 0;
	r.y = 0;
	w = 10;													// Asumsi kecepatan sudut adalah 10 rad/s
	a = 0;
	while (!((r.x>target.x)&&(r.y>target.y))){	// Cari r yang udah lewat target, ambil nilai a nya
		r.x += Calc(w,a,t).x;
		r.y += Calc(w,a,t).y;
		a += dT;
	}
	while (((Mutlak(r.x-target.x)<=dT)&&(Mutlak(r.y-target.y)<=dT))){	// turunnin w sampe ketemu r yang pas, yang jelas pas di run proses ga kelar kelar
		w -=dT;															// ga ngerti lagi kak maaf
		r.x += Calc(w,a,t).x;
		r.y += Calc(w,a,t).y;
	}
	
	std::cout << "w : " << w << " a : " << a << std::endl;
	
//	for (double w=dT; w<1; w+=dT){
//		r.x += Calc(w,a,t).x;
//		r.y += Calc(w,a,t).y;
//		if (((Mutlak(r.x-target.x)<=dT)&&(Mutlak(r.y-target.y)<=dT))){
//			std::cout << "w : " << r.x << " a : " << r.y << std::endl; 
//		}
//	}
//	std::cout << "w : " << Calc(10,10,19).x << " a : " << Calc(10000,10,100).y << std::endl; 
}
 


