//Esta instruccion preprocesador hace que solo se compile una vez, apesar de que se incluya en varios cpps
#pragma once



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////     Encabezado de la Librearia Function_Algorithms    ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el Encabezado       ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "Store.h"					  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////

	///Nombre de espacios contenedor de todas funciones de la libreria de funciones
	///Permite operaciones de integracion y derivacion
namespace Function_Algorithms{


static class Integration{
private:

	template<class T>
static inline T SumaInferior( const Store::Vector<T>& X, const Store::Vector<T>& F ){

	if( X.Length() != F.Length() ){
		//no se corresponden las ternas de datos, no se calculara
		return -1;
	}

	T s=0;

	for(int i=0;i < (X.Length()-1); i++){
		T delX = X[i+1]-X[i];
		// A = b * h
			// donde h es la altura
			// b es el base
			
		/*	
					_____________		Este rectangulo tiene la altura de la componente y vecina menor
				   |			 |		de esta forma la suma de todas estas areas dara la Suma Inferior de la funcion
				   |			 |
				   |			 | ---> h 
				   |			 |
				   |			 |
				   |			 |
				   |_____________|
						  |
						  V
						  b
		*/
		if( F[i] < F[i+1] ){ 
			s += delX * F[i];
		}else{
			s += delX * F[i+1];
		}
	}
	
	return s;
	
}

	template<class T>
static inline T SumaSuperior( const Store::Vector<T>& X, const Store::Vector<T>& F ){

	if( X.Length() != F.Length() ){
		//no se corresponden las ternas de datos, no se calculara
		return -1;
	}

	T s=0;

	for(int i=0;i < (X.Length()-1); i++){
		T delX = X[i+1]-X[i];
		// A = b * h
			// donde h es la altura
			// b es el base
			
		/*	
					_____________		Este rectangulo tiene la altura de la componente y vecina mayor
				   |			 |		de esta forma la suma de todas estas areas dara la Suma Superior de la funcion
				   |			 |
				   |			 | ---> h 
				   |			 |
				   |			 |
				   |			 |
				   |_____________|
						  |
						  V
						  b
		*/
		if( F[i+1] < F[i] ){ 
			s += delX * F[i];
		}else{
			s += delX * F[i+1];
		}
	}
	
	return s;
	
}


public:


///Este metodo templatizado calcula la integral de la funcion representada por el dominio, primer parametro, y funcion, segundo parametro
///Se realiza una aproximacion del area, sumando todas las areas que se forman con los trapezios de xi-xi+1 y las yi+yi+1
///La integral se calcula con bordes cerrados
///
///@param Vector<T> terna de valores del dominio de la funcion
///@param Vector<T> terna de valores de la imagen de la funcion
///
///@return T integral definida de la funcion de F, desde el primer elemento de X hasta el ultimo
	template<class T>
static T trapz( const Store::Vector<T>& X, const Store::Vector<T>& F ){

	if( X.Length() != F.Length() ){
		//no se corresponden las ternas de datos, no se calculara
		return -1;
	}

	T s=0;

	for(int i=0;i < (X.Length()-1); i++){
		T delX = X[i+1]-X[i];
		// A = (1/2) * h * ( b1 + b2 )
			// donde h es la altura, ie distancia entre las lineas paralelas
			// b1 es el lado mayor, o base "mayor"
			// b2 es el lado menor, o base "menor"

		/*		Trapezoide: cuadrilatero con 2 lados paralelos y 2 no-paralelos		
							-----
					    ----     |		Este trapezoide representa una "porcion de mi funcion"
				    ----         |
				   |			 |
				   |			 |
		   b2 <--- |			 | ---> b1 
				   |			 |
				   |			 |			(si el decir base a ese lado y altura a esa es poco feliz...
				   |			 |				pero es ua notacion)
				   |_____________|
						  |
						  V
						  h
		*/
		s += (0.5*delX)*( F[i+1] + F[i] );
	}
	
	return s;
	
}

	template<class T>
 Store::Vector<T> Darboux(Store::Vector<T>& X,Store::Vector<T>& F){

	if( X.Length() != F.Length() ){
		return -1;
	}

		Store::Vector<T> s(2);

		s[0]=SumaInferior(X,F);
		s[1]=SumaSuperior(X,F);

		return s;

}

};//Fin de clase Integration

static class Derivation{
private:


public:

