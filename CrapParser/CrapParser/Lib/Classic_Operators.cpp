/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////      Librearia precompilada de Visual Studio 2008     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "stdafx.h"				      /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////             Encabezado de la librearia                ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/			#include "Classic_Operators.h"                /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el codigo           ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include <iostream>                   /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////        Codigo de la Librearia Classic_Operators       ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Classic_Store{

						//////////////////////////////////////////////////////////////////////
		/////////////////				    Definicion de Constructores						 /////////////////
						//////////////////////////////////////////////////////////////////////

	template<class T>
Vector<T>::Vector()
{
	this->Componentes=0;

	this->MC = new T* [1];

	this->MC[0] = new T [0];

}

	template<class T>
	Vector<T>::Vector(const Classic_Store::Vector<T> &B)
{

	this->Componentes = B.Componentes;

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes] ;
	


	for(int i=0 ; ( i < this->Componentes ) ; i++ )
		this->MC[0][i] = B.MC[0][i];
	
	
}

	template<class T>
Vector<T>::Vector(int cant)
{
	this->Componentes = cant;

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes];


	for(int i=0;( i< this->Componentes ); i++)
		this->MC[0][i] = 0;

}

	template<class T>
Vector<T>::Vector(const int cant,const T& val)
{
	
	this->Componentes = cant;

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes];


	

	for(int i=0;( i< this->Componentes ); i++)
		this->MC[0][i] = val;


}

						//////////////////////////////////////////////////////////////////////
		/////////////////			    	    Definicion de Miselanio	   	  		         /////////////////
						//////////////////////////////////////////////////////////////////////

	template<class T>
void Classic_Store::Vector<T>::View(int spc,int pres){


	if( this->Componentes > 0 ){//si esta vacio que no deje especio

	//para que deje algun lugar cuando empieza a mostrar el vector
	std::cout<<'\n';

	//if(false){

	//todo esto es simplemente un ajuste de presicion a pata
	//T er = (9.0/(powf(10,(pres+1))));

	//T mostrar = 0;

	//for( int i=0; ( i < this->Componentes) ; i++ ){

	//	mostrar=this->MC[0][i];

	//	if(abs(mostrar - (static_cast<int>(mostrar) )) <= er){
	//			cout.width(std::streamsize(spc));
	//			cout<</*setw(spc)<<setprecision(pres)<<*/ ((int)(*(MC+0))[i]);}
	//			else{
				//cout.precision(std::streamsize(pres));
	//			cout.width(std::streamsize(spc));
				
	//			cout<</*setw(spc)<<setprecision(pres)<<*/ (*(MC+0))[i];	
	//	}
	
	//}

	//}
	

	//El metodo de er, no sirve, nose porque lo hize, por eso lo guarde por las dudas, pero no hay qeu usarlo, 
	//poruqe no hace nada nuevo
	for( int i=0; ( i < this->Componentes) ; i++ ){
	
		std::cout.precision( std::streamsize(pres) );

		std::cout.width( std::streamsize(spc) );
		
		std::cout<< MC[0][i];
	}
	



	//Para que deje algun espacio despues de mostrar
	std::cout<<'\n';

		}
	
}


	template<class T>
inline void Classic_Store::Vector<T>::fill( T val){

	for(int i=0;( i<this->Componentes ); i++)
		MC[0][i] = val;


}


						//////////////////////////////////////////////////////////////////////
		/////////////////				    Definicion de Operadores	   				     /////////////////
						//////////////////////////////////////////////////////////////////////


	template<class T>
inline Classic_Store::Vector<T> Classic_Store::Vector<T>::operator+( const Classic_Store::Vector<T>& B ){
	
	Classic_Store::Vector<T> AUX(this->Componentes);


	if( this->Componentes == B.Componentes ){

		 
	
		for( int i=0; ( i < this->Componentes) ; i++ )
			AUX.MC[0][i] = ( this->MC[0][i] + B.MC[0][i] ); 		

		return AUX;

}
	
	//si no esta definida, es decir no tiene la misma cantidad de componentes entonces
	//devuelve un vector llenos de -9999, de dimension del primer operando

	AUX.fill( static_cast<T>(-9999) );

	return AUX;
	
}

	template<class T>
inline Classic_Store::Vector<T> Classic_Store::Vector<T>::operator-( const Classic_Store::Vector<T>& B )
{

	Classic_Store::Vector<T> AUX(this->Componentes);


	if( this->Componentes == B.Componentes ){

		
	
		for( int i=0; ( i < this->Componentes) ; i++ )
			AUX.MC[0][i] = ( this->MC[0][i] - B.MC[0][i] ); 		

		return AUX;

	}


		
	//si no esta definida, es decir no tiene la misma cantidad de componentes entonces
	//devuelve un vector llenos de -9999, de dimension del primer operando

	AUX.fill( static_cast<T>(-9999) );

	return AUX;
	
}

	template<class T>
inline Classic_Store::Vector<T> Classic_Store::Vector<T>::operator*( const Classic_Store::Vector<T> & B ){

	Classic_Store::Vector<T> AUX( this->Componentes );

	//Se ejecuta si son de la misma cantidad de componentes
	if( this->Componentes == B.Componentes ){

		for( int i=0; ( i < this->Componentes ) ; i++ ){

			AUX.MC[0][i] = ( this->MC[0][i] * B.MC[0][i] );

		}

		return AUX;
	
	}

	//sino devuelve un vector tamaño de this->Componentes con puros -9999

	for( int i=0; ( i < this->Componentes ) ; i++ ){

			AUX.MC[0][i] = ( -9999 );

		}

	return AUX;



}

	template<class T>
