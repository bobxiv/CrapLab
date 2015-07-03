#include "..\..\Exception.h"



template <class T>
void Matrix<T>::PDes(T escal){
	
for(int i= 0;(i<F);i++)
	for(int j=0;(j<C);j++)
		(*(MC+i))[j]*=escal;
	
	
}


	template <class T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &B){
	
	Matrix<T> aux(F,C);
	
	//en resumen pregunta si esta definida la suma convencional de matrices
	if(F==B.F && C==B.C)
	{
		
	
	
	for(int i=0;(i<F);i++)
		for(int j=0;(j<C);j++)
			(*(aux.MC+i))[j]=((*(MC+i))[j])+((*(B.MC+i))[j]);
	
	return aux;
	}
	

/*si no esta definida, es decir que no coinciden las dimensiones, develve 
	una matriz de la dimension del primer operando, llena de -9999	*/
	aux.fill( -9999 );
	
	return aux;
	
}

	template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &B)
{

	Matrix<T> aux(this->F, this->C) ;
	
	//el motivo de estavariable es uqe B esun const asi que no lo puedo modificar
	Matrix<T> aux2(B);

	//hago el segundo negativo y se lo sumo a la matriz this
	aux2.PDes(-1);

	//si llega a no estar definida la suma, en ese caso la resta tampoco,
	//asi uqe me va a devolver una Matrix aux con puros ceros,
	//esto lo hace dentro de la suma
	aux = *(this) + aux2;

	//la otra variable aux2 no va a ningun lado muere aca
	return aux;

}


	template <class T>
Matrix<T> Matrix<T>::operator *(const Matrix<T> &B){
	
	
	
	/*Puede que se ingresen los vectores los 2 por filas, o los 2 por columnas, 
	entonces el producto convencional por definicion, no serviria, pero
	se tolerara esta falta de protocolo, y se lo considerara igual al producto, pero
	para esto se deberan ejecutar estos 2 condicionales que siguen que contemplan los
	casos:
	*/
	
	/*en este caso si los 2 vectores son vectores columna, ejemplo:
	
			1
			1		
			1
	
	*/
	if ( (this->C == 1) && (B.C==1) && (this->F==B.F) ){
		
		//es un escalar el resultado
		Matrix<T> aux(1,1);
		
		//aca o F o C es 1, asi que el valor del mayor no se va a alterar
		for(int k=0;(k<(F));k++){
		aux.MC[0][0]+=(MC[k][0]*B.MC[k][0]);	
		}
		
		return aux;
			
		
	}
		
	/*en este caso si los 2 vectores son vectores fila, ejemplo:
	
			1	1	1
		
	*/
		if ( (this->F == 1) && (B.F==1) && (this->C==B.C) ){
		//es un escalar el resultado
		Matrix<T> aux(1,1);
		
		//aca o F o C es 1, asi que el valor del mayor no se va a alterar
		for(int k=0;(k<(C));k++){
		aux.MC[0][0]+=(MC[0][k]*B.MC[0][k]);	
		}
		
		return aux;
		
	}
	/*en el caso que un vector sea vector columan y el otro vector fila, entonces
	se ajustaria a la definicion de producto matricial, siempre y cuando 
	estos posean la misma cantidad de componentes*/
		
		
		
		Matrix<T> aux(this->F,B.C);
	
	/*Aca ejecuta el prducto matricial segun definicion estricta, preguntando, si
	las filas columnas de la primera son iguales a las filas de la segunda,
	y si es cierto resuelve segun definicion
	*/

		
	//en resumen pregunta si esta definido el producto
	if(this->C==B.F)
	{
			
		T prd=0;
		T comp=0;
		
		for(int i=0;(i<(aux.F));i++)
		{	for(int j=0;(j<(aux.C));j++)
			{	for(int k=0;(k<C);k++)//notar que C es igual a B.F
				{prd=((*(this->MC+i))[k])*((*(B.MC+k))[j]);
				comp += prd;
				}
			//aca asigno ya una componente de la matriz destus de hacer un producto punto
			((*(aux.MC+i))[j])=comp;
			comp = 0;
			}
		
		}
		
		return aux;
		
		
	}


	
	//si no esta definido el producto,devuelve una matriz llena de ceros
	aux.clean();
	
	return aux;
	
}

