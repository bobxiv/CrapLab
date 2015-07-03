			template<class T>
		inline int Matrix<T>::Get_F()const{

			return (this->F);

		}


			template<class T>
		inline int Matrix<T>::Get_C()const{

			return (this->C);

		}
	
			
			template<class T>
		inline T& Matrix<T>::Get_Component( int I, int J ) const{

			return ( this->MC[I-1][J-1] );

			}

			
	
		template <class T>
	int Matrix<T>::Fout(int Fila){
	
		
	if(Fila <= F && (Fila > 0))
	{
	T **aux=new  T*[F-1];//arreglo auxiliar
	
	for(int i=0;i<F-1;i++)
	{	*(aux+i)=new T[C];}
	
	
	for(int i=0;(i<(Fila-1));i++ )//copio todo hasta el anterior del que quiero borrar
		for(int j=0;(j<C);j++)
		{((*(aux+i))[j])=(this->MC[i][j]);	}
		
		//el que quiero borrar quedo en la nada
		
	for(int i=Fila;(i<F);i++ ){//copio todo desde el siguiente del que quiero borrar
		for(int j=0;(j<C);j++){	
			(aux[i-1][j])=(this->MC[i][j]);	}
	}
		
	/*Aca pasa algo loquisimo... cuando llega a este punto en el depurado,
	venia ejecutando todo bien y de golpe salta a cualquier lado y las variables
	MC y aux quedan como fuera de contecto e inaccesible...
	pero tiene alguna relacion con el delete, ya que si lo quito calcula todo bien
	de todas formas estoy haciendo algo muy malo ya que esta quedando espacio ocupado en
	memoria al pedo, que si es que lo intento borrar pas auna locura que va en contra
	del paradigma de estructuracion!!!!
	
	AL CARAJO CON STROUSTROP
	*/
	
	
	//for(int i=0;i<F;i++){
	//delete[] *(MC+i);	}//borro a lo que apunta cada uno de los punteros a flotantes
		
	//delete (this->MC);//borro a lo que apunta el puntero a punteros a flotantes
		
	(this->MC)=aux;//hago que MC apunte al puntero aux
	//claor que aux se destruira luego de ejecutada la funcion, pero a lo que apunta no!
		
	(this->F)=F-1;
	
	return 1;//si se pudo ejecutar	
	}			
		
		
	return 0;//si no se ejecuto	
	}
	
	
		template <class T>
	int Matrix<T>::Cout(int Columna){
		
	if(Columna <= C && (Columna > 0))
	{
	T **aux=new  T*[F];//arreglo auxiliar
	
	for(int i=0;i<F;i++)
	{	*(aux+i)=new T[C-1];}
	
	
	for(int j=0;(j<(Columna-1));j++ )//copio todo hasta el anterior del que quiero borrar
		for(int i=0;(i<F);i++)
		{(*(aux+i))[j]=MC[i][j];	}
		
		//el que quiero borrar quedo en la nada
		
	for(int j=Columna;(j<C);j++ )//copio todo desde el siguiente del que quiero borrar
		for(int i=0;(i<F);i++)
		{aux[i][j-1]=MC[i][j];	}
			
		
	for(int i=0;i<F;i++)
	delete[] *(MC+i);//borro a lo que apunta cada uno de los punteros a flotantes
		
	delete MC;//borro a lo que apunta el puntero a punteros a flotantes
		
	MC=aux;//hago que MC apunte al puntero aux
	//claro que aux se destruira luego de ejecutada la funcion, pero a lo que apunta no!
		
	C=C-1;
	
	return 1;//si se pudo ejecutar	
	}			
		
		
	return 0;//si no se ejecuto	
	}
	

	
	template <class T>
Matrix<T>::Matrix(){

	this->F=0;
	this->C=0;

}

	template <class T>
Matrix<T>::Matrix(int I, int J){
	
	F=I;
	
	C=J;
		
	MC=new T*[F];//es un arreglod e punteros, cuyos punteros apuntan  a arreglos
	
	//crea los arreglos de cada puntero de MC
	for(int i =0;(i<F);i++)
	{	*(MC+i)=new T[C];
		
	}
	
	
	//aca la inicializo, todos los valores en 0 o equivalente
	for(int j=0;(j<C);j++)	
		for(int i=0;(i<F);i++)
			(*(MC+i))[j] = 0;
	
}

	template <class T>
Matrix<T>::Matrix(const Matrix<T> &OBJ){
	
	F=OBJ.F;
	C=OBJ.C;
	
	MC = new T*[F];
	
	for(int i=0;(i<F);i++)
	(*(MC+i))=new T[C];
		
	for(int i=0;(i<F);i++)
		for(int j=0;(j<C);j++)
			MC[i][j]=OBJ.MC[i][j];
		
		
}

	template <class T>