	///Esta funcion calcula la derivada primera de todo un rango de datos utilizando una formula de 2 puntos
	///En las fronteras utiliza formulas de el mismo numero de puntos adelantadas y atrasadas respectivamente
	///El error cometido por truncamiento es del orden de O(h) y por redonde aproximadamente O(1/h), esto en el interior, no en la frontera
	///@param Store::Vector<T> el dominio de la funcion, funciona mejor si son puntos cercanos enre si
	///@param Store::Vector<T> la imagen de la funcion
	///@return Store::Vector<T> la terna de datos con los resultados de la derivada
		template<class T>
	static Store::Vector<T> Derivate1_2Puntos( Store::Vector<T>& X , Store::Vector<T>& F){

		if( X.Length() != F.Length() ){
			return -1;
		}

			//		M = posicion final
			int M = X.Length()-1;

		Store::Vector<T> s(M+1);

		for( int i =0;i < (M); i++){

			//		formula adelantada 1 punto
			//	f′(x) =  ( f(x + h) − f(x) ) / h
			s[i] = ( F[i+1] - F[i] ) / (X[i+1] - X[i]);

		}

		//		formula atrasada 1 punto
		//	f'(x) = (-f(x-h)+f(x)) / h
		s[M]= ((-1)*F[M-1]+F[M]) / (X[M]-X[M-1]);

		return s;

	}

	///Esta funcion calcula la derivada primera de todo un rango de datos utilizando una formula de 2 puntos
	///En las fronteras utiliza formulas de el mismo numero de puntos adelantadas y atrasadas respectivamente
	///El error cometido por truncamiento es del orden de O(h^2) y por redonde aproximadamente O(1/h^2), esto en el interior, no en la frontera
	///@param Store::Vector<T> el dominio de la funcion, funciona mejor si son puntos cercanos enre si
	///@param Store::Vector<T> la imagen de la funcion
	///@return Store::Vector<T> la terna de datos con los resultados de la derivada
		template<class T>
	static Store::Vector<T> Derivate1_3Puntos( Store::Vector<T>& X , Store::Vector<T>& F){

		if( X.Length() != F.Length() ){
			return -1;
		}


			//		M = posicion final
			int M = X.Length()-1;

		Store::Vector<T> s( M+1 );

		//		formula adelantada 2 puntos
		//	f'(1) = (-f(3)+4*f(2)-3*f(1)) / 2h;
		s[0]= ( (-1)*F[2] + 4*F[1] - 3*F[0]) / ((X[1] - X[0])*2);

		for( int i =1;i < M; i++){

			//		formula adelantada 1 punto y atrasada 1 punto
			//	f′(x) =  ( f(x + h) − f(x) ) / 2h
			s[i] = ( F[i+1] - F[i-1] ) / ((X[i+1] - X[i])*2);

		}

		//		formula atrasada 2 puntos
		//	f'(M) = (f(M-2)-4*f(M-1)+3*f(M)) / 2h;
		s[M]= (F[M-2] - 4*F[M-1] + 3*F[M] ) / ((X[M] - X[M-1])*2);

		return s;

	}

	///Esta funcion calcula la derivada segunda de todo un rango de datos utilizando una formula de 3 puntos
	///En la primera frontera utiliza una formula delantada y en la ultima frontera es la copia del ante ultimo
	///El error cometido por truncamiento es del orden de O(h^2) y por redonde aproximadamente O(1/h^2), esto en el interior, no en la frontera
	///@param Store::Vector<T> el dominio de la funcion, funciona mejor si son puntos cercanos enre si
	///@param Store::Vector<T> la imagen de la funcion
	///@return Store::Vector<T> la terna de datos con los resultados de la derivada
		template<class T>
	static Store::Vector<T> Derivate2_3Puntos( Store::Vector<T>& X , Store::Vector<T>& F){

		if( X.Length() != F.Length() ){
			return -1;
		}

			//		M = posicion final
			int M = X.Length()-1;

		Store::Vector<T> s( M+1 );

		//		formula adelantada 2 puntos
		//	f''(1) = (f(3) - 2*f(2) +f(1) / 2h;	notar que entre parenesis aca esta en base 1
		s[0]= (F[2] - 2*F[1] + F[0]) / ( pow( (X[1] - X[0]),2 ) );

		for( int i =1;i < M; i++){

			//		formula adelantada 1 punto y atrasada 1 punto
			//	f′'(x) =  ( f(x + h) - 2*f(x) + f(x - h) ) / (h^2)
			s[i] = ( F[i+1] - 2*F[i] + F[i-1] ) / ( pow( (X[i+1] - X[i]),2 ) );

		}

		
		//		Nose como deducir unaformula atrasada a tres puntos... ni si es que la hay
		//	entonces tendra el mismo valor que en le punto anterior
		s[M]= s[M-1];

		return s;

	}