template<class T>
Matrix<T> Matrix<T>::operator *(const T esc){

	Matrix<T> aux = (*this);

	for( int i = 1; i <= (*this).F; i++ )
		for( int j = 1; j <= (*this).C; j++ )
			aux.MC[i][j] *= esc;

	return aux;

	}


	template<class T>
Matrix<T> Matrix<T>::Product(const Matrix<T> & B){


/*Puede que se ingresen los vectores los 2 por filas, o los 2 por columnas, 
	entonces el producto convencional por definicion, no serviria, pero
	se tolerara esta falta de protocolo, y se lo considerara igual al producto, pero
	para esto se deberan ejecutar estos 2 condicionales que siguen que contemplan los
	casos:
	*/
	
	/*en este caso si los 2 vectores son vectores columna, ejemplo:
	
			1
			1		
			1
	
	*/
	if ( (this->C == 1) && (B.C==1) && (this->F==B.F) ){
		
		//es un escalar el resultado
		Matrix<T> aux(1,1);
		
		//aca o F o C es 1, asi que el valor del mayor no se va a alterar
		for(int k=0;(k<(F));k++){
		aux.MC[0][0]+=(MC[k][0]*B.MC[k][0]);	
		}
		
		return aux;
			
		
	}
		
	/*en este caso si los 2 vectores son vectores fila, ejemplo:
	
			1	1	1
		
	*/
		if ( (this->F == 1) && (B.F==1) && (this->C==B.C) ){
		//es un escalar el resultado
		Matrix<T> aux(1,1);
		
		//aca o F o C es 1, asi que el valor del mayor no se va a alterar
		for(int k=0;(k<(C));k++){
			aux.MC[0][0]+=(MC[0][k]*B.MC[0][k]);	
		}
		
		return aux;
		
	}
	/*en el caso que un vector sea vector columan y el otro vector fila, entonces
	se ajustaria a la definicion de producto matricial, siempre y cuando 
	estos posean la misma cantidad de componentes*/
		
		
		
		Matrix<T> aux(this->F,B.C);
	
	/*Aca ejecuta el prducto matricial segun definicion estricta, preguntando, si
	las filas columnas de la primera son iguales a las filas de la segunda,
	y si es cierto resuelve segun definicion
	*/

		
	//en resumen pregunta si esta definido el producto
	if(this->C==B.F)
	{
			
		T prd=0;
		T comp=0;
		
		for(int i=0;(i<(aux.F));i++)
		{	for(int j=0;(j<(aux.C));j++)
			{	for(int k=0;(k<C);k++)//notar que C es igual a B.F
				{prd=((*(this->MC+i))[k])*((*(B.MC+k))[j]);
				comp += prd;
				}
			//aca asigno ya una componente de la matriz destus de hacer un producto punto
			((*(aux.MC+i))[j])=comp;
			comp = 0;
			}
		
		}
		
		return aux;
		
		
	}

	
	
	//si no esta definido el producto,devuelve una matriz llena de ceros
	aux.clean();
	
	return aux;



}


	template<class T>
