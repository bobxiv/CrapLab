///Clase templatizada, extiende RES_Base, representa un "mini arbol" que simboliza la operacion binaria de producto entre dos elementos
///Los parametros template son:
///- Tipo del elemento izquierdo
///- Tipo del elemento derecho
///- Del tipo que contiene el elemento izquierdo
///- Del tipo que contiene el elemento derecho
	template<class L, class R, class T,class U>
class Prod:public RES_Base<L,R,T,U>{
public:

	///Cosntructor basico
	///@param L hijo izquierdo
	///@param R hijo derecho
	///Llama al constructor identico del padre
	inline Prod(const L&, const R&);

	///Devuelve el elemento de la posicion especificada que estara en el resultado, luego de ejcutar el producto
	///Notar que devuelve el tipo de dato mas "amplio", yse le pasa typename para que el compilador 
	///sepa que es un tipo de dato, que por ser template sera constante en el tiempo de ejecucion
	inline typename promote<T,U>::res operator[](int) const;

	///Dice si es que tiene la misma cantidad de elemnetos
	inline bool Does_Components_Match();

	///Devuelve la cantidad de componentes de el de la izquierda
	///Primero se debe ver si es el mismo con la funcion:  Does_Components_Match()
	///Se llama asi, igual que el metodo de Vector, para compativilidad
	inline int Length() const;
	
	///Operador de asignacion
	///@param Store::Minus<L,R,T,U> el nuevo valor del objeto
	inline Store::Prod<L,R,T,U>& operator=( const Store::Prod<L,R,T,U>& );

};





//-----------------------------------  Comienzo de Especializaciones





//Para LEFT

///Especializacion de los templates Prod para el producto por un escalar, del lado IZQUIERDO
///En este caso el tipo de dato del hijo izquerdo es del mismo tipo que el valor que contiene
///El motivo de la especializacion es que en el operador [], del lado del escalar no se lo debe 
///llamar, ya qeu esto terminaria en un error indudablemente, ya que no existe y es imposible 
///sobrecargar un operador para un tipo build-in. La otra diferencia en este caso es que Length()
///devuelve la dimension del elemento de la derecha, en vez del de la izquierda, porque este ultimo es un escalar.
	template<class L,class R,class U>
class Prod<L,R,L,U>:public RES_Base<L,R,L,U>{
public:

	///Cosntructor basico
	///@param L hijo izquierdo
	///@param R hijo derecho
	///Llama al constructor identico del padre
	inline Prod(const L LEFT, const R& RIGHT):RES_Base<L,R,L,U>::RES_Base(LEFT,RIGHT){};

	///Devuelve el elemento de la posicion especificada que estara en el resultado, luego de ejcutar el producto
	///Notar que devuelve el tipo de dato mas "amplio", yse le pasa typename para que el compilador 
	///sepa que es un tipo de dato, que por ser template sera constante en el tiempo de ejecucion
	///
	///Aqui recide una diferencia de la especializacion, ya que devuelve el escalar sin operador []
	///y el otro operando con el operador []
	inline typename promote<L,U>::res operator[](int) const;

	///Devuelve la cantidad de componentes de el de la derecha(en este caso)
	///Primero se debe ver si es el mismo con la funcion:  Does_Components_Match()
	///Se llama asi, igual que el metodo de Vector, para compativilidad
	///
	///La otra diferencia es en este metodo, donde se devuelve en este caso el tamano del
	///elemento de la derecha, ya que el de la izquierda es un escalar, ie sera 1 siempre
	inline int Length() const;
	
	///Operador de asignacion
	///@param Store::Minus<L,R,L,U> el nuevo valor del objeto
	inline Store::Prod<L,R,L,U>& operator=( const Store::Prod<L,R,L,U>& );

};


	template<class L, class R, class U>
inline typename promote<L,U>::res Prod<L,R,L,U>::operator[](int i) const{

	//Devuelve la componente resultado del producto
	return ( Left * Right[i] );


}

	template <class L, class R, class U>
