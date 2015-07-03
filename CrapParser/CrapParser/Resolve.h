Store::Matrix<double> Serch_Constants_Variables( ANTLR3_STRING_struct* val){

			
		//si es algun tipo de numero especial, ie pi o e
		if(	(!(val->compare8(val,"pi"))) || (!(val->compare8(val,"PI")))  ){
			Store::Matrix<double> num(1,1);//sucio
			num.Get_Component(1,1) = acos((double)-1);
			return num;
		}
		if(	(!(val->compare8(val,"e")))  ||  (!(val->compare8(val,"E")))  ){
			Store::Matrix<double> num(1,1);//sucio
			num.Get_Component(1,1) = exp((double)1);
			return num;
		}

		//si no lo puedo hacer un numero y no es 0, entonces es una variable
		if( atof( (const char*)val->chars ) == 0 && val->chars[0] != '0' ){

			std::string aux ((char*)val->chars);
			std::map<std::string,Store::Matrix<double>>::iterator it = VarList_MD.find( aux );
			
			if( it != VarList_MD.end() ){
				Store::Matrix<double> OUTmatx((*it).second);
					return OUTmatx;
				}

					throw UNDECL_VAR(aux);

			}else{//si ni es un numero especial ni una variable tiene que ser si o si un numero comun

		Store::Matrix<double> OUTmatx(1,1);
		OUTmatx.Get_Component(1,1) = atof( (const char*)val->chars );
		return OUTmatx;

			}

	}











//Funcion encargada de recorrer en postorden el arbol y resolverlo
//devolviendo el resultado de la expression, ejecutando asignaciones, o graficando
//Notar que debe ser un template y no una sobrecarga, porque la diferencia esta en la devolucion 
//del metodo,luego eso no forma parte de la firma y por lo tanto la sobrecarga no puede decidirse por cual ejecutar
	template<typename T>
Res<T> Resolve( pANTLR3_BASE_TREE T){
	return 0;
	}



	template<>
Res<double> Resolve( pANTLR3_BASE_TREE T){

	ANTLR3_STRING_struct* val = T->toString(T);

	if( T->getChildCount(T) == 0 ){

		if(	(!(val->compare8(val,"pi"))) || (!(val->compare8(val,"PI")))  ){
			return acos((double)-1);//sucio
		}
		if(	(!(val->compare8(val,"e")))  ||  (!(val->compare8(val,"E")))  ){
			return exp((double)1);//sucio
		}


		std::string aux ((char*)val->chars);
		std::map<std::string,double>::iterator it = VarList_D.find( aux );
		
			
			if( it != VarList_D.end() ){
					Res<double> s((*it).second,aux);
					//en este caso puede ser que se este pidiendo el valor de la variable,
					//en ese caso por el return sale el valor, o que sea una asignacion, entonces
					//lo que importa en realidad es que se almacene en whom a que variable se le asignara el nuevo valor
					return s;
				}
		
		return atof( (const char*)val->chars );
			

	}

	Res<double> A=0,B=0;

	if( T->getChildCount(T) == 2){
	pANTLR3_BASE_TREE child1, child2;

		child1 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,0) );
			A = Resolve<double>(child1);
		child2 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,1) );
			B = Resolve<double>(child2);
	}else{
		pANTLR3_BASE_TREE child1= static_cast<pANTLR3_BASE_TREE>( T->getChild(T,0) );;
		A = Resolve<double>(child1);

	}




	switch(val->chars[0]){
		case'+':
			 {	
			 return A.val+B.val;	
				break;
			 }
		case'-':
			{
			return A.val-B.val;
				break;
			}
		case'*':
			{
			return A.val*B.val;
				break;
			}
		case'/':
			{
			if( B.val == 0 )
				throw ZERO_DIV<double>(A.val);
			return A.val/B.val;
				break;
			}
		case'^':
			{
			return pow(A.val,B.val);
				break;
			}
		case'=':
			{
			VarList_D[A.whom]= B.val;
			return B.val;
				break;
			}
		default:
			{
				if( !(val->compare8(val,"sin")) ){
					return sin(A.val);
				}
				if( !(val->compare8(val,"cos")) ){
					return cos(A.val);
				}
				if(	!(val->compare8(val,"tan"))	){
					return tan(A.val);
				}
				if( !(val->compare8(val,"sqrt")) ){
					return sqrt(A.val);
				}
				if( !(val->compare8(val,"abs"))  ){
					return abs(A.val);
				}
				if(	!(val->compare8(val,"exp"))  ){
					return exp(A.val);
				}
				if(	!(val->compare8(val,"log"))  ){
					return log(A.val);
				}
				if(	!(val->compare8(val,"log10"))  ){
					return log10(A.val);
				}
				if(	!(val->compare8(val,"floor"))  ){
					return floor(A.val);
				}
				if(	!(val->compare8(val,"ceil"))  ){
					return ceil(A.val);
				}
				if(	!(val->compare8(val,"round"))  ){
					if( A.val >= 0){
						return floor( A.val +0.5);
						}else{
							return ceil( abs(A.val) -0.5);
						}

				}
				if(	!(val->compare8(val,"'"))  ){
						return ceil( abs(A.val) -0.5);///VER ACA
				}

				if(	!(val->compare8(val,"asin"))  ){
					return asin(A.val);
				}
				if(	!(val->compare8(val,"acos"))  ){
					return acos(A.val);
				}
				if(	!(val->compare8(val,"atan"))  ){
					return atan(A.val);
				}
				if(	!(val->compare8(val,"sinh"))  ){
					return sinh(A.val);
				}
				if(	!(val->compare8(val,"cosh"))  ){
					return cosh(A.val);
				}
				if(	!(val->compare8(val,"tanh"))  ){
					return tanh(A.val);
				}
				
				return 0;

				break;
			}


	}

}

//Importante tener en cuenta que el constructor de vector que recibe un numero(int), lo que hace es crear
//un vector con el numero de cantidades de elementos, NO CREAR UN VECTOR CON UNA COMPONENTE CON ESA COMPONENTE
//por eso antes de devolver los nodos terminales que seran o variables, en este caso no hay problema o
//escalares, primero se crea el vector y despues se lo devuelve, porque si se lo haria de una entonces 
//se crearia un vector lleno de ceros del tamano que sea el escalar! y eso no es lo que se quiere
	template<>
