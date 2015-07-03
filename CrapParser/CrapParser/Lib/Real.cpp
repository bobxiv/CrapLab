#include "stdafx.h"


#include <iostream>

#include <conio.h>

#include "..\Headers\Store.h"

#include <fstream>

#include "..\Headers\BenchMark.h"

#include "..\Headers\GUI_Helper.h"

#include "..\Headers\Classic_Operators.h"

#include "..\Headers\Function.h"

#include <Windows.h>

void MostrarCeros(){

	for(int i=0; (i < 1000) ; i++)
		std::cout<<0;
}


int _tmain(int argc, _TCHAR* argv[])
{

	/*
	Store::Vector<float> novo(3);

	float aux=0;
	
	
	std::cin>> aux;
	novo.insert(aux,1);

	std::cin>> aux;
	novo.insert(aux,2);

	std::cin>> aux;
	novo.insert(aux,3);

	novo.View();



	Store::Vector<float> novo2(3);

	std::cin>> aux;
	novo2.insert(aux,1);

	std::cin>> aux;
	novo2.insert(aux,2);

	std::cin>> aux;
	novo2.insert(aux,3);

	novo2.View();

	float A;

	A = novo * novo2;

	std::cout<<"El producto punto es: "<< A<<'\n';

	Store::Vector<float>* res= new Store::Vector<float>(3);

	res = novo % novo2;

	std::cout<<"El producto cruz es: ";
	res->View();

	std::cout<< "\n\n\n";

	Store::Vector<float> alea(15);

	

	std::cout<<"El minimo es: ";
	std::cin>>aux;

	float aux2=0;

	std::cout<<"El maximo es: ";
	std::cin>>aux2;

	alea.Random(aux, aux2);


	std::cout<<"El vector es: ";
	alea.View();

	*/

	//std::cout<<"\n\n\n";
	/*
	Store::Matrix<float> Hola(9,9);

	float aux;
	float aux2;


	std::cout<<"El minimo es: ";
	std::cin>>aux;

	std::cout<<"El maximo es: ";
	std::cin>>aux2;


	Hola.Random(aux, aux2);

	Hola.View();

	Hola = Hola * Hola;

	std::cout<<"Hola * Hola =";
	Hola.View();

	std::cout<<"El det de Hola * Hola = "<< Hola.det(Store::fila,1)<< "\n";
	*/
	


	//float aux = 5.0;

	//Store::Vector<float> Temp( 4 , aux );

	//Store::Vector<float> Temp2( 4 , (float)6 );

	//Temp.Per_Component_Product( Temp2 ).View();

	//Store::Vector<float>::Per_Component_Product(Temp,Temp2) ;
	//Store::Vector<float>::Per_Component_Product(Temp , Temp2);

/*
Store::Matrix<float> AUX(6,6);

AUX.Random(0,100);

AUX.View();

Store::Matrix<float> Original;

Original = AUX.Gauss();

AUX.View();
Original.View();
*/

/*
Store::Matrix<float> AUX(5,8);

AUX.Random(0,100);


std::ofstream output("Operaciones.txt" );



if( output.is_open() ){
AUX.Gauss_View_Instantaniusly(output);

output.close();
}

*/


/* Ejemplo Bueno

Store::Matrix<float> AUX(2,3);

//AUX.Random(0,100);

AUX.insert(0.003,1,1);
AUX.insert(59.14,1,2);
AUX.insert(59.17,1,3);
AUX.insert(5.291,2,1);
AUX.insert(6.130,2,2);
AUX.insert(46.78,2,3);


AUX.View(20,4);

//AUX.Gauss_PP();
AUX.Gauss();

AUX.View(20,8);

*/

/*
Store::Matrix<float> AUX(2,3);

AUX.insert(0.003,1,1);
AUX.insert(59.14,1,2);
AUX.insert(59.17,1,3);
AUX.insert(5.291,2,1);
AUX.insert(6.130,2,2);
AUX.insert(46.78,2,3);

//AUX.Random(0,2);

AUX.View(7,2);


Store::Vector<float> Resultado;
Resultado = AUX.Resolve();

std::cout<<"Resultado segun metodo ordinario\n";

Resultado.View(14 ,5);

float he = Resultado.Get_Component(1);

std::cout<<"\nLa componente primera es: "  << he<<'\n';

he = Resultado.Get_Component(2);

std::cout<<"La componente segunda es: " << he<<'\n';


std::cout<<"\n\n\n";



AUX.insert(0.003,1,1);
AUX.insert(59.14,1,2);
AUX.insert(59.17,1,3);
AUX.insert(5.291,2,1);
AUX.insert(6.130,2,2);
AUX.insert(46.78,2,3);


AUX.View(7,2);


std::cout<<"Resultado segun metodo de pivoteo parcial\n";

Resultado = AUX.Resolve_PP();

Resultado.View();


he = Resultado.Get_Component(1);

std::cout<<"\nLa componente primera es: "  << he<<'\n';

he = Resultado.Get_Component(2);

std::cout<<"La componente segunda es: " << he<<'\n';

*/
//Store::Vector<float> (*F)(const Store::Vector<float>&,const Store::Vector<float>&) = Ta//&(Store::Vector<float>::Per_Component_Product) ;
/*
Store::Vector<float> (*F)(const Store::Vector<float>&,const Store::Vector<float>&) = Store::Vector<float>::Cross;

BenchMark::Operator2< Store::Vector<float> > Data( F );

float jaja=5;

float jeje = 6;

Data.Execute(5000,UNO,DOS);

Data.Show_Time();

Data.Equivalence_Table();
*/


/*
typedef float Comp;

typedef Store::Vector<Comp> Vect;

typedef Store::Plus< Vect , Vect , Comp , Comp >  Plus;

typedef Store::Expression< Vect , Comp > E;
*/

//Store::Vector<float> UNO(3, 5);
//Store::Vector<float> DOS(3, 3);

//DOS= UNO*3+DOS*5*UNO*5*2+DOS*3*4+UNO*DOS*2*UNO+UNO-DOS;

//std::ofstream out("Vector.txt");

//DOS.View(16,6,out);

//out.close();


//Classic_Store::Vector<float> CUNO(3, 5);
//Classic_Store::Vector<float> CDOS(3, 3);


//CDOS= CUNO*3+CDOS*5*CUNO*5*2+CDOS*3*4+CUNO*CDOS*2*CUNO+CUNO-CDOS;

//CDOS.View(16,6);

//DOS = UNO+DOS+UNO;
/*
HRTimer Time;

Time.Start();
for(int i=0;( i<1000 ); i++)
DOS= UNO*3+DOS*(5*UNO*5*2+DOS*3*4+UNO*DOS*2*UNO+UNO-DOS);//DOS = UNO*DOS*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO*UNO;
Time.Stop();
double temp = Time.GetDurationInSecs();
std::cout<< "El tiempo en segundos de los templates es "<<temp<<'\n';

Time.Start();
for(int i=0;( i<1000 ); i++)
CDOS= CUNO*3+CDOS*(5*CUNO*5*2+CDOS*3*4+CUNO*CDOS*2*CUNO+CUNO-CDOS);//CDOS = CUNO*CDOS*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO*CUNO;
Time.Stop();
double clas = Time.GetDurationInSecs();
std::cout<< "El tiempo en segundos de los clasicos es "<<clas<<'\n';

std::cout<<"Los templates son " << (clas/temp) <<" veces mas rapidos que los operadores clasicos\n";

/*
std::cout<<"El vector de los clasicos da:\n";
CDOS.View(16,6);

std::cout<<"El vector de los templates da:\n";
DOS.View(16,6);
*/
/*
int o;


Store::Vector<float> K;
Store::Vector<float> Y(201);
Store::Vector<float> Z;

K.Fill_Stair(-10,10,0.1);
Z.Fill_Stair(-10,10,0.1);

Y = K*((1/2.0))+K*Z;

std::cout<<"El Vector antes de guardarlo es: \n";
Y.View();

o = Y.To_Bynary( std::string("Y3") );

if( o == 0 ){
	
	std::cout<<"El archivo NO pudo ser creado o sobreescribido\n";

}
if( o == 1 ){

	std::cout<<"El archivo SI pudo ser creado o sobreescribido\n";	

}
if( o == 3 ){

	std::cout<<"Gravisimo error, no esta definido el encabezado\n";	

}



Store::Vector<float> B;

o = K.To_Bynary( std::string("X3") );



if( o == 0 ){
	
	std::cout<<"El archivo NO se pudo abrir\n";

}
if( o == 1 ){

	std::cout<<"El archivo SI se pudo abrir y leer\n";	

}
if( o == 3 ){

	std::cout<<"No se pudo copiar el .crap al vector, porque no son compatibles\n";	

}

std::cout<<"El Vector despues de ser leido es: \n";
K.View();

Z.To_Bynary(std::string("Z3"));

Z.View();




//Plus (Store::Vector<float>::*F)(const Vect&) = &( Store::Vector<float>::operator&& );

//typedef Plus (Store::Vector<float>::*F)(const Vect&);

//F HEY = &( Store::Vector<float>::operator&& );
/*
BenchMark::Operator1< Vect , E >  Data( &( Store::Vector<float>::operator+ ) );
Data.Execute( 1000, UNO, DOS );
std::cout<<"THE TEMPLATES WAY:\n";
Data.Show_Time();


BenchMark::Operator1< Classic_Store::Vector<float> , Classic_Store::Vector<float> > Data_Classic( &( Classic_Store::Vector<float>::operator+ ) );
Data_Classic.Execute( 1000, CUNO, CDOS);
std::cout<<"THE Classic WAY:\n";
Data_Classic.Show_Time();


Vect ONE(3, 5);
Vect TWO(3, 3);
Store::Vector<float> THREE(3);

THREE= ONE - TWO;*/
/*
Classic_Store::Vector<float> CUNOD(1000000, 5);
Classic_Store::Vector<float> CDOSD(1000000, 3);

BenchMark::Operator1< Vect , Store::Minus<Store::Vector<float>,Store::Vector<float>,float,float >>  DataT( &( Store::Vector<float>::operator- ) );
Data.Execute( 1, ONE, TWO );
std::cout<<"THE TEMPLATES WAY:\n";
Data.Show_Time();

BenchMark::Operator1< Classic_Store::Vector<float> , Classic_Store::Vector<float> > Data_ClassicC( &( Classic_Store::Vector<float>::operator- ) );
Data_Classic.Execute( 1, CUNOD, CDOSD);
std::cout<<"THE Classic WAY:\n";
Data_Classic.Show_Time();
*/

//int i;

//GUI_Helper::Console_Icon ICON;

/*
BenchMark::Element hola;

std::cout<< hola.Increase(2)<<'\n';

std::cout<< hola.Increase(2)<<'\n';

std::cout<< hola.Increase(2)<<'\n';
*/


//i = ICON.From_CHAR_to_BINARY("pi");

//if( i != 0 ){

//	std::cout<<"No se pudo procesar From_CHAR_to_BINARY\n";

//}


/*
i = ICON.Read_Console_Icon( "pi" );

if( i != 0 ){

	std::cout<<"No se pudo procesar Read_Console_Icon\n";

}

ICON.Draw_Console_Icon();
*/

//Store::Plus< Store::Vector<float> , Store::Vector<float> , float , float>;

//Store::Vector<float> TRES;

//TRES = UNO && DOS;

//TRES.View();


/*
unsigned char aux = getch();

std::cout<< (unsigned int)aux << '\n';
*/
/*
void* Function;

Function = MostrarCeros;

void (*F)() = static_cast< void (*)() >(Function);

F();

std::cout<<"\n\n\n\n\n";
std::cout<<(int)(std::string::npos);
std::string aux;
std::getline(std::cin,aux,'\n');


Store::Vector<float> Dom(1);
Dom.Fill_Stair(0,2,0.5);

Store::Vector<float> Im(Dom.Length());
Im = Dom*Dom;


std::cout<<"\n\nLa inegral definida de X^2 desde 0 hasta 100 es: "<<Function_Algorithms::Integration::trapz<float>(Dom,Im)<<"\n\n";
Dom.Fill_Stair(0,2,0.005);
Im = Dom*Dom;

Store::Vector<float> res (2);
//res = Function_Algorithms::Integration::Darboux<float>(Dom,Im);
//Function_Algorithms::Integration::Darboux<float>(Dom,Im);
Function_Algorithms::Integration ko;


std::cout<<"La ntegral exacta esta en este rango: ( ";

res.View_Component(1);

std::cout<<" , ";
res.View_Component(2);

std::cout<<" )\n\n";

LARGE_INTEGER jk;

QueryPerformanceFrequency(&jk);

QueryPerformanceCounter(&jk);











Store::Vector<float> SAS(1);
SAS.Fill_Stair(0,2,0.5);

Store::Vector<float> SES(SAS.Length());
SES = SAS*SAS;


Store::Vector<float> res2 = Function_Algorithms::Derivation::Derivate1_2Puntos<float>(SAS,SES);
res2= Function_Algorithms::Derivation::Derivate1_2Puntos<float>(SAS,res2);
res2= Function_Algorithms::Derivation::Derivate1_2Puntos<float>(SAS,res2);
res2= Function_Algorithms::Derivation::Derivate1_2Puntos<float>(SAS,res2);
std::cout<<"Ahora con la derivacion de segundo orden, pero derivada 4 veces\n";

for( int i=0; i < SAS.Length();i++){
std::cout<<"\nEl dominio en ese punto: ";
SAS.View_Component(i);
std::cout<<"\n\nDerivada en ese punto: ";
res2.View_Component(i);
}

std::cout<<"\n\n\n";

Store::Vector<float> res3 = Function_Algorithms::Derivation::Derivate4_5Puntos(SAS,SES);

std::cout<<"Ahora con la derivacion de segurndo tercer\n";

for( int i=0; i < SAS.Length();i++){
std::cout<<"\nEl dominio en ese punto: ";
SAS.View_Component(i);
std::cout<<"\n\nDerivada en ese punto: ";
res3.View_Component(i);
}

std::cout<<"\n\n\n";
//std::cout<< ;jk.QuadPart;
std::cout<<"\n\n";

Store::Vector<float> Auu(5,2);
Store::Vector<float> Euu(5,3);

Store::Vector<float> jujuju( Auu+Euu);


//GUI::GUI_Helper::Parse(aux);
*/

Store::Vector<double> A(15,2);
Store::Vector<double> B(15,1);

Store::Vector<double> C = A+B;
C.View();

	system("pause");


	return 0;
}