Matrix<T> Product(const Matrix<T> & A, const Matrix<T> & B){


/*Puede que se ingresen los vectores los 2 por filas, o los 2 por columnas, 
	entonces el producto convencional por definicion, no serviria, pero
	se tolerara esta falta de protocolo, y se lo considerara igual al producto, pero
	para esto se deberan ejecutar estos 2 condicionales que siguen que contemplan los
	casos:
	*/
	
	/*en este caso si los 2 vectores son vectores columna, ejemplo:
	
			1
			1		
			1
	
	*/
	if ( (A.C == 1) && (B.C==1) && (A.F==B.F) ){
		
		//es un escalar el resultado
		Matrix<T> aux(1,1);
		
		//aca o F o C es 1, asi que el valor del mayor no se va a alterar
		for(int k=0;( k < (A.F) );k++){
		aux.MC[0][0] += (A.MC[k][0] * B.MC[k][0]);	
		}
		
		return aux;
			
		
	}
		
	/*en este caso si los 2 vectores son vectores fila, ejemplo:
	
			1	1	1
		
	*/
		if ( (A.F == 1) && (B.F==1) && (A.C==B.C) ){
		//es un escalar el resultado
		Matrix<T> aux(1,1);
		
		//aca o F o C es 1, asi que el valor del mayor no se va a alterar
		for(int k=0;(k < (A.C));k++){
		aux.MC[0][0] += ( A.MC[0][k]*B.MC[0][k] );	
		}
		
		return aux;
		
	}
	/*en el caso que un vector sea vector columan y el otro vector fila, entonces
	se ajustaria a la definicion de producto matricial, siempre y cuando 
	estos posean la misma cantidad de componentes*/
		
		
		
		Matrix<T> aux(this->F,B.C);
	
	/*Aca ejecuta el prducto matricial segun definicion estricta, preguntando, si
	las filas columnas de la primera son iguales a las filas de la segunda,
	y si es cierto resuelve segun definicion
	*/

		
	//en resumen pregunta si esta definido el producto
	if(A.C==B.F)
	{
			
		T prd=0;
		T comp=0;
		
		for(int i=0;(i<(aux.F));i++)
		{	for(int j=0;(j<(aux.C));j++)
			{	for(int k=0;(k<A.C);k++)//notar que A.C es igual a B.F
				{prd=((*(A.MC+i))[k])*((*(B.MC+k))[j]);
				comp += prd;
				}
			//aca asigno ya una componente de la matriz destus de hacer un producto punto
			((*(aux.MC+i))[j])=comp;
			comp = 0;
			}
		
		}
		
		return aux;
		
		
	}
	
	
	//si no esta definido el producto,devuelve una matriz llena de ceros
	aux.clean();
	
	return aux;


}



	template<class T>
Matrix<T> Matrix<T>::Per_Component_Product( const Matrix<T> & B ){

	Store::Matrix<T> aux( this->F,this->C);

	//solo esta definido si es que son de la misma dimension
	if( ( this->F == B.F ) && ( this->C == B.C ) ){

		for( int i = 0; ( i < this->F ) ; i++){
	
			for( int j= 0; ( j < this->C ) ; j++ ){

				aux.MC[i][j] = ( this->MC[i][j] * B.MC[i][j] );

			}

		}

	//se pudo operar, devuevo el resultado por valor
	return aux;


	}

	//devuelve una matriz de dimension de la que llama, llena de -9999
	//un absurdo
	aux.fill(-9999);

	return aux;


}

	template<class T>
Matrix<T> Matrix<T>::Per_Component_Product(const Matrix<T> & A, const Matrix<T> & B ){

	Store::Matrix<T> aux( A.F,A.C);

	//solo esta definido si es que son de la misma dimension
	if( ( A.F == B.F ) && ( A.C == B.C ) ){

		for( int i = 0; ( i < A.F ) ; i++){
	
			for( int j= 0; ( j < A.C ) ; j++ ){

				aux.MC[i][j] = ( A.MC[i][j] * B.MC[i][j] );

			}

		}

	//se pudo operar, devuevo el resultado por valor
	return aux;


	}

	//devuelve una matriz de dimension del primer parametro, llena de -9999
	//un absurdo
	aux.fill(-9999);

	return aux;


}


	template <class T>