Res<Store::Vector<double>> Resolve( pANTLR3_BASE_TREE T){

	ANTLR3_STRING_struct* val = T->toString(T);

	if( T->getChildCount(T) == 0 ){

		if( (!(val->compare8(val,";"))) ){
			not_print = 1;
			return Res<Store::Vector<double>>( Store::Vector<double>(),"-");
			}

		if( (!(val->compare8(val," "))) ){
			not_print = 1;
			return Res<Store::Vector<double>>( Store::Vector<double>() );
			}
		
		//si es algun tipo de numero especial, ie pi o e
		if(	(!(val->compare8(val,"pi"))) || (!(val->compare8(val,"PI")))  ){
			Store::Vector<double> num(1,acos((double)-1));//sucio
			return num;
		}
		if(	(!(val->compare8(val,"e")))  ||  (!(val->compare8(val,"E")))  ){
			Store::Vector<double> num(1,exp((double)1));//sucio
			return num;
		}

		//si no lo puedo hacer un numero y no es 0, entonces es una variable
		if( atof( (const char*)val->chars ) == 0 && val->chars[0] != '0' ){

			std::string aux ((char*)val->chars);
			std::map<std::string,Store::Vector<double>>::iterator it = VarList_VD.find( aux );
			
			if( it != VarList_VD.end() ){
					Res<Store::Vector<double>> s((*it).second,aux);
					//entonces esto puede resutar en:
					//a) Utiliza el valor de la variable
					//b) reasignarle un valor a la variable
							//para cualquiera de los casos nesesita la variable y su valor, los devuelvo
					return s;
				}

	
				//En una correcta utilizacion de la gramatica esto solo puede resultar en una asginacion
				//devuelvo la variable
				Res<Store::Vector<double>> s(0,aux);
				return s;

			}else{//si ni es un numero especial ni una variable tiene que ser si o si un numero comun

		Store::Vector<double> OUTvect(1,atof( (const char*)val->chars ) );
		return OUTvect;

			}
			

	}//si no estra en este if es porque no es un nodo terminal

		{//Este es el magnifico caso en el que no se imprime resultado 
		pANTLR3_BASE_TREE TEMP = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,T->getChildCount(T)-1) );
		ANTLR3_STRING_struct* tex = TEMP->toString(TEMP);
			
		if(
			!tex->compare8( tex , ";" )
			
			){
		//Resolve<Store::Vector<double>>( static_cast<pANTLR3_BASE_TREE>(T->getChild(T,T->getChildCount(T)-1)) ) == 
		//		Res<Store::Vector<double>>(Store::Vector<double>(),"-",1) ) 
		  
				not_print=1;//dice a nivel global que no se imprima
				T->deleteChild(T,T->getChildCount(T)-1);//borro el hijo que dice que no se imprima
		   }

		}

		//--------------------------------- Proceso el contenido interno del arbol


	Res<Store::Vector<double>> A=0,B=0;

	//Notar que a diferencia de el Resolve de double aca esta el caso de 1 hijo y el de mas de 1 y 2
	//separado, esto es por la asignacion multiple de vectores [...] que obliga a tener muchos hijos

	if( T->getChildCount(T) == 2){//en el caso que sea una expression binaria comun
	pANTLR3_BASE_TREE child1, child2;

		child1 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,0) );
			A = Resolve<Store::Vector<double>>(child1);
		child2 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,1) );
			B = Resolve<Store::Vector<double>>(child2);
			
		}else{
			if( T->getChildCount(T) == 1){//en el caso que halla una funcion en la expression
				pANTLR3_BASE_TREE child= static_cast<pANTLR3_BASE_TREE>( T->getChild(T,0) );
				A = Resolve<Store::Vector<double>>(child);
			}else{//solo en el caso de un arreglo [] o el caso [..] el resto son todas operaciones binarias
				pANTLR3_BASE_TREE child1;

					Store::Vector<double> novo;
					//por todos los hijos despues del primero los recorro y armo el vector con 
					//su contenido
					for(int i=0;i < T->getChildCount(T);i++){
						child1 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,i) );//cargo un hijo

						novo.Resize(novo.Length()+1);//agrando el vector
						novo.insert( (Resolve<Store::Vector<double>>(child1)).val[0],novo.Length());//lo agrego

						if( (i==0) ){//si es la primera vez, luego me fijo si el segundo es :
							//lo que significaria que es un ingreso por rango, el cual hay que leer y cargar de forma
							//especial. Notar que solo aparece en el arbol el primer : el otro ya seria redundante 
							child1 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,1) );
								if( !(child1->toString(child1)->compare8(child1->toString(child1),":") ) ){//me fijo si efectivamente tiene un :
								child1 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,2) );//entonces crago el dato para saber de a cuantos abanzar
								double path = atof( (char*)(child1->toString(child1)->chars) );
								child1 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,3) );//leo luego hasta donde se llena
								double to = atof( (char*)child1->toString(child1)->chars );

								double from = novo[0];//el desde donde estaba ingresado en el primer elemento del vector

								novo.Fill_Stair(from,to,path);//lo lleno

								i=T->getChildCount(T);//elijo un i para que salga del for y termine de ingresar
								
									}
							}

						}//fin del for
					B.val=novo;
				}//fin del caso para arrays
		}//fin del if mas externo, que pregunta por operaciones binarias

	//--------------------------------- Fin de Procesar el contenido interno del arbol



	switch(val->chars[0]){
		case'+':
			{	
			 return A.val+B.val;	
				break;
			 }
		case'-':
			{
			return A.val-B.val;
				break;
			}
		case'*':
			{
						//esto es para que funcione el producto por un escalar
			//porque la clase si recibe un vector de tamaño 1 y otro de otro tamano
			//no considera como el de 1 como escalar, lo que esta bien poruqe en el compilador
			//si se quiere producto por un escalar se lo tiene que hacer al producto por un escalar 1,2,3,4... pero aca 
			//nesesito de que pase eso porque todo es un vector, y nada un escalar
			if( B.val.Length() == 1 ){
				double escalar = B.val[0];
				return A.val*escalar;
				}
			if( A.val.Length() == 1 ){//lo mismo que arriba pero para el caso de escalar a la izquierda
				double escalar = A.val[0];
				return escalar*B.val;

				}
			
			//si los dos son vectores, y ninguno un escalar
			return A.val*B.val;
				break;
			}
		case'/':
			{
			for( int i=0; i < B.val.Length() ; i++ )
				if( B.val[i] == 0 )
					throw ZERO_DIV<Store::Vector<double>>(A.val);
			return A.val/B.val;
				break;
			}
		case'^':
			{//como la potencia tiene sentido solo eleveda aun numero, no un vector, si se eleva a n vector, se toma
			//la primera componente
			if( B.val.Length() > 1 )
				throw SEC_ARG_MUST_BE_ESC();
			return Store::Pow<Store::Vector<double>>::Get(A.val,B.val[0]);
				break;
			}
		case'=':
			{
			VarList_VD[A.whom]= B.val;
			//de esta forma B lleva consigo la variable a la que se asigno
			//y luego se puede decir que se asigno a la variable "x"
			B.whom = A.whom;
			return B;			  
				break;
			}
		case'[':
			{
				return B;//a esta variable le asigne todo el nuevo vector
				break;
			}
		default:
			{
				if( !( val->compare8(val,"plot") ) ){
					std::string name("X5");
					std::string path("Content\\");
					Store::Vector<double> XXX(A.val.Length());
					for(int i=0;i<A.val.Length();i++){
						XXX[i]=A.val[i];
						}
					XXX.To_Bynary(name,path);

					name="Y5";
					path="Content\\";
					Store::Vector<double> YYY(B.val.Length());
					for(int i=0;i<B.val.Length();i++){
						YYY[i]=B.val[i];
						}
					YYY.To_Bynary(name,path);
	
					system("Crap_Graph.exe");
					return 0;
					}
				if(	!(val->compare8(val,"cross"))  ){
					return Store::Vector<double>::Cross(A.val,B.val);
				}
				if(	!(val->compare8(val,"trapz"))  ){
					//Temporales para convertir de el area, escalar a un vector con el area en una componente
					double area = Function_Algorithms::Integration::trapz(A.val,B.val);
					Store::Vector<double> temp(1,area); 
					
					return Res<Store::Vector<double>>( temp );
				}
				if(	!(val->compare8(val,"der1"))  ){
					return Function_Algorithms::Derivation::Derivate1_3Puntos(A.val,B.val);
				}
				if(	!(val->compare8(val,"der2"))  ){
					return Function_Algorithms::Derivation::Derivate2_3Puntos(A.val,B.val);
				}
				if(	!(val->compare8(val,"der3"))  ){
					return Function_Algorithms::Derivation::Derivate3_4Puntos(A.val,B.val);
				}
				if(	!(val->compare8(val,"der4"))  ){
					return Function_Algorithms::Derivation::Derivate4_5Puntos(A.val,B.val);
				}
				if(	!(val->compare8(val,"rand"))  ){
					//No esta hecha aca
					//return Function_Algorithms::Derivation::Derivate4_5Puntos(A.val,B.val);
				}
				if( !(val->compare8(val,"sin")) ){
					return  Store::Sin<Store::Vector<double>>::Get(A.val);
				}
				if( !(val->compare8(val,"cos")) ){
					return Store::Cos<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"tan"))	){
					return Store::Tan<Store::Vector<double>>::Get(A.val);
				}
				if( !(val->compare8(val,"sqrt")) ){
					return Store::Sqrt<Store::Vector<double>>::Get(A.val);
				}
				if( !(val->compare8(val,"abs"))  ){
					return Store::ABS<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"exp"))  ){
					return Store::Exp<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"log"))  ){
					return Store::Ln<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"log10"))  ){
					return Store::Log<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"floor"))  ){
					return Store::FLOOR<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"ceil"))  ){
					return Store::CEIL<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"asin"))  ){
					return Store::ASin<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"acos"))  ){
					return Store::ACos<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"atan"))  ){
					return Store::ATan<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"sinh"))  ){
					return Store::SinH<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"cosh"))  ){
					return Store::CosH<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"tanh"))  ){
					return Store::TanH<Store::Vector<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"size"))  ){
					Store::Vector<double> aux( 1,A.val.Length() );
					return aux;
				}
				
				return 0;

				break;
			}

			//por las dudas si algo sale mal y llega aca sin salir, que devuelva nada 
			//asi no devuelve basura, ya que eso podria hacer que explote
			return Res<Store::Vector<double>>();


	}

}







