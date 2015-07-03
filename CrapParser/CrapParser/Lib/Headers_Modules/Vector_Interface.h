		template <class T>
	///Clase templatizada disenada para almacenar y operar con arreglos unidimensionales.
	///Esta es una de las clases mas extensas. Hereda de Custom_Storage, como Matrix.
	///Posee funcionalidad para realizar operaciones basicas como:
	///- Suma Vectoriales
	///- Resta Vectoriales
	///- Producto por un escalar
	///- Producto Punto o escalar
	///- Producto elemento a elemento
	///- Division elemento a elemento
	///- Ect
	///
	///Y otras funciones avanzadas como:
	///- Producto Cruz
	///- Ect
	///
	///Por ultimo  otras funciones especiales como:
	///- Serializacion, pudiendo hacer salida o entrada de archivos
	///- Representacion por un stream de su contenido
	///- Ect
	///@author Emmanuel Rojas Fredini
	class Vector:public CustomStorage<T>
	{
	private:
		
		///Este miembro contiene la cantidad de componentes que posee el vector.
		int Componentes;

		///Ejecuta el operador delete en el arreglo MC
		inline void Dispose_Array();

		///Ejecuta el operador new en el arreglo.
		///Renueva a MC con las dimensiones que se les pase.
		///@param size  Establece cual es el tamano del arreglo
		inline void Renew_Array(int size);

		///Este metodo es auxiliar a From_Binary.
		///No se debe utilizar, a menos que se observan cuidadosamente sus operaciones internas.
		///@param 
		///@return void
		inline void Read_Data( Store::Header& , std::ifstream& );

	public:

		friend class Matrix<T>;

		///Este constructor por defecto.
		///Inicializa el vector con 0 componentes.
		Vector();

		//Vector(  Store::Plus<Store::Vector<T>,Store::Vector<T>,T,T>& );

		///Este constructor inicializa el vector por copia.
		///@param B Vector<T>, con el mismo parametro template, de donde se copiaran sus datos por valor
		Vector( const Vector<T>& B);

		///Este constructor inicializa el vector por copia, con un objeto Matrix
		///Si la matriz no es convertible a vector( no tiene F o C 1 ) luego se inicializa por defecto el vector 
		///@param M Matrix<T>, con el mismo parametro template, de donde se copiaran sus datos por valor
		Vector( const Matrix<T> & M );

		///Este constructor inicializa el vector con una instancia de una expression
		///Esto permite por ejemplo Store::Vector<int> A( B + C ) donde B y C son vector de enteros tambien
		///@param B Store::Expression<E,T>, es el resultado de una operacion
			template<typename E>
		Vector( Store::Expression<E,T>& Res ){
			this->Componentes = Res.Length();

			this->MC = new T*[1];
			this->MC[0]=new T[this->Componentes];

			for(int i=0;(i < this->Componentes);i++){
					this->MC[0][i] = Res[i];
				}
			
			}

		///Este constructor inicializa un vector de dimension por parametro.
		///Tener en cuenta que si se omite el parametro se llamara a el constructor por defecto.
		///@param size  Tamano del nuevo vector
		Vector( int size );

		///Este constructor inicializa un vector, con cantidad de componentes y valor del arreglo.
		///Es muy similar a el por copia, solo qeu en vez de solicitar un objeto Vector,
		///solo pide sus miembros mas importantes.
		///@param size  Tamano del nuevo vector
		///@param data  valores del nuevo vector
		Vector( const int , const T& );
	
		///Re-dimensiona el vector.
		///Si se achica el vector, entonces se pieden los datos de las componentes de las posiciones
		///finales. Si se agranda el vector se inicializan las nuevas componentes con 0.
		///@param newsize  Establece cual sera el nuevo tamaño
		///@return void
		void Resize(int newsize);

		///Limpia el vector.
		///Combirtiendo todas las componentes del vector al valor 0.
		///IE hace 0 el vector.
		///@return void
		inline void clean();

		///Se encarga de llenar el arreglo.
		///Combierte todas las componentes del vector al valor que se pasa por parametro.
		///IE hace (parametro) el vector
		///@param newvalue  Es el valor nuevo del vector
		///@return void
		inline void fill( T& newvalue );

		//Combierte todas las componentes del vector al valor que se pasa por parametro
		//IE hace (parametro) el vector
		//La particularidad de esta es que no se pasa por referencia, y por eso debe ser utilizado
		//para pasarle constantes
		//Devuelve void
		inline void fill( T );

		///Llena el vector con valores entre 2 rangos, considerando los dos limites dentro
		///Se llena con valores que poseen un paso determinado, ie crecen constantemente.
		///
		///@param from  Establece desde donde se llenara el vector
		///@param to  Establece hasta donde se llenara el vector
		///@param steep  Establece el paso con que se saltara de valor en valor
		///@return void
		///-Importante, si el valor de fin del llenado no esta alineado con el paso
		///desde el comienzo, se tomara el valor mas cercano a este redondeando hacia arriba
		inline void Fill_Stair(T from,T to,T steep);

		///Muestra el vector por el flujo que se idique.
		///@param width  Establece el ancho que ocupara una sola componente, modifica setw o width
		///- Por defecto setw wa 5
		///@param pres  Establece la precision con la que se mostrara el valor, modifica setprecision, ie el numero de decimales despues de la coma decimal
		///- Por defecto setprecision es 2
		///@param out  El objeto ostream por el que se hara la salida 
		///- Por defecto la salida es por el flujo estandar cout
		///@return void
		void View(int=7,int=2, std::ostream& = std::cout);

		///Lleva los datos del objeto a un archivo binario.
		///Este metodo es el qeu realiza las salidas, porlas que se comunica, por medio de archivos .crap
		///con el graficador CrapGraph.
		///@param name  El string que establece el nombre del archivo, si no se le pone una extension, por defecto la extension es .crap
		///@param path  El string con la direccion donde se almacenara el archivo 
		///- Por defecto el path es la carpeta Data 
		///@return int  
		///Si es 0 no se pudo crear o sobreesctibir el archivo, si es 1 salio todo bien. 
		///Si sorprendentemente devuelve 3 el problema se debe a que no hay una instanciacion para ese tipo de dato
		///es decir no se creo un envabezado y por lo tanto no se puede guardar el dato, pero esto jamas deberia ocurrir
		///
		///- Importante, si no se le pone extension al archivo, elegir un nombre sin punto
		int To_Bynary( std::string& , std::string& = std::string(".\\Data\\") );

		///Lee un archivo binario que contenga datos de un vector, y lo asigna al vector que llama al metodo.
		///@param name  El string que establece el nombre del archivo, si no se le pone una extension, por defecto la extension es .crap
		///@param path  El string con la direccion donde se almacenara el archivo 
		///- Por defecto el path es la carpeta Data 
		///@return int 
		///Si es 0 no se pudo abrir el archivo, si es 1 salio todo bien.
		///Si llega a devolver 3 es porque se pudo abrir el archivo pero este no es un archivo de un Vector de este tipo o es una Matrix, asi que no se pudo leer
		///
		///- Importante, si no se le pone extension al archivo, elegir un nombre sin punto
		int From_Binary( std::string& , std::string& = std::string(".\\Data\\") );

		///Muestra el valor de una componente del vector.
		///@param pos  Establece la posicion del elemento a mostrar
		///@param out  Establece el stream por el que se hara la salida
		///- Por defecto las salida es por el flujo estandar 
		///@return int  Si es 0 si no se pudo ejecutar, si es 1 salio todo bien.
		///
		///Nombre Completo: View Componente
		int View_Component( int , std::ostream& = std::cout );

		///Muestra la cantidad de componentes del vector.
		///@param out  Establece el steam de por el que se hara la salida
		///- Por defecto las salida es por el flujo estandar 
		///@return void
		///
		///Nombre Completo: Show Componentes
		void Show_C( std::ostream& = std::cout );

		///Devuelve el valor de la componente del vector que se pida.
		///@param comp  Establece la componente que se desea obtener 
		///@return T
		///Devuelve -9999 o equivalente si recibe una componente fuera de rango.
		inline T Get_Component( int ) const;

		///Devuelve la cantidad de componentes del vector.
		///Es lo mismo qeu hace Length().
		///@see Length()
		///@return int 
		///Nombre Completo: Get Componentes
		inline int Get_C() const;

		///Devuelve la cantidad de componentes del vector.
		///Es lo mismo qeu hace Get_C().
		///@see Get_C()
		///@return int
		inline int Length() const;

		///Inserta un valor en una de las componentres del vector.
		///@param value  El dato que se ingresara al vector
		///@param pos  Establece la posicion, componente, donde se ingresara el valor		
		///@return int  Si no se pudo ejecutar, o 1 si pudo ejecutar
		int insert(T,int);
		
		///Sobrecarga el operador + como esta definido matematicamente.
		///Se realiza Componente a componente.
		///Esta es la suma de de 2 Vectores.
		///@param const Vector<T>  El operando derecho
		///@return Expression< VpV , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline Store::Expression< Store::VpV , T > operator+( const Store::Vector<T>& );

		
			template<class B>
		///Sobrecarga el operador + como esta definido matematicamente.
		///Se realiza Componente a componente.
		///Esta es la suma de un Vector y un Expression que contiene algo dentro
		///@param const Expression< B , T >  El operando derecho
		///@return Expression< VpE , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline Store::Expression< Store::VpE , T > operator+( const Store::Expression< B, T >& );

		
			template<class A>
		///Sobrecarga el operador + como esta definido matematicamente.
		///Es una funcion amiga. Se realiza Componente a componente.
		///Esta es la suma de una Expression que contiene algo dentro y un Vector.
		///@param const Expression< A , T >  El operando izquierdo
		///@param const Vector< T >  El operando derecho
		///@return Expression< EpV , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression<Store::EpV, T> operator+( const Store::Expression<A , T> & , const Vector<T> &);
		

			template<class A, class B>
		///Sobrecarga el operador + como esta definido matematicamente.
		///Es una funcion amiga. Se realiza Componente a componente.
		///Esta es la suma de una Expression que contiene algo dentro y otra Expression que contiene algo dentro.
		///@param const Expression< A , T >  El operando izquierdo
		///@param const Vector< T >  El operando derecho
		///@return Expression< EpE , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression<Store::EpE, T> operator+( const Store::Expression<A , T>& , const Store::Expression<B , T>&);

		///Sobrecarga el operador - como esta definido matematicamente.
		///Se realiza Componente a componente.
		///Esta es la resta de 2 Vectores.
		///@param const Vector< T >  El operando derecho
		///@return Expression< VmV , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline Store::Expression< Store::VmV , T > operator-( const Store::Vector<T>& TWO){
			
			Store::Expression< Store::VmV , T > RES( Store::VmV(*this,TWO) );

			return RES;
	
		}

			template<class B>
		///Sobrecarga el operador - como esta definido matematicamente.
		///Se realiza Componente a componente.
		///Esta es la resta de un Vector y de una Expression que contiene algo dentro.
		///@param const Expression< B , T >  El operando derecho
		///@return Expression< VmE , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline Store::Expression< Store::VmE , T > operator-( const Store::Expression< B, T >& TWO){

			Store::Expression< Store::VmE , T > RES( Store::VmE(*this,TWO) );

			return RES;

		}


			template<class A>
		///Sobrecarga el operador - como esta definido matematicamente.
		///Es una funcion amiga. Se realiza Componente a componente.
		///Esta es la resta de una Expression que contiene algo dentro y de un Vector.
		///@param const Expression< A , T >  El operando izquierdo
		///@param const Vector< T >  El operando derecho
		///@return Expression< EmV , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression<Store::EmV, T> operator-( const Store::Expression<A , T>& ONE , const Vector<T>& TWO){

			Store::Expression<Store::EmV, T> RES( Store::EmV(ONE,TWO) );

			return RES;

		}
		

			template<class A, class B>
		///Sobrecarga el operador - como esta definido matematicamente.
		///Es una funcion amiga. Se realiza Componente a componente.
		///Esta es la resta de una Expression que contiene algo dentro y otra Expression que contiene algo dentro.
		///@param const Expression< A , T >  El operando izquierdo
		///@param const Expression< B , T >  El operando derecho
		///@return Expression< EmE , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression<Store::EmE, T> operator-( const Store::Expression<A , T>& ONE, const Store::Expression<B , T>& TWO){

			Store::Expression<Store::EmE, T> RES( Store::EmE(ONE,TWO) );

			return RES;

		}
		
		///Sobrecarga el operador * como esta definido matematicamente.
		///Se realiza Componente a componente.
		///Esta es el producto de 2 Vectors.
		///@param const Vector< T >  El operando derecho
		///@return Expression< VxV , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline Store::Expression< Store::VxV , T> operator*( const Store::Vector<T>& TWO ){
		
			Store::Expression< Store::VxV , T> RES( Store::VxV(*this,TWO) );

			return RES;

		}

		inline Store::Expression< Store::VdV , T> operator/( const Store::Vector<T>& TWO ){
		
			Store::Expression< Store::VdV , T> RES( Store::VdV(*this,TWO) );

			return RES;

		}


			template<class B>
		///Sobrecarga el operador * como esta definido matematicamente.
		///Se realiza Componente a componente.
		///Esta es el producto de un Vector y una Expression que contiene algo dentro.
		///@param const Expression< B , T >  El operando derecho
		///@return Expression< VxE , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline Store::Expression< Store::VxE , T> operator*( const Store::Expression< B , T >& TWO ){
		
			Store::Expression< Store::VxE , T> RES( Store::VxE(*this,TWO) );

			return RES;

		}


			template<class A>
		///Sobrecarga el operador * como esta definido matematicamente.
		///Es una funcion amiga. Se realiza Componente a componente.
		///Esta es el producto de una Expression que contiene algo dentro y de un Vector.
		///@param const Expression< A , T >  El operando izquierdo
		///@param const Vector< T >  El operando derecho
		///@return Expression< ExV , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression< Store::ExV , T> operator*( const Store::Expression<A , T>& , const Store::Vector<T>& );


			template<class A, class B>
		///Sobrecarga el operador * como esta definido matematicamente.
		///Es una funcion amiga. Se realiza Componente a componente.
		///Esta es el producto de una Expression que contiene algo dentro y otra Expression que contiene algo dentro.
		///@param const Expression< A , T >  El operando izquierdo
		///@param const Expression< B , T >  El operando derecho
		///@return Expression< ExE , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression< Store::ExE , T> operator*( const Store::Expression<A , T>& , const Store::Expression<B , T>& ); 
		
		///Sobrecarga el operador * con la operacion de producto por un escalar.
		///Esta es el producto de un Vector por un escalar.
		///@param const TWO  El escalar
		///@return Expression< VxT , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline Store::Expression< Store::VxT , T> operator*( const T TWO ){
		
			Store::Expression< Store::VxT , T> RES( Store::VxT(*this,TWO) );

			return RES;

		}


			template<class A>
		///Sobrecarga el operador * con la operacion de producto por un escalar.
		///Es una funcion amiga.
		///Esta es el producto de una Expression que contiene algo dentro por un escalar.
		///@param const Expression< A , T > El operando izquierdo
		///@param const TWO  El escalar, operando derecho
		///@return Expression< ExT , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression< Store::ExT , T> operator*( const Store::Expression< A , T >& ONE , const T TWO ){

		Store::Expression< Store::ExT , T> RES( Store::ExT(ONE,TWO) );

		return RES;

		}
		
		///Sobrecarga el operador * con la operacion de producto por un escalar.
		///Es una funcion amiga.
		///Esta es el producto de un escalar por un Vector.
		///@param const ONE  El escalar, operando izquierdo
		///@param const Vector< T >  El operando derecho
		///@return Expression< TxV , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression< Store::TxV , T> operator*( const T ONE , const Store::Vector<T>& TWO ){

		Store::Expression< Store::TxV , T> RES( Store::TxV(ONE,TWO) );

		return RES;

		}


			template<class B>
		///Sobrecarga el operador * con la operacion de producto por un escalar.
		///Es una funcion amiga.
		///Esta es el producto de un escalar por una Expression que contiene algo dentro.
		///@param const ONE  El escalar, operando izquierdo
		///@param const Expression< B , T >  El operando derecho
		///@return Expression< TxE , T >  
		///
		///- Importante: Los tipos deben ser iguales.
		inline friend Store::Expression< Store::TxE , T> operator*( const T ONE , const Store::Expression<B , T>& TWO ){

			Store::Expression< Store::TxE , T> RES( Store::TxE(ONE,TWO) );

			return RES;

		}

			template<class A>
		inline friend Store::Expression< Store::EdT , T> operator/( const Store::Expression< A , T >& ONE , const T TWO ){

				Store::Expression< Store::EdT , T> RES( Store::EdT(ONE,TWO));

				return RES;

		}
		
			template<class B>
		inline friend Store::Expression< Store::TdV , T> operator/( const T ONE , const Store::Vector<B>& TWO ){

			Store::Expression< Store::TdV , T> RES( Store::TdV(ONE,TWO));

			return RES;

		}

			template<class B>
		inline friend Store::Expression< Store::TdE , T> operator/( const T ONE , const Store::Expression<B , T>& TWO ){

			Store::Expression< Store::TdE , T> RES( Store::TdE(ONE,TWO));

			return RES;

		}


		inline bool operator==( const Store::Vector<T>& TWO )const{

			if( this->Componentes == TWO.Componentes ){

				for(int i=0; i < this->Componentes;i++){
					if( this->MC[i] != TWO.MC[i] )
						return false;
					}

				}else{

			return false;

				}

			return true;

		}

		///Esta funcion realiza un producto componente a componente.
		///
		///Alias de operador *
		inline Store::Expression<Store::VxV , T> Per_Component_Product( const Vector<T>& );


			template<class B>
		///Esta funcion realiza un producto componente a componente.
		///
		///Alias de operador *
		inline Store::Expression<Store::VxE , T> Per_Component_Product( const Store::Expression<B , T>& );


			template<class A>
		///Esta funcion realiza un producto componente a componente.
		///
		///Alias de operador *
		inline friend Store::Expression<Store::ExV , T> Per_Component_Product( const Store::Expression<A , T>& , const Store::Vector<T>& );


			template<class A, class B>
		///Esta funcion realiza un producto componente a componente.
		///
		///Alias de operador *
		inline friend Store::Expression<Store::ExE , T> Per_Component_Product( const Store::Expression<A , T>& , const Store::Expression<B , T>& );

		///Esta funcion estatica realiza un producto componente a componente.
		///
		///Importante: Es Static.
		///
		///Alias de operador *
		inline static Store::Expression<Store::VxV , T> Per_Component_Product( const Store::Vector<T>& ONE, const Store::Vector<T>& TWO ){

			Store::Expression<Store::VxV , T> RES( Store::VxV(ONE,TWO) );

			return RES;

		}


			template<class B>
		///Esta funcion realiza un producto componente a componente.
		///
		///Importante: Es Static.
		///
		///Alias de operador *
		inline static Store::Expression<Store::VxE , T> Per_Component_Product( const Store::Vector<T>& ONE, const Store::Expression<B , T>& TWO ){

			Store::Expression<Store::VxE , T> RES( Store::VxE(ONE,TWO) );

			return RES;

		}


			template<class A>
		///Esta funcion realiza un producto componente a componente.
		///
		///Importante: Es Static.
		///
		///Alias de operador *
		inline static Store::Expression<Store::ExV , T> Per_Component_Product( const Store::Expression<A , T>& ONE, const Store::Vector<T>& TWO ){

			Store::Expression<Store::ExV , T> RES( Store::ExV(ONE,TWO) );

			return RES;

		}


			template<class A, class B>
		///Esta funcion realiza un producto componente a componente.
		///
		///Importante: Es Static.
		///
		///Alias de operador *
		inline static Store::Expression<Store::ExE , T> Per_Component_Product( const Store::Expression<A , T>& , const Store::Expression<B , T>& ){

			Store::Expression<Store::ExE , T> RES( Store::ExE(ONE,TWO) );

			return RES;

		}

		///Esta funcion realiza una division componente a componente.
		///
		///Alias de operador /
		inline Store::Expression<Store::VdV , T> Per_Component_Division( const Vector<T>& TWO ){

			Store::Expression< Store::VdV , T > RES( Store::VdV( *this,TWO) );

			return RES;

		}


			template<class B>
		///Esta funcion realiza una division componente a componente.
		///
		///Alias de operador /
		inline Store::Expression<Store::VdE , T> Per_Component_Division( const Store::Expression<B , T>& TWO ){

			Store::Expression< Store::VxE , T > RES( Store::VxE(*this,TWO) );

			return RES;

		}


			template<class A>
		///Esta funcion realiza una division componente a componente.
		///
		///Alias de operador /
		inline friend Store::Expression<Store::EdV , T> Per_Component_Division( const Store::Expression<A , T>& , const Vector<T>& );


			template<class A, class B>
		///Esta funcion realiza una division componente a componente.
		///
		///Alias de operador /
		inline friend Store::Expression<Store::EdE , T> Per_Component_Division( const Store::Expression<A , T>& , const Store::Expression<B , T>& );

		///Esta funcion realiza una division componente a componente.
		///
		///Importante: Static.
		///
		///Alias de operador /
		static Vector<T> Per_Component_Division( const Vector<T> & , const Vector<T> & );

		///Este funcion realiza la operacion de producto punto o escalar.
		///@param Vector<T>  El operando derecho
		///@return T 
		T Point_Product( const Vector<T> & );

		///Este funcion realiza la operacion de producto punto o escalar.
		///
		///Importante: Static.
		///
		///@param Vector<T>  El operando izquierdo
		///@param Vector<T>  El operando derecho
		///@return T
		static T Point_Product( const Vector<T> &, const Vector<T> & );

		///Sobrecarga el operador % con la operacion de producto cruz.
		///@param Vector<T>  El operando derecho
		///@return Vector<T>
		Vector<T> operator%( const Vector<T> & );

		///Esta funcion realiza un producto cruz.
		///@param Vector<T>  El operando derecho
		///@return Vector<T>
		Vector<T> Cross( const Vector<T> & );

		///Esta funcion realiza un producto cruz.
		///
		///Importante: Static.
		///
		///@param Vector<T>  El operando derecho
		///@return Vector<T>
		static Vector<T> Cross( const Vector<T> & A , const Vector<T> & B );

		///Devuelve la componente que se pase como argumento.
		///@param pos  La posicion de la componente que se desea
		///@return const T
		///
		///- Importante: Base Cero
		inline T& operator[](int) const;

		///Operador de conjuncion( Y )
		///Considera 1 o mas verdadero y 0 falso, aplica un operador conjuncion( Y ) con este criterio.
		///Se realiza componente a componente.
		///@param Vector<T>  El operando derecho
		///@return Vector<T>  Otro Vector con el operador aplicado
		Store::Vector<T> operator&&(const Store::Vector<T>&);

									//Estos operadores = se mantienen por robustes y versatilidad
									//Pero no son para nada nesesarios en las expresiones
									//Ya que las expresiones se manejan con Expressions

		///Operador de asignaicon.
		///@param Plus< Vector<T> , Vector<T> , T , T >  Un un objeto Plus
		///@return Vector<T>  El vector resultante de la operacion
		///
		///- Importante: Tener presente que este operador sera el cuello de botella, ya
		///que aca es donde realmente se resuelve la expression, con todos sus operadores.
		///Las demas operaciones solo se dedican a crear las estructuras de arboles para este momento.
		inline Store::Vector<T>& operator=( const Store::Plus<Store::Vector<T>,Store::Vector<T>,T,T>& );

		///Operador de asignaicon.
		///@param Minus< Vector<T> , Vector<T> , T , T >  Un un objeto Plus
		///@return Vector<T>  El vector resultante de la operacion
		///
		///- Importante: Tener presente que este operador sera el cuello de botella, ya
		///que aca es donde realmente se resuelve la expression, con todos sus operadores.
		///Las demas operaciones solo se dedican a crear las estructuras de arboles para este momento.
		inline Store::Vector<T>& operator=( const Store::Minus<Store::Vector<T>,Store::Vector<T>,T,T>& );

									//Fin de Operadores = no nesesarios en expresiones


			template<class B>
		///Operador de asignaicon.
		///@param Expression< B , T >  Un un objeto Expression
		///@return Vector<T>  El vector resultante de la operacion
		///
		///- Importante: Tener presente que este operador sera el cuello de botella, ya
		///que aca es donde realmente se resuelve la expression, con todos sus operadores.
		///Las demas operaciones solo se dedican a crear las estructuras de arboles para este momento.
		inline Store::Vector<T>& operator=( const Store::Expression< B , T >& E ){
		
			int newLength = E.Length();

			//si no tiene la misma cantidad de elementos entonces re-dimensino el arreglo y lo asigno
			if(this->Componentes != newLength){

				this->Dispose_Array();

				this->Renew_Array(newLength);
	
			}

			
		

			for( int i=0;( i < this->Componentes ); i++)
				this->MC[0][i] = E[i];

			return (*this);


		}

		///Operador de asignaicon.
		///@param Vector< T >  Un un objeto Vector
		///@return Vector<T>  El vector resultante de la operacion
		///
		///- Importante: Tener presente que este operador sera el cuello de botella, ya
		///que aca es donde realmente se resuelve la expression, con todos sus operadores.
		///Las demas operaciones solo se dedican a crear las estructuras de arboles para este momento.
		inline Store::Vector<T>& operator=( const Store::Vector<T>& V ){

			
			int newLength = V.Length();

				//si tienen distinta dimension entonces lo re-dimensiona
			if(this->Componentes != newLength){

				this->Dispose_Array();

				this->Renew_Array(newLength);
		
			}
		

			for( int i=0;( i < this->Componentes ); i++)
				this->MC[0][i] = V[i];

			return (*this);

		}

		///Llena el vector con datos aleatorios, utilizando la funcion rand.
		///@param min  Es el valor minimo
		///@param min  Es el valor maximo
		///@return void
		///
		///- Importante: Utiliza la funcion Time( NULL ) como semilla de rand()
		void Random( T, T);

		///Este metodo devuelve un Header con toda la informacion del vector.
		///Es especial para la salida y entrada, comparando los structs Headers,
		///pero otro uso es para recibir un detalle completo de la constitucion y tipos del Vector
		///@return Header
		///Puede llegar a devolver un Header lleno de ?(a exepcion de las dimensiones que si las completa siempre) 
		///esto quiere decir que el tipo de vector es inexportable a un header, pero esto jamas deveria de suceder
		Store::Header Get_Type();

		
		
	};

	//-------------------------------------------------------------------------------------------------------------





	//Vector Friend Functions:

