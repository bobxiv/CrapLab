/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////      Librearia precompilada de Visual Studio 2008     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "stdafx.h"					  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el codigo           ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include <string>                     /*///////////////////////////*/
/*///////////////////////////*/					#include <iostream>                   /*///////////////////////////*/
/*///////////////////////////*/                 #include <fstream>                    /*///////////////////////////*/
/*///////////////////////////*/					#include <map>                        /*///////////////////////////*/ 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////             Encabezado de la librearia                ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/					#include "..\Headers\GUI_Helper.h"	  /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


namespace GUI{

	


int Console_Icon::From_CHAR_to_BINARY( char* Name , char* Path ){
	
		std::string File(Name);

		std::string P(Path);

	File += ".txt";

	int m;

	m = File.rfind( '.' );

	if( m == std::string::npos ){
		
		File += ".txt";


	}

	P += File;

	//se lee de un archivo de texto
	std::ifstream input( P.c_str() , std::ios::app );
	
	if( !(input.is_open()) ){
		
		return 1;

	}

	//quiero el ultimo punto del archivo
	//no me va a devolver npos, porque como ya lo agregue al punto estoy seguro que aunquesea uno hay
	//o puede haber sido ingresado con´punto, tambien andaria bien
	int i = P.rfind( '.' );

	P.replace( i , 4 , ".ico" );

	//la salida es a un archivo binario
	std::ofstream output( P.c_str(), std::ios::binary );

	if( !(output.is_open()) ){
		
		return 2;

	}
	
	
		//Almaceno al comienzo lugar para un int que tendra el tamaño del archivo
		//una vez que cargo el binary lo agrego, peor la variable ya esta creada
		int tamano =  0;

		output.write( (char*)(&tamano), 4);
	

	//lo maximo que puede tener una ventana de consola son 80, y uno para el \0
	char* AUX= new char[81];
	char* saltodelinea = new char;
	saltodelinea[0] = '\n';

	while( !input.eof() ){


		input.getline( AUX , std::streamsize(256) );

		output.write( AUX , input.gcount() );
	
		//como el getline, me trae todo hasta el '\n', pero no incluido este se lo agrego
		output.write( saltodelinea , 1);

	}

	

		//almaceno al comienzo el tamaño del archibo binario
		//output.seekp(0 , std::ios::end );	//esto se comenta porque ya estoy al final del archivo
		
		tamano = output.tellp();

		output.seekp(0 , std::ios::beg );

		output.write( (char*)(&tamano), 4);



	output.close();

	input.close();


	return 0;

}


int Console_Icon::Read_Console_Icon( char* Name , char* Path ){

		std::string File(Name);


		std::string P(Path);

	File += ".txt";

	int m;

	m = File.rfind( '.' );

	if( m == std::string::npos ){
		
		File += ".ico";


	}

	P += File;

	std::ifstream input( P.c_str() , std::ios::binary || std::ios::app );

	if( !(input.is_open()) ){
		
		return 1;

	}

	
	input.read( (char*)(&Long) , 4 );


	//en el caso de que no halla nada el el ico entonces se ejecuta con Long 0, sino seria -1
	//como Long me dan los elemento smas el fin de archivo, hay un lugar que no nesesito guardarlo
	if( Long == 0 ){

		//si es cero, entonces no tengo nada que copiar
		input.close();

		return 0;

	}else{

		char* AUX= new char[Long-1];

		//copio todo a AUX	
		input.read( AUX, Long-1 );

		Icon = AUX;

	}

	

	input.close();

	
	
	return 0;



}



void Console_Icon::Draw_Console_Icon( std::ostream& output ){

	output<<'\n';
	
	int i=0;
	

	while( i < Long ){ //Icon[i] != '\0' ){

		output<< Icon[i];

		i++;

	}


	output<<'\n'<<'\n';


}




}