#include <set>
#include <time.h>

	template<>
Res<Store::Matrix<double>> Resolve( pANTLR3_BASE_TREE T){

	ANTLR3_STRING_struct* val = T->toString(T);
/*
		std::string a = (char*)val->chars;
		if( (a.find(".^") != std::string::npos) && (a.find(".^") > 0) ){
			Res<Store::Matrix<double>> A(Store::Matrix<double>(1,1));
			A.val.Get_Component(1,1)=atof( (a.substr(0,a.find(".^"))).c_str() );

			a.erase(0,a.find(".^")+2);
			
			//la cosa mas sucia qe se me pudo haber ocurrido
			pANTLR3_INPUT_STREAM input;
			pCrapGrammaticLexer lexer;
			pANTLR3_COMMON_TOKEN_STREAM tokens;
			pCrapGrammaticParser parser;

			input = antlr3NewAsciiStringInPlaceStream((pANTLR3_UINT8)a.c_str(),a.length(),NULL);
			lexer = CrapGrammaticLexerNew(input);
			tokens= antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT,
				 lexer->pLexer->tokSource );
			parser= CrapGrammaticParserNew( tokens);

			CrapGrammaticParser_entry_return ast;
			ast = parser->entry(parser);
			
			Res<Store::Matrix<double>> B = Resolve<Store::Matrix<double>>(ast.tree);
			
				double escalar = A.val.Get_Component(1,1);
				for(int i=1;i <= B.val.Get_F();i++)
					for(int j=1;j <= B.val.Get_C();j++)
						B.val.Get_Component(i,j)=Store::Pow<double>::Get(escalar,B.val.Get_Component(i,j));
			return B;

			}

			*/


	//solo se pone en verdadero si es el mismbro izquierdo de una asignacion
	//de lo contrario tira una exepcion UNDECL_VAR
	static bool must_decl=false;

	if( T->getChildCount(T) == 0 ){

		if( (!(val->compare8(val,";"))) ){
			not_print = 1;
			return Res<Store::Matrix<double>>( Store::Matrix<double>(),"-");
			}

		if( (!(val->compare8(val," "))) ){
			not_print = 1;
			return Res<Store::Matrix<double>>( Store::Matrix<double>() );
			}
		
		//si es algun tipo de numero especial, ie pi o e
		if(	(!(val->compare8(val,"pi"))) || (!(val->compare8(val,"PI")))  ){
			Store::Matrix<double> num(1,1);//sucio
			num.Get_Component(1,1) = acos((double)-1);
			return num;
		}
		if(	(!(val->compare8(val,"e")))  ||  (!(val->compare8(val,"E")))  ){
			Store::Matrix<double> num(1,1);//sucio
			num.Get_Component(1,1) = exp((double)1);
			return num;
		}

		//si no lo puedo hacer un numero y no es 0, entonces es una variable
		if( atof( (const char*)val->chars ) == 0 && val->chars[0] != '0' ){

			std::string aux ((char*)val->chars);
			std::map<std::string,Store::Matrix<double>>::iterator it = VarList_MD.find( aux );
			
			if( it != VarList_MD.end() ){
					Res<Store::Matrix<double>> s((*it).second,aux);
					//entonces esto puede resutar en:
					//a) Utiliza el valor de la variable
					//b) reasignarle un valor a la variable
							//para cualquiera de los casos nesesita la variable y su valor, los devuelvo
					return s;
				}

				if( !must_decl )
					throw UNDECL_VAR(aux);

				must_decl=false;
	
				//En una correcta utilizacion de la gramatica esto solo puede resultar en una asginacion
				//devuelvo la variable
				Res<Store::Matrix<double>> s(0,aux);
				return s;

			}else{//si ni es un numero especial ni una variable tiene que ser si o si un numero comun

		Store::Matrix<double> OUTmatx(1,1);
		OUTmatx.Get_Component(1,1) = atof( (const char*)val->chars );
		return OUTmatx;

			}
			

	}//si no estra en este if es porque no es un nodo terminal

		{//Este es el magnifico caso en el que no se imprime resultado 
		pANTLR3_BASE_TREE TEMP = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,T->getChildCount(T)-1) );
		ANTLR3_STRING_struct* tex = TEMP->toString(TEMP);
			
		if(
			!tex->compare8( tex , ";" )
			
			){
		//Resolve<Store::Vector<double>>( static_cast<pANTLR3_BASE_TREE>(T->getChild(T,T->getChildCount(T)-1)) ) == 
		//		Res<Store::Vector<double>>(Store::Vector<double>(),"-",1) ) 
		  
				not_print=1;//dice a nivel global que no se imprima
				T->deleteChild(T,T->getChildCount(T)-1);//borro el hijo que dice que no se imprima
		   }

		}

		//--------------------------------- Proceso el contenido interno del arbol


	Res<Store::Matrix<double>> A=0,B=0;

	//Notar que a diferencia de el Resolve de double aca esta el caso de 1 hijo y el de mas de 1 y 2
	//separado, esto es por la asignacion multiple de vectores [...] que obliga a tener muchos hijos

	if( T->getChildCount(T) == 2){//en el caso que sea una expression binaria comun
	pANTLR3_BASE_TREE child1, child2;

		if( !val->compare8( val , "=" )) must_decl=true;

		child1 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,0) );
			A = Resolve<Store::Matrix<double>>(child1);
		child2 = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,1) );
			B = Resolve<Store::Matrix<double>>(child2);
			
		}else{
			if( T->getChildCount(T) == 1){//en el caso que halla una funcion en la expression
				pANTLR3_BASE_TREE child= static_cast<pANTLR3_BASE_TREE>( T->getChild(T,0) );
				A = Resolve<Store::Matrix<double>>(child);

				//si es menos unitario lo resuelvo aca para que no choque con el menos binario
			if(	!(val->compare8(val,"-")) ){
					A.val.PDes(-1);
					return A.val;
				}
				//si es mas unitario lo resuelvo aca para que no choque con el menos binario
			if(	!(val->compare8(val,"+")) ){
					return A.val;
				}
			}else{//solo en el caso de un arreglo [] o el caso [..] el resto son todas operaciones binarias
			pANTLR3_BASE_TREE child1;


				//------------------- De todo este codigo salgo sabiendo el numero de filas y columnas
				//------------------- y si es consistente los elementos con sus columnas
				int filas=1;
				std::set<int> Columnas;
				//cols es un temporal que lleva las columans por fila
				int cols=0;

				int prev=0;
				for( int y=0;y < T->getChildCount(T);y++){
					pANTLR3_BASE_TREE H = static_cast<pANTLR3_BASE_TREE>(T->getChild(T,y));
					if( ! ((H)->toString(H)->compare8((H)->toString(H), ";" ) ) ){
						filas++;
						
						Columnas.insert(cols);
						if( Columnas.size() > 1 )
							throw BAD_DIM(std::string("La matriz que esta intentando crear tiene distinta cantidad de columns en cada \nfila\n"));
						

						cols=0;

						}else{
							//-------------------------- si es un rango lo manejo aca
							if( ! ((H)->toString(H)->compare8((H)->toString(H), ":" ) ) ){
								double from=prev;
								y++;
								H = static_cast<pANTLR3_BASE_TREE>(T->getChild(T,y));
								//si no se le pone un paso, lo asume 1
								double pace=0;
								if( !(H->toString(H)->compare8(H->toString(H),":")))
									pace=1;
								else{
									Store::Matrix<double> pace_temp( Serch_Constants_Variables(H->toString(H)) );
									pace= pace_temp.Get_Component(1,1);
									//como le sigue un :
									y++;
									}
								y++;
								int cont = T->getChildCount(T);
								H = static_cast<pANTLR3_BASE_TREE>(T->getChild(T,y));
														
								Store::Matrix<double> to_temp( Serch_Constants_Variables(H->toString(H)));
									double to=to_temp.Get_Component(1,1);

								double aux=from;
								int cant=1;
								while( true ){
									if ( (aux+=pace) <= to){
										cant++;
										}
									else
										break;
								}
									//le sumo lo del rango
									//parece estupido el +1 -1 pero representa el hecho que antes el from 
									//lo habia sumado ahora se lo resto
									cols = ( 1 - 1 + cant );

									//No se pueden enganchar sin dejar un numero entre medio dos rangos
									prev=0;
									
								}else{//-------------------------- si no estro al if de arriba no era un rango
							Res<Store::Matrix<double>> comp = Resolve<Store::Matrix<double>>(H);
							Store::Matrix<double> to_prev_temp( comp.val );
							prev= to_prev_temp.Get_Component(1,1);
							cols++;
								}
						}

					}

				Columnas.insert(cols);
				if( Columnas.size() > 1 )
					throw BAD_DIM(std::string("La matriz que esta intentando crear tiene distinta cantidad de columns en cada \nfila\n"));

				//------------------- ya se filas, numero de filas y Columnas[0], el numero de columnas
				
				Store::Matrix<double> novo(filas,*(Columnas.begin()));

				int fil=1;
				int col=1;
				prev=0;
				for( int i=0;i < T->getChildCount(T);i++){
					pANTLR3_BASE_TREE child = static_cast<pANTLR3_BASE_TREE>( T->getChild( T, i ) );
					if( !( child->toString( child )->compare8( child->toString( child ) , ";" ) ) ) {
						fil++;
						col=1;
						continue;
						}

					if( !( child->toString( child )->compare8( child->toString( child ) , ":" ) ) ){
							double from = prev;
							i++;
							child = static_cast<pANTLR3_BASE_TREE>(T->getChild(T,i));
							//si no se le pone un paso, lo asume 1
							double pace=0;
							if( !(child->toString(child)->compare8(child->toString(child),":")))
								pace=1;
							else{
								Res<Store::Matrix<double>> comp= Resolve<Store::Matrix<double>>(child);
								Store::Matrix<double> pace_temp( comp.val);
								pace=pace_temp.Get_Component(1,1);
								//como le sigue un :
								i++;
								}

							i++;
							child = static_cast<pANTLR3_BASE_TREE>(T->getChild(T,i));
								
								Res<Store::Matrix<double>> comp= Resolve<Store::Matrix<double>>(child);
								Store::Matrix<double> to_temp( comp.val );
								double to= to_temp.Get_Component(1,1);

								if( ( (from < to) && (pace<0) ) || ( (from > to) && (pace>0)  ))
									throw BAD_DIM(std::string("Las dimensiones del rango son incorrectas\n"));

								double aux=from;
								while( true ){
									if ( (aux+=pace) <= to){
										novo.Get_Component(fil,col)=aux;
										//ya esta visto que los arreglos estan bien y que simepre va en una fila
										col++;
										}
									else
										break;
								}

						}else{
							Res<Store::Matrix<double>> comp= Resolve<Store::Matrix<double>>(child);
							if( (comp.val.Get_C() == 1) && (comp.val.Get_F() == 1) ){
								Store::Matrix<double> to_save_temp( comp.val );
								novo.Get_Component(fil,col)= to_save_temp.Get_Component(1,1);
								prev= novo.Get_Component(fil,col);
								col++;

								}

						}


					}
				/*Codigodelicado pero que no maneja rangos
					for(int i=0;i < filas;i++){
						for(int j=0;j < *(Columnas.begin());j++){
							pANTLR3_BASE_TREE child = static_cast<pANTLR3_BASE_TREE>( T->getChild(T,(*(Columnas.begin())*i+j+i)) );
							novo.Get_Component(i+1,j+1) = atof( (char*)child->toString(child)->chars );
							}

						}
				*/
					B.val=novo;
				}//fin del caso para arrays
		}//fin del if mas externo, que pregunta por operaciones binarias

	//--------------------------------- Fin de Procesar el contenido interno del arbol



	switch(val->chars[0]){
		case'+':
			{	

			//manejan los casos de un escalar que se suma a una matriz
			//en ese caso el escalar hace de matriz
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				Store::Matrix<double> aux(A.val.Get_F(), A.val.Get_C());
				for(int i=1;i <= aux.Get_F();i++){
					for(int j=1;j <= aux.Get_C();j++){
						aux.Get_Component(i,j)=B.val.Get_Component(1,1);
						}
					}
				return A.val+aux;
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){
				double escalar = A.val.Get_Component(1,1);
				Store::Matrix<double> aux(B.val.Get_F(), B.val.Get_C());
				for(int i=1;i <= aux.Get_F();i++){
					for(int j=1;j <= aux.Get_C();j++){
						aux.Get_Component(i,j)=A.val.Get_Component(1,1);
						}
					}
				return B.val+aux;
				}


			//manejo desde fuera del operador las exepciones
			if(A.val.Get_C()!=B.val.Get_C() || A.val.Get_F()!=B.val.Get_F()){
				char f1[50];
				char c1[50];
				char f2[50];
				char c2[50];
				throw BAD_DIM( std::string("La primera matriz tiene dimensiones ") + itoa(A.val.Get_F(),f1,10) + std::string("x") + itoa(A.val.Get_C(),c1,10)
					+ std::string(" y la\nsegunda matriz tiene dimensiones ") + itoa(B.val.Get_F(),f2,10) + std::string("x") + itoa(B.val.Get_C(),c2,10) + std::string("\n") );
					
				}

			 return A.val+B.val;	
				break;
			 }
		case'-':
			{

				//esto esta aca para evitar coliciones
				if(	!(val->compare8(val,"-^"))  ){
			//Con este operador tambien esta permitida la division por escalares
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				return Store::Pow<Store::Matrix<double>>::Get(A.val,escalar);
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){//lo mismo que arriba pero para el caso de escalar a la izquierda
				double escalar = A.val.Get_Component(1,1);
				for(int i=1;i <= B.val.Get_F();i++)
					for(int j=1;j <= B.val.Get_C();j++)
						B.val.Get_Component(i,j)=Store::Pow<double>::Get(escalar,B.val.Get_Component(i,j));
				return B;

				}
			//Si no es por un escalar es por otra matriz

			//manejo desde fuera del operador las exepciones
			if(A.val.Get_C()!=B.val.Get_C() || A.val.Get_F()!=B.val.Get_F()){
				char f1[50];
				char c1[50];
				char f2[50];
				char c2[50];
				throw BAD_DIM( std::string("La primera matriz tiene dimensiones ") + itoa(A.val.Get_F(),f1,10) + std::string("x") + itoa(A.val.Get_C(),c1,10)
					+ std::string(" y la\nsegunda matriz tiene dimensiones ") + itoa(B.val.Get_F(),f2,10) + std::string("x") + itoa(B.val.Get_C(),c2,10) + std::string("\n") );
					
				}

					return A.val.Per_Component_Potence(B.val);
					}



			//manejan los casos de un escalar que se suma a una matriz
			//en ese caso el escalar hace de matriz
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				Store::Matrix<double> aux(A.val.Get_F(), A.val.Get_C());
				for(int i=1;i <= aux.Get_F();i++){
					for(int j=1;j <= aux.Get_C();j++){
						aux.Get_Component(i,j)=B.val.Get_Component(1,1);
						}
					}
				return A.val-aux;
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){
				double escalar = A.val.Get_Component(1,1);
				Store::Matrix<double> aux(B.val.Get_F(), B.val.Get_C());
				for(int i=1;i <= aux.Get_F();i++){
					for(int j=1;j <= aux.Get_C();j++){
						aux.Get_Component(i,j)=A.val.Get_Component(1,1);
						}
					}
				return aux-B.val;
				}

			//manejo desde fuera del operador las exepciones
			if(A.val.Get_C()!=B.val.Get_C() || A.val.Get_F()!=B.val.Get_F()){
				char f1[50];
				char c1[50];
				char f2[50];
				char c2[50];
				throw BAD_DIM( std::string("La primera matriz tiene dimensiones ") + itoa(A.val.Get_F(),f1,10) + std::string("x") + itoa(A.val.Get_C(),c1,10)
					+ std::string(" y la\nsegunda matriz tiene dimensiones ") + itoa(B.val.Get_F(),f2,10) + std::string("x") + itoa(B.val.Get_C(),c2,10) + std::string("\n") );
					
				}

			return A.val-B.val;
				break;
			}
		case'*':
			{
						//esto es para que funcione el producto por un escalar
			//porque la clase si recibe un vector de tamaño 1 y otro de otro tamano
			//no considera como el de 1 como escalar, lo que esta bien porque en el compilador
			//si se quiere producto por un escalar se lo tiene que hacer al producto por un escalar 1,2,3,4... pero aca 
			//nesesito de que pase eso porque todo es un vector, y nada un escalar
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				A.val.PDes(escalar);
				return A.val;
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){//lo mismo que arriba pero para el caso de escalar a la izquierda
				double escalar = A.val.Get_Component(1,1);
				B.val.PDes(escalar);
				return B.val;

				}
			
			//si los dos son vectores, y ninguno un escalar

			//manejo desde fuera del operador las exepciones
			if(A.val.Get_C()!=B.val.Get_F()){
				char c1[50];
				char f2[50];
				throw BAD_DIM( std::string("Las columnas de la primera matriz son ") + itoa(A.val.Get_C(),c1,10) 
					+ std::string(" y las filas de la segunda son ") + itoa(B.val.Get_F(),f2,10) + std::string("\n") );
					
				}

			return A.val*B.val;
			break;
			}
		case'/':
			{
			//Con este operador tambien esta permitida la division por escalares
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				if( escalar == 0 )
					throw ZERO_DIV<Store::Matrix<double>>(A.val);
				A.val.PDes(1/escalar);
				return A.val;
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){//lo mismo que arriba pero para el caso de escalar a la izquierda
				double escalar = A.val.Get_Component(1,1);
				if( escalar == 0 ) 
					throw BAD_DIM(std::string("No puede dividir un escalar por un arreglo\n"));
				B.val.PDes(1/escalar);
				return B.val;

				}

			//Si no es por un escalar es por otra matriz


			//manejo desde fuera del operador las exepciones
			if(A.val.Get_C()!=B.val.Get_C() || A.val.Get_F()!=B.val.Get_F()){
				char f1[50];
				char c1[50];
				char f2[50];
				char c2[50];
				throw BAD_DIM( std::string("La primera matriz tiene dimensiones ") + itoa(A.val.Get_F(),f1,10) + std::string("x") + itoa(A.val.Get_C(),c1,10)
					+ std::string(" y la\nsegunda matriz tiene dimensiones ") + itoa(B.val.Get_F(),f2,10) + std::string("x") + itoa(B.val.Get_C(),c2,10) + std::string("\n") );
					
				}

			for( int j=1; j <= B.val.Get_C() ; j++ )
				for( int i=1; i <= B.val.Get_F() ; i++ )
					if( B.val.Get_Component(i,j) == 0 )
						throw ZERO_DIV<Store::Matrix<double>>(A.val);
			//nose que tenia el operador / de las matrices, pero ahora no le veo el sentido
			return A.val.Per_Component_Division(B.val);
				break;
			}
		case'^':
			{
			
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				Store::Matrix<double> temp(A.val);
				for(int k=0;k<(escalar-1);k++)//notar que es escalar-1 esntonces cuando es 2 tenemos A*A y no A*A*A
					A.val= A.val * temp;
				return A.val;
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){//lo mismo que arriba pero para el caso de escalar a la izquierda
				double escalar = A.val.Get_Component(1,1);
				Store::Matrix<double> temp(B.val);
				for(int k=0;k<(escalar-1);k++)
					B.val= B.val * temp;
				return B.val;

				}

				throw SEC_ARG_MUST_BE_ESC();
			break;
			}
		case'=':
			{
			VarList_MD[A.whom]= B.val;
			//de esta forma B lleva consigo la variable a la que se asigno
			//y luego se puede decir que se asigno a la variable "x"
			B.whom = A.whom;
			return B;			  
				break;
			}
		case'[':
			{
			//Si solo hay un elemento en el array [x] luego entra como si fuese funcion 
			//y almacena el valor en A
			if( T->getChildCount(T) == 1 )
				B.val=A.val;

			//Si hay dos elementos en el array [x y] luego entra como si fuese operacion binaria
			//y almacena un valor en A y otro en B
			if( T->getChildCount(T) == 2 ){
				Store::Matrix<double> aux(1,2);
				aux.Get_Component(1,1)=A.val.Get_Component(1,1);
				aux.Get_Component(1,2)=B.val.Get_Component(1,1);
				B.val=aux;
				}

				return B;//a esta variable le asigne ttoda la nueva matriz
				break;
			}
			case'(':
			{

			return A;

				break;
			}
		default:
			{
				if( !( val->compare8(val,"plot") ) ){
					std::string name("X1");
					//std::string path("..\\..\\Crap_Graph\\Crap_Graph\\bin\\x86\\Debug\\Content\\");
					std::string path("Content\\");
					if( (A.val.Get_C() > 1) && (A.val.Get_F() > 1) )//si pasa esto no sirve esta matriz para hacer un vector
						throw BAD_DIM(std::string("La funcion plot lleva un vector como primer argumento, utilize vector fila\no columna indistintamente\n"));							
					Store::Vector<double> XXX(A.val);
					if( XXX.Length() == 1 ) 
						throw BAD_DIM(std::string("El primer argumento es un punto y la funcion plot no puede dibujar puntos,\npruebe con rangos de datos, de almenos 2 elementos\n"));

					if( !XXX.To_Bynary(name,path) )
						throw GEN_OUT_IN_ERR(std::string("No se pueden guardar los archivos .crap\n"));

					name="Y1";
					//path=("..\\..\\Crap_Graph\\Crap_Graph\\bin\\x86\\Debug\\Content\\");
					path="Content\\";
					if( (B.val.Get_C() > 1) && (B.val.Get_F() > 1) )//si pasa esto no sirve esta matriz para hacer un vector
						throw BAD_DIM(std::string("La funcion plot lleva un vector como segundo argumento, utilize vector fila\no columna indistintamente\n"));														
					Store::Vector<double> YYY(B.val);
					if( YYY.Length() == 1 ) 
						throw BAD_DIM(std::string("El segundo argumento es un punto y la funcion plot no puede dibujar puntos,\npruebe con rangos de datos, de almenos 2 elementos\n"));

					if( !YYY.To_Bynary(name,path) )
						throw GEN_OUT_IN_ERR(std::string("No se pueden guardar los archivos .crap\n"));



					if(XXX.Length() != YYY.Length())
						throw BAD_DIM(std::string("Los argumentos de plot deben tener igual dimension\n"));
	

					
					//Direccion relativa a la acrpeta de Debug del otro proyecto:
					//"..\\..\\Crap_Graph\\Crap_Graph\\bin\\x86\\Debug\\Crap_Graph.exe";

					//Version que sigue corriendo CrapLab
					//WinExec("Crap_Graph.exe");
					//Version que espera a que termine Crap_Graph
					system("Crap_Graph.exe");
					return 0;
					}

				//Comienzo de Operadores aritmeticos componente a componente
				if(	!(val->compare8(val,".*"))  ){
			//Con este operador tambien esta permitida la multiplicacion por escalares
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				A.val.PDes(escalar);
				return A.val;
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){//lo mismo que arriba pero para el caso de escalar a la izquierda
				double escalar = A.val.Get_Component(1,1);
				B.val.PDes(escalar);
				return B.val;

				}
			//Si no es por un escalar es por otra matriz

						//manejo desde fuera del operador las exepciones
			if(A.val.Get_C()!=B.val.Get_C() || A.val.Get_F()!=B.val.Get_F()){
				char f1[50];
				char c1[50];
				char f2[50];
				char c2[50];
				throw BAD_DIM( std::string("La primera matriz tiene dimensiones ") + itoa(A.val.Get_F(),f1,10) + std::string("x") + itoa(A.val.Get_C(),c1,10)
					+ std::string(" y la\nsegunda matriz tiene dimensiones ") + itoa(B.val.Get_F(),f2,10) + std::string("x") + itoa(B.val.Get_C(),c2,10) + std::string("\n") );
					
				}


					return A.val.Per_Component_Product(B.val);
					}
				if(	!(val->compare8(val,"./"))  ){
			//Con este operador tambien esta permitida la division por escalares
			if( (B.val.Get_C() == 1) && (B.val.Get_F() == 1) ){
				double escalar = B.val.Get_Component(1,1);
				A.val.PDes(1/escalar);
				return A.val;
				}
			if( (A.val.Get_C() == 1) && (A.val.Get_F() == 1) ){//lo mismo que arriba pero para el caso de escalar a la izquierda
				double escalar = A.val.Get_Component(1,1);
				B.val.PDes(1/escalar);
				return B.val;

				}
			//Si no es por un escalar es por otra matriz

			//manejo desde fuera del operador las exepciones
			if(A.val.Get_C()!=B.val.Get_C() || A.val.Get_F()!=B.val.Get_F()){
				char f1[50];
				char c1[50];
				char f2[50];
				char c2[50];
				throw BAD_DIM( std::string("La primera matriz tiene dimensiones ") + itoa(A.val.Get_F(),f1,10) + std::string("x") + itoa(A.val.Get_C(),c1,10)
					+ std::string(" y la\nsegunda matriz tiene dimensiones ") + itoa(B.val.Get_F(),f2,10) + std::string("x") + itoa(B.val.Get_C(),c2,10) + std::string("\n") );
					
				}

					return A.val.Per_Component_Division(B.val);
					}
				//Fin de Operadores aritmeticos componente a componente

				if(	!(val->compare8(val,"inv"))  ){
					return A.val.inv();
					}
				if(	!(val->compare8(val,"gauss"))  ){
					A.val.Gauss_PP();//gauss lo hace inplace, pero el valor de A es el de res, y no el de
									 //la variable ne la tabla. Se hace en dos pasos porque 
									 //gauss devuelve la matriz antes de gausearla
					return A.val;
					}
				if(	!(val->compare8(val,"gaussv"))  ){
					A.val.Gauss_View();//gauss lo hace inplace, pero el valor de A es el de res, y no el de
									 //la variable ne la tabla. Se hace en dos pasos porque 
									 //gauss devuelve la matriz antes de gausearla
					return A.val;
				}
				if(	!(val->compare8(val,"adj"))  ){
					return A.val.adj();;
					}

				if(	!(val->compare8(val,"res"))  ){
					return A.val.Resolve_PP();
					}
				if(	!(val->compare8(val,"cross"))  ){
						//ahora una exepcion que dice si son aceptables
					if( !( ((A.val.Get_F()== 3) && (B.val.Get_F()==3) && (A.val.Get_C()==1) && (B.val.Get_C()==1)) || ((A.val.Get_F()== 1) && (B.val.Get_F()==1) && (A.val.Get_C()==3) && (B.val.Get_C()==3)) || ((A.val.Get_F()== 3) && (B.val.Get_F()==1) && (A.val.Get_C()==1) && (B.val.Get_C()==3)) || ((A.val.Get_F()== 1) && (B.val.Get_F()==3) && (A.val.Get_C()==3) && (B.val.Get_C()==1)) ) )
						throw BAD_DIM(std::string(std::string("Los vectores del producto vectorial deben tener 3 componentes\n")));
					return Store::Matrix<double>::Cross(A.val,B.val);
					}
				if(	!(val->compare8(val,"det"))  ){
					Store::Matrix<double> aux(1,1);
					aux.Get_Component(1,1) = A.val.det(Store::FILACOLUMNA::fila,1);
					return aux;
					}
				if(	!(val->compare8(val,"ones"))  ){
					Store::Matrix<double> aux(A.val.Get_Component(1,1),A.val.Get_Component(1,1));
					aux.fill(1);
					return aux;
					}
				if(	!(val->compare8(val,"zeros"))  ){
					Store::Matrix<double> aux(A.val.Get_Component(1,1),A.val.Get_Component(1,1));
					aux.fill(0);
					return aux;
					}
				if(	!(val->compare8(val,"trapz"))  ){
					if( (A.val.Get_C() != B.val.Get_C()) || (A.val.Get_F() != B.val.Get_F()) )
						throw BAD_DIM(std::string("Los argumentos de trapz deben tener las mismas dimensiones\n"));
					//Temporales para convertir de el area, escalar a un vector con el area en una componente
					Store::Vector<double> ONE( A.val );
					Store::Vector<double> TWO( B.val );
					double area = Function_Algorithms::Integration::trapz(ONE,TWO);
					Store::Matrix<double> temp(1,1);
					temp.Get_Component(1,1) = area;
					
					return Res<Store::Matrix<double>>( temp );
				}
				if(	!(val->compare8(val,"der1"))  ){
					if( (A.val.Get_C() != B.val.Get_C()) || (A.val.Get_F() != B.val.Get_F()) )
						throw BAD_DIM(std::string("Los argumentos de der1 deben tener las mismas dimensiones\n"));
					Store::Vector<double> ONE( A.val );
					Store::Vector<double> TWO( B.val );
					Store::Vector<double> s = Function_Algorithms::Derivation::Derivate1_3Puntos(ONE,TWO);

					return Store::Matrix<double>(s);
				}
				if(	!(val->compare8(val,"der2"))  ){
					if( (A.val.Get_C() != B.val.Get_C()) || (A.val.Get_F() != B.val.Get_F()) )
						throw BAD_DIM(std::string("Los argumentos de der2 deben tener las mismas dimensiones\n"));
					Store::Vector<double> ONE( A.val );
					Store::Vector<double> TWO( B.val );
					Store::Vector<double> s = Function_Algorithms::Derivation::Derivate2_3Puntos(ONE,TWO);

					return Store::Matrix<double>(s);
				}
				if(	!(val->compare8(val,"der3"))  ){
					if( (A.val.Get_C() != B.val.Get_C()) || (A.val.Get_F() != B.val.Get_F()) )
						throw BAD_DIM(std::string("Los argumentos de der3 deben tener las mismas dimensiones\n"));
					Store::Vector<double> ONE( A.val );
					Store::Vector<double> TWO( B.val );
					Store::Vector<double> s = Function_Algorithms::Derivation::Derivate3_4Puntos(ONE,TWO);

					return Store::Matrix<double>(s);
				}
				if(	!(val->compare8(val,"der4"))  ){
					if( (A.val.Get_C() != B.val.Get_C()) || (A.val.Get_F() != B.val.Get_F()) )
						throw BAD_DIM(std::string("Los argumentos de der4 deben tener las mismas dimensiones\n"));
					Store::Vector<double> ONE( A.val );
					Store::Vector<double> TWO( B.val );
					Store::Vector<double> s = Function_Algorithms::Derivation::Derivate4_5Puntos(ONE,TWO);

					return Store::Matrix<double>(s);
				}
				if(	!(val->compare8(val,"rand"))  ){
					Store::Matrix<double> s(A.val.Get_Component(1,1),B.val.Get_Component(1,1));
					srand(time(NULL));
					for( int i=1;i <= s.Get_F(); i++)
						for( int j=1;j <= s.Get_C(); j++)
							s.Get_Component(i,j)= rand();

					return s;
				}
				if( !(val->compare8(val,"sin")) ){
					return  Store::Sin<Store::Matrix<double>>::Get(A.val);
				}
				if( !(val->compare8(val,"cos")) ){
					return Store::Cos<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"tan"))	){
					return Store::Tan<Store::Matrix<double>>::Get(A.val);
				}
				if( !(val->compare8(val,"sqrt")) ){
					return Store::Sqrt<Store::Matrix<double>>::Get(A.val);
				}
				if( !(val->compare8(val,"abs"))  ){
					return Store::ABS<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"exp"))  ){
					return Store::Exp<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"log"))  ){
					return Store::Ln<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"log10"))  ){
					return Store::Log<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"floor"))  ){
					return Store::FLOOR<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"ceil"))  ){
					return Store::CEIL<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"asin"))  ){
					return Store::ASin<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"acos"))  ){
					return Store::ACos<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"atan"))  ){
					return Store::ATan<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"sinh"))  ){
					return Store::SinH<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"cosh"))  ){
					return Store::CosH<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"tanh"))  ){
					return Store::TanH<Store::Matrix<double>>::Get(A.val);
				}
				if(	!(val->compare8(val,"size"))  ){
					Store::Matrix<double> aux( 1 , 2 );
					aux.Get_Component(1,1) = A.val.Get_F();
					aux.Get_Component(1,2) = A.val.Get_C();

					return aux;
					}
				//si es menos unitario lo resuelvo en la seccion de lectura de hijos para funciones
				//para que no choque con el menos binario


			//por las dudas si algo sale mal y llega aca sin salir, que devuelva nada 
			//asi no devuelve basura, ya que eso podria hacer que explote
			return Res<Store::Matrix<double>>();


	}

}

}