Matrix<T>::Matrix(const Vector<T> &V){
	
	F=1;
	C=V.Componentes;
	
	MC = new T*[F];
	
	for(int i=0;(i<F);i++)
	(*(MC+i))=new T[C];
		
	
	for(int j=0;(j<C);j++)
		MC[0][j]= V[j];
		
		
}


	template <class T>
Matrix<T>::Matrix(int ij){

	F=ij;
	C=F;
	
MC=new T*[F];

for(int k=0;(k<F);k++)
	MC[k]=new T[C];

//Transformo a esta matriz en una identidad por este metodo
this->ident();
	
}



	template <class T>
inline void Matrix<T>::clean(){
	
	
	
	for(int j=0;(j<C);j++)	
		for(int i=0;(i<F);i++)
			(*(MC+i))[j] = 0;
		
		
}

	template<class T>
inline void Matrix<T>::fill(T val){
	
	for(int i=0;( i<this->F ); i++){
		for(int j=0;( j<this->C ); j++)
			(*(MC+i))[j] = val;

	}


}

		template<class T>
	void Matrix<T>::Random( T min, T max){


		srand(time(NULL));
		
		T aux;

		//porque % nunca iria a dar max
		max += 1;

		//nesesito la diferencia para sacra un rand entre dos valores
		int diff = (max - min);

		for(int i = 0; ( i < this->F ) ; i++){
			for(int j = 0; ( j < this->C ) ; j++){
				aux = ( rand() % diff + static_cast<int>(min) );
				this->MC[i][j] = aux;
			}
	}


		}

	template <class T>
void Matrix<T>::View(int spc,int pres, std::ostream& output){
	
	if( (this->C > 0) && (this->F > 0) ){//si esta vacio que no deje especio

	/*el error que tolera al redondear esta relacionado con 
	la presicion con que se lo muestra. Es decir que si se lo muestra con 2 decimales de 
	presicion, entonces una diferencia minima de 0.01 decimales para mostrar en flotantes
	Y asi proporcional a la presicion con la que se muestre
	Notar que el 9 como numerador es para que solo se muestre si va a tener un cambio en
	la visualizacion, y sino que se lo	omita y que lo muestre redondeado
	*/
	T er = (9.0/(powf(10,(pres+1))));
	
	//auxiliar para ir sacando los valores y mostrarlos
	T mostrar=0;
	
	//para que deje algun lugar cuando empieza a mostrar la matriz
	//output<<'\n';
	
	for(int i =0;(i<F);i++)
	{	for(int j=0;(j<C);j++)
		{	mostrar=(*(MC+i))[j];
		
		/*si la diferencia entre el redondeado y el real es pequeña,
		no perseptible por la presicion, entonces muestra una apoximacion, sino
		muestra el flotante con decimales
		*/
			if(abs(mostrar - (static_cast<int>(mostrar) )) <= er){
				output.width(std::streamsize(spc));
				output<</*setw(spc)<<setprecision(0)<<*/ ((int)(*(MC+i))[j]);}
			else{

				mostrar*=Store::Pow<T>::Get(10,pres);
				mostrar=static_cast<int>(mostrar);
				mostrar/=Store::Pow<T>::Get(10,pres);

				output.width(std::streamsize(spc));
				
				output<</*setw(spc)<<setprecision(pres)<<*/ mostrar;	
			}
		
	
	
	}
		
		//Para que no queden todos los renglones de las matrices pegados
		output<<'\n'<<'\n';
}
//para que despues de emostrar la matriz deje un espacio como para mostrar otra
		output<<'\n';

		}

}

/*
Importante aca copie el codigo del View anterior podria haber hecho una llamada adentro con los parametros de la otra forma
pero se perderia tiempo entre llamada y llamada
Si se implementa inline el View no habria cambios y seria igual de rapido se se hace la llamada al metodo View anterior 
con los parametros modificados
Pero se los volvio a escribir, para que siendo inline View o no siendo inline ande optimamente
aunque se genere un codigo mas grande, no es una gran pedida
*/
	template<class T>
