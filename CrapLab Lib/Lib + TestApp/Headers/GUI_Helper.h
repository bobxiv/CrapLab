//Esta instruccion preprocesador hace que solo se compile una vez, apesar de que se incluya en varios cpps
#pragma once
							/////////////////////////////////////////////////////////////////////
							/*    Importante solo en esta libreria se rompe la convencion	   */
							/*			0-noanda			1-anda							   */
							/*						aca es									   */
							/* 0-anda	   	 1-no anda por algo	   	2-no anda por otra cosa    */
							/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Encabezado de la Librearia GUI_Helper         ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////         Librearias que utilizo en el Encabezado       ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*///////////////////////////*/				    	#include <map> 	                  /*///////////////////////////*/
/*///////////////////////////*/						#include <string>			      /*///////////////////////////*/
/*///////////////////////////*/						#include <vector>			      /*///////////////////////////*/
/*///////////////////////////*/						#include <iostream>			      /*///////////////////////////*/
/*///////////////////////////*/						#include "Store.h"			      /*///////////////////////////*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////******************************************************///////////////////////////////


namespace GUI{

	

	//class GUI_Helper{
	//private:


	//	//Contenedor:
	//	//Asocia a un strig(id) ---------------- un puntero a funcion, que se almacena en un puntero a void
	//	static std::map<const char* , void*> Functions;
	//	
	//	//Este buffer contiene todas las variables declaradas de Vector que contienen enteros
	//	static std::vector< Store::Vector<int> > IVectorBuffer;

	//	//Este buffer contiene todas las variables declaradas de Vector que contienen flotantes
	//	static std::vector< Store::Vector<float> > FVectorBuffer;

	//	//Este buffer contiene todas las variables declaradas de Vector que contienen dobles
	//	static std::vector< Store::Vector<double> > DVectorBuffer;

	//public:

	//	inline static void InicializeStack(){

	//		//GUI::GUI_Helper::Functions["Gaussear"];
	//		//GUI::GUI_Helper::Functions["Inversa"];
	//		//GUI::GUI_Helper::Functions["Determinante"];
	//		





	//	}

	//	static void Parse(std::string& Linea){
	//
	//		std::string Nombre;

	//		std::string Parametros;

	//		std::string Elementos;

	//		//Si es que tiene un igual hay una asignacion
	//		std::vector<std::string> params;

	//		if( Linea.rfind('=') != std::string::npos ){

	//			int pos = Linea.rfind('=');

	//			Nombre = Linea.substr( 0 , pos );

	//			Elementos = Linea.substr( pos+1 , Linea.length()-1 );

	//			pos = 0;

	//			
	//			while( pos != ( Elementos.length()-1 ) ){

	//				if( ( Parametros.find( ',', pos)  <  Parametros.find( ')', pos) ) && (Parametros.find( ',', pos) != std::string::npos) ){

	//						params.push_back( Parametros.substr( pos , Parametros.find( ',', pos )- pos ) );
	//						pos = Parametros.find( ',', pos )+1;

	//				}else{

	//						params.push_back( Parametros.substr( pos , Parametros.find( ')', pos )- pos ) );
	//						pos = Elementos.length()-1;
	//				}


	//		}

	//		//si es que hay un parentesis hay una funcion
	//		if( Linea.rfind('(') != std::string::npos ){

	//			int pos = Linea.rfind('(');

	//			Nombre = Linea.substr( 0 , pos );

	//			Parametros = Linea.substr( pos+1 , Linea.length()-1 );

	//			
	//			pos = 0;

	//			while( pos != ( Parametros.length()-1 ) ){

	//				if( ( Parametros.find( ',', pos)  <  Parametros.find( ')', pos) ) && (Parametros.find( ',', pos) != std::string::npos) ){

	//						params.push_back( Parametros.substr( pos , Parametros.find( ',', pos )- pos ) );
	//						pos = Parametros.find( ',', pos )+1;

	//					}else{

	//						params.push_back( Parametros.substr( pos , Parametros.find( ')', pos )- pos ) );
	//						pos = Parametros.length()-1;
	//					}


	//			}
	//			
	//		}


	//		switch(Nombre[0]){
	//			case 'G':{

	//				if( Nombre == "Gaussear"  ){

	//					

	//				}

	//				break;
	//							}
	//			case 'I':{

	//				if( Nombre == "Inversa" ){


	//				}

	//				break;
	//						   }
	//			case 'D':{

	//				if( Nombre == "Determinante" ){


	//				}

	//				break;
	//								}

	//			default:{

	//				
	//				break;
	//					}

	//		}
	//
	//	}



	//};




	class Console_Icon{
	private:

		char* Icon;

		//dice el tamaño del archivo
		int Long;

	public:

		//Este metodo procesa un objeto tipo txt y lo pasa a otro de tipo ico que es binario
		//Recibe:
		//-El nombre del archivo con o sin extension, si no se le pasa extension se considera txt
		//-El path donde esta el archivo
		//Por defecto el path es la carpeta Icons en el proyecto
		//Devuelve:
		//-2 si no se pudo abrir/crear el .ico
		//-1 si no se pudo abrir el .txt
		//-0 si ocurrio todo correctamente
		//Importante, si no se le pone extension al archivo, elegir un nombre sin punto
		int From_CHAR_to_BINARY( char* Name , char* Path = ".\\Icons\\" );

		//Este metodo lee el contenido de un archivo .ico y lo pasa al miembro de dato local
		//Recibe:
		//-El nombre del archivo con o sin extension, si no se le pasa extension se considera txt
		//-El path donde esta el archivo
		//Por defecto el path es la carpeta Icons en el proyecto
		//Devuelve:
		//-1 si no se pudo abrir el .ico
		//-0 si ocurrio todo correctamente
		//Importante, si no se le pone extension al archivo, elegir un nombre sin punto
		int Read_Console_Icon( char* Name , char* Path = ".\\Icons\\" );

		//Este metodo escribe el contenido del archivo .ico leido 
		//en el flujo que se pase como parametro
		//Por defecto este flujo es el estandar cout
		void Draw_Console_Icon( std::ostream& = std::cout );


	};






}//Fin de GUI