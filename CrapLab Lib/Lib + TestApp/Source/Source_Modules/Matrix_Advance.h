//Calcula la inversa de la matriz y la devuelve utilizando la adjunta y el determinante
			template <class T>
		Matrix<T> Matrix<T>::inv(){
		
		//creo una matriz auxiliar que es la adjunta de la de llamada
		Matrix<T> aux(this->adj());
		
		
		T determinante=0;
		
		//calcula el determinante y lo pone en la variable del mismo nombre
		determinante=(this->det(fila ,1,0));
		
		//multiplica toda la matriz aux, por el reciproco del determinante
		for(int k=1;(k<=C);k++)
		aux.prod_ma( fila ,k,(1/determinante));;
		
		//devuelvo la matriz ya inversa
		return aux;
		
	}
	
	
	
	//Calcula la adjunta de la matriz que la llame
		template <class T>
	Matrix<T> Matrix<T>::adj(){
		
		//creo una matriz auxiliar, con las dimensiones justas
		Matrix<T> AUX((this->F),(this->C));
		
		T aux=0;
		
		//asigna a cada componente de AUX, el cofactor correspondiente de MC 
		//de la matriz que llamo
		for(int i=0;(i<F);i++){
			for(int j=0;(j<C);j++){
			aux=(this->cofac(i+1,j+1));
				(AUX.MC[i][j])=aux;	}
		}	
		
		//transpongo la matriz auxiliar
		AUX.trans();
		
		
		//devuelvo AUX, ya siendo la adjunta de la matriz que llamo la funcion
		return AUX;
		
	}
	
	
	
	//Menor de Aij:
	//Es la matriz A menos la fila i, y la columna j
		template <class T>
	Matrix<T> Matrix<T>::menor(int I, int J){//devuelve el menor como objeto Matrix
		
		Matrix<T> aux(F,C);//creo el objeto Matrix que voy a hacer el menor
		
		aux=*(this);//le asigno a aux, todo lo que tiene esta matriz
		
		//le saco la fila I y la columna J, como dice la definicion de menor	
		aux.Fout(I);
		aux.Cout(J);
		

		//devuelvo la referencia a el objeto aux, para asignarlo a otro objeto Matrix
		//lo que se borrara sera el puntero aux, pero no a lo que apunta
		return aux;	
	}


	
	
	//Cofactor de Aij:
	//Aij = (-1)^(i+j)* det(Mij)     siendo M el menor ij de A
	//Ademas el cofactor solo tiene sentido si se calcula el cofactor de una matriz cuadrada
	//porque no esta definido el determinanate de una menor que no sea cuadrado
		template <class T>
	T Matrix<T>::cofac(int I, int J){//devuelve el cofactor, notar qeu el cofactor es un numero
		
		int signo= -1;//es el (-1)^(i+j), afectara el signo del cofactor
		
		for(int k=1;(k<(I+J));k++)
		signo *= -1;
		
		//es el valor que va a tener el determinante del menor ij
		T determinante=0;
		
		//Constructor de copia
		Matrix<T> AUX( (this->menor(I,J)) );
		
		//calculo del determinante
		determinante = AUX.det( fila ,1,1);
		
		
		return (signo*determinante);
		
	}

			template <class T>
	T Matrix<T>::det(FILACOLUMNA FC=fila, int num = 1,int cont = 1){
		
		if(this->F == this->C)//solo calcula el det si la matriz es cuadrada
		{
			
			//Es la definicion del determinante de 2x2, que es totalmente nesesaria 
			//para resolver
			if(this->F == 2){//tambien C es = 2
				
				T DETF=0;//declaro donde pondre el determinante 2x2
				
				//por definicion matematica
				DETF=(((this->MC[1-1][1-1])*(this->MC[2-1][2-1]))-((this->MC[1-1][2-1])*(this->MC[2-1][1-1])));
				
				return DETF;//devuelvo el determinante 2x2
			}
			
			//Es si tengo solo un determinante de 1x1, el determinante es la unica 
			//componente de la matriz
			if(this->F==1){//tambien lo es this->C	
			
			return (this->MC[0][0]);
			
			
			}
			
			
		if(cont > C){//tambien es igual a F, porque la matriz es cuadrada
			return 0;//cuando termina el contador, devuelve 0
		}
			
		//salida recursiva
		/*DET A = a11*A11 + a12*A12 + ... + a1n*A1n    
		siendo A el cofactor de esa posicion
		*/
	return (((MC[0][cont-1])*(this->cofac(1,cont))) + (this->det( fila ,1,cont+1)));		
			
		}
		
		
		return 0;//Si no se pudo realizar		
			
	}


	
	template <class T>
