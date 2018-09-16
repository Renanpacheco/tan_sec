#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao(double x);
double der_funcao(double x);

double tangente(double x0,double prec);

int main(){
	double i;
	i=tangente(0.75, 0.01);
	/*i=der_funcao(3);
	printf("%lf\n", i);
	i=funcao(3);
	printf("%lf\n", i);
	i=funcao(3)/der_funcao(3);*/
	printf("%lf", i);
}

double funcao(double x){ // x^3 -9x +3
	double aux;
	aux=x*x*x;
	return aux-9*x+3;
	
}

double der_funcao(double x){//3x^2-9
	double aux;
	aux=x*x;
	return 3*aux-9;
}

double tangente(double x0,double prec){
	double aux,x1, x_barra;
	int k;
	aux=funcao(x0);
	
	if(fabs(aux)<prec){
		x_barra = x0;
		return x_barra;				
		
	}
	
	else{
		k=1;
	
		while(fabs(aux)> prec){
			x1= x0-(funcao(x0)/der_funcao(x0));
			aux=funcao(x1);

		
			if((fabs(aux)< prec) || (fabs(x1-x0) < prec) ){
				x_barra = x1;
				break;
			}
		
			x0=x1;
			k++;
		
			}
		}
			
	return aux;
}
