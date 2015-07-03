/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////      Librearia precompilada de Visual Studio 2008     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "stdafx.h"				      /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el codigo           ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include <iostream>					  /*///////////////////////////*/
/*///////////////////////////*/					#include <fstream>					  /*///////////////////////////*/
/*///////////////////////////*/					#include <string>					  /*///////////////////////////*/
/*///////////////////////////*/					#include "Numeric.h"	         	  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////             Encabezado de la librearia                ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "Store.h"	             	  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Codigo de la Definicion del nombre de espacios Store  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Store{





	//Esta funcion no es nesesaria que sea amiga, ni miembro ni de Vector ni de Matrix
	///Esta funcion recibe un input, lo lee y devuelve el encabezado que posee el archivo
	///
	///@param std::ifstream la entrada por la que se lee el archivo
	///@return Header el encabezado del archivo
	inline Header Read_Header( std::ifstream& input ){

	Header H;

	input.read( (char*) (&H.Kind) , 1 );

	input.read( (char*) (&H.First_D) , 4 );
	
	if( H.Kind == 'M' ){

		input.read( (char*) (&H.Second_D) , 4 );

	}else{

		H.Second_D = 0;
	}

	input.read( (char*) (&H.Type) , 1 );

	if( H.Type == 'C' ){

		input.read( (char*) (&H.CType) , 1 );

		input.read( (char*) (&H.Mode) , 1 );

	}else{

		H.CType = '-';
		H.Mode = '-';

	}

	return H;


}

///Esta funcion recibe un Header y un ifstream posicionado en donde comienzan los datos y los lee, esta hecha para ser utilizada dentro de From_Binary, desde alguna estructura
///Importante, deben ya ser compatibles los Headers, solo se pasan aca para informacion para saber que leer
///
///@param Header el encabezdo del archivo
///@param std::ifstream el archivo, posicionado donde empieza este
///@return void
	template<class T>
inline void Store::Vector<T>::Read_Data( Store::Header& H , std::ifstream& input){


	//Simples

	if( (H && Store::Header('V',0,0,'I','-','-') ) || ( H && Store::Header('V',0,0,'F','-','-') ) ){

		for( int i = 0 ; ( i < H.First_D ) ; i++ )
			input.read( (char*)(&this->MC[0][i]) , 4 );

	}
	

	if( H && Store::Header('V',0,0,'D','-','-') ){

		for( int i = 0 ; ( i < H.First_D ) ; i++ )
			input.read( (char*)(&this->MC[0][i]) , 8 );

	}

	//Complejos


/*
	if( H && Store::Header('V',0,0,'C','I','B') ){

		int AUX;

		for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].R_M(AUX);
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].I_A(AUX);
		}
		this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Vectorial_Binomical );

		
	}

	
	if( H && Store::Header('V',0,0,'C','I','P') ){

		int AUX;

		for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].R_M(AUX);
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].I_A(AUX);
		}
		this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Polar );

		
	}

	if( H && Store::Header('V',0,0,'C','F','B') ){

		float AUX;

		for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].R_M(AUX);
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].I_A(AUX);
		}
		this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Vectorial_Binomical );

		
	}

	if( H && Store::Header('V',0,0,'C','F','P') ){

		float AUX;

		for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].R_M(AUX);
			input.read( (char*)(&AUX) , 4 );
			this->MC[0][i].I_A(AUX);
		}
		this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Polar );

		
	}

	if( H && Store::Header('V',0,0,'C','D','B') ){

		double AUX;

		for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			input.read( (char*)(&AUX) , 8 );
			this->MC[0][i].R_M(AUX);
			input.read( (char*)(&AUX) , 8 );
			this->MC[0][i].I_A(AUX);
		}
		this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Vectorial_Binomical );

		
	}

	if( H && Store::Header('V',0,0,'C','D','P') ){

		double AUX;

		for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			input.read( (char*)(&AUX) , 8 );
			this->MC[0][i].R_M(AUX);
			input.read( (char*)(&AUX) , 8 );
			this->MC[0][i].I_A(AUX);
		}
		this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Polar );

		
	}
*/



}




///Este metodo esta solo para especializarlo, si no existe una especializacion para un tipo de dato
///es decir que no hay soporte para ese tipo, luego la funcion siempre devuelve 3
///@param std::string el nombre del archivo
///@param std::string la direccion donde se guardara
///@return int siempre 3, que significa que no existe una especializacion para el tipo de dato para el que se lo quizo utilizar
	template<class T>
