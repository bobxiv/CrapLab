//Esta instruccion preprocesador hace que solo se compile una vez, apesar de que se incluya en varios cpps
#pragma once

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////   Encabezado Y Definicion de la Librearia BenchMark   ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////                 Librearias que utilizo                ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "Timer.h"                    /*///////////////////////////*/
/*///////////////////////////*/					#include <iostream>                   /*///////////////////////////*/
/*///////////////////////////*/					#include "Store.h"                    /*///////////////////////////*/		  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/*
								------------Clase Operator------------
								|									 |
					   	Clase Operator1						 Clase Operator2


*/


const int primero = 14;

const int segundo =12;

const int tercero =16;

const int cuarto =15;

const int quinto =15;



namespace BenchMark{



//Operator es la clase padre de todos los Operators de BenchMark
	class Operator{
protected:

//Este mien¿mbor almacena enq ue tiempo se realizo la operacion
//Diferencia de primera marca y segunda marca
double Time;

public:

//Muestra el timpo por en por el flujo que se le pase
//Recibe:
//-La presicion de los flotantes
//-El flujo por el que saldra
void Show_Time(int = 0,std::ostream& = std::cout);

void Equivalence_Table(int=16,int=0,std::ostream& = std::cout);

//Este metodo devuelve el valor de la variable Time
double Get_Time();

};



void Operator::Equivalence_Table(int spc,int pres ,std::ostream& output){

//Cada linea de la consola tiene exactamente 80 chars de espacio

output<<'*';
	
	output.width(std::streamsize(49));
	output.fill( '=' );

output<< " Equivalence  Table ";

	output.fill( '=' );
	output.width(std::streamsize(30));


output<<'*';

output.fill(' ');


//Renglon de la Leyenda
output<<'*'<<' '<<' ';

	output.width(13);

output<<"Nanoseconds";

	output.width(12);

output<<"Ticks";

	output.width(18);

output<<"Microseconds";

	output.width(15);

output<<"Milliseconds";

	output.width(12);

output<<"Seconds";

	output.width(4);

output<<' '<<' '<<' '<<'*';


//Primer Renglon de Datos
output<<'*'<<' ';


	output.flags( std::ios::internal );
	output.width(primero);

output<<"100";

	output.flags( std::ios::internal );
	output.width(segundo);

output<<"1";
	
	output.flags( std::ios::internal );
	output.width(tercero);

output<<"0.1";
	
	output.flags( std::ios::internal );
	output.width(cuarto);

output<<"0.0001";

	output.flags( std::ios::internal );
	output.width(quinto);

output<<"0.0000001";

	output.width(4);

output<<' '<<' '<<'*';


//Segundo Renglon de Datos
output<<'*'<<' ';


	output.flags( std::ios::internal );
	output.width(primero);

output<<"10,000";

	output.flags( std::ios::internal );
	output.width(segundo);

output<<"100";
	
	output.flags( std::ios::internal );
	output.width(tercero);

output<<"10.0";
	
	output.flags( std::ios::internal );
	output.width(cuarto);

output<<"0.0100";

	output.flags( std::ios::internal );
	output.width(quinto);

output<<"0.0000100";

	output.width(4);

output<<' '<<' '<<'*';


//Tercer Renglon de Datos
output<<'*'<<' ';


	output.flags( std::ios::internal );
	output.width(primero);

output<<"100,000";

	output.flags( std::ios::internal );
	output.width(segundo);

output<<"1,000";
	
	output.flags( std::ios::internal );
	output.width(tercero);

output<<"100.0";
	
	output.flags( std::ios::internal );
	output.width(cuarto);

output<<"0.1000";

	output.flags( std::ios::internal );
	output.width(quinto);

output<<"0.0001000";

	output.width(4);

output<<' '<<' '<<'*';


//Cuarto Renglon de Datos
output<<'*'<<' ';


	output.flags( std::ios::internal );
	output.width(primero);

output<<"1,000,000";

	output.flags( std::ios::internal );
	output.width(segundo);

output<<"10,000";
	
	output.flags( std::ios::internal );
	output.width(tercero);

output<<"1,000.0";
	
	output.flags( std::ios::internal );
	output.width(cuarto);

output<<"1.0000";

	output.flags( std::ios::internal );
	output.width(quinto);

output<<"0.0010000";

	output.width(4);

output<<' '<<' '<<'*';


//Quinto Renglon de Datos
output<<'*'<<' ';


	output.flags( std::ios::internal );
	output.width(primero);

output<<"10,000,000";

	output.flags( std::ios::internal );
	output.width(segundo);

output<<"100,000";
	
	output.flags( std::ios::internal );
	output.width(tercero);

output<<"10,000.0";
	
	output.flags( std::ios::internal );
	output.width(cuarto);

output<<"10.0000";

	output.flags( std::ios::internal );
	output.width(quinto);

output<<"0.0100000";

	output.width(4);

output<<' '<<' '<<'*';

//Sexto Renglon de Datos
output<<'*'<<' ';


	output.flags( std::ios::internal );
	output.width(primero);

output<<"100,000,000";

	output.flags( std::ios::internal );
	output.width(segundo);

output<<"1,000,000";
	
	output.flags( std::ios::internal );
	output.width(tercero);

output<<"100,000.0";
	
	output.flags( std::ios::internal );
	output.width(cuarto);

output<<"100.0000";

	output.flags( std::ios::internal );
	output.width(quinto);

output<<"0.1000000";

	output.width(4);

output<<' '<<' '<<'*';


//Septimo Renglon de Datos
output<<'*'<<' ';


	output.flags( std::ios::internal );
	output.width(primero);

output<<"1,000,000,000";

	output.flags( std::ios::internal );
	output.width(segundo);

output<<"10,000,000";
	
	output.flags( std::ios::internal );
	output.width(tercero);

output<<"1,000,000.0";
	
	output.flags( std::ios::internal );
	output.width(cuarto);

output<<"1,000.0000";

	output.flags( std::ios::internal );
	output.width(quinto);

output<<"1.0000000";

	output.width(4);

output<<' '<<' '<<'*';

//Brarra Final

output<<'*';

	output.width(79);
	output.fill('=');

output<<"*";

output<<'\n';


}


	
void Operator::Show_Time(int pres, std::ostream& output){

output<<'\n';

output.precision(std::streamsize(pres));

//Ya da el tiempo en segundos
output<<"Segundo en realizar la accion: \t\t" << Time << '\n'<<'\n';

output.precision(std::streamsize(pres));

//	1 seg ----- 1000 mseg	
//
//	seg/1000 = mseg
output<<"Milisegundos en realizar la accion: \t" << (Time*1000) << '\n'<<'\n';

output.precision(std::streamsize(pres));

//	1 mseg ----- 1000 mcseg
//
//	mseg/1000 = mcseg
output<<"Microsegundos en realizar la accion: \t" << (Time*1000000) << '\n'<<'\n';

output.precision(std::streamsize(pres));

//	1 mcseg ----- 10 ticks
//
//	mcseg/10 = tick
output<<"Ticks en realizar la accion: \t\t" << (Time*10000000) << '\n'<<'\n';

output.precision(std::streamsize(pres));

//	1 tick ----- 100 nseg
//
//	tick/100 = nseg
output<<"Nanosegundos en realizar la accion: \t" << (Time*1000000000) << '\n';


output<<'\n';


}


double Operator::Get_Time(){

return Time;


}







//Operator 2 recibe una funcion con dos parametros como se especifica e el miembro Function
	template<class T>
	class Operator2:public Operator{
private:

//Este miembro almacena un puntero a funcion
//este debe recibir dos parametros de tipo const T&
//y devolver T por valor
T (*Function)(const T&,const T&);

public:

Operator2( T (*)(const T&,const T&) );

//Este metodo realiza varios calculos y llena el miembro Time 
//que dice cuanto tardo en ralizar los calculos
//Recibe:
//-Un entero que seran la cantidad de veces que se repetira la accion
//-Un valor T que sera por el que se realizara la accion,
//es decir le segundo operando del operador binario
//Devuelve void
void Execute(int,T&,T&);

};