Matrix<T> Matrix<T>::Gauss(){

	//devuelvo Original, la matriz antes de gausearla, y gauseao in-place y no modifico this
	Store::Matrix<T> Original(*this);


	// Pregunata: ¿Cunatas cuantos pivotes va a haber?
	// depende de la cantidad de columnas y de fialas
	// Ejemplos:
	//	a	d
	//	b	e
	//	c	f		
	//				Aca va a haber dos pivotes: a y e

	//	a	b	c
	//	d	e	f			
	//				Aca tambien va a haber dos pivotes: a y e

	//En uno de los casos restrinje el numero de pivotes las filas, como en el ejemplo segundo
	//En otro de los casos redtrinje el numero de pivotes las columnas, como en el ejemplo primero

	//Conclusion: El menor, numeros de columnas, o numero de filas es el que restrinje la cantidad de pivotes, ie 
	//va a haber "menor" numero de pivotes, y gauseando solo repito el proceso por la cantidad de pivotes que hay

	int menor;
	if( this->C < this->F ) 
	{
		menor = this->C;
	}else{
	
		menor = this->F; // en el caos que las dos sean iguales entoces con F me viene bien, porque cualquiera de las dos sirve
	}



	//menor NO ES menor - 1, porque el ultimo pivote puede llegar a tener algo abajo, aunque no sea el caso de las matrices cuadradas o las que 
	//tienen mas columnas que filas
	for( int j = 0; ( j < ( menor ) ) ; j++ ){

		//esta variable es solo para facilitar la lectura, pero no es nesesaria
		//dice en que posicion de fila esta el pivote
		int pivote = (j+1);
	

			//esto pregunta desde el que le sigue al pivote, la pregunta es engañosa porque pivote no esta en base 0
			//se hace mientars i sea menor que F y el pivote tenga 0
			//si alguna es falsa sale
		//Entonces si i es F, es decir no entra en el arreglo sale enseguida antes de la primer entrada
		//Y si el pivote es distinto de cero sale enseguida cuando se cumpla
		for( int i = (pivote) ; ( ( i < this->F ) && ( this->MC[pivote-1][j] == 0 ) ) ; i++ ){

			//hace el intercambio por le que sigue si este le sirve, es decir si es que ese no es cero la componente
			if ( this->MC[i][j] != 0 ){

				this->int_ma(Store::fila , pivote , (i+1) );//si es que ya es pivote, entonces este metodo, no hace nada, se da cuenta. No hace nada al pedo
				
			}


		}


		T m = 0;

		//hago esto desde el que le sigue al pivote hasta el final
		//son las operaciones elementales para hacer 0 los elementos debajo del pivote
		for( int i = pivote ; ( i < this->F ) ; i++ ){

			//si es que es cero entonces que no haga el paso, seria inutil
			if( this->MC[i][j] != 0 ){

				m = ( this->MC[i][j] / this->MC[pivote-1][j] ) ;
			
				this->res_ma( Store::fila , pivote , (i+1) , m );
			}

		}
	


	}//Aca ya termino de gausear, la matriz (*this) ya esta gausada

		
	//devuelvo Original, que contien la matriz antes de ser gauseada
	return Original;

		
	
}


	template<class T>
Matrix<T> Matrix<T>::Gauss_PP(){

	//devuelvo Original, la matriz antes de gausearla, y gauseao in-place y no modifico this
	Store::Matrix<T> Original(*this);


	// Pregunata: ¿Cunatas cuantos pivotes va a haber?
	// depende de la cantidad de columnas y de fialas
	// Ejemplos:
	//	a	d
	//	b	e
	//	c	f		
	//				Aca va a haber dos pivotes: a y e

	//	a	b	c
	//	d	e	f			
	//				Aca tambien va a haber dos pivotes: a y e

	//En uno de los casos restrinje el numero de pivotes las filas, como en el ejemplo segundo
	//En otro de los casos redtrinje el numero de pivotes las columnas, como en el ejemplo primero

	//Conclusion: El menor, numeros de columnas, o numero de filas es el que restrinje la cantidad de pivotes, ie 
	//va a haber "menor" numero de pivotes, y gauseando solo repito el proceso por la cantidad de pivotes que hay

	int menor;
	if( this->C < this->F ) 
	{
		menor = this->C;
	}else{
	
		menor = this->F; // en el caos que las dos sean iguales entoces con F me viene bien, porque cualquiera de las dos sirve
	}



	//menor NO ES menor - 1, porque el ultimo pivote puede llegar a tener algo abajo, aunque no sea el caso de las matrices cuadradas o las que 
	//tienen mas columnas que filas
	for( int j = 0; ( j < ( menor ) ) ; j++ ){

		//esta variable es solo para facilitar la lectura, pero no es nesesaria
		//dice en que posicion de fila esta el pivote
		int pivote = (j+1);
	

		//una variable para almacenar la componente mayor debajo del pivote, porque este es con pivoteo parcial, asi que el pivote sera el mayor
		//ya la inicializo con el elemento del pivote, y lo cambio solo si encontre uno mayor
		T CompMayor = this->MC[pivote-1][j];
		//aca guardo el indice o mejor dicho en que fila esta la componente mayor, notar que ya la inicializo con la del pivote
		//esta en base 0
		int indiceDEcomponente = (pivote-1);


			//Recorre del que le sigue al pivote y veo cual es el mayor, notar que el pivote ya lo tengo en cuanta desde el comienzo
		//entonces el mayor es el qeu muevo hacia el pivote
		for( int i = (pivote) ; ( ( i < this->F ) ) ; i++ ){

			//solo entra si es que esta componente es mayor que la que estaba en la variable, por mayor ablo de valor absoluto
			//lo que quiero son numeros grandes, si son positivos o negativos no me interesa
			if ( abs(this->MC[i][j]) > abs(CompMayor) ){

				CompMayor = this->MC[i][j] ;
				indiceDEcomponente = i;
								
			}


		}

		//ya conozco cual es la mayor entonces hago el movimiento si y solo si es que la mayor no era la que ya estaba como pivote
		if( indiceDEcomponente != (pivote-1) ){
			
			this->int_ma(Store::fila , pivote , (indiceDEcomponente+1) );

		}




		T m = 0;

		//hago esto desde el que le sigue al pivote hasta el final
		//son las operaciones elementales para hacer 0 los elementos debajo del pivote
		for( int i = pivote ; ( i < this->F ) ; i++ ){

			//si es que es cero entonces que no haga el paso, seria inutil
			if( this->MC[i][j] != 0 ){

				m = ( this->MC[i][j] / this->MC[pivote-1][j] ) ;
			
				this->res_ma( Store::fila , pivote , (i+1) , m );
			}

		}
	


	}//Aca ya termino de gausear, la matriz (*this) ya esta gausada

		
	//devuelvo Original, que contien la matriz antes de ser gauseada
	return Original;

}