int Store::Vector<T>::To_Bynary( std::string& NAME , std::string& PATH ){
return 3;
}


///Especializacion para int, guarda el verctor en un archivo binario de extension crap
///
///@param std::string el nombre del archivo
///@param std::string la direccion donde se guardara
///@return int 1 si es que lo pudo guardar correctamente, y 0 si fallo al guardarlo
	template<>
int Store::Vector<int>::To_Bynary( std::string& NAME , std::string& PATH ){

	int aux;
		
	aux = NAME.rfind( '.' );

	if( aux == std::string::npos ){
		
		NAME += ".crap";


	}

	//concateno todo el nombre del archivo
	PATH += NAME;
	
	std::ofstream output( PATH.c_str() , std::ios::binary );

	if( !output.is_open() ){

		//no se pudo abrir, asi que devuelvo 0
		return 0;

	}

		//Encabezado

	char ident = 'V';

	//Char que dice si es matriz o Vector, en este caso es vector
	output.write( (char*)(&ident) , 1 );

	//el tamaño de componentes
	output.write( (char*)(&this->Componentes) , 4 );

	ident = 'I';
	output.write( (char*)(&ident) , 1);

		//Fin del encabezado
	
	//Ahora empiezo a guardar los datos

	for( int i=0; (i < this->Componentes) ; i++ ){

	output.write( (char*)(&this->MC[0][i]) , 4 );

	}

	//Ya esta todo guardado

	output.close();


	return 1;


}

///Especializacion para float, guarda el verctor en un archivo binario de extension crap
///
///@param std::string el nombre del archivo
///@param std::string la direccion donde se guardara
///@return int 1 si es que lo pudo guardar correctamente, y 0 si fallo al guardarlo
	template<>
int Store::Vector<float>::To_Bynary( std::string& NAME , std::string& PATH ){

	int aux;
		
	aux = NAME.rfind( '.' );

	if( aux == std::string::npos ){
		
		NAME += ".crap";


	}

	//concateno todo el nombre del archivo
	PATH += NAME;
	
	std::ofstream output( PATH.c_str() , std::ios::binary );

	if( !output.is_open() ){

		//no se pudo abrir, asi que devuelvo 0
		return 0;

	}

		//Encabezado

	char ident = 'V';

	//Char que dice si es matriz o Vector, en este caso es vector
	output.write( (char*)(&ident) , 1 );

	//el tamaño de componentes
	output.write( (char*)(&this->Componentes) , 4 );

	ident = 'F';
	output.write( (char*)(&ident) , 1);

		//Fin del encabezado
	
	//Ahora empiezo a guardar los datos

	for( int i=0; (i < this->Componentes) ; i++ ){

	output.write( (char*)(&this->MC[0][i]) , 4 );

	}

	//Ya esta todo guardado

	output.close();


	return 1;


}

///Especializacion para dobles, guarda el verctor en un archivo binario de extension crap
///
///@param std::string el nombre del archivo
///@param std::string la direccion donde se guardara
///@return int 1 si es que lo pudo guardar correctamente, y 0 si fallo al guardarlo
	template<>
int Store::Vector<double>::To_Bynary( std::string& NAME , std::string& PATH ){

	int aux;
		
	aux = NAME.rfind( '.' );

	if( aux == std::string::npos ){
		
		NAME += ".crap";


	}

	//concateno todo el nombre del archivo
	PATH += NAME;
	
	std::ofstream output( PATH.c_str() , std::ios::binary );

	if( !output.is_open() ){

		//no se pudo abrir, asi que devuelvo 0
		return 0;

	}

		//Encabezado

	char ident = 'V';

	//Char que dice si es matriz o Vector, en este caso es vector
	output.write( (char*)(&ident) , 1 );

	//el tamaño de componentes
	output.write( (char*)(&this->Componentes) , 4 );

	ident = 'D';
	output.write( (char*)(&ident) , 1);

		//Fin del encabezado
	
	//Ahora empiezo a guardar los datos

	for( int i=0; (i < this->Componentes) ; i++ ){

	output.write( (char*)(&this->MC[0][i]) , 8 );

	}

	//Ya esta todo guardado

	output.close();


	return 1;


}

///Especializacion para Complejo<int>, guarda el verctor en un archivo binario de extension crap
///
///@param std::string el nombre del archivo
///@param std::string la direccion donde se guardara
///@return int 1 si es que lo pudo guardar correctamente, y 0 si fallo al guardarlo
	template<>
