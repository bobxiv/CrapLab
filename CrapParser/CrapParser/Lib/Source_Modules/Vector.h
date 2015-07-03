//Este metodo si se utiliza desde el destructor
	template<class T>
inline void Store::Vector<T>::Dispose_Array(){
	//Borro los punteros, solo hay un puntero que contiene todos los elementos
	delete this->MC[0];
	//Borro los punteros a punteros, solo hay uno pero lo borro igual como a el puntero
	delete this->MC;
	
}

//Este no se usa en los constructores solo fuera de estos
//Debido a que este metodo tiene un if, que no seria nesesario en los constructores
	template<class T>
inline void Store::Vector<T>::Renew_Array(int size){

		this->MC = new T*[1];
		this->Componentes = size;
		this->MC[0] = new T[this->Componentes];
	
}


	template<class T>
Vector<T>::Vector()
{
	this->Componentes=0;

	this->MC = new T* [1];

	this->MC[0] = new T [0];

}
/*
	template<class T>
Vector<T>::Vector(  Store::Plus<Store::Vector<T>,Store::Vector<T>,T,T>& P ){


	this->Componentes = P.Length();

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes];
	

	for( int i=0; (i < this->Componentes) ; i++ ){

		this->MC[0][i] = P[i];

	}
	
	
}
*/
	

	template<class T>
Vector<T>::Vector(const Vector<T> &B)
{

	this->Componentes = B.Componentes;

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes] ;
	


	for(int i=0 ; ( i < this->Componentes ) ; i++ )
		this->MC[0][i] = B.MC[0][i];
	
	
}

	template<class T>
Vector<T>::Vector(int size)
{
	this->Componentes = size;

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes];


	for(int i=0;( i< this->Componentes ); i++)
		this->MC[0][i] = 0;

}

	template<class T>
Vector<T>::Vector(const int size,const T& data)
{
	
	this->Componentes = size;

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes];
	

	for(int i=0;( i< this->Componentes ); i++)
		this->MC[0][i] = data;


}

	template<class T>
Vector<T>::Vector( const Matrix<T> &M)
{
	if( M.F > 1 && M.C > 1 ){
		Vector();
	}else{

	this->Componentes = (M.F == 1)? M.C:M.F;

	this->MC = new T*[1];

	this->MC[0] = new T[this->Componentes];
	

	for(int i=0;( i< this->Componentes ); i++)
		this->MC[0][i] = (M.F == 1)? M.MC[0][i] : M.MC[i][0];

		}


}


	template<class T>
void Vector<T>::Resize(int newsize){

	T* aux = new T[newsize];//almaceno los valores en una variable auxiliar
	//que ya me los ubico a los datos en el heap

	//primero lleno hasta la ubicacion menor de datos
	if( this->Componentes < newsize ){

	for(int i=0;i<this->Componentes;i++){
		aux[i]=this->MC[0][i];
		}//si aca me sobran entonces lo lleno de ceros al resto
		for(int i= (this->Componentes) ; ( i < newsize ) ; i++)
		aux[i] = 0;
		
		}else{
			for(int i=0;i < newsize;i++){
			aux[i]=this->MC[0][i];
		}
		}

		//borro el arreglo viejo, ya habiendo guardado los datos
		this->Dispose_Array();

		//almaceno lo nuevo, usando claro el aux, que son mis datos viejos
	this->MC = new T*[1];
	
	this->MC[0] = aux;

	//actualizo la dimension
	this->Componentes = newsize;
			


}

	template<class T>
inline void Vector<T>::clean(){

	for(int i=0;( i<this->Componentes ); i++)
		MC[0][i] = 0;


}

	template<class T>
inline void Vector<T>::fill( T& newvalue){

	for(int i=0;( i<this->Componentes ); i++)
		MC[0][i] = newvalue;


}


	template<class T>
inline void Vector<T>::fill( T val){

	for(int i=0;( i<this->Componentes ); i++)
		MC[0][i] = val;


}

	template<class T>
inline void Store::Vector<T>::Fill_Stair(T from ,T to ,T steep ){

	//Es la cantidad de veces que entra el paso en el rango,
	//Lo redondeo hacia arriba 
	int cant = Store::CEIL<T>::Get( ( to - from )/steep );
	
	T val = from;

	if( this->Componentes != (cant+1) ){
	//cant+1 porque se cuenta el incial tambien,ie es base cero
	this->Resize(cant+1);
	}

	//pongo la base
	this->MC[0][0] = from;

	//Todos los que le siguen, el +1 es porque se cuenta el comienzo
	for(int i =1;( i < cant+1); i++){
		val += steep;
		this->MC[0][i] = val;
		
	}


}

	template<class T>
void Vector<T>::View(int spc,int pres, std::ostream& output ){

	if( this->Componentes > 0 ){//si esta vacio que no deje especio

	//para que deje algun lugar cuando empieza a mostrar el vector
	//output<<'\n';

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
	
		output.precision( std::streamsize(pres) );

		output.width( std::streamsize(spc) );
		
		output<< MC[0][i];
	}

	//Para que deje algun espacio despues de mostrar
		output<<'\n';

		}
	
}


	template<class T>