/*
Importante aca se repite el codigo de gauseo porque la columna de incognitas, no se pivotea
y colocar una bandera en el metodo  para saber si es que esta aumentada o no la matriz, significa
mas procesos para una funcion que debe ser rapida como la de gauseo, asi qeu se repite el codigo 
sacrificando tamaño por eficiencia
De colocar una bandera en el metodo se podria llamar desde aqui, ya que es inline 
no representa trabajo de llamada a la funcion
*/

	template<class T>
Vector<T> Matrix<T>::Resolve( ){


					///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			  ///////											Comienzo de la etapa de Gauseo											  ///////
				    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	

	int menor;
	//si son iguales que le saque uno a menor, ie a la cantidad de pivotes a calculas
	if( this->C <= this->F ) 
	{
											//*************************************************//
											//		Paso Fundamental para la resolucion        //
											//*************************************************//
		
															menor = ( this->C - 1 );

							//esto es lo importante para al resolucion, si son mas chicas las columnas de C, que no se cuenten 
							//la columna independiente, de incognitas, ya que esa no se pivotea

	}else{
	
		//Notar qeu si entra aca, es decir si tiene mas incognitas que ecuaciones, entonces tendra infinitas soluciones o ninguna, pero jamas una sola
		menor = this->F;
	}



	//menor NO ES menor - 1, porque el ultimo pivote puede llegar a tener algo abajo, aunque no sea el caso de las matrices cuadradas o las que 
	//tienen mas columnas que filas
	for( int j = 0; ( j < ( menor ) ) ; j++ ){

		//esta variable es solo para facilitar la lectura, pero no es nesesaria
		//dice en que posicion de fila esta el pivote
		int pivote = (j+1);
	

			//esto pregunta desde el que le sigue al pivote, la pregunta es engañosa porque pivote no esta en base 0
			//se hace mientars i sea menor que F y el pivote tenga 0
			//si alguna es falsa sale
		//Entonces si i es F, es decir no entra en el arreglo sale enseguida antes de la primer entrada
		//Y si el pivote es distinto de cero sale enseguida cuando se cumpla
		for( int i = (pivote) ; ( ( i < this->F ) && ( this->MC[pivote-1][j] == 0 ) ) ; i++ ){

			//hace el intercambio por le que sigue si este le sirve, es decir si es que ese no es cero la componente
			if ( this->MC[i][j] != 0 ){

				this->int_ma(Store::fila , pivote , (i+1) );//si es que ya es pivote, entonces este metodo, no hace nada, se da cuenta. No hace nada al pedo
				
			}


		}


		T m = 0;

		//hago esto desde el que le sigue al pivote hasta el final
		//son las operaciones elementales para hacer 0 los elementos debajo del pivote
		for( int i = pivote ; ( i < this->F ) ; i++ ){

			//si es que es cero entonces que no haga el paso, seria inutil
			if( this->MC[i][j] != 0 ){

				m = ( this->MC[i][j] / this->MC[pivote-1][j] ) ;
			
				this->res_ma( Store::fila , pivote , (i+1) , m );
			}

		}
	


	}

					///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			  ///////											Fin de la etapa de gauseo												  ///////
				    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

			
		//esta llamada a la funcion no recibe parametros, lo calcula solo con la matriz, la considera aumentada
	return ( this->BackwardSustitution() );


}

	template<class T>
