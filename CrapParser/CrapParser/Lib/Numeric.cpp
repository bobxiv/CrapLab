/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////      Librearia precompilada de Visual Studio 2008     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "stdafx.h"				      /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el codigo           ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "Store.h"		              /*///////////////////////////*/
/*///////////////////////////*/					#include <iostream>                   /*///////////////////////////*/
/*///////////////////////////*/					#include <cmath>                      /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////             Encabezado de la librearia                ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "Numeric.h"         		  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////            Codigo de la Librearia Numeric             ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	namespace Numeric
	{


	
						//////////////////////////////////////////////////////////////////////
		/////////////////					Implementacion de Clase Numeric					 /////////////////
						//////////////////////////////////////////////////////////////////////


				template <class T>
		void Complejo<T>::View_V( int , int )
		{
	
			//El formato que usa es ( Real , Imaginario )
			std::cout<< "( " << this->RI.Get_Component(1) << ", " << this->RI.Get_Component(2) << ")\n";



		}


		template<class T>
		void Complejo<T>::View_B(int=7,int=2){

		//El formato que usa es ( Real , Imaginario )
		std::cout<< this->RI.Get_Component(1);
			
		if( this->RI.Get_Component(2) >= 0 ){
				
			std::cout<< " +";
				
		}else{
			std::cout<< " -";
				
		}
			
		std::cout<< " " << this->RI.Get_Component(2) << "i\n";


		}


			template <class T>
		Complejo<T>::Complejo()
		{
			this->RI.Resize(2);
			
			

		}

			template <class T>
		Complejo<T>::Complejo(const Complejo<T> &B)
		{
			this->RI.Resize(2);

			this->R_M( B.R_M() );

			this->I_A( B.I_A() );
			

		}

			template <class T>
		Complejo<T>::Complejo( T Real, T Imaginario, VecBin_Polar M)
		{	
			this->RI.Resize(2);

			this->Mode = M;

			this->RI.insert(Real , 1);

			this->RI.insert(Imaginario, 2);

		}

			template <class T>
		Complejo<T>::Complejo(T Ambos,  VecBin_Polar M)
		{

			this->RI.Resize(2);

			this->Mode = M;

			this->RI.insert(Ambos, 1);

			this->RI.insert(Ambos, 2);
			

		}



			template<class T>
		VecBin_Polar Complejo<T>::Current_Mode(){

			return ( this->Mode );

		}



			template<class T>
		VecBin_Polar Complejo<T>::Set_Mode(VecBin_Polar NEW_MODE){

			if( this->Mode != NEW_MODE ){

				this->SwitchMode();

				if( this->Mode == Vectorial_Binomical )
					return Polar;
				else
					return Vectorial_Binomical;

			}else

			//Porque el que se introdujo y el que estaban son el mismo
			//asi que no hago nada y el dato anterior es igual al que ingreso recien
			return NEW_MODE;

		}

			template<class T>
		VecBin_Polar Numeric::Complejo<T>::Arbitrari_Set_Mode(VecBin_Polar NEW_MODE){

			Numeric::VecBin_Polar Previus_MODE = this->Mode;

			this->Mode = NEW_MODE;

			return Previus_MODE;


		}


			template<class T>
		void Complejo<T>::SwitchMode(){
/*
			switch( this->Mode ){

				case ( Vectorial_Binomical ):
					{

						//Metodo:

						// M*M = R*R + I*I
						// M = (R*R + I*I)^(1/2)
						T Magnitud;

						Magnitud = sqrt( this->R_M() * this->R_M() + this->I_A() * this->I_A() );
						
						// sin( Q ) = I_A(cateto opuesto) / M
						// asin( sin( Q ) ) = Q
						//						Siendo Q el argumento
						T Argumento = ( this->I_A() / Magnitud );

						Argumento = asin( Argumento );

						//Sino se podria sacar el cos( Q ) y con el sen y cos sacar el angulo pero es mas lento
						//T Cos_Argumento = ( this->R_M() / M );

						this->RI.insert( Magnitud , 1 );

						this->RI.insert( Argumento , 2 );

						this->Mode = Polar;

						break;
					}
				case ( Polar ):
					  {

						  //Metodo:

						  // senQ = I/M
						  // senQ * M = I
						  //				Siendo Q el Argumento
						  T Imaginario =( sin( this->I_A() ) * this->R_M() );

						this->RI.insert( Imaginario , 2 );

						//Teorema de Pitagoras:
						// M*M = R*R + I*I;
						// M*M - I*I = R*R
						// (M*M - I*I)^(1/2) = R
						
						this->RI.insert( sqrt(this->R_M() * this->R_M() - Imaginario * Imaginario ) , 1 );

						this->Mode = Vectorial_Binomical;


						break;

					  }


			}//aca termina el switch, y hasta aca ya se cambio el Mode y los valores

		*/	
		}



			template<class T>
		inline T Complejo<T>::R_M() const{


			return ( this->RI.Get_Component(1) );


		}

			template<class T>
		inline T Complejo<T>::R_M(const T val){

			T aux= ( this->RI.Get_Component(1) );
			
			this->RI.insert(val, 1);

			return aux;

			}

			template<class T>
		inline T Complejo<T>::I_A(const T val){

			T aux= this->RI.Get_Component(2);

			this->RI.insert(val ,2 );

			return aux;

			}

			template<class T>
		inline T Complejo<T>::I_A() const{

			return ( this->RI.Get_Component(2) );

		}

		

			template <class T>
		Complejo<T> Complejo<T>::operator+(const Complejo<T> &B )
		{

			
			Complejo<T> AUX;
			
			//pregunto si es que estan trabajando con el mimo modo, sino no tendria sentido el resultado
			if( this->Mode == B.Mode ){

				switch( this->Mode ){

				
					case ( Vectorial_Binomical ):
						{
							AUX.RI = ( this->RI + B.RI );

							AUX.Mode = Vectorial_Binomical;

							break;
						}

					case ( Polar ) :
						{

							AUX.RI = this->R_M() + B.R_M();

							AUX.RI = this->I_A() * B.I_A();

							AUX.Mode = Polar;

							break;
						}




				}
			

				//devuelvo el resultado despues de procesado
			return AUX;





			}else
			{// sino no estan trabajando conel mismo modo

				AUX.RI.fill(-9999);
				return AUX;

			}

		}


			template <class T>
		Complejo<T> Complejo<T>::operator+(const T &B )
		{
			Complejo<T> AUX;

			AUX.R_M( this->R_M() + B );

			AUX.I_A( this->I_A() );
					
			AUX.Mode = this->Mode;
							
			return AUX;
			

		}




			template<class T>
		void Complejo<T>::operator +=(const Complejo<T>& SUMANDO ){

			(*this) = ( (*this) + SUMANDO ) ;


			return ;

		}

			template<class T>
		void Complejo<T>::operator +=(const T& VAL){

			(*this) = ( (*this) + VAL ) ;

			return ;

		}


			template <class T>
		Complejo<T> Complejo<T>::operator-(const Complejo<T> &B )
		{

			Complejo<T> AUX;

			AUX.RI = ( this->RI - B.RI );

			return AUX;
		

		}


			template<class T>
		Complejo<T> Complejo<T>::operator-(const T &B )
		{
			Complejo<T> AUX( *this );

			AUX.R_M( AUX.R_M() - B );

			return AUX;

		}


			template<class T>
		Complejo<T> Complejo<T>::operator*(const Complejo<T> &B )
		{

			//Esta definida asi: 
			//	(a,b) * (c,d) = ( a*c - b*d , a*d + b*c )

			Complejo<T> AUX;

			//utilizo esta variablepara cargar los datos, asi es mas legible
			T num;

			num= ( this->R_M() * B.R_M() - this->I_A() * B.I_A() );

			AUX.R_M( num ); 

			num = ( this->R_M() * B.I_A() + this->I_A() * B.R_M() ) ;

			AUX.I_A( num );

			AUX.Mode = this->Mode;


			return AUX;


		}

			template<class T>
		Complejo<T> Complejo<T>::operator*(const T &val ){
		

			//es miembro a mienmbro la operacion
			Complejo<T> AUX;

			AUX.R_M( this->R_M() * val ); 

			AUX.I_A( this->I_A() * val ); 

			AUX.Mode = this->Mode;


			return AUX;

		}


			template <class T>
		Complejo<T> Complejo<T>::operator/(const Complejo<T> &B )
		{

			//Esta definida asi: 
			//	(a,b) / (c,d) = ( ( a*c + b*d ) / (c^2 + d^2) , ( b*c - a*d ) / (c^2 + d^2) ) 

			Complejo<T> AUX; 

			AUX.R_M( ( this->R_M() * B.R_M() + this->I_A() * B.I_A() ) / ( B.R_M()*B.R_M() + B.I_A()*B.I_A() ) );


			AUX.I_A( ( this->R_M() * B.R_M() + this->I_A() * B.I_A() ) / ( B.R_M()*B.R_M() + B.I_A()*B.I_A() ) );

			AUX.Mode = this->Mode;

			return AUX;

		}


			template <class T>
		Complejo<T> Complejo<T>::operator/(const T &val ){
		

			//es miembro a mienmbro la operacion
			Complejo<T> AUX;

			AUX.R_M( this->R_M() / val ); 

			AUX.I_A( this->I_A() / val ); 

			AUX.Mode = this->Mode;


			return AUX;


		}


		template<class T>
	Complejo<T>& Complejo<T>::operator=( const Complejo<T>& B ){

		this->R_M( B.R_M() );

		
		this->I_A( B.I_A() );

		return *(this);


	}

		template<class T>
	T Numeric::Complejo<T>::operator[]( const int i ){

		return ( this->RI[i] );



	}

		

	
	
}//Fin del nombre de espacios Numeric, contenedor de 'esta libreria'



	
template class Numeric::Complejo<double>;
	
template class Numeric::Complejo<float>;

template class Numeric::Complejo<int>;



