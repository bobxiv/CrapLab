// CrapParser.cpp : Defines the entry point for the CrapLab application.
//

#include "stdafx.h"

extern "C"{
#include <antlr3.h>
#include "Parser\CrapGrammaticLexer.h" 
#include "Parser\CrapGrammaticParser.h"
}	

#include <iostream>
#include <fstream>
#include <string>

#include <cmath> 
#include <cctype> 

//Propias
#include "Lib\Store.h"
#include "Lib\Function.h"

//Tabla de simbolo/valor y variables globales
#include "Table.h"

//Contiene las exepciones
#include "Exception.h"

//utilidades necesarias
#include "Utility.h"

//funciones recursivas que resuelven las gramaticas
//Contiene:
//1) Una version para calculadoras escalares
//2) Una version para calculadoras vectoriales
//3) Una version para calculadoras matriciales
#include "Resolve.h"

#include "Lib\GUI_Helper.h"

#include <iomanip>
#include <conio.h>

inline void Print_Help(){

	std::cout<<"*** operators:\n\n";
	std::cout<<std::setw(8)<<"+"<<std::setw(8)<<"-";
	std::cout<<std::setw(8)<<"*"<<std::setw(8)<<".*";
	std::cout<<std::setw(8)<<"/"<<std::setw(8)<<"./";
	std::cout<<std::setw(8)<<"^"<<std::setw(8)<<"-^"<<std::endl;
	std::cout<<std::setw(8)<<"("<<std::setw(8)<<")";
	std::cout<<std::setw(8)<<";";
	std::cout<<std::setw(8)<<"["<<std::setw(8)<<"]";
	std::cout<<std::setw(8)<<"="<<"\n\n";

		const int esp = 12;

	std::cout<<"*** constants:\n\n";
	std::cout<<std::setw(esp)<<"pi"<<std::setw(esp)<<"e"<<"\n\n";

	std::cout<<"*** commands:\n\n";
	std::cout<<std::setw(esp)<<"help"<<std::setw(esp)<<"exit";
	std::cout<<std::setw(esp)<<"clear"<<std::setw(esp)<<"error_log"<<"\n\n";

	std::cout<<"*** generals functions:\n\n";
	std::cout<<std::setw(esp)<<"sin"<<std::setw(esp)<<"sinh";
	std::cout<<std::setw(esp)<<"cos"<<std::setw(esp)<<"cosh";
	std::cout<<std::setw(esp)<<"tan"<<std::setw(esp)<<"tanh\n";
	std::cout<<std::setw(esp)<<"log10"<<std::setw(esp)<<"log";
	std::cout<<std::setw(esp)<<"sqrt"<<std::setw(esp)<<"abs";
	std::cout<<std::setw(esp)<<"exp"<<std::setw(esp)<<"floor\n";
	std::cout<<std::setw(esp)<<"ceil"<<std::setw(esp)<<"asin";
	std::cout<<std::setw(esp)<<"acos"<<std::setw(esp)<<"atan";
	std::cout<<std::setw(esp)<<"size"<<std::setw(esp)<<"cross\n";
	std::cout<<std::setw(esp)<<"round"<<std::setw(esp)<<"trapz";
	std::cout<<std::setw(esp)<<"der1"<<std::setw(esp)<<"der2";
	std::cout<<std::setw(esp)<<"der3"<<std::setw(esp)<<"der4\n";
	std::cout<<std::setw(esp)<<"rand"<<std::setw(esp)<<"det";
	std::cout<<std::setw(esp)<<"ones"<<std::setw(esp)<<"zeros";
	std::cout<<std::setw(esp)<<"inv"<<std::setw(esp)<<"gauss\n";
	std::cout<<std::setw(esp)<<"res"<<std::setw(esp)<<"adj";
	std::cout<<std::setw(esp)<<"gaussv"<<"\n\n";

	std::cout<<"*** special functions:\n\n";
	std::cout<<std::setw(esp)<<"plot"<<'\n';

	std::cout<<"\t\t\t\t"<<"| Everything key-sensitive at exeption of |\n";
	std::cout<<"\t\t\t\t"<<"| commands and constants key-insensitive  |\n";
	

	}

