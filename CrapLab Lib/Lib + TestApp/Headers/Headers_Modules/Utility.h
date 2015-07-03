	///Formato del encabezado de los .crap
///Estos archivos se encargan de exportacion y almacenamiento de Vectores o Matrices.
///Estos se utilizan para la comunicacion entre plugins y parael almacenamiento propio.
///
///- IMPORTANTE: Para algunos casos no todos los valores son nesesarios.
///@author Emmanuel Rojas Fredini
struct Header{

///.
///Guarda:
///
///- 'M' si es matriz
///- 'V' si es vector
char Kind;

///.
///Guarda:
///- Numero de componentes si es Vector
///- Numero de filas si es Matriz
///
///Abreviaicon de First Dimension
int First_D;

///.
///Guarda:
///- Numero de columnas si es Matriz
///
///Abreviaicon de Second Dimension
int Second_D;

///.
///Guarda:
///- Tipo de dato que contiene el vector o matriz
char Type;

///.
///Guarda:
///- Si el tipo de dato es complejo esto dice que contiene complejos
///
///Abreviaicon de Complex Type
char CType;

///.
///Guarda:
///- Si el tipo de dato es complejo esto dice si se los guardo polar o binomicamente
char Mode;

///Constructor principal.
///@param K Inicializa Kind
///@param F Inicializa First_D
///@param S Inicializa Second_D
///@param T Inicializa Type
///@param CT Inicializa CType
///@param M Inicializa Mode
Header(char K,int F,int S,char T,char CT,char M): Kind(K), First_D(F), Second_D(S), Type(T), CType(CT), Mode(M) {}; 

///Constructor por defecto.
///Por defecto se inicializan como desconocidos.
///Esto implica que:
///- Kind = ?
///- First_D = 0
///- Second_D = 0
///- CType = ?
///- Mode = ?
Header(){
Kind = '?'; 
First_D = 0;
Second_D = 0;
Type = '?';
CType = '?';
Mode = '?';
}

///Operador de comparacion de tipos entre encabezados.
///Este operador devuelve verdadero si dos Headers son de la misma clase, pero no completamente iguales
///es decir que son del mismo tipo, pero pueden variar en las dimensiones.\n
///Se compara el atributo Kind, Type, CType y Mode.
///@param B  Otro objecto de tipo Header
///@return bool  Si son relativamente iguales
bool operator&&( Store::Header& B ){

	return ( (this->Kind == B.Kind) && (this->Type == B.Type) && (this->CType == B.CType) && (this->Mode == B.Mode) );


}

///Operador de comparacion absoluta entre encabezados.
///Este operador devuelve verdadero si dos Headers son completamente iguales.\n
///Se comparan todos los atributos.
///@param B  Otro objeto de tipo Header
///@return bool  Si son absolutamente iguales
bool operator==( Store::Header& B ){

	return ( (this->Kind == B.Kind) && (this->Type == B.Type) && (this->CType == B.CType) && (this->Mode == B.Mode) && 
		(this->First_D == B.First_D) && (this->Second_D == B.Second_D) );


}



};