Matrix<T> Matrix<T>::operator /(const Matrix<T> & B){
	
	Matrix<T> aux(this->F,B.C);
	
	if(C==B.F)
	{
		
		
		for(int i=0;(i<(aux.F));i++)
			for(int j=0;(j<(aux.C));j++)	//el cero, tercer parametro dice que se haga el producto por fila
			(*(aux.MC+i))[j] = producto_componente(i,j,0,B);
			//la funcion devuelve, recursivamente el resultado de la componente
				
	return aux;	
	}
	
	//si no esta definido devuelve una matriz con puros ceros
	aux.clean();
	return aux;
	
}


	template <class T>
T Matrix<T>::producto_componente(int I,int J,int k,const Matrix<T> &B){
	
/*si llego hasta este punto se entinede que this->C es igual a B.F, que son las que varian 
	segun la definicion de producto matricial*/
	if(k==this->C)
	{
		return 0;//condicion de salida	
	}	
	
	
	//formula a calcular muchas veces... y nose que mas decir
	return (((*(MC+I))[k])*(*(B.MC+k))[J])+producto_componente(I,J,k+1,B);
	
	
}


	template<class T>
Matrix<T> Matrix<T>::Per_Component_Division(const Matrix<T> & B ){

	Store::Matrix<T> aux( this->F,this->C);

	//solo esta definido si es que son de la misma dimension
	if( ( this->F == B.F ) && ( this->C == B.C ) ){

		for( int i = 0; ( i < this->F ) ; i++){
	
			for( int j= 0; ( j < this->C ) ; j++ ){

				aux.MC[i][j] = ( this->MC[i][j] / B.MC[i][j] );

			}

		}

	//se pudo operar, devuevo el resultado por valor
	return aux;


	}

	//devuelve una matriz de dimension de la que llama, llena de -9999
	//un absurdo
	aux.fill(-9999);

	return aux;



}


	template<class T>
Matrix<T> Matrix<T>::Per_Component_Division(const Matrix<T> & A, const Matrix<T> & B ){

Store::Matrix<T> aux( A.F,A.C);

	//solo esta definido si es que son de la misma dimension
	if( ( A.F == B.F ) && ( A.C == B.C ) ){

		for( int i = 0; ( i < A.F ) ; i++){
	
			for( int j= 0; ( j < A.C ) ; j++ ){

				aux.MC[i][j] = ( A.MC[i][j] / B.MC[i][j] );

			}

		}

	//se pudo operar, devuevo el resultado por valor
	return aux;


	}

	//devuelve una matriz de dimension del primer parametro, llena de -9999
	//un absurdo
	aux.fill(-9999);

	return aux;


}

	template<class T>
Matrix<T> Store::Matrix<T>::Per_Component_Potence(const Matrix<T> &B){
	
	Store::Matrix<T> aux( this->F,this->C);

	//solo esta definido si es que son de la misma dimension
	if( ( this->F == B.F ) && ( this->C == B.C ) ){

		for( int i = 0; ( i < this->F ) ; i++){
	
			for( int j= 0; ( j < this->C ) ; j++ ){

				aux.MC[i][j] = ( Store::Pow<T>::Get(this->MC[i][j] , B.MC[i][j]) );

			}

		}

	//se pudo operar, devuevo el resultado por valor
	return aux;


	}

	//devuelve una matriz de dimension de la que llama, llena de -9999
	//un absurdo
	aux.fill(-9999);

	return aux;

	}

	template <class T>