Vector<T> Matrix<T>::Resolve_PP(){


	
					///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			  ///////											Comienzo de la etapa de Gauseo											  ///////
				    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	

	int menor;
	//si son iguales que le saque uno a menor, ie a la cantidad de pivotes a calculas
	if( this->C <= this->F ) 
	{
											//*************************************************//
											//		Paso Fundamental para la resolucion        //
											//*************************************************//
		
															menor = ( this->C - 1 );

							//esto es lo importante para al resolucion, si son mas chicas las columnas de C, que no se cuenten 
							//la columna independiente, de incognitas, ya que esa no se pivotea

	}else{
	
		//Notar qeu si entra aca, es decir si tiene mas incognitas que ecuaciones, entonces tendra infinitas soluciones o ninguna, pero jamas una sola
		menor = this->F;
	}



	//menor NO ES menor - 1, porque el ultimo pivote puede llegar a tener algo abajo, aunque no sea el caso de las matrices cuadradas o las que 
	//tienen mas columnas que filas
	for( int j = 0; ( j < ( menor ) ) ; j++ ){

		//esta variable es solo para facilitar la lectura, pero no es nesesaria
		//dice en que posicion de fila esta el pivote
		int pivote = (j+1);
	

		//una variable para almacenar la componente mayor debajo del pivote, porque este es con pivoteo parcial, asi que el pivote sera el mayor
		//ya la inicializo con el elemento del pivote, y lo cambio solo si encontre uno mayor
		T CompMayor = this->MC[pivote-1][j];
		//aca guardo el indice o mejor dicho en que fila esta la componente mayor, notar que ya la inicializo con la del pivote
		//esta en base 0
		int indiceDEcomponente = (pivote-1);


			//Recorre del que le sigue al pivote y veo cual es el mayor, notar que el pivote ya lo tengo en cuanta desde el comienzo
		//entonces el mayor es el qeu muevo hacia el pivote
		for( int i = (pivote) ; ( ( i < this->F ) ) ; i++ ){

			//solo entra si es que esta componente es mayor que la que estaba en la variable, por mayor ablo de valor absoluto
			//lo que quiero son numeros grandes, si son positivos o negativos no me interesa
			if ( abs(this->MC[i][j]) > abs(CompMayor) ){

				CompMayor = this->MC[i][j] ;
				indiceDEcomponente = i;
								
			}


		}

		//ya conozco cual es la mayor entonces hago el movimiento si y solo si es que la mayor no era la que ya estaba como pivote
		if( indiceDEcomponente != (pivote-1) ){
			
			this->int_ma(Store::fila , pivote , (indiceDEcomponente+1) );

		}




		T m = 0;

		//hago esto desde el que le sigue al pivote hasta el final
		//son las operaciones elementales para hacer 0 los elementos debajo del pivote
		for( int i = pivote ; ( i < this->F ) ; i++ ){

			//si es que es cero entonces que no haga el paso, seria inutil
			if( this->MC[i][j] != 0 ){

				m = ( this->MC[i][j] / this->MC[pivote-1][j] ) ;
			
				this->res_ma( Store::fila , pivote , (i+1) , m );
			}

		}
	


	}//Aca ya termino de gausear, la matriz (*this) ya esta gausada


					///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			  ///////											Fin de la etapa de gauseo												  ///////
				    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

			
		//esta llamada a la funcion no recibe parametros, lo calcula solo con la matriz, la considera aumentada
	return ( this->BackwardSustitution() );




}


	template<class T>
inline  Store::Vector<T> Matrix<T>::BackwardSustitution( Store::Matrix<T>& MTX , Store::Vector<T>& IND ){


			///////////////////////////
	      //* Sustitucion acia atras  *//
			///////////////////////////


	/*		IDEA


			ai,n+1 es el elemneto de la columna independiente
			SUM son los elementos que le siguen a cada pivote, son componentes multiplicadas por
			las incognitas, que son las que ya he sacado
			ai,i es la componente de la incognita que voy a sacar ahora


			Forma:		(	ai,n+1 - SUM( ai,j*xj ) de j=i+1 hasta n	  ) / ai,i

	*/



	//Variable para devolver
	Store::Vector<T> Incognitas( IND.Length() );

	//guarda valores
	//tiene ultima incognita
	T X = ( IND.Get_Component( IND.Length() ) /	MTX.MC[MTX.F][MTX.C] ) ;

	Incognitas.insert( X , IND.Length() );


	T Sumatoria = 0;

	for(int i = (MTX.F-2); ( i > -1) ; i--){

		for( int j = (i+1) ; ( j < MTX.C ) ; j++ ){

			Sumatoria += ( MTX.MC[i][j] * Incognitas.Get_Component( (j+1) ) );

		}

		X = ( IND.Get_Component( i+1 ) - Sumatoria ) / MTX.MC[i][i];

		Sumatoria = 0;

		Incognitas.insert( X , (i+1) );

	}




	return Incognitas;

	
}


	template<class T>
inline Store::Vector<T> Matrix<T>::BackwardSustitution( Store::Matrix<T>& MTX , Store::Matrix<T>& IND ){


			///////////////////////////
	      //* Sustitucion hacia atras  *//
			///////////////////////////


	/*		IDEA


			ai,n+1 es el elemneto de la columna independiente
			SUM son los elementos que le siguen a cada pivote, son componentes multiplicadas por
			las incognitas, que son las que ya he sacado
			ai,i es la componente de la incognita que voy a sacar ahora


			Forma:		(	ai,n+1 - SUM( ai,j*xj ) de j=i+1 hasta n	  ) / ai,i

	*/

	int length;
	//dice si la matriz es un vector fila o columna
	Store::FILACOLUMNA colfil;

	if( IND.C > IND.F ){
		length = IND.C;
		colfil = Store::fila;
	}else{
		length = IND.F;
		colfil = Store::columna;
	}


	//Variable para devolver
	Store::Vector<T> Incognitas( length );

	//guarda valores
	//tiene ultima incgonita
	T X;

	switch( colfil ){
			case Store::fila:{

				X = ( IND.MC[0][length]  /	MTX.Get_Component( MTX.Get_F() , MTX.Get_C() ) ) ;
								
				break;
							 }
			case Store::columna:{

				X = ( IND.MC[length][0]  /	MTX.Get_Component( MTX.Get_F() , MTX.Get_C() ) ) ;

				break;

								}

		}

	

	Incognitas.insert( X , length );


	T Sumatoria = 0;

	for(int i = (MTX.F-2); ( i > -1) ; i--){

		for( int j = (i+1) ; ( j < MTX.C ) ; j++ ){

			Sumatoria += ( MTX.MC[i][j] * Incognitas.Get_Component( (j+1) ) );

		}

		switch( colfil ){
			case Store::fila:{

				X = ( IND.MC[0][i] - Sumatoria ) / MTX.MC[i][i];
				
				break;
							 }
			case Store::columna:{

				X = ( IND.MC[i][0] - Sumatoria ) / MTX.MC[i][i];

				break;

								}

		}


		Sumatoria = 0;

		Incognitas.insert( X , (i+1) );

	}




	return Incognitas;



}





	template<class T>
