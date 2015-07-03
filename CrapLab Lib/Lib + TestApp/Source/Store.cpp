/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////      Librearia precompilada de Visual Studio 2008     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "stdafx.h"				      /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////
 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el codigo           ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include <cmath>					  /*///////////////////////////*/
/*///////////////////////////*/					#include <iostream>					  /*///////////////////////////*/
/*///////////////////////////*/					#include <fstream>					  /*///////////////////////////*/
/*///////////////////////////*/					#include <conio.h>					  /*///////////////////////////*/
/*///////////////////////////*/					#include <ctime>					  /*///////////////////////////*/
/*///////////////////////////*/					#include <string>					  /*///////////////////////////*/
/*///////////////////////////*/					#include "..\Headers\Numeric.h"		  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////             Encabezado de la librearia                ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "..\Headers\Store.h"			  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Codigo de la Definicion del nombre de espacios Store  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	namespace Store
	{


							  ////////////////////////////////////////////////////////
		///////////////////////           Implementacion de Clase Vector             ///////////////////////
							  ////////////////////////////////////////////////////////


#include "Source_Modules\Vector.h"


							  ////////////////////////////////////////////////////////
		///////////////////////         Fin de Implementacion de Clase Vector        ///////////////////////
							  ////////////////////////////////////////////////////////



using namespace std;


	
						//////////////////////////////////////////////////////////////////////
		/////////////////					Implementacion de Clase Matrix					 /////////////////
						//////////////////////////////////////////////////////////////////////


#include "Source_Modules\Matrix_Basic.h"

#include "Source_Modules\Matrix_Elemental_Operations.h"

#include "Source_Modules\Matrix_Advance.h"

#include "Source_Modules\Matrix_Arithmetics.h"


						//////////////////////////////////////////////////////////////////////
		/////////////////			  Fin de Implementacion de Clase Matrix					 /////////////////
						//////////////////////////////////////////////////////////////////////


						//////////////////////////////////////////////////////////////////////
		/////////////////					Implementacion de Clase MatrixX 				 /////////////////
						//////////////////////////////////////////////////////////////////////



						//////////////////////////////////////////////////////////////////////
		/////////////////			  Fin de Implementacion de Clase MatrixX				 /////////////////
						//////////////////////////////////////////////////////////////////////





}//Fin del nombre de espacios Store, contenedor de 'esta libreria'



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////     Fin del Codigo del nombre de espacios Store       ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template class Store::Matrix<double>;

template class Store::Matrix<float>;

template class Store::Matrix<int>;


template class Store::Vector<double>;

template class Store::Vector<float>;

template class Store::Vector<int>;

/*
template class Store::Vector< Numeric::Complejo<double> >;

template class Store::Vector< Numeric::Complejo<float> >;

template class Store::Vector< Numeric::Complejo<int> >;
*/
	