Matrix<T> Matrix<T>::operator %(const Matrix<T> & B){
	
	//es para devolver, notar que devuelve de 1x3 los vectores
	Matrix<T> AUX(1,3);
	
		
	
	/*solo tiene sentido entre vectores de 3 componentes cada uno
	la pregunta es epicamente larga, porque considero todos los casos dentro de ella
	son 4 combinaciones diferentes posibles
	-3x1  3x1
	-1x3  1x3
	-3x1  1x3
	-1x3  3x1
	*/
	if(((F== 3) && (B.F==3) && (C==1) && (B.C==1)) || ((F== 1) && (B.F==1) && (C==3) && (B.C==3)) || ((F== 3) && (B.F==1) && (C==1) && (B.C==3)) || ((F== 1) && (B.F==3) && (C==3) && (B.C==1))){
	
		
		
		/*es para pasar B a este y usarlo temporalmente asi ordenado, para hacer mas facil
		la definicion del producto vectorial*/
		Matrix<T> AUX2(1,3);
	
		
		
		/*es para pasar this->MC a este y usarlo temporalmente asi ordenado, para 
		hacer mas facil la definicion del producto vectorial*/
		Matrix<T> AUX3(1,3);
	

		
	//paso B a AUX2, para no tener problema con el orden de B
		if(B.F > B.C){
		for(int i=0;(i<(B.F));i++){
			AUX2.MC[0][i]=B.MC[i][0];	}
				
	}else{
		AUX2=B;
		
	}
	
	
	
	//paso this->MC a AUX3, para no tener problema con el orden de this->MC
		if(F > C){
		for(int i=0;(i<(F));i++){
			AUX3.MC[0][i]=this->MC[i][0];	}
			
	}else{
			AUX3=*(this);
		
	}
	
	
	
		/*Hecho por definicion:
			u=a1*i+b1*j+c1*k
			v=a2*i+b2*j+c2*k
			u x v :
					(b1*c2-c1*b2)i+(c1*a2-a1*c2)j+(a1*b2-b1*a2)k
		*/
		(AUX.MC[0][0])=(((AUX3.MC[0][1])*(AUX2.MC[0][2]))-((AUX3.MC[0][2])*(AUX2.MC[0][1])));
		(AUX.MC[0][1])=(((AUX3.MC[0][2])*(AUX2.MC[0][0]))-((AUX3.MC[0][0])*(AUX2.MC[0][2])));
		(AUX.MC[0][2])=(((AUX3.MC[0][0])*(AUX2.MC[0][1]))-((AUX3.MC[0][1])*(AUX2.MC[0][0])));
		
		
		//si todo esta bien devuelve el vector resultado
		return AUX;
		
}

		for(int j=0;(j<3);j++)
			AUX.MC[0][j]=(-9999);
			
	//si no cumple las condiciones nesesarias, devuelve este vector absurdo
	return AUX;
	
}



	template<class T>
Matrix<T> Matrix<T>::Cross( const Matrix<T> & B){


	//es para devolver, notar que devuelve de 1x3 los vectores
	Matrix<T> AUX(1,3);
	
		
	
	/*solo tiene sentido entre vectores de 3 componentes cada uno
	la pregunta es epicamente larga, porque considero todos los casos dentro de ella
	son 4 combinaciones diferentes posibles
	-3x1  3x1
	-1x3  1x3
	-3x1  1x3
	-1x3  3x1
	*/
	if(((F== 3) && (B.F==3) && (C==1) && (B.C==1)) || ((F== 1) && (B.F==1) && (C==3) && (B.C==3)) || ((F== 3) && (B.F==1) && (C==1) && (B.C==3)) || ((F== 1) && (B.F==3) && (C==3) && (B.C==1))){
	
		
		
		/*es para pasar B a este y usarlo temporalmente asi ordenado, para hacer mas facil
		la definicion del producto vectorial*/
		Matrix<T> AUX2(1,3);
	
		
		
		/*es para pasar this->MC a este y usarlo temporalmente asi ordenado, para 
		hacer mas facil la definicion del producto vectorial*/
		Matrix<T> AUX3(1,3);
	

		
	//paso B a AUX2, para no tener problema con el orden de B
		if(B.F > B.C){
		for(int i=0;(i<(B.F));i++){
			AUX2.MC[0][i]=B.MC[i][0];	}
				
	}else{
		AUX2=B;
		
	}
	
	
	
	//paso this->MC a AUX3, para no tener problema con el orden de this->MC
		if(F > C){
		for(int i=0;(i<(F));i++){
			AUX3.MC[0][i]=this->MC[i][0];	}
			
	}else{
			AUX3=*(this);
		
	}
	
	
	
		/*Hecho por definicion:
			u=a1*i+b1*j+c1*k
			v=a2*i+b2*j+c2*k
			u x v :
					(b1*c2-c1*b2)i+(c1*a2-a1*c2)j+(a1*b2-b1*a2)k
		*/
		(AUX.MC[0][0])=(((AUX3.MC[0][1])*(AUX2.MC[0][2]))-((AUX3.MC[0][2])*(AUX2.MC[0][1])));
		(AUX.MC[0][1])=(((AUX3.MC[0][2])*(AUX2.MC[0][0]))-((AUX3.MC[0][0])*(AUX2.MC[0][2])));
		(AUX.MC[0][2])=(((AUX3.MC[0][0])*(AUX2.MC[0][1]))-((AUX3.MC[0][1])*(AUX2.MC[0][0])));
		
		
		//si todo esta bien devuelve el vector resultado
		return AUX;
		
}

		for(int j=0;(j<3);j++)
			AUX.MC[0][j]=(-9999);
			
	//si no cumple las condiciones nesesarias, devuelve este vector absurdo
	return AUX;
	

}


	template<class T>