int Store::Vector<Numeric::Complejo<int>>::To_Bynary( std::string& NAME , std::string& PATH ){

	int aux;
		
	aux = NAME.rfind( '.' );

	if( aux == std::string::npos ){
		
		NAME += ".crap";


	}

	//concateno todo el nombre del archivo
	PATH += NAME;
	
	std::ofstream output( PATH.c_str() , std::ios::binary );

	if( !output.is_open() ){

		//no se pudo abrir, asi que devuelvo 0
		return 0;

	}

		//Encabezado

	char ident = 'V';

	//Char que dice si es matriz o Vector, en este caso es vector
	output.write( (char*)(&ident) , 1 );

	//el tamaño de componentes
	output.write( (char*)(&this->Componentes) , 4 );

	ident = 'C';
	output.write( (char*)(&ident) , 1);

	//es un complejo de enteros
	ident = 'I';
	output.write( (char*)(&ident) , 1);

	//si es complejo, digo si las componentes estan en forma polar o binomica
	//si es polar uso P, si es binomica uso B

	switch( this->MC[0][0].Current_Mode() ){
		
		case Numeric::VecBin_Polar::Vectorial_Binomical :{
			ident = 'P';
			output.write( (char*)(&ident) , 1 );
			break;

		}

		case Numeric::VecBin_Polar::Polar :{
			ident = 'B';
			output.write( (char*)(&ident) , 1 );
			break;

		}


	}
	
		//Fin del encabezado
	
	//Ahora empiezo a guardar los datos

	int Comps;

	for( int i=0; (i < this->Componentes) ; i++ ){

		Comps = this->MC[0][i].R_M();
	output.write( (char*)( &Comps ) , 4 );
		Comps = this->MC[0][i].I_A();
	output.write( (char*)( &Comps ) , 4 );

	}

	//Ya esta todo guardado

	output.close();


	return 1;


}

///Especializacion para Complejo<float>, guarda el verctor en un archivo binario de extension crap
///
///@param std::string el nombre del archivo
///@param std::string la direccion donde se guardara
///@return int 1 si es que lo pudo guardar correctamente, y 0 si fallo al guardarlo
	template<>
int Store::Vector<Numeric::Complejo<float>>::To_Bynary( std::string& NAME , std::string& PATH ){

	int aux;
		
	aux = NAME.rfind( '.' );

	if( aux == std::string::npos ){
		
		NAME += ".crap";


	}

	//concateno todo el nombre del archivo
	PATH += NAME;
	
	std::ofstream output( PATH.c_str() , std::ios::binary );

	if( !output.is_open() ){

		//no se pudo abrir, asi que devuelvo 0
		return 0;

	}

		//Encabezado

	char ident = 'V';

	//Char que dice si es matriz o Vector, en este caso es vector
	output.write( (char*)(&ident) , 1 );

	//el tamaño de componentes
	output.write( (char*)(&this->Componentes) , 4 );

	ident = 'C';
	output.write( (char*)(&ident) , 1);

	//es un complejo de enteros
	ident = 'F';
	output.write( (char*)(&ident) , 1);

	//si es complejo, digo si las componentes estan en forma polar o binomica
	//si es polar uso P, si es binomica uso B

	//Tener en cuanta que si cualquiera de las componentes trabaja de una manera, 
	//entonces se considera que todas trabajan de la misma forma asi que basta preguntar por un elemnto cualquiera
	switch( this->MC[0][0].Current_Mode() ){
		
		case Numeric::VecBin_Polar::Vectorial_Binomical :{
			ident = 'P';
			output.write( (char*)(&ident) , 1 );
			break;

		}

		case Numeric::VecBin_Polar::Polar :{
			ident = 'B';
			output.write( (char*)(&ident) , 1 );
			break;

		}


	}

		//Fin del encabezado
	
	//Ahora empiezo a guardar los datos

	float Comps;

	for( int i=0; (i < this->Componentes) ; i++ ){

		Comps = this->MC[0][i].R_M();
	output.write( (char*)(&Comps ) , 4 );
		Comps = this->MC[0][i].I_A();
	output.write( (char*)(&Comps ) , 4 );

	}

	//Ya esta todo guardado

	output.close();


	return 1;


}

///Especializacion para Complejo<dobles>, guarda el verctor en un archivo binario de extension crap
///
///@param std::string el nombre del archivo
///@param std::string la direccion donde se guardara
///@return int 1 si es que lo pudo guardar correctamente, y 0 si fallo al guardarlo
	template<>