inline Store::Vector<T> Matrix<T>::BackwardSustitution(){



	///////////////////////////
	      //* Sustitucion acia atras  *//
			///////////////////////////


	/*		IDEA


			ai,n+1 es el elemneto de la columna independiente
			SUM son los elementos que le siguen a cada pivote, son componentes multiplicadas por
			las incognitas, que son las que ya he sacado
			ai,i es la componente de la incognita que voy a sacar ahora


			Forma:		(	ai,n+1 - SUM( ai,j*xj ) de j=i+1 hasta n	  ) / ai,i

	*/





	//Variable para devolver
	Store::Vector<T> Incognitas( this->F );

	//guarda valores
	//tiene ultima incgonita
	T X = ( this->MC[this->F-1][this->C-1] / this->MC[this->F-1][this->C-2] ) ;

	Incognitas.insert( X , this->F );


	T Sumatoria = 0;

	for(int i = (this->F-2); ( i > -1) ; i--){

		for( int j = (i+1) ; ( j < this->C ) ; j++ ){

			Sumatoria += ( this->MC[i][j] * Incognitas.Get_Component( (j+1) ) );

		}

		X = ( this->MC[i][this->C-1] - Sumatoria ) / this->MC[i][i];

		Sumatoria = 0;

		Incognitas.insert( X , (i+1) );

	}




	return Incognitas;


}



//--------------------------------     Operaciones GaussView


	template<class T>
void Matrix<T>::Show_int_ma(Store::FILACOLUMNA rc, int I,int J, std::ostream& output ){

	switch(rc){

		case fila:{
			output<< '\n';
	
			output<< '\t' <<"( R" << I << " ) <-> ( R" << J << " )";

			output<< '\n';


			break;

		}
		case columna:{

			output<< '\n';
	
			output<< '\t' <<"( C" << I << " ) <-> ( C" << J << " )";

			output<< '\n';

		
			break;

		}

	}


}

	template<class T>
void Matrix<T>::Show_sum_ma(Store::FILACOLUMNA rc , int I ,int J , T esc, std::ostream& output ){

	switch(rc){

		case fila:{
			output<< '\n';
	
			output<< '\t' << "( R" << J << " + (" <<  esc << ')'
				<< "*R" << I <<" ) <-> ( R" << J << " )";

			output<< '\n';


			break;

		}
		case columna:{

			output<< '\n';
	
			output<< 't' << "( C" << J << " + (" <<  esc << ')'
				<< "*C" << I <<" ) <-> ( C" << J << " )";

			output<< '\n';

		
			break;

		}

	}



}

	template<class T>
	void Matrix<T>::Show_res_ma(Store::FILACOLUMNA rc ,int I ,int J , T esc, std::ostream& output ){

	switch(rc){

		case fila:{
			output<< '\n';
	
			output<< '\t' << "( R" << J << " - (" <<  esc << ')'
				<< "*R" << I <<" ) <-> ( R" << J << " )";

			output<< '\n';


			break;

		}
		case columna:{

			output<< '\n';
	
			output<< '\t' << "( C" << J << " - (" <<  esc << ')'
				<< "*C" << I <<" ) <-> ( C" << J << " )";

			output<< '\n';

		
			break;

		}

	}


}


//Aca se utilizan las funciones privadas de esta la clase Matrix:
//-Show_sum_ma
//-Show_res_ma
//-Show-int_ma
	template<class T>
