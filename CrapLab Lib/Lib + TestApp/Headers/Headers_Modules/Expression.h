	///Clase templatizada encargada de wrapear objetos o datos en su interior
	///Almacena un objeto de tipo E(por ejemplo un Vector)
	///Este a su vez posee elementos de tipo T(por ejemplo int o complejo)
	///
	///Notar que almacena su interior por valor, lo que es un derroche si se almacenan 
	///estructuras grandes como Vector, pero si se almacenan valores int por ejemplo
	///es mas rapido ya que no hay qeu desreferenciarlo para conseguirlo.
	///Por esto se almacena por valor, y existe una especializacion a esta clase que
	///se encarga de almacenar por referencia cuando se trata de Vector o Matrix su interior
	template<class E, class T>
class Expression{
private:

	///Objeto el cual wrapea
	///Por la implementacion de los operadores + - * / seran:
	///- "Mini Arbol" como Plus, Prod, Minus o Div
	///	tener presente que VpE VpV EpV  VmE VmV EmV  ect son tambien "mini arboles"
	const E EXPR;

public:

	///Constructor por copia
	inline Expression( const E& expr): EXPR(expr){};

	///Devuelve el resultado de la componente que se le pida, este es el metodo CLAVE, el que resolvera todo el arbol
	///Entonces si solo es un Vector devuelve la componente, o si es un
	///Plus, Minus, Prod devuelve la suma, resta, o producto respectivamente de la componente
	///@param int el numero de componente a calcular
	///@return T el valor resultado de la operacion
	inline T operator[](int) const;

	///Devuelva el tamaño del elemento
	///No importando si se trata de un Plus, Minus, Prod o incluso un Vector
	///@return int el length de su objeto wrapeado
	inline int Length() const;

};






//-----------------------------------  Comienzo de Especializacion





	///Especializacion de la clase expression
	///Si es un Vector, lo almaceno por referencia ya que asi sera mas pequena la estructura
	template<class T>
class Expression<Store::Vector<T>,T>{
private:

	///Almacena el vector por referencia
	const Store::Vector<T>& EXPR;

public:
	///Constructor de copia
	inline Expression(const Store::Vector<T>& expr): EXPR(expr){};

	///Devuelve el resultado de la componente que se le pida, este es el metodo CLAVE, el que resolvera todo el arbol
	///Entonces si solo es un Vector devuelve la componente, o si es un
	///Plus, Minus, Prod devuelve la suma, resta, o producto respectivamente de la componente
	///@param int el numero de componente a calcular
	///@return T el valor resultado de la operacion
	inline T operator[](int) const;

	///Devuelva el tamaño del elemento
	///No importando si se trata de un Plus, Minus, Prod o incluso un Vector
	///@return int el length de su objeto wrapeado
	inline int Length() const;
};


//-----------------------------------  Fin de Especializacion



//-----------------------------------  Definicion



	template<class E,class T>
inline int Store::Expression<E,T>::Length() const{

	return EXPR.Length();

}



	template<class T>
inline int Store::Expression<Store::Vector<T>,T>::Length() const{

	return EXPR.Length();

}



	template<class E, class T>
inline T Expression<E, T>::operator [](int i) const{

	//Devuelve Elemento i de la expresion
		//Pudiendo ser la expression:
		//- Plus
		//- Prod
		//Si fuese un Vector EXPR entonces llama a su operador [] especializado
			//Y asi se llama iteradamente hasta haber recorrido todo el arbol, sacando la 
			//componente i de cada nodo
return EXPR[i];

}
//Esta especializacion creo que no es importante... verificar!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	template<class T>
inline T Expression<Store::Vector<T>, T>::operator [](int i) const{

	//En este caso como esta formado por Vector la Expression
		//Devuelve: Elemento i del Vector
			//Nota: debe estar sobrecargado el operador del Vector
return EXPR[i];


}