int Vector<T>::View_Component( int C, std::ostream& output){

	//para que deje algun lugar cuando empieza a mostrar el vector
	output<<'\n';

	if( (C > 0) && (C <= this->Componentes) ){

		output<< this->MC[0][ (C-1) ];

		//Para que deje algun espacio despues de mostrar
		output<<'\n';

		return 1;

	}

	return 0;


}

	template<class T>
void Store::Vector<T>::Show_C( std::ostream& output ){

	output<<'\n'<<"El vector tiene "<< this->Componentes<<" componentes"<<'\n';

}

	template<class T>
inline T Vector<T>::Get_Component( int C ) const{


	if( (C > 0) && (C <= this->Componentes) ){

		return ( this->MC[0][C-1] );

	}
		
	return (-9999);

}

	template<class T>
inline int Store::Vector<T>::Get_C() const{

	return (this->Componentes);

}

	template<class T>
int Vector<T>::insert(T val ,int C){


	if( (C > 0) && (C <= this->Componentes) ){
		this->MC[0][ (C-1) ] = val;

		//salio todo bien
		return 1;
	}

	//no se pudo ingreasar el valor
	return 0;


}


	template<class T>
inline int Vector<T>::Length() const{


return (this->Componentes);


}


	template<class T>
T Vector<T>::Point_Product( const Store::Vector<T> & B){

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
T Vector<T>::Point_Product(const Store::Vector<T> & A, const Store::Vector<T> & B){
	
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


	template <class T>
Vector<T> Vector<T>::operator%( const Vector<T>& B ){

	
	//es para devolver, notar que devuelve un vector de 3 componentes
	Vector<T> AUX(3);
	
		
	
	/*solo tiene sentido entre vectores de 3 componentes
	*/
	if( ( this->Componentes == 3) && (B.Componentes == 3) ){
	
			

	
		/*Hecho por definicion:
			u=a1*i+b1*j+c1*k
			v=a2*i+b2*j+c2*k
			u x v :
					(b1*c2-c1*b2)i+(c1*a2-a1*c2)j+(a1*b2-b1*a2)k
		*/
		(AUX.MC[0][0])=(((this->MC[0][1])*(B.MC[0][2]))-((this->MC[0][2])*(B.MC[0][1])));
		(AUX.MC[0][1])=(((this->MC[0][2])*(B.MC[0][0]))-((this->MC[0][0])*(B.MC[0][2])));
		(AUX.MC[0][2])=(((this->MC[0][0])*(B.MC[0][1]))-((this->MC[0][1])*(B.MC[0][0])));
		
		
		//devuelve el vector resultado
		return AUX;
		
	}


		for(int j=0;(j<3);j++)
			AUX.MC[0][j]=(-9999);
			
	//si no cumple las condiciones nesesarias, devuelve este vector absurdo, lleno de -9999
	return AUX;


}


		template<class T>
	Vector<T> Vector<T>::Cross( const Vector<T> & B ){


	return ( (*this) % B );



}


		template<class T>
	Vector<T> Vector<T>::Cross( const Vector<T> & A , const Vector<T> & B ){


	//El operador binario & no puede tener parametro izquierdo const
	//return ( A % B );

	Vector<T> AUX(3);
				
	/*solo tiene sentido entre vectores de 3 componentes
	*/
	if( ( A.Componentes == 3) && (B.Componentes == 3) ){
	
			

	
		/*Hecho por definicion:
			u=a1*i+b1*j+c1*k
			v=a2*i+b2*j+c2*k
			u x v :
					(b1*c2-c1*b2)i+(c1*a2-a1*c2)j+(a1*b2-b1*a2)k
		*/
		(AUX.MC[0][0])=(((A.MC[0][1])*(B.MC[0][2]))-((A.MC[0][2])*(B.MC[0][1])));
		(AUX.MC[0][1])=(((A.MC[0][2])*(B.MC[0][0]))-((A.MC[0][0])*(B.MC[0][2])));
		(AUX.MC[0][2])=(((A.MC[0][0])*(B.MC[0][1]))-((A.MC[0][1])*(B.MC[0][0])));
		
		
		//devuelve el vector resultado
		return AUX;
		
	}


		for(int j=0;(j<3);j++)
			AUX.MC[0][j]=(-9999);
			
	//si no cumple las condiciones nesesarias, devuelve este vector absurdo, lleno de -9999
	return AUX;



	}


		template<class T>
	inline T& Vector<T>::operator[](int i) const{

	return ( this->MC[0][i] );

	}

		template<class T>
	Store::Vector<T>& Store::Vector<T>::operator=( const Store::Plus<Store::Vector<T>,Store::Vector<T>,T,T>& P ){
		
		int newLength = P.Length();

		//si tiene menos elementos o igual al nuevo, entonces con sobreescribir esta bien
		if(this->Componentes > newLength){

		this->Dispose_Array();

		}

		this->Renew_Array(newLength);
		

		for(int i=0;( i < this->Componentes ); i++)
			this->MC[0][i] = P[i];

		return (*this);

	}

			template<class T>
	Store::Vector<T>& Store::Vector<T>::operator=( const Store::Minus<Store::Vector<T>,Store::Vector<T>,T,T>& P ){
		
		int newLength = P.Length();

		//si tiene menos elementos o igual al nuevo, entonces con sobreescribir esta bien
		if(this->Componentes > newLength){

		this->Dispose_Array();

		}

		this->Renew_Array(newLength);


		for(int i=0;( i < this->Componentes ); i++)
			this->MC[0][i] = P[i];

		return (*this);

	}

		template<class T>
	Store::Vector<T> Vector<T>::operator&&(const Store::Vector<T>& B){

		Store::Vector<T> AUX(this->Componentes);

		if( this->Componentes == B.Componentes ){

			for(int i=0;( i < this->Componentes  ); i++){

				if( ( this->MC[0][i] > 0 ) && ( B.MC[0][i] > 0 ) ){
					AUX.MC[0][i] = 1;//es verdadero

				}else{
					AUX.MC[0][i] = 0;//es falso
				}

			}

			return AUX;

		}	

		AUX.fill( static_cast<T>( -9999 ) );

		return AUX;
			
		
			

	}
		

		template<class T>
	void Vector<T>::Random( T min, T max){

	srand(time(NULL));
		
	T aux;

	//porque % nunca iria a dar max
	max += 1;

	//nesesito la diferencia para sacar un rand entre dos valores
	int diff = (max - min);
	

	for(int i = 0; ( i < this->Componentes ) ; i++){
		aux = ( rand() % diff + static_cast<int>(min) );
		this->MC[0][i] = aux;
	}




	}






//-------------------------------------- Get_Type y sus Especializaciones


	template<class T>
Store::Header Store::Vector<T>::Get_Type(){

	Store::Header H;

	H.Kind = '?';

	H.First_D = this->Componentes;

	H.Second_D = 0;

	H.Type= '?';

	H.CType = '?';

	H.Mode = '?';

	return H;

}

	template<>
Store::Header Store::Vector<int>::Get_Type(){

	Store::Header H;

	H.Kind = 'V';

	H.First_D = this->Componentes;

	H.Second_D = 0;

	H.Type= 'I';

	H.CType = '-';

	H.Mode = '-';

	return H;

}

	template<>
Store::Header Store::Vector<float>::Get_Type(){

	Store::Header H;

	H.Kind = 'V';

	H.First_D = this->Componentes;

	H.Second_D = 0;

	H.Type= 'F';

	H.CType = '-';

	H.Mode = '-';

	return H;

}

	template<>
Store::Header Store::Vector<double>::Get_Type(){

	Store::Header H;

	H.Kind = 'V';

	H.First_D = this->Componentes;

	H.Second_D = 0;

	H.Type= 'D';

	H.CType = '-';

	H.Mode = '-';

	return H;

}

	template<>
Store::Header Store::Vector<Numeric::Complejo<int>>::Get_Type(){

	Store::Header H;

	H.Kind = 'V';

	H.First_D = this->Componentes;

	H.Second_D = 0;

	H.Type= 'C';

	H.CType= 'I';

	switch( this->MC[0][0].Current_Mode() ){
		case Numeric::VecBin_Polar::Polar :{

			H.Mode = 'P';
			break;
										   }
	case Numeric::VecBin_Polar::Vectorial_Binomical :{

		H.Mode = 'B';
		break;
													 }

	}




	return H;

}

	template<>
Store::Header Store::Vector<Numeric::Complejo<float>>::Get_Type(){

	Store::Header H;

	H.Kind = 'V';

	H.First_D = this->Componentes;

	H.Second_D = 0;

	H.Type= 'C';

	H.CType= 'F';

	switch( this->MC[0][0].Current_Mode() ){
		case Numeric::VecBin_Polar::Polar :{

			H.Mode = 'P';
			break;
										   }
	case Numeric::VecBin_Polar::Vectorial_Binomical :{

		H.Mode = 'B';
		break;
													 }

	}


	return H;

}

	template<>
Store::Header Store::Vector<Numeric::Complejo<double>>::Get_Type(){

	Store::Header H;

	H.Kind = 'V';

	H.First_D = this->Componentes;

	H.Second_D = 0;

	H.Type= 'C';

	H.CType= 'D';

	switch( this->MC[0][0].Current_Mode() ){
		case Numeric::VecBin_Polar::Polar :{

			H.Mode = 'P';
			break;
										   }
	case Numeric::VecBin_Polar::Vectorial_Binomical :{

		H.Mode = 'B';
		break;
													 }

	}


	return H;

}
