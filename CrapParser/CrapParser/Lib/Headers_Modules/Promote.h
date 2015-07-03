	///Clase Promote resuelve que tipo de dato es mas "amplio" es decir que podemos expresar el otro tipo sin perder informacion
	///Asi por ejemplo si tenemos que devolver la suma de a+b donde a es int y b float
	///en esta situacion es correcto devolver un resultado en float, ya que de esta forma no perderemos informaicon
	///como pasaria si devolvemos int, de esta forma se truncaria la mantisa decimal del float
	///El metodo depende esencialmente de la especializacion de templates
	///En caso de que los dos tipos sean iguales, que me devuelva el primero seria correcto ya que son identicos
	///asi se resuelve tambien estos casos de dos tipos identicos
	template <class T1,class T2>
class promote{
public:
	///Tipo de dato que se resuelve como el mas "amplio"
	typedef T1 res ;

};

//Especializamos para que se encarge de int-float-double
//			3C2 = 3
//						3P2 = 6
//Vemos como el caso estandar templatizado sin especializacion se encarga de los casos en los
//que el primer dato es el mas "amplio", pero agregaremos la especializacion por seguridad y legibilidad
//Asi que de solo 3 combinaicones nesesarias agregaremos las 6 totales

	template <>
class promote<int,double>{
public:
	///Tipo de dato que se resuelve como el mas "amplio"
	typedef double res ;
};
	//No nesesaria, se encarga el general
	template <>
class promote<double,int>{
public:
	///Tipo de dato que se resuelve como el mas "amplio"
	typedef double res ;
};

	template <>
class promote<int,float>{
public:
	///Tipo de dato que se resuelve como el mas "amplio"
	typedef float res ;
};
	//No nesesaria, se encarga el general
	template <>
class promote<float,int>{
public:
	///Tipo de dato que se resuelve como el mas "amplio"
	typedef float res ;
};

	template<>
class promote<float,double>{
public:
	///Tipo de dato que se resuelve como el mas "amplio"
	typedef double res;
};
	//No nesesaria, se encarga el general
	template<>
class promote<double,float>{
public:
	///Tipo de dato que se resuelve como el mas "amplio"
	typedef double res;
};