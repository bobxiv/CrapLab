//	Resolucion de funciones en los template mediante especializacon

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion ceil(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION CEIL
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	 template<class T>
class CEIL{
public:
	inline static T Get( T val ){
		return val;
	}

};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en timepo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion ceil(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION CEIL
	template<>
class CEIL<float>{
public:
	 inline static int Get( float val ){
		return (int)(ceilf(val));
	}

};
	template<>
class CEIL<long double>{
public:
	inline static int Get( long double val){
		return (int)(ceill(val));
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en timepo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion ceil(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION CEIL
	template<>
class CEIL<double>{
public:
	 inline static int Get( double val ){
		 return (int)(ceill(val));
	}

};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion floor(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION FLOOR
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	 template<class T>
class FLOOR{
public:
	inline static T Get( T val ){
		return val;
	}

};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en timepo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion floor(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION FLOOR
	template<>
class FLOOR<float>{
public:
	 inline static int Get( float val ){
		 return (int)(floorf(val));
	}

};
	template<>
class FLOOR<long double>{
public:
	inline static int Get( long double val){
		return (int)(floorl(val));
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en timepo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion floor(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION FLOOR
	template<>
class FLOOR<double>{
public:
	 inline static int Get( double val ){
		 return (int)(floor(val));
	}

};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION FLOOR
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Sin{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SIN
	template<>
class Sin<long double>{
public:
	inline static long double Get( long double val ){
		return (sinl(val));
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SIN
	template<>
class Sin<float>{
public:
	inline static float Get( float val ){
		return (sinf(val));
	}
}; 

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SIN
	template<>
class Sin<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
					res[i] = sin(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SIN
	template<>
class Sin<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
					res[i] = sinf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COS
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Cos{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COS
	template<>
class Cos<long double>{
public:
	inline static long double Get( long double val ){
		return (cosl(val));
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COS
	template<>
class Cos<float>{
public:
	inline static float Get( float val ){
		return (cosf(val));
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COS
	template<>
class Cos<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = cos(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COS
	template<>
class Cos<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = cosf(val[i]);
				}
			return res;
		}
};


///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sqrt(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SQRT
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Sqrt{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sqrt(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SQRT
	template<>
class Sqrt<long double>{
public:
	inline static long double Get( long double val ){
		return (sqrtl(val));
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sqrt(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SQRT
	template<>
class Sqrt<float>{
public:
	inline static float Get( float val ){
		return (sqrtf(val));
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sqrt(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SQRT
	template<>
class Sqrt<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = sqrt(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sqrt(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SQRT
	template<>
class Sqrt<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = sqrtf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sinh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SINH
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class SinH{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sinh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SINH
	template<>
class SinH<long double>{
public:
	inline static long double Get( long double val ){
		return sinh(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sinh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SINH
	template<>
class SinH<float>{
public:
	inline static float Get( float val ){
		return sinhf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sinh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SINH
	template<>
class SinH<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = sinh(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion sinh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION SINH
	template<>
class SinH<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = sinhf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cosh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COSH
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class CosH{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cosh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COSH
	template<>
class CosH<long double>{
public:
	inline static long double Get( long double val ){
		return cosh(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cosh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COSH
	template<>
class CosH<float>{
public:
	inline static float Get( float val ){
		return coshf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cosh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COSH
	template<>
class CosH<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = cosh(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion cosh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION COSH
	template<>
class CosH<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = coshf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TAN
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Tan{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TAN
	template<>
class Tan<long double>{
public:
	inline static long double Get( long double val ){
		return tan(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TAN
	template<>
class Tan<float>{
public:
	inline static float Get( float val ){
		return tanf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TAN
	template<>
class Tan<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = tan(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TAN
	template<>
class Tan<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = tanf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tanh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TANH
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class TanH{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tanh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TANH
	template<>
class TanH<long double>{
public:
	inline static long double Get( long double val ){
		return tanh(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tanh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TANH
	template<>
class TanH<float>{
public:
	inline static float Get( float val ){
		return tanhf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tanh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TANH
	template<>
class TanH<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = tanh(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion tanh(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION TANH
	template<>
class TanH<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = tanhf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion asin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ASIN
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class ASin{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion asin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ASIN
	template<>
class ASin<long double>{
public:
	inline static long double Get( long double val ){
		return asin(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion asin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ASIN
	template<>
class ASin<float>{
public:
	inline static float Get( float val ){
		return asinf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion asin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ASIN
	template<>
class ASin<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = asin(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion asin(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ASIN
	template<>
class ASin<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = asinf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion acos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ACOS
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class ACos{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion acos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ACOS
	template<>
class ACos<long double>{
public:
	inline static long double Get( long double val ){
		return acos(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion acos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ACOS
	template<>
class ACos<float>{
public:
	inline static float Get( float val ){
		return acosf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion acos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ACOS
	template<>
class ACos<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = acos(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion acos(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ACOS
	template<>
class ACos<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = acosf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion atan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ATAN
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class ATan{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion atan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ATAN
	template<>
class ATan<long double>{
public:
	inline static long double Get( long double val ){
		return atan(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion atan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ATAN
	template<>
class ATan<float>{
public:
	inline static float Get( float val ){
		return atanf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion atan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ATAN
	template<>
class ATan<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = atan(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion atan(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION ATAN
	template<>
class ATan<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = atanf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion abs(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para double, Vector, Matrix, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. EN EL CASO DE ABS NO HAY PROBLEMA ENTRE FLOAT Y DOUBLE ES LA MISMA FUNCION PERO PARA CLASES USER-BUILD
///SI HAY PROBLEMA Y ESTO LO RESUELVE
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class ABS{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion abs(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para double, Vector, Matrix, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. EN EL CASO DE ABS NO HAY PROBLEMA ENTRE FLOAT Y DOUBLE ES LA MISMA FUNCION PERO PARA CLASES USER-BUILD
///SI HAY PROBLEMA Y ESTO LO RESUELVE
	template<>
class ABS<long double>{
public:
	inline static long double Get( long double val ){
		return abs(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion abs(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para double, Vector, Matrix, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. EN EL CASO DE ABS NO HAY PROBLEMA ENTRE FLOAT Y DOUBLE ES LA MISMA FUNCION PERO PARA CLASES USER-BUILD
///SI HAY PROBLEMA Y ESTO LO RESUELVE
	template<>
class ABS<float>{
public:
	inline static float Get( float val ){
		return abs(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion abs(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para double, Vector, Matrix, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. EN EL CASO DE ABS NO HAY PROBLEMA ENTRE FLOAT Y DOUBLE ES LA MISMA FUNCION PERO PARA CLASES USER-BUILD
///SI HAY PROBLEMA Y ESTO LO RESUELVE
	template<>
class ABS<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = abs(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion abs(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para double, Vector, Matrix, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. EN EL CASO DE ABS NO HAY PROBLEMA ENTRE FLOAT Y DOUBLE ES LA MISMA FUNCION PERO PARA CLASES USER-BUILD
///SI HAY PROBLEMA Y ESTO LO RESUELVE
	template<>
class ABS<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = abs(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Ln{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG
	template<>
class Ln<long double>{
public:
	inline static long double Get( long double val ){
		return log(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG
	template<>
class Ln<float>{
public:
	inline static float Get( float val ){
		return logf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG
	template<>
class Ln<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = log(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG
	template<>
class Ln<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = logf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log10(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG10
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Log{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log10(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG10
	template<>
class Log<long double>{
public:
	inline static long double Get( long double val ){
		return log10(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log10(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG10
	template<>
class Log<float>{
public:
	inline static float Get( float val ){
		return log10f(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log10(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG10
	template<>
class Log<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = log10(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion log10(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION LOG10
	template<>
class Log<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = log10f(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion exp(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION EXP
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Exp{
public:
	inline static T Get( T val ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion exp(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION EXP
	template<>
class Exp<long double>{
public:
	inline static long double Get( long double val ){
		return exp(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion exp(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION EXP
	template<>
class Exp<float>{
public:
	inline static float Get( float val ){
		return expf(val);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion exp(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION EXP
	template<>
class Exp<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = exp(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion exp(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION EXP
	template<>
class Exp<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = expf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion pow(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION POW
///
///Solo las especializaciones tiene utilidad verdadera, ya que esta basica, no llama nada
	template<class T>
class Pow{
public:
	inline static T Get( T val,T pot ){
		return val;
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion pow(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION POW
	template<>
class Pow<long double>{
public:
	inline static long double Get( long double val , long double pot){
		return pow(val,pot);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion pow(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION POW
	template<>
class Pow<float>{
public:
	inline static float Get( float val ,float pot ){
		return powf(val,pot);
	}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion pow(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION POW
	template<>
class Pow<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val , double pot ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = pow(val[i],pot);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion pow(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION POW
	template<>
class Pow<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val , float pot ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = powf(val[i], pot);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion ceil(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION CEIL
	template<>
class CEIL<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = ceil(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion ceil(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION CEIL
	template<>
class CEIL<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = ceilf(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion floor(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION FLOOR
	template<>
class FLOOR<Store::Vector<double>>{
public:
	inline static Store::Vector<double> Get( Store::Vector<double> val ){
			int aux = val.Length();
	
			Store::Vector<double> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = floor(val[i]);
				}
			return res;
		}
};

///Clase templatizada encargada de resolver el llamado de funciones en template donde no se sabe a ciencia exacta en tiempo de programacion que tipo sera
///Asi si tenemos que llamar a una funcion floor(a) en un template pero a es de tipo T(parametro del template no sabemos entonces
///si llama a la funcion para int, float, double, ect entonces lo resolvemos con esta clase templatizada, que especializa llamando
///a las funcion indicada. NOTAR QUE EN EL CASO DE UNA FUNCION SOBRECARGADA NO HABRIA PROBLEMA,PERO ESTE NO ES EL CASO
///DE LA FUNCION FLOOR
	template<>
class FLOOR<Store::Vector<float>>{
public:
	inline static Store::Vector<float> Get( Store::Vector<float> val ){
			int aux = val.Length();
	
			Store::Vector<float> res(aux);

			for(int i=0;(i < aux);i++){
				res[i] = floorf(val[i]);
				}
			return res;
		}
};
