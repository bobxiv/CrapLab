//Esta instruccion preprocesador hace que solo se compile una vez, apesar de que se incluya en varios cpps
#pragma once




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////          Encabezado de la Librearia Numeric           ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el Encabezado       ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "Store.h"					  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////

/*											Idea Original

								------------Clase Complejo------------
								|									 |
					   	Clase Vectorial/Binomico				Clase Polar

			Utilizando polimorfismo se podria tener arrelos heterogeneos
			Y cambiar de momento a momento para trabajar de las dos maneras

			Problema, en la matriz, no me sirve que sea heterogeneo, ademas si quiero cambiar de
			forma a forma deberia estar formada la matriz (ie MC) de punteros a Clase Complejo
			Pero seria problematico, porque cada vez que se cambia de forma de trabajar, habria que 
			crear una nueva instancia del otro tipo y cambiar a lo que apunta la clase complejo,
			esto se volveria pesado in-nesesariamente. Sumandole a esto el peso de trabajar con la tabla
			de metodos virtuales.

			Asi que se utilizo:

											Clase Complejo

							Podiendo esta clase operar de forma Vectorial/Binomica o Polar
							manejandose con una bandera que es Mode, que es un enum 
							que dice si se trabaja de forma Vectorial/Binomica o Polar


*/


	///Nombre de espacios contenedor de el tipo de dato auxiliares, ensamblablescon Vector y Matrix
namespace Numeric
{
	///Posee dos valores Vectorial_Binomical y Polar
	///Se usa como bandera para poner saber en Complejo de que forma se lo esta operando en este momento
	enum VecBin_Polar{ Vectorial_Binomical , Polar };

	/*
//Concatenacion de Expresiones y operaciones, todavia no implementado
//Suma
#define CpC Store::Plus< Store::Expression< Complejo<T> , T > , Store::Expression< Complejo<T> , T > , T , T >

#define EpC Store::Plus< Store::Expression< A , T > , Store::Expression< Complejo<T> , T > , T , T >

#define CpE Store::Plus< Store::Expression< Complejo<T> , T > , Store::Expression< B , T > , T , T >

#define EpE Store::Plus< Store::Expression< A , T > , Store::Expression< B , T > , T , T >

//Resta
#define CmC Store::Minus< Store::Expression< Complejo<T> , T > , Store::Expression< Complejo<T> , T > , T , T >

#define EmC Store::Minus< Store::Expression< A , T > , Store::Expression< Complejo<T> , T > , T , T >

#define CmE Store::Minus< Store::Expression< Complejo<T> , T > , Store::Expression< B , T > , T , T >

#define EmE Store::Minus< Store::Expression< A , T > , Store::Expression< B , T > , T , T >

//Producto componente a componente
#define CxC Prod< Store::Expression< Complejo<T> , T > , Store::Expression< Complejo<T> , T > , T , T >

#define ExC Prod< Expression< A , T > , Expression< Complejo<T> , T > , T , T >

#define CxE Prod< Expression< Complejo<T> , T > , Expression< B , T > , T , T >

#define ExE Prod< Expression< A , T > , Expression< B , T > , T , T >

//Division componente a componente
#define VdV Div< Expression< Vector<T> , T > , Expression< Vector<T> , T > , T , T >

#define EdV Div< Expression< A , T > , Expression< Vector<T> , T > , T , T >

#define VdE Div< Expression< Vector<T> , T > , Expression< B , T > , T , T >

#define EdE Div< Expression< A , T > , Expression< B , T > , T , T >

//Producto por un escalar
#define VxT Prod< Expression< Vector<T> , T > , T , T , T >

#define ExT Prod< Expression< A , T > , T , T , T >

#define TxE Prod< T , Expression< B , T > , T , T >

#define TxV Prod< T , Expression< Vector<T> , T > , T , T >
*/


	template <class T>
	class Complejo
	{
	private:

		///Vector de dos componentes, la primera Real, la segunda Imaginaria
		///Ademas tiene algunas funcionalidades propias de un vector utiles para esta tarea
		Store::Vector<T> RI;

		///Dice si los valores del complejo estan en forma Vectorial o Binomica(Real, Imaginario)
		///O si estan en forma PolaR_M(Magnitud, Direccion)
		///Dependiendo de este valor es como se ejecuta cada operacion
		VecBin_Polar Mode;

		///Este metodo privado cambia el valor de Mode al contrario y transforma cada componente al modo actual
		void SwitchMode();


	public:

		/*CONSTRUCTOR: Este es un constructor por defecto, no ejecuta ninguna operacion
		*/
		Complejo();

		/*CONSTRUCTOR: Este es un constructor por copia
		*/
		Complejo(const Complejo<T> &B);

		//CONSTRUCTOR: Este constructor inicializa un numero Complejo, se inicializan
		//sus dos componentes en los valores que se le pasa
		//Recibe:
		//-Un dato que sera el valor de la Componente Real del Complejo, o la Magnitud 
		//-Un dato que sera el valor de la Componente Imaginaria del Complejo, o la Direcion
		//-Un VecBin_Polar que dice de que forma se trabajara los complejos
		//Por defecto se trabaja con complejos en forma Vectorial o Binomica
		Complejo(T , T, VecBin_Polar = Vectorial_Binomical);
		

		//CONSTRUCTOR: Este constructor inicializa un numero Complejo, se inicializan
		//sus dos componentes en los valores que se le pasa con el mismo valor
		//Recibe:
		//-Un dato que sera el valor de la Componente Real y la Imaginaria, o la Magnitud y Direcion
		//-Un VecBin_Polar que dice de que forma se trabajara los complejos
		//Por defecto se trabaja con complejos en forma Vectorial o Binomica
		Complejo( T , VecBin_Polar = Vectorial_Binomical);