//atrapa todos las operaciones del tipo 'commands', ver en help
inline void Catch_Commands(std::string& text){

	if( text.empty() ) text=" ";

		{
		//paso todo a minusculas poruqe es key-insensitive
		 std::string aux = text;
		for( int i=0; i < text.length() ;i++ ){
			 aux[i]= tolower(aux[i]);
		 }

		if( aux == "exit" ){ 
			exit(0);
			}
		
		 if( aux == "help" ){
			 Print_Help();
			 _getch();
			 text = " ";
			 }
		 if( aux.find("help",0) != std::string::npos ){
			 std::string com = aux.substr(aux.find(" ",0)+1);
			 
			 
			 if( com == "sin" ){
				 std::cout<<"Calcula el seno de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "sinh" ){
				 std::cout<<"Calcula el seno hiperbolico de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "cos" ){
				 std::cout<<"Calcula el coseno de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "cosh" ){
				 std::cout<<"Calcula el coseno hiperbolico de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "tan" ){
				 std::cout<<"Calcula la tangente de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "tanh" ){
				 std::cout<<"Calcula la tangente hiperbolica de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "log10" ){
				 std::cout<<"Calcula el logaritmo base diez de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "log" ){
				 std::cout<<"Calcula el logaritmo natural de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "sqrt" ){
				 std::cout<<"Calcula la raiz cuadrada de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "abs" ){
				 std::cout<<"Calcula el valor absoluto de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "exp" ){
				 std::cout<<"Calucla la exponencial de un valor x, ya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "floor" ){
				 std::cout<<"Calcula el piso de un valor x, ie su aproximacion mas cercana al numero k\nnatural mas pequeno que este, puede operar en matrices o escalares\n";
				 text=" ";
				 return;
				 }

			 if( com == "ceil" ){
				 std::cout<<"Calcula el techo de un valor x, ie su aproximacion mas cercana al numero k\nnatural mas grande que este, puede operar en matrices o escalares\n";
				 text=" ";
				 return;
				 }

			 if( com == "asin" ){
				 std::cout<<"Calcula el arco seno, inversa del seno, de un valor x,\nya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "acos" ){
				 std::cout<<"Calcula el arco coseno, inversa del coseno, de un valor x,\nya sea matricial o escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "atan" ){
				 std::cout<<"Calcula el arco tangente, inversa de la tangente, de un valor x,\nya sea matricial escalar\n";
				 text=" ";
				 return;
				 }

			 if( com == "size" ){
				 std::cout<<"Muestra las dimensiones del resultado de una expresion con el formato:\n\tFilas/Columna\n";
				 text=" ";
				 return;
				 }

			 if( com == "cross" ){
				 std::cout<<"Calcula el producto cruz de los vectores a y b. Las condiciones son:\n\ta) Tener ambos una dimensión de 3 componentes\n\tb) Ser ambos vectores fila o vectores columna\n";
				 text=" ";
				 return;
				 }

			 if( com == "round" ){
				 std::cout<<"Redondea un valor x, ie su aproximacion mas cercana al numero k\nnatural mas cercano a este, puede operar en matrices o escalares\n";
				 text=" ";
				 return;
				 }

			 if( com == "trapz" ){
				 std::cout<<"Calcula el area de la funcion definida por los vectores x e y,\nie integra la función definida por esos dos vectores.\nSiendo el rango de x desde a a b\n";
				 text=" ";
				 return;
				 }

			 if( com == "der1" ){
				 std::cout<<"La primera derivada de la funcion definida por los vectores x e y\ncon respecto a x\n";
				 text=" ";
				 return;
				 }

			 if( com == "der2" ){
				 std::cout<<"La segunda derivada de la funcion definida por los vectores x e y\ncon respecto a x\n";
				 text=" ";
				 return;
				 }

			 if( com == "der3" ){
				 std::cout<<"La tercera derivada de la funcion definida por los vectores x e y\ncon respecto a x\n";
				 text=" ";
				 return;
				 }

			 if( com == "der4" ){
				 std::cout<<"La cuarta derivada de la funcion definida por los vectores x e y\ncon respecto a x\n";
				 text=" ";
				 return;
				 }

			 if( com == "rand" ){
				 std::cout<<"Genera una matriz con valores aleatorios de la dimension que especifiquen\nlos argumentos con el formato Filas/Columnas\n"; 
				 text=" ";
				 return;
				 }

			 if( com == "det" ){
				 std::cout<<"Calcula el determinante de la matriz X.\nLa unica condicion es que X debe ser cuadrada\n";
				 text=" ";
				 return;
				 }

			 if( com == "ones" ){
				 std::cout<<"Genera una matriz llena de unos de la dimension que especifiquen\nlos argumentos con el formato Filas/Columnas\n";
				 text=" ";
				 return;
				 }

			 if( com == "zeros" ){
				 std::cout<<"Genera una matriz llena de ceros de la dimension que especifiquen\nlos argumentos con el formato Filas/Columnas\n";
				 text=" ";
				 return;
				 }

			 if( com == "inv" ){
				 std::cout<<"Calcula la inversa de la matriz X.\nLas condiciones son:\n\ta) Que X sea cuadrada\n\tb) Que el determinante de X sea distinto de 0\n";
				 text=" ";
				 return;
				 }

			 if( com == "gauss" ){
				 std::cout<<"Calcula la matriz gausseada, ie llevada a su forma escalonada\n";
				 text=" ";
				 return;
				 }

			 if( com == "res" ){
				 std::cout<<"Resuleve el sistema lineal, la ultima columna de la matriz\nse considera la columna de condiciones\n";
				 text=" ";
				 return;
				 }

			 if( com == "adj" ){
				 std::cout<<"Calcula la matriz adjunta. La única condición es que la matriz sea cuadrada\n";
				 text=" ";
				 return;
				 }

			 if( com == "gaussv" ){
				 std::cout<<"Realiza todos los pasos necesarios para llevar la matriz X a su forma gauseada.\nMuestra un paso y espera que el usuario presione una tecla para continuar\ncon el proceso.\nAl final muestra un resumen de todas las operaciones realizadas\n";
				 text=" ";
				 return;
				 }

			 if( com == "plot" ){
				 std::cout<<"Abre el programa graficador, CrapGraph, y dibuja la funcion que se le haya\npasado como parametro. La funcion se forma con sus valores independientes x,\nprimer parametro, y sus valores dependientes y, segundo parametro.\nCondiciones:\n\ta) Tanto x como y deben ser vectores (no pueden ser puntos,\n\t   no se grafican puntos)\n\tb) También x e y deben tener igual cantidad de componentes\n\tc) Si esta permitido que x sea un vector fila e y columna y viceversa\n";
				 text=" ";
				 return;
				 }


			 std::cout<<"No existe el comando "<<com<<std::endl;
			 text=" ";
			 return;


	
			 }


		 if( aux == "error_log" ){
			 
			 std::ifstream errors;
			 errors.open("error_log.txt");

			 if( !errors.is_open() ){
				 std::cout<<"No se puede acceder al log de errores. Esta seguro que esta en su lugar?\n";
				 std::cerr<<"IMPOSIBLE ACCESO PARA LECTURA DE ESTE ARCHIVO\n";
				 }

			 std::cout<<'\n';
			 std::string line;
			 while( !errors.eof() ){
			 std::getline(errors,line,'\n');
			 std::cout<<line;
			 std::cout<<'\n';
				 }


			 text = " ";

			 }

		 int pos = aux.find(" ");
		 if( aux.substr( 0 , pos) == "clear" ){
			std::string var = aux.substr( ++pos , aux.length() );
			VarList_MD[var]=0;
			VarList_MD.erase(VarList_MD.find(var));
			text = " ";
			 }
		 
		}

	}