void Matrix<T>::View( std::ostream& output, int spc,int pres){

/*el error que tolera al redondear esta relacionado con 
	la presicion con que se lo muestra. Es decir que si se lo muestra con 2 decimales de 
	presicion, entonces una diferencia minima de 0.01 decimales para mostrar en flotantes
	Y asi proporcional a la presicion con la que se muestre
	Notar que el 9 como numerador es para que solo se muestre si va a tener un cambio en
	la visualizacion, y sino que se lo	omita y que lo muestre redondeado
	*/
	T er = (9.0/(powf(10,(pres+1))));
	
	//auxiliar para ir sacando los valores y mostrarlos
	T mostrar=0;
	
	//para que deje algun lugar cuando empieza a mostrar la matriz
	output<<'\n';
	
	for(int i =0;(i<F);i++)
	{	for(int j=0;(j<C);j++)
		{	mostrar=(*(MC+i))[j];
		
		/*si la diferencia entre el redondeado y el real es pequeña,
		no perseptible por la presicion, entonces muestra una apoximacion, sino
		muestra el flotante con decimales
		*/
			if(abs(mostrar - (static_cast<int>(mostrar) )) <= er){
				output.precision(std::streamsize(0));
				output.width(std::streamsize(spc));
				output<</*setw(spc)<<setprecision(0)<<*/ ((int)(*(MC+i))[j]);}
			else{
				output.precision(std::streamsize(pres));
				output.width(std::streamsize(spc));
				
				output<</*setw(spc)<<setprecision(pres)<<*/ (*(MC+i))[j];	
			}
		
	
	
	}
		
		//Para que no queden todos los renglones de las matrices pegados
		output<<'\n'<<'\n';
}
//para que despues de emostrar la matriz deje un espacio como para mostrar otra
		output<<'\n'<<'\n';


}

	template<class T>
void Store::Matrix<T>::Show_F( std::ostream& output ){

	output<< '\n' <<"La matriz tiene "<< this->F<<" filas"<<'\n'; 

}

	template<class T>
void Store::Matrix<T>::Show_C( std::ostream& output ){

	output<< '\n' <<"La matriz tiene "<< this->C<<" columnas"<<'\n'; 

}



	template <class T>
int Matrix<T>::View_Component(int fil,int col, std::ostream& output){
	
	
	output<<'\n';
	
	if( (fil <= F) && (fil > 0) && (col <= C) && (col > 0) )
	{
	//le resto 1 por el tema indices claro esta	
		output<<MC[fil-1][col-1];
	
		output<<'\n';
	
	return 1;//si se ejecuto
	}
	
	
	return 0;//si no se ejecuto porque no estaba en el rango de la matriz
	
}


	template <class T>
Matrix<T> Matrix<T>::trans(){
	
	Matrix<T> Original( (*this) );

	int aux;
	
	aux=F;
	
	F=C;
	C=aux;
	
	
	T** auxM=new T*[F];
	
	for(int i=0;(i<F);i++)
		(*(auxM+i))=new T[C];
	
	//pasa las componentes de MC a la transpuesta auxiliar
	for(int i=0;(i<F);i++)
		for(int j=0;(j<C);j++)
			(*(auxM+i))[j]=(*(MC+j))[i];
		
	//borra el contenido de todo lo que apuntaban los punteros de MC
	//Si borro MC, a lo que apuntaban sus punteros no se borra
	for(int i=0;(i<F);i++)
	delete[] *(MC+i);
			
	delete[] MC;//borra el arreglo de punteros que apuntaba MC
	
	MC=auxM;

	return Original;
	
}


	template <class T>
int Matrix<T>::ident(){
	
	if(F==C){
	
	/*recorro por columnas, si pregunto si la fila es la misma que la columna(i=j)
	si es igual le pongo un 1, si no es igual le pongo un 0
	*/
		for(int i=0;(i<F);i++){
			for(int j=0;(j<C);j++){
				if(i!=j){
					((*(this->MC+i))[j])=0;
					}else{
					((*(this->MC+i))[j])=1;
					}
			}
		}
		
		//si se pudo realizar
		return 1;	
	}		
	
	//si no se pudo realizar
	return 0;
	
}


	template <class T>
int Matrix<T>::insert(T val,int fil,int col){
	
	if((fil <= F) && (col <= C))
	{
	//la componente de la matriz especificada se le asigna el valor
	(*(MC+fil-1))[col-1]=val;
	
	return 1;//si se ejecuto todo bien
	}	
	
	return 0;//si no se ejecuta nada
	
}


	template <class T>
int Matrix<T>::insert(T** insM,int fil,int col){
	
	if((fil = F) && (col = C))
	{
	
	//recorre las matrices copiando valor por valor
	for(int i=0;(i<F);i++)
		for(int j=0;(j<C);j++)
			(*(MC+i))[j]=(*(insM+i))[j];	
		
		
	return 1;//si se ejecuto todo bien	
	}
		
	
	return 0;//si no se ejecuta nada
	
}