	///Esta funcion calcula la derivada tercera de todo un rango de datos utilizando una formula de 5 puntos
	///En la primera frontera(dos componentes) utiliza una formula delantada y en la ultima frontera(dos componentes) es la copia del anterior valor
	///El error cometido por truncamiento es del orden de O(h^2) y por redonde aproximadamente O(1/h^2), esto en el interior, no en la frontera
	///@param Store::Vector<T> el dominio de la funcion, funciona mejor si son puntos cercanos enre si
	///@param Store::Vector<T> la imagen de la funcion
	///@return Store::Vector<T> la terna de datos con los resultados de la derivada
		template<class T>
	static Store::Vector<T> Derivate3_4Puntos( Store::Vector<T>& X , Store::Vector<T>& F){

		if( X.Length() != F.Length() ){
			return -1;
		}

			//		M = posicion final
			int M = X.Length()-1;

		Store::Vector<T> s( M+1 );

		//		formula adelantada 2 puntos
		//	f'''(1) = ( f(4) − 3*f(3) + 3*f(2) − f(1) ) / h^3; notar que entre parenesis aca esta en base 1
		s[0]= ( F[3] - 3*F[2] + 3*F[1] - F[0] ) / ( pow( (X[1] - X[0]),3 ) );

		s[1]= ( F[4] - 3*F[3] + 3*F[2] - F[1] ) / ( pow( ( X[2] - X[1]),3 ) );

		for( int i =2;i < (M-1); i++){

			//		formula adelantada 2 punto y atrasada 2 punto
			//	f′''(x) =  ( f(x+2h) − 2*f(x+h) + 2*f(x-h) − f(x-2h) ) / (2h^3)
			s[i] = ( F[i+2] - 2*F[i+1] + 2*F[i-1] - F[i-2] ) / ( pow( (X[i+1] - X[i]),3 ) );

		}

		
		//		Nose como deducir unaformula atrasada a tres puntos... ni si es que la hay
		//	entonces tendra el mismo valor que en le punto anterior
		s[M-1]= s[M-2];
		s[M]= s[M-1];

		return s;

	}

	///Esta funcion calcula la derivada tercera de todo un rango de datos utilizando una formula de 5 puntos
	///En la primera frontera(dos componentes) utiliza una formula delantada y en la ultima frontera(dos componentes) es la copia del anterior valor
	///El error cometido por truncamiento es del orden de O(h^2) y por redonde aproximadamente O(1/h^2), esto en el interior, no en la frontera
	///@param Store::Vector<T> el dominio de la funcion, funciona mejor si son puntos cercanos enre si
	///@param Store::Vector<T> la imagen de la funcion
	///@return Store::Vector<T> la terna de datos con los resultados de la derivada
		template<class T>
	static Store::Vector<T> Derivate4_5Puntos( Store::Vector<T>& X , Store::Vector<T>& F){

		if( X.Length() != F.Length() ){
			return -1;
		}

			//		M = posicion final
			int M = X.Length()-1;

		Store::Vector<T> s( M+1 );

		//		formula adelantada 4 puntos
		//	f′'''(x) = ( f(4) − 4*f(3) + 6*f(2) − 4*f(1) + f(0) ) / h^4; notar que entre parenesis aca esta en base 1
		s[0]= ( F[4] - 4*F[3] + 6*F[2] - 4*F[1] + F[0] ) / ( pow( (X[1] - X[0]),4 ) );
		s[1]= ( F[5] - 4*F[4] + 6*F[3] - 4*F[2] + F[1] ) / ( pow( (X[2] - X[1]),4 ) );
		s[2]= ( F[6] - 4*F[5] + 6*F[4] - 4*F[3] + F[2] ) / ( pow( (X[3] - X[2]),4 ) );
		s[3]= ( F[7] - 4*F[6] + 6*F[5] - 4*F[4] + F[3] ) / ( pow( (X[4] - X[3]),4 ) );

		for( int i =4;i < (M-1); i++){

			//		formula adelantada 2 punto y atrasada 2 punto
			//	f′'''(x) =  ( f(x+2h) − 4*f(x+h) + 6*f(x) − 4*f(x-h) + f(x-2h) ) / h^4
			s[i] = ( F[i+2] - 4*F[i+1] + 6*F[i] - 4*F[i-1] + F[i-2] ) / ( pow( (X[i+1] - X[i]),4 ) );

		}

		
		//		Nose como deducir unaformula atrasada a cinco puntos... ni si es que la hay
		//	entonces tendra el mismo valor que en le punto anterior
		s[M-1]= s[M-2];
		s[M]= s[M-1];

		return s;

	}

};//Fin de clase Derivation


}//Fin de Function_Algorithms