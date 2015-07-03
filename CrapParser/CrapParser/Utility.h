//Este tipo de dato es el que devuelve Resolve, almacena un valor templatizado T
//que sera el valor de la expresion que se introdujo, y contiene ademas un string
//este cumple la funcion en la asignaiocn = de almacenar sobre que variable se esta almacenando
//Esto es nesesario ya que el AST almacena:
//		    |-=-|
//       |---   ---|
// Var ---	       --- expression		Y si solo devuelvo el val de Var luego nose a donde asignarla
//										asi que guardo en el string a que variable se le debe asignar, si no existe
//										se la crea
//En cualquier otra ocasion diferente a la asignacion el string solo contiene '-' 
	template<typename T>
struct Res{
		Res(): val(0),whom("-"){}
		Res(T res): val(res),whom("-"){}
		Res(T res, std::string str): val(res),whom(str){}

		operator T(){

			return this->val;
		}
		//No mal interpretar el significado de este operador solo asegura igualdad del valor not_print
		bool operator==(const Res<T>& B)const{

			return
				( (this->not_print == B.not_print) );
		}
		
		T val;
		std::string whom;
	};