Matrix<T> Matrix<T>::Gauss_View2(){

	int INTERCAMBIO_COUNT = 0;
	int SUMA_COUNT = 0;
	int RESTA_COUNT = 0;

	//devuelvo Original, la matriz antes de gausearla, y gauseao in-place y no modifico this
	Store::Matrix<T> Original(*this);

	std::cout<<"La matriz Original es:\n";
	Original.View();

	system("pause");


	// Pregunata: ¿Cunatas cuantos pivotes va a haber?
	// depende de la cantidad de columnas y de fialas
	// Ejemplos:
	//	a	d
	//	b	e
	//	c	f		
	//				Aca va a haber dos pivotes: a y e

	//	a	b	c
	//	d	e	f			
	//				Aca tambien va a haber dos pivotes: a y e

	//En uno de los casos restrinje el numero de pivotes las filas, como en el ejemplo segundo
	//En otro de los casos redtrinje el numero de pivotes las columnas, como en el ejemplo primero

	//Conclusion: El menor, numeros de columnas, o numero de filas es el que restrinje la cantidad de pivotes, ie 
	//va a haber "menor" numero de pivotes, y gauseando solo repito el proceso por la cantidad de pivotes que hay

	int menor;
	if( this->C < this->F ) 
	{
		menor = this->C;
	}else{
	
		menor = this->F; // en el caos que las dos sean iguales entoces con F me viene bien, porque cualquiera de las dos sirve
	}



	//menor NO ES menor - 1, porque el ultimo pivote puede llegar a tener algo abajo, aunque no sea el caso de las matrices cuadradas o las que 
	//tienen mas columnas que filas
	for( int j = 0; ( j < ( menor ) ) ; j++ ){

		//esta variable es solo para facilitar la lectura, pero no es nesesaria
		//dice en que posicion de fila esta el pivote
		int pivote = (j+1);
	

		//esto pregunta desde el que le sigue al pivote, la pregunta es engañosa porque pivote no esta en base 0
			//se hace mientars i sea menor que F y el pivote tenga 0
			//si alguna es falsa sale
		//Entonces si i es F, es decir no entra en el arreglo sale enseguida antes de la primer entrada
		//Y si el pivote es distinto de cero sale enseguida cuando se cumpla
		for( int i = (pivote) ; ( ( i < this->F ) && ( this->MC[pivote-1][j] == 0 ) ) ; i++ ){

			//hace el intercambio por le que sigue si este le sirve, es decir si es que ese no es cero la componente
			if ( this->MC[i][j] != 0 ){

				this->int_ma(Store::fila , pivote , (i+1) );//si es que ya es pivote, entonces este metodo, no hace nada, se da cuenta. No hace nada al pedo

				//Muestro el paso
				this->Show_int_ma(Store::fila, pivote, (i+1) );

				INTERCAMBIO_COUNT++;

				this->View();

				system("pause");
	
			}

		}//fin del primer for i


		T m = 0;

		//hago esto desde el que le sigue al pivote hasta el final
		//son las operaciones elementales para hacer 0 los elementos debajo del pivote
		for( int i = pivote ; ( i < this->F ) ; i++ ){

			//si es que es cero entonces que no haga el paso, seria inutil
			if( this->MC[i][j] != 0 ){

				m = ( this->MC[i][j] / this->MC[pivote-1][j] ) ;
			
				this->res_ma( Store::fila , pivote , (i+1) , m );

				//Muestro el paso
				this->Show_res_ma(Store::fila, pivote, (i+1), m );

				//para el criterio de menor o mayor o igual a 0 
				//tener en cuenta que lo que hace es una resta, y si m es negativo se hace suma,
				//por eso esta invertido
				if( m < 0 ){
		
					SUMA_COUNT++;
				}else{
	
					RESTA_COUNT++;
				}

				this->View();

				system("pause");

			}

		}//fin del segundo for i
	


	}//Aca ya termino de gausear, la matriz (*this) ya esta gausada

	std::cout<<"\nTermino el proceso de Gauseo\n";
	std::cout<< "Operaciones elementales de intercambio realizadas: " << INTERCAMBIO_COUNT<<'\n';
	std::cout<< "Operaciones elementales de resta y producto por un escalar realizadas: " << RESTA_COUNT<<'\n';
	std::cout<< "Operaciones elementales de suma y producto por un escalar realizadas: " << SUMA_COUNT<<'\n';
	std::cout<< "Operaciones elementales totales realizadas: " << (INTERCAMBIO_COUNT + RESTA_COUNT + SUMA_COUNT) << '\n';
	
		
	//devuelvo Original, que contien la matriz antes de ser gauseada
	return Original;



	

return (*this);



}


//Aca se utilizan las funciones privadas de esta la clase Matrix:
//-Show_sum_ma
//-Show_res_ma
//-Show-int_ma
	template<class T>
