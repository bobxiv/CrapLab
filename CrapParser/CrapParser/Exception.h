//Se lanza cuando hay una division por 0
template<class T>
class ZERO_DIV{
public:
	//almacena el valor del numerador, es nesesario ya que:
	//1) 0/0 es NAN
	//2) +A/0 es Inf
	//3) -A/0 es -Inf
	T num_val;

	ZERO_DIV(){} 
	ZERO_DIV( T& A): num_val(A){} 
	
	};

//significa Second_Argument_Must_Be_Escalar signidica que en la potencia
//el segundo parametro debe ser un escalar
class SEC_ARG_MUST_BE_ESC{};

//significa BAD_DIMENSION signidica que se esta intentando utilizar una
//matriz o vector de un tamaño incorrecto para una expression, por ejemplo
// pasar plot( Matriz de 2x2 , vector de 3 elementos ) el primer parametro no puede ser
class BAD_DIM{
	public:
		BAD_DIM(): what(""){}
		BAD_DIM(std::string& says): what(says){}

		std::string what;
	};

//significa GENERIC_OUTPUT_INPUT_ERROR signidica que no se pudo efectur alguna operacion de salida o entrada.
//Un ejemplo de esto es cuando no se puede guardar los datos a graficar por Crap_Graph
class GEN_OUT_IN_ERR{
public:
	GEN_OUT_IN_ERR(): what(""){}
	GEN_OUT_IN_ERR(std::string& says): what(says){}
	
	std::string what;
	};

class BAD_SINTAX{};

class UNDECL_VAR{
public:
	std::string who;
	UNDECL_VAR(std::string var): who(var){}
	};