inline int Prod<L,R,L,U>::Length() const{

	return Right.Length();

}

	template <class L,class R, class U>
inline Store::Prod<L,R,L,U>& Store::Prod<L,R,L,U>::operator=( const Store::Prod<L,R,L,U>& TWO ){

	this->Left = TWO.Left;

	this->Right = TWO.Right;

	return (*this);

}

//Para Right

///Especializacion de los templates Prod para el producto por un escalar, del lado DERECHO
///En este caso el tipo de dato del hijo derecho es del mismo tipo que el valor que contiene
///El motivo de la especializacion es que en el operador [], del lado del escalar no se lo debe 
///llamar, ya qeu esto terminaria en un error indudablemente, ya que no existe y es imposible 
///sobrecargar un operador para un tipo build-in
	template<class L,class R,class T>
class Prod<L,R,T,R>:public RES_Base<L,R,T,R>{
public:

	///Cosntructor basico
	///@param L hijo izquierdo
	///@param R hijo derecho
	///Llama al constructor identico del padre
	inline Prod(const L& LEFT, const R RIGHT):RES_Base<L,R,T,R>::RES_Base(LEFT,RIGHT){};

	///Devuelve el elemento de la posicion especificada que estara en el resultado, luego de ejcutar el producto
	///Notar que devuelve el tipo de dato mas "amplio", yse le pasa typename para que el compilador 
	///sepa que es un tipo de dato, que por ser template sera constante en el tiempo de ejecucion
	///
	///Aqui recide la diferencia de la especializacion, ya que devuelve el escalar sin operador []
	///y el otro operando con el operador []
	inline typename promote<T,R>::res operator[](int) const;

	///Devuelve la cantidad de componentes de el de la izquierda
	///Primero se debe ver si es el mismo con la funcion:  Does_Components_Match()
	///Se llama asi, igual que el metodo de Vector, para compativilidad
	inline int Length() const;
	
	///Operador de asignacion
	///@param Store::Minus<L,R,T,R> el nuevo valor del objeto
	inline Store::Prod<L,R,T,R>& operator=( const Store::Prod<L,R,T,R>& );

};


	template<class L, class R, class T>
inline typename promote<T,R>::res Prod<L,R,T,R>::operator[](int i) const{

	//Devuelve la componente resultado del producto
	return ( Left[i] * Right );


}

	template <class L, class R, class T>
inline int Prod<L,R,T,R>::Length() const{

	return Left.Length();

}

	template <class L, class R, class T>
inline Store::Prod<L,R,T,R>& Store::Prod<L,R,T,R>::operator=( const Store::Prod<L,R,T,R>& TWO ){

	this->Left = TWO.Left;

	this->Right = TWO.Right;

	return (*this);

}



//-----------------------------------  Fin de Especializaciones


//-----------------------------------  Definicion


	template<class L,class R, class T, class U>
inline Prod<L,R,T,U>::Prod(const L& LEFT, const R& RIGHT):RES_Base<L,R,T,U>::RES_Base(LEFT,RIGHT){

}
	
	template<class L,class R,class T, class U>
inline typename promote<T,U>::res Store::Prod<L,R,T,U>::operator[](int i) const{

	//Devuelve la componente resultado del producto
	//Recorre a sus elementos internos, expandiendose por todos sus hijos y nietos
	return ( Left[i] * Right[i] );


}

	template <class L,class R,class T,class U>
inline bool Store::Prod<L,R,T,U>::Does_Components_Match(){

	return ( Left.Length() == Right.Length() );


}

	template <class L,class R,class T,class U>
inline int Store::Prod<L,R,T,U>::Length() const{

	return Left.Length();

}

	template <class L,class R,class T,class U>
inline Store::Prod<L,R,T,U>& Store::Prod<L,R,T,U>::operator=( const Store::Prod<L,R,T,U>& TWO ){

	this->Left = TWO.Left;

	this->Right = TWO.Right;

	return (*this);

}