Matrix<T> Matrix<T>::Gauss_View( std::ostream& output ){

	int INTERCAMBIO_COUNT = 0;
	int SUMA_COUNT = 0;
	int RESTA_COUNT = 0;

	//si se oprime suprimir se acelera el proceso de Gauseo
	unsigned char oprimida= ' ';

	//dice si se ejecutara rapido o normal, 
	//si es rapido no muestra los siguientes pasos , si es normal los muestra
	//si se presiona suprimir se pasa a modo rapido
	bool rapido= false;

	//devuelvo Original, la matriz antes de gausearla, y gauseao in-place y no modifico this
	Store::Matrix<T> Original(*this);

	output<<"Presione suprimir para acelerar el proceso de Gauseo\n";
	output<<"La matriz Original es:\n";
	Original.View(output);
		

	oprimida = _getch();

			//Porque puede que lo quieran acelerar antes que muestre el primer paso

	//El 224 es el ASCII de suprimir
	if( oprimida == 224 ){

			output<<"Acaba de acelerar el proceso, no se mostaran los pasos siguientes\n";

			//Modo acelerado, no muestra los siguientes pasos
			rapido = true;


			}


	// Pregunata: ¿Cunatas cuantos pivotes va a haber?
	// depende de la cantidad de columnas y de fialas
	// Ejemplos:
	//	a	d
	//	b	e
	//	c	f		
	//				Aca va a haber dos pivotes: a y e

	//	a	b	c
	//	d	e	f			
	//				Aca tambien va a haber dos pivotes: a y e

	//En uno de los casos restrinje el numero de pivotes las filas, como en el ejemplo segundo
	//En otro de los casos redtrinje el numero de pivotes las columnas, como en el ejemplo primero

	//Conclusion: El menor, numeros de columnas, o numero de filas es el que restrinje la cantidad de pivotes, ie 
	//va a haber "menor" numero de pivotes, y gauseando solo repito el proceso por la cantidad de pivotes que hay

	int menor;
	if( this->C < this->F ) 
	{
		menor = this->C;
	}else{
	
		menor = this->F; // en el caos que las dos sean iguales entoces con F me viene bien, porque cualquiera de las dos sirve
	}



	//menor NO ES menor - 1, porque el ultimo pivote puede llegar a tener algo abajo, aunque no sea el caso de las matrices cuadradas o las que 
	//tienen mas columnas que filas
	for( int j = 0; ( j < ( menor ) ) ; j++ ){

		//esta variable es solo para facilitar la lectura, pero no es nesesaria
		//dice en que posicion de fila esta el pivote
		int pivote = (j+1);
			


		//esto pregunta desde el que le sigue al pivote, la pregunta es engañosa porque pivote no esta en base 0
			//se hace mientars i sea menor que F y el pivote tenga 0
			//si alguna es falsa sale
		//Entonces si i es F, es decir no entra en el arreglo sale enseguida antes de la primer entrada
		//Y si el pivote es distinto de cero sale enseguida cuando se cumpla
		for( int i = (pivote) ; ( ( i < this->F ) && ( this->MC[pivote-1][j] == 0 ) ) ; i++ ){

			//hace el intercambio por le que sigue si este le sirve, es decir si es que ese no es cero la componente
			if ( this->MC[i][j] != 0 ){

				this->int_ma(Store::fila , pivote , (i+1) );//si es que ya es pivote, entonces este metodo, no hace nada, se da cuenta. No hace nada al pedo

				INTERCAMBIO_COUNT++;

				//se lo saltea si esta en modo rapido, ie no muestra los siguientes pasos
				//pero si los cuenta
				if (rapido == false ){
					//Muestro el paso
					this->Show_int_ma(Store::fila, pivote, (i+1) , output );
				
					this->View(output);

					oprimida = _getch();

					if( oprimida == 224 ){

					output<<"Acaba de acelerar el proceso, no se mostaran los pasos siguientes\n";

					//Modo acelerado, no muestra los siguientes pasos
					rapido = true;

				

					}

				//si entro aca es porque en un comienzo era 0 el pivote, pero aca se cambia y en el for va a salir porque ahora si es distinto de 0 el pivote

				}

				

			}

		}//fin del primer for i

		

		


		T m = 0;

		//hago esto desde el que le sigue al pivote hasta el final
		//son las operaciones elementales para hacer 0 los elementos debajo del pivote
			//Si es que no hay ninguno abajo sale antes de la primer entrada
		for( int i = pivote ; ( i < this->F ) ; i++ ){

			//si es que es cero entonces que no haga el paso, seria inutil
			if( this->MC[i][j] != 0 ){

				m = ( this->MC[i][j] / this->MC[pivote-1][j] ) ;
			
				this->res_ma( Store::fila , pivote , (i+1) , m );

				//para el criterio de menor o mayor o igual a 0 
				//tener en cuenta que lo que hace es una resta, y si m es negativo se hace suma,
				//por eso esta invertido
				if( m < 0 ){
		
					SUMA_COUNT++;
				}else{
	
					RESTA_COUNT++;
				}

				
				//se lo saltea si esta en modo rapido, ie no muestra los siguientes pasos
				//pero si los cuenta
				if( rapido == false ){

					//Muestro el paso
					this->Show_res_ma(Store::fila, pivote, (i+1), m , output );
	
					this->View(output);
			

					oprimida = _getch();

					if( oprimida == 224 ){

						//esta pregunta es poruqe si es el ultimo paso elemental entonces no se hacelera, poruqe no quedan pasos por hacer
						//no es esencial para nada, pero es un lindo detalle y un arreglo para los quizquillosos
						if( ( i == (this->F - 1) ) && ( ( pivote+1 ) == menor ) ){//notar que menor da la cantidad maxima de pivotes que tendra la matriz gauseada
							output<<"No se acelero porque no quedaban pasos elementales por hacer\n";
						}else{//si no era el ultimo paso, entonces si decimos que se acelera

							output<<"Acaba de acelerar el proceso, no se mostaran los pasos siguientes\n";

							//Modo acelerado, no muestra los siguientes pasos
							rapido = true;

						}

					}

				}


			}


		}//fin del segundo for i
	


	}//fin del for del j
	//Aca ya termino de gausear, la matriz (*this) ya esta gausada

	//si lo acelere entonces tengo qeu mostrar como quedo, si es que no se acelero entonces ya con el paso anterior mostre como quedo
	if( rapido == true ){
	
		output<<"La matriz gauseada queda:\n";
		
		this->View(output);
	}

	output<<"\nTermino el proceso de Gauseo\n";
	output<< "Operaciones elementales de intercambio realizadas: " << INTERCAMBIO_COUNT<<'\n';
	output<< "Operaciones elementales de resta y producto por un escalar realizadas: " << RESTA_COUNT<<'\n';
	output<< "Operaciones elementales de suma y producto por un escalar realizadas: " << SUMA_COUNT<<'\n';
	output<< "Operaciones elementales totales realizadas: " << (INTERCAMBIO_COUNT + RESTA_COUNT + SUMA_COUNT) << '\n';
	
		
	//devuelvo Original, que contien la matriz antes de ser gauseada
	return Original;




}

	template<class T>
