
						/*	Comienzo Datos y Declaraciones nesesarias para el sistema de templates   */

	template<class E, class T>
	///Clase templatizada contenedora o de envolvimiento.
	///Sus parametros template significan:
	///- E es el tipo de estructura qeu continene, ie matriz, vector, o definida por el usuario.
	///- T es el tipo de dato que almacena la estructura que envuelve.
class Expression;

	template<class L, class R, class T,class U>
	///Clase templatizada contenedora que representa una suma entre dos objetos.
	///Esta clase contiene referencias a dos objetos que pueden ser:
	///- Expression (con cualuqier elemento dentro)
	///- Plus (a su vez con culquier elementos dentro)
	///- Minus (a su vez con cualquier elementos dentro)
	///- Prod (a su vez con cualquier elementos dentro)
	///- Div (a su vez con cualquier elementos dentro)
	///
	///Posee el operador [] que devuelve el elemento correspondiente resuelto,
	///ie calculado, realizando la operacion de suma entre sus dos miembros.
class Plus;

	template<class L, class R, class T,class U>
	///Clase templatizada contenedora que representa una resta entre dos objetos.
	///Esta clase contiene referencias a dos objetos que pueden ser:
	///- Expression (con cualuqier elemento dentro)
	///- Plus (a su vez con culquier elementos dentro)
	///- Minus (a su vez con cualquier elementos dentro)
	///- Prod (a su vez con cualquier elementos dentro)
	///- Div (a su vez con cualquier elementos dentro)
	///
	///Posee el operador [] que devuelve el elemento correspondiente resuelto,
	///ie calculado, realizando la operacion de resta entre sus dos miembros.
class Minus;

	template<class L, class R, class T,class U>
	///Clase templatizada contenedora que representa un producto entre dos objetos.
	///Esta clase contiene referencias a dos objetos que pueden ser:
	///- Expression (con cualuqier elemento dentro)
	///- Plus (a su vez con culquier elementos dentro)
	///- Minus (a su vez con cualquier elementos dentro)
	///- Prod (a su vez con cualquier elementos dentro)
	///- Div (a su vez con cualquier elementos dentro)
	///
	///Posee el operador [] que devuelve el elemento correspondiente resuelto,
	///ie calculado, realizando la operacion producto entre sus dos miembros.
class Prod;

	template<class L, class R, class T,class U>
	///Clase templatizada contenedora que representa una division entre dos objetos.
	///Esta clase contiene referencias a dos objetos que pueden ser:
	///- Expression (con cualuqier elemento dentro)
	///- Plus (a su vez con culquier elementos dentro)
	///- Minus (a su vez con cualquier elementos dentro)
	///- Prod (a su vez con cualquier elementos dentro)
	///- Div (a su vez con cualquier elementos dentro)
	///
	///Posee el operador [] que devuelve el elemento correspondiente resuelto,
	///ie calculado, realizando la operacion de division entre sus dos miembros.
class Div;


	template <class T>
class Vector;

//Suma
#define VpV Plus< Expression< Vector<T> , T > , Expression< Vector<T> , T > , T , T >

#define EpV Plus< Expression< A , T > , Expression< Vector<T> , T > , T , T >

#define VpE Plus< Expression< Vector<T> , T > , Expression< B , T > , T , T >

#define EpE Plus< Expression< A , T > , Expression< B , T > , T , T >

//Resta
#define VmV Minus< Expression< Vector<T> , T > , Expression< Vector<T> , T > , T , T >

#define EmV Minus< Expression< A , T > , Expression< Vector<T> , T > , T , T >

#define VmE Minus< Expression< Vector<T> , T > , Expression< B , T > , T , T >

#define EmE Minus< Expression< A , T > , Expression< B , T > , T , T >

//Producto componente a componente
#define VxV Prod< Expression< Vector<T> , T > , Expression< Vector<T> , T > , T , T >

#define ExV Prod< Expression< A , T > , Expression< Vector<T> , T > , T , T >

#define VxE Prod< Expression< Vector<T> , T > , Expression< B , T > , T , T >

#define ExE Prod< Expression< A , T > , Expression< B , T > , T , T >

//Division componente a componente
#define VdV Div< Expression< Vector<T> , T > , Expression< Vector<T> , T > , T , T >

#define EdV Div< Expression< A , T > , Expression< Vector<T> , T > , T , T >

#define VdE Div< Expression< Vector<T> , T > , Expression< B , T > , T , T >

#define EdE Div< Expression< A , T > , Expression< B , T > , T , T >

//Producto por un escalar
#define VxT Prod< Expression< Vector<T> , T > , T , T , T >

#define ExT Prod< Expression< A , T > , T , T , T >

#define TxE Prod< T , Expression< B , T > , T , T >

#define TxV Prod< T , Expression< Vector<T> , T > , T , T >

//Division por un escalar
#define VdT Div< Expression< Vector<T> , T > , T , T , T >

#define EdT Div< Expression< A , T > , T , T , T >

#define TdE Div< T , Expression< B , T > , T , T >

#define TdV Div< T , Expression< Vector<T> , T > , T , T >

						/*	Fin de Datos y Declaraciones nesesarias para el sistema de templates   */