int Store::Vector<Numeric::Complejo<double>>::To_Bynary( std::string& NAME , std::string& PATH ){

	int aux;
		
	aux = NAME.rfind( '.' );

	if( aux == std::string::npos ){
		
		NAME += ".crap";


	}

	//concateno todo el nombre del archivo
	PATH += NAME;
	
	std::ofstream output( PATH.c_str() , std::ios::binary );

	if( !output.is_open() ){

		//no se pudo abrir, asi que devuelvo 0
		return 0;

	}

		//Encabezado

	char ident = 'V';

	//Char que dice si es matriz o Vector, en este caso es vector
	output.write( (char*)(&ident) , 1 );

	//el tamaño de componentes
	output.write( (char*)(&this->Componentes) , 4 );

	ident = 'C';
	output.write( (char*)(&ident) , 1);

	//es un complejo de enteros
	ident = 'D';
	output.write( (char*)(&ident) , 1);

	//si es complejo, digo si las componentes estan en forma polar o binomica
	//si es polar uso P, si es binomica uso B

	switch( this->MC[0][0].Current_Mode() ){
		
		case Numeric::VecBin_Polar::Vectorial_Binomical :{
			ident = 'P';
			output.write( (char*)(&ident) , 1 );
			break;

		}

		case Numeric::VecBin_Polar::Polar :{
			ident = 'B';
			output.write( (char*)(&ident) , 1 );
			break;

		}


	}

		//Fin del encabezado
	
	//Ahora empiezo a guardar los datos

	double Comps;

	for( int i=0; (i < this->Componentes) ; i++ ){

		Comps = this->MC[0][i].R_M();
	output.write( (char*)(&Comps ) , 8 );
		Comps = this->MC[0][i].I_A();
	output.write( (char*)(&Comps ) , 8 );

	}

	//Ya esta todo guardado

	output.close();


	return 1;


}




///Abre un archivo y carga el Vector con los datos que saca del archivo
///
///@param std::string el nombre del archivo
///@param std::string la direccion del archivo
///@return 0 si no puedo abrir el archivo, 3 si la informacion del archivo no es compatible con esta estructura y 1 si es que se leyo y todo salio bien
	template<class T>
int Store::Vector<T>::From_Binary( std::string& NAME , std::string& PATH ){

	int aux;
		
	aux = NAME.rfind( '.' );

	if( aux == std::string::npos ){
		
		NAME += ".crap";


	}

	//concateno todo el nombre del archivo
	PATH += NAME;
	
	std::ifstream input( PATH.c_str() , std::ios::binary || std::ios::app );

	if( !input.is_open() ){

		//no se pudo abrir, asi que devuelvo 0
		return 0;

	}

		//Leo el Encabezado

	Header H;
	
	H = Read_Header( input );

	if( !(H && this->Get_Type())  ){

		return 3;//no son compatibles por ser una matriz o de distinto tipo

	}

		//Fin de la lectura del encabezado y comprobado qeu coinciden en tipos
	
	//Ahora empiezo a leer los datos

	this->Resize( H.First_D );

	//Importante, este Read Data se le pasa el ifsteram, a diferencia de Read Header
	//Porque si abro otro ifstream, me tengo que saltear el encabezado
	//y como este es dinamico, es mas facil pasar el ifsteam y no hacer los calculos leyendo el encabezado
	Read_Data( H , input );

	//Ya esta todo guardado

	input.close();


	return 1;


}


}

//Instanciaciones explicitas

inline void Store::Vector<int>::Read_Data( Store::Header&  , std::ifstream& );
inline void Store::Vector<float>::Read_Data( Store::Header&  , std::ifstream& );
inline void Store::Vector<double>::Read_Data( Store::Header&  , std::ifstream& );
/*
inline void Store::Vector<Numeric::Complejo<int>>::Read_Data( Store::Header&  , std::ifstream& );
inline void Store::Vector<Numeric::Complejo<float>>::Read_Data( Store::Header&  , std::ifstream& );
inline void Store::Vector<Numeric::Complejo<double>>::Read_Data( Store::Header&  , std::ifstream& );
*/


template int Store::Vector<int>::From_Binary( std::string&  , std::string&  );
template int Store::Vector<float>::From_Binary( std::string&  , std::string&  );
template int Store::Vector<double>::From_Binary( std::string&  , std::string&  );
/*
template int Store::Vector<Numeric::Complejo<int>>::From_Binary( std::string&  , std::string&  );
template int Store::Vector<Numeric::Complejo<float>>::From_Binary( std::string&  , std::string&  );
template int Store::Vector<Numeric::Complejo<double>>::From_Binary( std::string&  , std::string&  );
*/