	template<class T>
Operator2<T>::Operator2( T (*F)(const T&,const T&) ){

Time=0;

Function = F;


}



	template<class T>
void Operator2<T>::Execute(int loop, T& A, T& B){

	HRTimer Timer;

//Comienza a contar
Timer.Start();

	for( int i = 0; ( i < loop ) ; i++){

		Function(A,B);
		
	}


//termina de contar
Timer.Stop();


Time = Timer.GetDurationInSecs();


}




	//El segundo parametro del template es lo que devuelve sea Plus o Prod
	template<class T, class U>
	class Operator1:public Operator{
private:

//Este miembro almacena un puntero a funcion
//este debe recibir dos parametros de tipo const T&
//y devolver T por valor
	U (T::*Function)(const T&);

public:

	Operator1( U (T::*)(const T&) );

//Este metodo realiza varios calculos y llena el miembro Time 
//que dice cuanto tardo en ralizar los calculos
//Recibe:
//-Un entero que seran la cantidad de veces que se repetira la accion
//-Un valor T que sera por el que se realizara la accion, ie el que llama a la funcion
//-Un valor T que sera con quien se realizara la accion
//Devuelve void
void Execute(int,T&,T&);

};



	
	template<class T,class U>
	Operator1<T,U>::Operator1( U (T::*F)(const T&) ){

Time=0;

Function = F;


}



	template<class T,class U>
void Operator1<T,U>::Execute(int loop, T& A, T& B){

	HRTimer Timer;

//Comienza a contar
Timer.Start();

	

	for( int i = 0; ( i < loop ) ; i++){

		(A.*Function)(B) ;
		
	}


//termina de contar
Timer.Stop();


Time = Timer.GetDurationInSecs();


}


}//Fin del nombre de espacios BenchMark, contenedor de 'esta libreria'