inline void Presentacion(){

	std::cout<<"CrapLab, version 0.6\n";
	std::cout<<"!Copyright (!C)\n";

		{

	GUI::Console_Icon MyGUI;

	//como ya esta procesado no lo regenero al .ico
	//MyGUI.From_CHAR_to_BINARY("pi");
	int res = MyGUI.Read_Console_Icon("pi.ico");
	if( res == 1 )
		std::cout<<"\nNo se pudo abrir el archivo, esta seguro qeu el icono esta en su lugar?\n";

	MyGUI.Draw_Console_Icon();

		}

	}



std::ofstream* error_log;

void redirect_cerr_to_a_error_log(){
	/*Esto redirecionaria la salida del objeto cerr que en un comeinzo esta 
	  Linkeado con el stream estandar, pero como la salida que me molesta 
	  esta hecha con C, no utiliza cerr, sino solo el stream estandar
	  este es elqeu debo redireccionar(indirectamente tambien redireciono cerr
	*/
	 
	/*
	error_log = new std::ofstream;
	error_log->open("error_log.txt");

	std::cerr.rdbuf( error_log->rdbuf() );
	*/

	//Redirecciona el stream estandar a elarchivo error_log.txt
	//Pero antes de eso intenta limpiar la salida estadar stderr, 
	//a la que estaba antes linkeado

	freopen( "error_log.txt","w",stderr);

	std::cerr<<"CrapLab 0.6 Error Log:\n\n";
	
	}