Matrix<T> Matrix<T>::Gauss_View_Instantaniusly( std::ostream& output ){

int INTERCAMBIO_COUNT = 0;
	int SUMA_COUNT = 0;
	int RESTA_COUNT = 0;

	//devuelvo Original, la matriz antes de gausearla, y gauseao in-place y no modifico this
	Store::Matrix<T> Original(*this);

	output<<"La matriz Original es:\n";
	Original.View(output);


	// Pregunata: ¿Cunatas cuantos pivotes va a haber?
	// depende de la cantidad de columnas y de fialas
	// Ejemplos:
	//	a	d
	//	b	e
	//	c	f		
	//				Aca va a haber dos pivotes: a y e

	//	a	b	c
	//	d	e	f			
	//				Aca tambien va a haber dos pivotes: a y e

	//En uno de los casos restrinje el numero de pivotes las filas, como en el ejemplo segundo
	//En otro de los casos redtrinje el numero de pivotes las columnas, como en el ejemplo primero

	//Conclusion: El menor, numeros de columnas, o numero de filas es el que restrinje la cantidad de pivotes, ie 
	//va a haber "menor" numero de pivotes, y gauseando solo repito el proceso por la cantidad de pivotes que hay

	int menor;
	if( this->C < this->F ) 
	{
		menor = this->C;
	}else{
	
		menor = this->F; // en el caos que las dos sean iguales entoces con F me viene bien, porque cualquiera de las dos sirve
	}



	//menor NO ES menor - 1, porque el ultimo pivote puede llegar a tener algo abajo, aunque no sea el caso de las matrices cuadradas o las que 
	//tienen mas columnas que filas
	for( int j = 0; ( j < ( menor ) ) ; j++ ){

		//esta variable es solo para facilitar la lectura, pero no es nesesaria
		//dice en que posicion de fila esta el pivote
		int pivote = (j+1);
	

		//esto pregunta desde el que le sigue al pivote, la pregunta es engañosa porque pivote no esta en base 0
			//se hace mientars i sea menor que F y el pivote tenga 0
			//si alguna es falsa sale
		//Entonces si i es F, es decir no entra en el arreglo sale enseguida antes de la primer entrada
		//Y si el pivote es distinto de cero sale enseguida cuando se cumpla
		for( int i = (pivote) ; ( ( i < this->F ) && ( this->MC[pivote-1][j] == 0 ) ) ; i++ ){

			//hace el intercambio por le que sigue si este le sirve, es decir si es que ese no es cero la componente
			if ( this->MC[i][j] != 0 ){

				this->int_ma(Store::fila , pivote , (i+1) );//si es que ya es pivote, entonces este metodo, no hace nada, se da cuenta. No hace nada al pedo

				//Muestro el paso
				this->Show_int_ma(Store::fila, pivote, (i+1), output );

				INTERCAMBIO_COUNT++;

				this->View(output);

			}

		}//fin del primer for i


		T m = 0;

		//hago esto desde el que le sigue al pivote hasta el final
		//son las operaciones elementales para hacer 0 los elementos debajo del pivote
		for( int i = pivote ; ( i < this->F ) ; i++ ){

			//si es que es cero entonces que no haga el paso, seria inutil
			if( this->MC[i][j] != 0 ){

				m = ( this->MC[i][j] / this->MC[pivote-1][j] ) ;
			
				this->res_ma( Store::fila , pivote , (i+1) , m );

				//Muestro el paso
				this->Show_res_ma(Store::fila, pivote, (i+1), m , output );

				//para el criterio de menor o mayor o igual a 0 
				//tener en cuenta que lo que hace es una resta, y si m es negativo se hace suma,
				//por eso esta invertido
				if( m < 0 ){
		
					SUMA_COUNT++;
				}else{
	
					RESTA_COUNT++;
				}

				this->View(output);

			}

		}//fin del segundo for i
	


	}//Aca ya termino de gausear, la matriz (*this) ya esta gausada

	output<<"\nTermino el proceso de Gauseo\n";
	output<< "Operaciones elementales de intercambio realizadas: " << INTERCAMBIO_COUNT<<'\n';
	output<< "Operaciones elementales de resta y producto por un escalar realizadas: " << RESTA_COUNT<<'\n';
	output<< "Operaciones elementales de suma y producto por un escalar realizadas: " << SUMA_COUNT<<'\n';
	output<< "Operaciones elementales totales realizadas: " << (INTERCAMBIO_COUNT + RESTA_COUNT + SUMA_COUNT) << '\n';
	
		
	//devuelvo Original, que contien la matriz antes de ser gauseada
	return Original;



	

return (*this);


}
