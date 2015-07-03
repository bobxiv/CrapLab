///Clase templatizada base para las clases "mini arboles" Plus, Minus, Prod, Div
///Posee los elementos comunes de todos los "mini arboles"
///Los parametros template son:
///- Tipo del elemento izquierdo
///- Tipo del elemento derecho
///- Del tipo que contiene el elemento izquierdo
///- Del tipo que contiene el elemento derecho
	template<class L, class R, class T,class U>
class RES_Base{
protected:
	///Elemento o hijo izquierdo
	L Left;
	///Elemento o hijo derecho
	R Right;
public:
	///Cosntructor basico
	///@param L hijo izquierdo
	///@param R hijo derecho
	inline RES_Base( const L& LEFT , const R& RIGHT ): Left(LEFT), Right(RIGHT){};

};