void Enter_with_Console(){

	std::ifstream guard_in("guardian.shi",  std::ios::app || std::ios::beg );
	std::ofstream guard_out("guardian.shi", std::ios::app || std::ios::beg  );
	//guard_out.seekp(std::ios::beg);	
	
if( !(guard_out.is_open()) )
	exit(1);

 if( (!guard_in.is_open()) || (!guard_out.is_open()) )
	 exit(1);
 char* key=new char;
 guard_in.read(key,1);

 if( (*key) == 'N' ){
	  (*key) = 'S';
	  guard_out.write(key,1);
	  guard_out.close();
	WinExec("Console.exe -d \"C:\CrapLab\" -r \"/k \"CrapLab_CLI\"",1);
	exit(0);
	 }else{
		(*key) = 'N';
	  if(guard_out.write(key,1).bad()) exit(1);
	  guard_out.close();
	 }

 guard_in.close();

 return;

	}

#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
	{ 

	Enter_with_Console();
 
	//Todos los errores estaran almacenados en error_log.txt junto al ejecutable
	redirect_cerr_to_a_error_log();

	//Muestra el logo y el nombre
	Presentacion();

		//Ya introduzco esta variable por defecto
		VarList_VD["ans"]=0;

	std::string text;
	std::cout<<"CrapLab> ";
	std::getline(std::cin,text);

	Catch_Commands(text);


	bool roto=false;

	pANTLR3_INPUT_STREAM input = antlr3NewAsciiStringInPlaceStream((pANTLR3_UINT8)text.c_str() , (ANTLR3_UINT64)text.size(), NULL);

		if ( (ANTLR3_UINT64)input < 0 )
		{
			switch((ANTLR3_UINT64)input)
			{	
		      case    ANTLR3_ERR_NOMEM:
				  std::cout<<"No hay espacio, se cago el malloc en el input";
			      roto=true;
		          break;
		      default:
				  std::cout<<"Nose porque se rompio en el input";
				  roto=true;
			      break;
		      }

		}

		if(roto==false){

			pCrapGrammaticLexer lexer;
			lexer= CrapGrammaticLexerNew( input );

			if ( (ANTLR3_UINT64)lexer < 0 )
		    {
				 switch((ANTLR3_UINT64)lexer)
			     {
				     case    ANTLR3_ERR_NOMEM:
						std::cout<<"No hay espacio, se cago el malloc en el lexer";
						roto=true;
						break;
				
					 default:
						 std::cout<<"Nose porque se rompio en el lexer";
						 roto= true;
				         break;
			      }
		      }

			if( roto==false){

				pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(
					ANTLR3_SIZE_HINT,
					lexer->pLexer->tokSource);

				if ((ANTLR3_UINT64)tokens == ANTLR3_ERR_NOMEM)
			    {
					std::cout<<"No hay espacio, se rompio en token_stream";
					roto=true;
			    }

				if(roto ==false){

					pCrapGrammaticParser parser = CrapGrammaticParserNew(tokens);

					 if ((ANTLR3_UINT64)parser == ANTLR3_ERR_NOMEM)
					 {
						 std::cout<<"No hay espacio, se rompio en el parser";
						roto=true;
					 }

					 if(roto ==false){
						 
						 CrapGrammaticParser_entry_return ast = parser->entry(parser);
						 //para que se vallan almacenando los errores en el log
						 fflush(stderr);

						 //Imprime el arbol en notacion Lisp
						 //pANTLR3_STRING S =  ast.tree->toStringTree(ast.tree);
						 //puts((const char*)S->chars);

						 Res<Store::Matrix<double>> res;
						 try{
							 	if( ast.tree == NULL ) throw BAD_SINTAX();
								res = Resolve<Store::Matrix<double>>( ast.tree );
								VarList_MD["ans"] = res.val;//almaceno para tener el ultimo valor en esta variable
								if( !not_print ){
									if( res.whom == "-" ){
											std::cout<< "ans" << " =\n";
										}else{
											std::cout<< res.whom <<" =\n";
										}
									res.val.View(10,4);
									}else{
										not_print=0;
									}
							 
							 }catch( ZERO_DIV<double> e ){
								 if( e.num_val == 0 ){
									 std::cout<<"ANS\n";
									 }
								 if( e.num_val < 0 ){
									 std::cout<<"-Inf\n";
									 }else{
									 std::cout<<"Inf\n";
									 }

							 }catch( ZERO_DIV<Store::Vector<double>> e ){
								 if( e.num_val[0] == 0 ){
									 std::cout<<"ANS\n";
									 }
								 if( e.num_val[0] < 0 ){
									 std::cout<<"-Inf\n";
									 }
								 if( e.num_val[0] > 0 ){
									 std::cout<<"Inf\n";
									 }
							}catch( ZERO_DIV<Store::Matrix<double>> e ){
								if( e.num_val.Get_Component(1,1) == 0 ){
									std::cout<<"ANS\n";
								}
								if( e.num_val.Get_Component(1,1) < 0 ){
									std::cout<<"-Inf\n";
								}
								if( e.num_val.Get_Component(1,1) > 0 ){
									std::cout<<"Inf\n";
									 }
							 }catch(SEC_ARG_MUST_BE_ESC ){
									std::cout<<"El segundo argumento debe ser un escalar\n";
							 }catch(BAD_DIM e){
									std::cout<<e.what;
							 }catch(BAD_SINTAX ){
									 std::cout<<"La sintaxis es incorrecta\n";
							 }catch(UNDECL_VAR e){
									 std::cout<<"La variable "<<e.who<<" no esta declarada\n";
								 }

							 while(true){

							 std::cout<<"CrapLab> ";
							 std::getline(std::cin,text);

							//atrapa los commandos que no tienen que ver con un calculo o una exression
							//Estos son:	exit	help	"vacio"
							//Es key-insensitive
							Catch_Commands(text);

							 input = antlr3NewAsciiStringInPlaceStream((pANTLR3_UINT8)text.c_str(),text.length(),NULL);
							 lexer = CrapGrammaticLexerNew(input);
							 tokens= antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT,
								 lexer->pLexer->tokSource );
							 parser= CrapGrammaticParserNew( tokens);

						 ast = parser->entry(parser); 

	 					 //para que se vallan almacenando los errores en el log
						 fflush(stderr);

						 //Imprime el arbol en notacion Lisp
						 //S = ast.tree->toStringTree(ast.tree);
						 //puts((const char*)S->chars);

						 try{
							 if( ast.tree == NULL ) throw BAD_SINTAX();
						 res = Resolve<Store::Matrix<double>>( ast.tree );
						 VarList_MD["ans"] = res.val;//almaceno para tener el ultimo valor en esta variable
						 if( !not_print ){
									if( res.whom == "-" ){
											std::cout<< "ans" << " =\n";
										}else{
											std::cout<< res.whom <<" =\n";
										}
							 res.val.View(10,4);
						 	}else{
							not_print=0;
							 }

							 }catch( ZERO_DIV<double> e ){
								 if( e.num_val == 0 ){
									 std::cout<<"ANS\n";
									 }
								 if( e.num_val < 0 ){
									 std::cout<<"-Inf\n";
									 }else{
									 std::cout<<"Inf\n";
									 }

							 }catch( ZERO_DIV<Store::Vector<double>> e ){
								 if( e.num_val[0] == 0 ){
									 std::cout<<"ANS\n";
									 }
								 if( e.num_val[0] < 0 ){
									 std::cout<<"-Inf\n";
									 }
								 if( e.num_val[0] > 0 ){
									 std::cout<<"Inf\n";
									 }
								 }catch(SEC_ARG_MUST_BE_ESC ){
									std::cout<<"El segundo argumento debe ser un escalar\n";
								 }catch(BAD_DIM e){
									std::cout<<e.what;
								 }catch(BAD_SINTAX ){
									 std::cout<<"La sintaxis es incorrecta\n";

								 }catch(UNDECL_VAR e){
									 std::cout<<"La variable "<<e.who<<" no esta declarada\n";
									}
						


						 }
						


					 }
				}
			}
		}


	return 0;
}