		//Este metodo devuelve el estado de VecBin_Polar, ie como se esta trabajando el 
		//complejo
		//Devuelve VecBin_Polar
		VecBin_Polar Current_Mode();

		//Este metodo cambia el modo en que se trabaja el complejo, si es vectorial/Binomica o Polar
		//Ademas de cambiarse se producira una transformacion a los valores que correspondan en el metodo asignado
		//Recibe:
		//-El VecBin_Polar para establecer el modo de trabajo
		//Devuelve un VecBin_Polar que era el modo anterior de trabajo
		VecBin_Polar Set_Mode(VecBin_Polar);

		//Este metodo establece cual es el modo actual de trabajo
		//pero no hace converiosnes, solo cambia el valor del identificador
		//Esta pensado para si se carga desde un archibo en un Vector/Matrix que trabajaba de otra forma
		//los complejos, cuando cambie el modo en el que se trabaja no haya converisones, porque en 
		//este caso estarian de mas
		//Devuelve el VecBin_Polar anterior
		//Importante: Utilizar con extrema cautela este metodo
		VecBin_Polar Arbitrari_Set_Mode(VecBin_Polar);


		//Operacion de suma definida matematicamente de la forma tradicional
		Complejo<T> operator+(const Complejo<T>& );

		//Operacion de suma pero uno de los operando es un operando simple y no un Complejo,
		//asi que solo se le suma a la parte real del Complejo
		Complejo<T> operator +(const T&);

		//Operacion de suma definida matematicamente de la forma tradicional, utilizando la asignaicon +=
		void operator +=(const Complejo<T>& );

		//Operacion de suma pero uno de los operando es un operando simple y no un Complejo,
		//asi que solo se le suma a la parte real del Complejo
		//Pero esta implementada utilizando la asignaiocn +=
		void operator +=(const T& );

		//Operacion de resta definida matematicamente de la forma tradicional
		Complejo<T> operator-(const Complejo<T>& );

		//Operacion de resta pero uno de los operando es un operando simple y no un Complejo,
		//asi que solo se le resta a la parte real del Complejo
		Complejo<T> operator -(const T&);

		//Operacion de producto definida matematicamente de la forma tradicional
		Complejo<T> operator*(const Complejo<T>& );

		//Operacion de producto pero uno de los operando es un dato simple,
		//asi que se calcula el producto del dato simple tanto por la componente
		//real ocmo por la imaginaria
		Complejo<T> operator *(const T& );

		//Operacion de division definida matematicamente de la forma tradicional
		Complejo<T> operator/(const Complejo<T>& );

		//Operacion de divicion pero uno de los operando es un dato simple,
		//asi que se calcula el cociente del dato simple tanto por la componente
		//real ocmo por la imaginaria
		Complejo<T> operator /(const T& );

		//Operador de asignacion
		Complejo<T>& operator=( const Complejo<T>& B );

		T operator[]( const int );

		//La Componente Real
		//Recibe:
		//-El dato que se ingresara
		//Devuelve el dato anterior a la asignacion
		//
		//Nombre Completo: Real/Modulo  (asignacion)
		inline T R_M(const T);

		//La Componente Real
		//Devuelve el valor de la componente
		//
		//Nombre Completo: Real/Modulo  (obtencion)
		inline T R_M() const;

		//La Componente Imaginaria
		//Recibe:
		//-El dato que se ingresara
		//Devuelve el dato anterior a la asignacion
		//
		//Nombre Completo: Imaginario/Argumento   (asignacion)
		inline T I_A(const T);

		//La Componente Real
		//Devuelve el valor de la componente
		//
		//Nombre Completo: Imaginario/Argumento   (obtencion)
		inline T I_A() const;

		//Muestra el Complejo por el flujo estandar de salida cout
		//El formato es (Real, Imaginario)
		//Recibe:
		//-Un entero que establece el valor de la propiedad setw o width, ie el espacio en el que se coloca una salida
		//-Un entero que establece el valor de la propiedad setprecision o precision, ie el numero de decimales despues de la coma decimal
		//Por defecto setw wa 5
		//Por defecto setprecision es 2
		//Devuelve void
		//
		//Nombre Completo: View Vectorial
		void View_V(int=7,int=2);


		//El formato es (Real) +/- (Imaginario)i
		//Recibe:
		//-Un entero que establece el valor de la propiedad setw o width, ie el espacio en el que se coloca una salida
		//-Un entero que establece el valor de la propiedad setprecision o precision, ie el numero de decimales despues de la coma decimal
		//Por defecto setw wa 5
		//Por defecto setprecision es 2
		//Devuelve void
		//
		//Nombre Completo: View Binomical
		void View_B(int=7,int=2);



	};


	//Sobrecarga para sacarlo por el flujo de salida estandar en clase Matrix

	template<class T>
std::ostream& operator << ( std::ostream & OS , const Numeric::Complejo<T> & SALIDA ) {
	OS << "(" << SALIDA.R_M() << ", " << SALIDA.I_A() << ")" << '\n';

	return (OS);
}
/*
	template<class T>
void operator =( int A , Numeric::Complejo<T>& B ){

	//A  = 	(int)B.R_M();

	
}
*/





}//Fin del nombre de espacios Numeric, contenedor de 'esta libreria'

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////       Fin del Encabezado de la Librearia Numeric      ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////