Matrix<T> Matrix<T>::Cross(const Matrix<T> & A, const Matrix<T> & B){


//es para devolver, notar que devuelve de 1x3 los vectores
	Matrix<T> AUX(1,3);
	
		
	
	/*solo tiene sentido entre vectores de 3 componentes cada uno
	la pregunta es epicamente larga, porque considero todos los casos dentro de ella
	son 4 combinaciones diferentes posibles
	-3x1  3x1
	-1x3  1x3
	-3x1  1x3
	-1x3  3x1
	*/
	if(((A.F== 3) && (B.F==3) && (A.C==1) && (B.C==1)) || ((A.F== 1) && (B.F==1) && (A.C==3) && (B.C==3)) || ((A.F== 3) && (B.F==1) && (A.C==1) && (B.C==3)) || ((A.F== 1) && (B.F==3) && (A.C==3) && (B.C==1))){
	
		
		
		/*es para pasar B a este y usarlo temporalmente asi ordenado, para hacer mas facil
		la definicion del producto vectorial*/
		Matrix<T> AUX2(1,3);
	
		
		
		/*es para pasar this->MC a este y usarlo temporalmente asi ordenado, para 
		hacer mas facil la definicion del producto vectorial*/
		Matrix<T> AUX3(1,3);
	

		
	//paso B a AUX2, para no tener problema con el orden de B
		if(B.F > B.C){
		for(int i=0;(i<(B.F));i++){
			AUX2.MC[0][i]=B.MC[i][0];	}
				
	}else{
		AUX2=B;
		
	}
	
	
	
	//paso this->MC a AUX3, para no tener problema con el orden de this->MC
		if(A.F > A.C){
		for(int i=0;(i<(A.F));i++){
			AUX3.MC[0][i]=A.MC[i][0];	}
			
	}else{
			AUX3 = A;
		
	}
	
	
	
		/*Hecho por definicion:
			u=a1*i+b1*j+c1*k
			v=a2*i+b2*j+c2*k
			u x v :
					(b1*c2-c1*b2)i+(c1*a2-a1*c2)j+(a1*b2-b1*a2)k
		*/
		(AUX.MC[0][0])=(((AUX3.MC[0][1])*(AUX2.MC[0][2]))-((AUX3.MC[0][2])*(AUX2.MC[0][1])));
		(AUX.MC[0][1])=(((AUX3.MC[0][2])*(AUX2.MC[0][0]))-((AUX3.MC[0][0])*(AUX2.MC[0][2])));
		(AUX.MC[0][2])=(((AUX3.MC[0][0])*(AUX2.MC[0][1]))-((AUX3.MC[0][1])*(AUX2.MC[0][0])));
		
		
		//si todo esta bien devuelve el vector resultado
		return AUX;
		
}

		for(int j=0;(j<3);j++)
			AUX.MC[0][j]=(-9999);
			
	//si no cumple las condiciones nesesarias, devuelve este vector absurdo
	return AUX;
	

}