inline Classic_Store::Vector<T> Classic_Store::Vector<T>::operator*( const T B ){

	Classic_Store::Vector<T> AUX(*this);

	for( int i=0; ( i < this->Componentes ) ; i++ )
		AUX.MC[0][i] *= B;

	return AUX;


}



	template<class T>
inline Classic_Store::Vector<T> Classic_Store::Vector<T>::Per_Component_Product( const Classic_Store::Vector<T>& B){
	

	Classic_Store::Vector<T> AUX( this->Componentes );

	//Se ejecuta si son de la misma cantidad de componentes
	if( this->Componentes == B.Componentes ){

		for( int i=0; ( i < this->Componentes ) ; i++ ){

			AUX.MC[0][i] = ( this->MC[0][i] * B.MC[0][i] );

		}

		return AUX;
	
	}

	//sino devuelve un vector tamaño de this->Componentes con puros -9999

	for( int i=0; ( i < this->Componentes ) ; i++ ){

			AUX.MC[0][i] = ( -9999 );

		}

	return AUX;


}

	template<class T>
	inline static Classic_Store::Vector<T> Per_Component_Product( const Classic_Store::Vector<T> & A , const Classic_Store::Vector<T> & B ){

	Classic_Store::Vector<T> AUX( A.Componentes );

	//Se ejecuta si son de la misma cantidad de componentes
	if( A.Componentes == B.Componentes ){

		for( int i=0; ( i < A.Componentes ) ; i++ ){

			AUX.MC[0][i] = ( A.MC[0][i] * B.MC[0][i] );

		}

		return AUX;
	
	}

	//sino devuelve un vector tamaño de A.Componentes con puros -9999

	for( int i=0; ( i < A.Componentes ) ; i++ ){

			AUX.MC[0][i] = ( -9999 );

		}

	return AUX;


	}

	template<class T>
	inline T Classic_Store::Vector<T>::Point_Product( const Classic_Store::Vector<T> & B ){

		T tot=0;

	if( this->Componentes == B.Componentes ){

		
		T aux=0;

 

		for( int i=0; ( i < this->Componentes) ; i++ ){
			aux = ( this->MC[0][i] * B.MC[0][i] ); 	

			tot += aux;
		}

		

		return tot;
		
	}
	
	//si no esta definida, es decir no tiene la misma cantidad de componentes entonces
	//devuelve un valor -9999

	tot= -9999;

	return tot;

}

		
	template<class T>
	inline T Point_Product(const Store::Vector<T> & A, const Store::Vector<T> & B){
	
	T tot=0;

	if( A.Componentes == B.Componentes ){

		
		T aux=0;
	
 

		for( int i=0; ( i < A.Componentes) ; i++ ){
			aux = ( A.MC[0][i] * B.MC[0][i] ); 	

			tot += aux;
		}

		

		return tot;

	}

	//si no esta definida, es decir no tiene la misma cantidad de componentes entonces
	//devuelve un valor -9999

	tot= -9999;

	return tot;

}

	template<class T>
	inline Classic_Store::Vector<T> Classic_Store::Vector<T>::Per_Component_Division( const Classic_Store::Vector<T> & B ){
	
	Classic_Store::Vector<T> AUX( this->Componentes );

	//Se ejecuta si son de la misma cantidad de componentes
	if( this->Componentes == B.Componentes ){

		for( int i=0; ( i < this->Componentes ) ; i++ ){

			AUX.MC[0][i] = ( this->MC[0][i] / B.MC[0][i] );

		}

		return AUX;
	
	}

	//sino devuelve un vector tamaño de this->Componentes con puros -9999

	for( int i=0; ( i < this->Componentes ) ; i++ ){

		AUX.MC[0][i] = ( -9999 );

	}

	return AUX;

}

	template<class T>
	inline Classic_Store::Vector<T> Per_Component_Division( const Classic_Store::Vector<T>& A , const Classic_Store::Vector<T>& B ){

	Classic_Store::Vector<T> AUX( A.Componentes );

	//Se ejecuta si son de la misma cantidad de componentes
	if( A.Componentes == B.Componentes ){

		for( int i=0; ( i < A.Componentes ) ; i++ ){

			AUX.MC[0][i] = ( A.MC[0][i] / B.MC[0][i] );

		}

		return AUX;
	
	}

	//sino devuelve un vector tamaño de A.Componentes con puros -9999

	for( int i=0; ( i < A.Componentes ) ; i++ ){

		AUX.MC[0][i] = ( -9999 );

	}

	return AUX;

}





}//Fin del nombre de espacios Classic_Store, contenedor de 'esta libreria'

template class Classic_Store::Vector<double>;
	
template class Classic_Store::Vector<float>;

template class Classic_Store::Vector<int>;



//Instanciacion explicita de las funciones amigas de Clasic_Store
template Classic_Store::Vector<double> operator*(const double, const Classic_Store::Vector<double>& );

template Classic_Store::Vector<float> operator*(const float, const Classic_Store::Vector<float>& );

template Classic_Store::Vector<int> operator*(const int, const Classic_Store::Vector<int>& );



template class Classic_Store::Matrix<double>;
	
template class Classic_Store::Matrix<float>;

template class Classic_Store::Matrix<int>;
