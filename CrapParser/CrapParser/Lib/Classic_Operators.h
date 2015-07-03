//Esta instruccion preprocesador hace que solo se compile una vez, apesar de que se incluya en varios cpps
#pragma once


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////     Encabezado de la Librearia Classic_Operators      ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////          Librearias que utilizo en el codigo          ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "Store.h"                    /*///////////////////////////*/		  
/*///////////////////////////		      Para heredar de CustomStorage                 ///////////////////////////*/
/*///////////////////////////*/					#include <iostream>					  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


//Estas definiciones tiene rendimiento inferior a las de Store.h
//Su utilidad es para comparar una definicion de operadores de la forma tradicional que contienen estas definiciones
//con el desempeño de las definiciones templatizadas de la libreria Store.h
namespace Classic_Store{


		template<class T>
	class Vector;

	//Fuciones Amigas
		template<class T>
	inline Classic_Store::Vector<T> operator*( const T , const Classic_Store::Vector<T>& );


	template<class T>
class Vector:public Store::CustomStorage<T>{
private:
		

		int Componentes;//Contiene la cantidad de componentes que posee el vector

public:

						//////////////////////////////////////////////////////////////////////
		/////////////////				  	  Lista de Constructores						 /////////////////
						//////////////////////////////////////////////////////////////////////



		//CONSTRUCTOR: Este constructor inicializa el vector con 0 componentes
		Vector();

		//CONSTRUCTOR: Este constructor inicializa el vector por copia
		Vector( const Classic_Store::Vector<T>& );

		//CONSTRUCTOR: Este constructor inicializa un vector, cuya cantidad de 
		//componentes se pasa como parametro
		//Recibe:

		//-Un entero que establece la cantidad de componentes del vector
		//
		//Se inicializan con el valor 0 o equivalente
		Vector( int );

		//CONSTRUCTOR: Este constructor inicializa un vector, se le pasa
		//la cantidad de componentes y el valor que tendran todas
		//Recibe:
		//-Un entero que establece la cantidad de componentes del vector
		//-Un dato que sera el valor de todas las componentes
		Vector( const int , const T& );


						//////////////////////////////////////////////////////////////////////
		/////////////////			    	    Definicion de Miselanio	   	  		         /////////////////
						//////////////////////////////////////////////////////////////////////

		//Muestra el vector por el flujo estandar de salida cout.
		//Recibe:
		//-Un entero que establece el valor de la propiedad setw o width, ie el espacio en el que se coloca una salida
		//-Un entero que establece el valor de la propiedad setprecision o precision, ie el numero de decimales despues de la coma decimal
		//Por defecto setw wa 5
		//Por defecto setprecision es 2
		//Devuelve void
		void View(int=7,int=2);

		//Combierte todas las componentes del vector al valor que se pasa por parametro
		//IE hace (parametro) el vector
		//Devuelve void
		inline void fill( T );

						//////////////////////////////////////////////////////////////////////
		/////////////////				  	    Lista de Operadores	   					     /////////////////
						//////////////////////////////////////////////////////////////////////


	inline Classic_Store::Vector<T> operator+( const Classic_Store::Vector<T>& );

	inline Classic_Store::Vector<T> operator-( const Classic_Store::Vector<T> & );


	//Sobrecarga el operador * con la operacion de producto componente a componente
	inline Classic_Store::Vector<T> operator*( const Classic_Store::Vector<T> & );

	inline Classic_Store::Vector<T> operator*( const T );

	inline friend Classic_Store::Vector<T> operator*( const T A , const Classic_Store::Vector<T>& B ){
		Classic_Store::Vector<T> AUX(B);

		for( int i=0; ( i < B.Componentes ) ; i++ )
			AUX.MC[0][i] *= A;

		return AUX;


	}

	//Esta funcion realiza un producto componente a componente
	inline Classic_Store::Vector<T> Per_Component_Product( const Classic_Store::Vector<T> & );

	//Esta funcion realiza un producto componente a componente
	inline static Classic_Store::Vector<T> Per_Component_Product( const Classic_Store::Vector<T> & , const Classic_Store::Vector<T> & );


	inline T Point_Product( const Classic_Store::Vector<T> & );

	inline static T Point_Product( const Classic_Store::Vector<T> &, const Classic_Store::Vector<T> & );

	inline Classic_Store::Vector<T> Per_Component_Division( const Classic_Store::Vector<T> & );

	inline static Classic_Store::Vector<T> Per_Component_Division( const Classic_Store::Vector<T> & , const Classic_Store::Vector<T> & );

	//Classic_Store::Vector<T> operator%( const Classic_Store::Vector<T> & );

	//Classic_Store::Vector<T> Cross( const Classic_Store::Vector<T> & );

	//static Classic_Store::Vector<T> Cross( const Classic_Store::Vector<T> & A , const Classic_Store::Vector<T> & B );


};






	template<class T>
class Matrix{





	};


}//Fin del nombre de espacios Classic_Store, contenedor de 'esta libreria'