//Operacion de Suma
	template<class A, class T>
inline Store::Expression<Store::EpV, T> operator+( const Store::Expression<A , T> & , const Vector<T> &);

	template<class A, class B, class T>
inline Store::Expression<Store::EpE, T> operator+( const Store::Expression<A , T>& , const Store::Expression<B , T>&);

//Operacion de Resta
	template<class A, class T>
inline Store::Expression<Store::EmV, T> operator-( const Store::Expression<A , T> & , const Vector<T> &);

	template<class A, class B, class T>
inline Store::Expression<Store::EmE, T> operator-( const Store::Expression<A , T>& , const Store::Expression<B , T>&);

//Operacion de Producto
	template<class A, class T>
inline Store::Expression< Store::ExV , T> operator*( const Store::Expression<A , T>& , const Store::Vector<T>& );

	template<class A, class B, class T>
inline Store::Expression< Store::ExE , T> operator*( const Store::Expression<A , T>& , const Store::Expression<B , T>& ); 

//Operacion de Division
	template<class A, class T>
inline Store::Expression< Store::ExV , T> operator/( const Store::Expression<A , T>& , const Store::Vector<T>& );

	template<class A, class B, class T>
inline Store::Expression< Store::ExE , T> operator/( const Store::Expression<A , T>& , const Store::Expression<B , T>& ); 

//Operacion de Producto/Funcion
	template<class A, class T>
inline Store::Expression<Store::EdV , T> Per_Component_Division( const Store::Expression<A , T>& , const Vector<T>& );

	template<class A, class B, class T>
inline Store::Expression<Store::EdE , T> Per_Component_Division( const Store::Expression<A , T>& , const Store::Expression<B , T>& );

//Operacion de producto por un escalar
	template<class A, class T>
inline Store::Expression< Store::ExT , T> operator*( const Store::Expression< A , T >& , const T );
		
	template<class T>
inline Store::Expression< Store::TxV , T> operator*( const T , const Store::Vector<T>& );

	template<class B, class T>
inline Store::Expression< Store::TxE , T> operator*( const T , const Store::Expression<B , T>& ); 

//Operacion de division por un escalar
	template<class A, class T>
inline Store::Expression< Store::EdT , T> operator/( const Store::Expression< A , T >& , const T );
		
	template<class T>
inline Store::Expression< Store::TdV , T> operator/( const T , const Store::Vector<T>& );

	template<class B, class T>
inline Store::Expression< Store::TdE , T> operator/( const T , const Store::Expression<B , T>& ); 

//End of Vector Friend Function