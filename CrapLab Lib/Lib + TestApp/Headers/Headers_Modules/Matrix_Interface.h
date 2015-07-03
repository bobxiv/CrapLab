	///Dice si es que se opera en las filas o en las columnas.
	///Este enum tiene sentido solo para Matrix y MatrixX.
	enum FILACOLUMNA{fila,columna};


	

		template <class T>
		///Clase templatizada disenada con todos los miembros y operaciones concernientes a una Matriz.
		///Es una de las clases mas etensas. Hereda de Custom_Storage.
		///
///Sus mienbros son:
	///- Datos de matriz de 2x2(de 2 dimensines)
	///- Cantidad de Filas
	///- Cantidad de Columnas
///Algunas de sus operaciones son:
	///- Resolucion de sistemas de varias variables por varios metodos
	///- Determinante
	///- Inversa
	///- Transposicion
	///- Operaciones elementales
	///- Cofactores
	///- Menores
	///- Etc
	///
	///Importante: Tambien esta preparada para representar vectores y sus operaciones
	///@author Emmanuel Rojas Fredini
	class Matrix : public CustomStorage<T>{
protected:

	/*
	Es un puntero a puntero, que apunta a la matriz de datos organizados
	T** MC;

	Este miemro se hereda de CustomStorage
	*/

	///Entero qeu posee la cantidad de filas de la matiz
	int F;

	///Entero qeu posee la cantidad de columnas de la matiz
	int C;

	/*esta funcion calcula una comonente de el resultado de un producto matricial
	por medio de recursividad, la utilisa exclusivamente el 
	operador /(se supone que se sabe que no esta definida la division para matrices), 
	que tiene el propocito de probar la diferencia de rendimiento entre una solucion 
	convencional, for's, y una recursiva al producto matricial
	sus parametros son, fila, columna(estos del elemento que se va a calcular),
	el k, que se va incrementando hasta que llega a el valor final, es decir cant.
	de columnas de matriz 1 o cant. de fials de matriz 2, y la segunda matriz,
	la primera es ella misma	
	*/
	T producto_componente(int,int,int,const Matrix<T>&);

	//Este metodo privado muetra por el flujo estandar de salida cout que se efectuo una
	//operacion de Suma Matricial, relacionado con el metodo sum_ma
	//Recibe:
	//-Un entero diciendo si se realizo por fila o por columna, 0 e 1 respectivamente. 
	//Dependiendo de esto sera R o C el identificador de operacion
	//-Un entero que dice cual fue la Fila/Columna Origen, ie la que se multiplica por el escalar y luego se suma
	//-Un entero que dice cual fue la Fila/Columna Destino, ie cual fue la que al final se modificara
	//-Un valor T que dice cual fue el escalar que afecto al segundo parametro
	//-Un ostream que determina por donde se hara la salida
	//Por defecto el escalar es 1 o equivalente
	//Por defecto la salida es por el flujo estandar cout
	//El formato de salida es: (R/Ci + esc*R/Cj) <-> (R/Ci) 
	//
	//Devuelve void
	//Ayuda al Metodo Gauss_View
	void Show_sum_ma(Store::FILACOLUMNA , int,int, T = 1, std::ostream& = std::cout);

	//Este metodo privado muetra por el flujo estandar de salida cout que se efectuo una
	//operacion de Resta Matricial, relacionado con el metodo res_ma
	//Recibe:
	//-Un entero diciendo si se realizo por fila o por columna, 0 e 1 respectivamente. 
	//Dependiendo de esto sera R o C el identificador de operacion
	//-Un entero que dice cual fue la Fila/Columna Origen, ie la que se multiplica por el escalar y luego se resta
	//-Un entero que dice cual fue la Fila/Columna Destino, ie cual fue la que al final se modificara
	//-Un valor T que dice cual fue el escalar que afecto al segundo parametro
	//-Un ostream que determina por donde se hara la salida
	//Por defecto el escalar es 1 o equivalente
	//Por defecto la salida es por el flujo estandar cout
	//El formato de salida es: (R/Ci - esc*R/Cj) <-> (R/Ci) 
	//
	//Devuelve void
	//Ayuda al Metodo Gauss_View
	void Show_res_ma(Store::FILACOLUMNA ,int,int, T = 1, std::ostream& = std::cout);

	//Este metodo privado muetra por el flujo estandar de salida cout que se efectuo una
	//operacion de Intercambio Matricial, relacionado con el metodo int_ma
	//Reciebe:
	//-Un entero diciendo si se realizo por fila o por columna, 0 e 1 respectivamente. 
	//Dependiendo de esto sera R o C el identificador de operacion
	//-Un entero que dice cual fue la Fila/Columna Origen
	//-Un entero que dice cual fue la Fila/Columna Destin
	//-Un ostream que determina por donde se hara la salida
	//Por defecto la salida es por el flujo estandar cout
	//El formato de salida es: (R/Ci) <-> (R/Cj) 
	//
	//Devuelve void
	//Ayuda al Metodo Gauss_View
	void Show_int_ma(Store::FILACOLUMNA, int,int, std::ostream& = std::cout);
		
public:
	
	///Calcula la inversa de una matriz utilizando la adjunta de la matriz y el determinante
	///Devuelve una matriz, que es inversa de la de llamada
	///El rendimiento de este metodo no es optimo, porque utiliza recursividad
	///
	///El calculo es:		INV = (1/DET) * ADJ
	///
	///@return Matrix<T>
	Matrix<T> inv();
	
	///Calcula la adjunta de la matriz que la llama, utiliza el calculo de cofactores
	///y la transpuesta
	///Devuelve una matriz, que es la adjunta calculada
	///
	///El calculo es:		(matriz de cofactores)t
	///
	///@return Matrix<T>
	Matrix<T> adj();
	
	///Calcula el menor de la matriz MCij. 
	///
	///Notar que el menor es una matriz de F-1 y C-1
	///
	///@param int la posicion i de la componente
	///@param int la posicion j de la componente
	///@return Matrix<T> el menor de la componente
	Matrix<T> menor(int, int);
	
	///Calcula el cofactor de una componene
	///El rendimiento de este metodo no es optimo, porque utiliza recursividad
	///
	///Notar que un cofactor es una componente
	///
	///@param int la posicion i de la componente
	///@param int la posicion j de la componente
	///@return T
	T cofac(int,int);
	
	///Calcula el determinante de una matriz, porsupuesto que la matriz debe ser cuadrada,de no serlo, no estaria definido el determinante, directamente no haria nada 
	///Este metodo es recursivo, asi que su rendimiento no es optimo
	///
	///Por defecto: expande por fila, el contador es 1(no se debe alterar), la fila o columna por la que se expande es la primera
	///
	///@param FILACOLUMNA le dice por que expandir,si por filas o por columnas, 0 y 1 respectivamente
	///(si es 0 lo hace por filas, si es 1 lo hace por columnas)
	///@param int le dice por que fila o columna hacer la expancion por cofactores, si es por fila o por columnadepende del paremetro anterior               
	///@param int=1 contador,que determina un final de las llamadas, por defecto es 1, y SIEMPRE debe de ser este, de no serlo no funcionaria correctamente
	///@return T el valor  del determinante. Si no se pudo ejecutar devuelve 0 o equivalente
	T det(FILACOLUMNA, int,int = 1);
	
	///Saca una fila de una matriz.
	///@param int numero de fila que se desea sacar
	///@return int 0 si no se pudo ejecutar o 1 si pudo
	///
	///Nombre Completo: Fila Out
	int Fout(int);
	
	///Saca una columna de una matriz.
	///@param int numero de columna que se desea sacar
	///@return int 0 si no se pudo ejecutar o 1 si pudo
	///
	///Nombre Completo: Columna Out
	int Cout(int);

	///Devuelve la cantidad de filas que tiene la matriz
	inline int Get_F();

	///Devuelve la cantidad de columnas que tiene la matriz
	inline int Get_C();

	///Devuelve el valor de una componente
	///@param int la posicion i de la componente
	///@param int la posicion j de la componente
	///@return T la componente
	inline T Get_Component( int, int ) const;
	
	///Muestra la cantidad de filas
	///@param std::ostream ostream por el cual saldra, por defecto std::cout
	///@return void
	void Show_F( std::ostream& = std::cout );

	///Muestra la cantidad de columnas
	///@param std::ostream ostream por el cual saldra, por defecto std::cout
	///@return void
	void Show_C( std::ostream& = std::cout );

	//OPERACION ELEMENTAL: La funcion ejecuta la operacion en una matriz de producto por un escalar
	//Recibe:
	//-Un entero que dice si se aplica a filas o columnas, 0 o 1 respectivamente
	//-El numero de fila o columna que se afectara, de que sea fila o columna depende del primer parametro
	//-El valor del escalar por el que se multiplicara la fila o columna
	//por que escalar se multiplicara
	//Por defecto el escalar es 1 u equivalente
	//Devuelve void
	//
	//Nombre Completo: Producto Matricial
	void prod_ma (FILACOLUMNA,int,T = 1);
	
	//OPERACION ELEMENTAL: La funcion ejecuta la operacion en una matriz de producto 
	//por un escalar y luego suma a otra fila columna
	//Recibe:
	//-Un entero que dice si se aplica a filas o columnas, 0 o 1 respectivamente
	//-El numero de fila o columna(de que sea fila o columna depende del primer parametro) 
	//que se afectara por el escalar, y que luego se sumara a la otra fila o columna. 
	//IE Fila/Columna Origen
	//-El numero de fila o columna a la que se sumara la fila o columna del segundo parametro.
	//Esta es en fin la fila/columna que se modificara en la matriz resultado. 
	//IE Fila/Columna Destino
	//-El valor del escalar por el que se multiplicara la Fila/Columna Origen antes de sumarla
	//Por defecto el escalar es 1 u equivalente
	//Devuelve void
	//
	//Nombre Completo: Suma Matricial
	inline void sum_ma(FILACOLUMNA,int,int,T=1);
	//Es inline para mejorar el rendimiento ed otras funciones que precisan ser particularmente rapidas

	//OPERACION ELEMENTAL: La funcion ejecuta la operacion en una matriz de producto 
	//por un escalar y luego resta a otra fila columna
	//Recibe:
	//-Un entero que dice si se aplica a filas o columnas, 0 o 1 respectivamente
	//-El numero de fila o columna(de que sea fila o columna depende del primer parametro) 
	//que se afectara por el escalar, y que luego se sumara a la otra fila o columna. 
	//IE Fila/Columna Origen
	//-El numero de fila o columna a la que se restara la fila o columna del segundo parametro.
	//Esta es en fin la fila/columna que se modificara en la matriz resultado. 
	//IE Fila/Columna Destino
	//-El valor del escalar por el que se multiplicara la Fila/Columna Origen antes de restarla
	//Por defecto el escalar es 1 u equivalente
	//Devuelve void
	//
	//Nombre Completo: Resta Matricial
	inline void res_ma(FILACOLUMNA,int,int,T=1);
	//Es inline para mejorar el rendimiento ed otras funciones que precisan ser particularmente rapidas
	
	//OPERACION ELEMENTAL: La funcion ejecuta la operacion en una matriz de intercambio
	//entre dos filas o columnas.
	//Recibe:
	//-Un entero, que si es 0 ejecuta para filas, y si es 1 ejecuta para columnas
	//-Un entero, que dice que fila columna se intercambiara. IE Fila/Columna Origen
	//-Un entero, que dice que fila columna se intercambiara. IE Fila/Columna Destino
	//Devuelve void
	//
	//Nombre Completo: Intercambio Matricial
	inline void int_ma(FILACOLUMNA,int,int);
	//Es inline para mejorar el rendimiento ed otras funciones que precisan ser particularmente rapidas
	
	/*CONSTRUCTOR: Este es un constructor por defecto, no ejecuta ninguna operacion
	*/
	Matrix();
	
	//CONSTRUCTOR: Este constructor inicializa una matriz de dos dimensiones, que se pasan por parametro
	//e inicializa todas las componentes en 0
	//Recibe:
	//-Un entero que establece la cantidad de filas de la matriz
	//-Un entero que establece la cantidad de columnas de la matriz
	Matrix(int,int);
	
	//CONSTRUCTOR: Este es un constructor de copia. La matriz generada tendra
	//las mismas dimensiones la matriz del parametro 
	Matrix(const Matrix &);
	
	//CONSTRUCTOR: Este constructor genera una matriz cuadrada de nxn, siendo n el parametro.
	//Tener en cuanta uqe la matriz tendra 1 o equivalente en la diagonal principal y
	//0 o equivalente en el resto d componentes
	
	Matrix(int);
	
	//Gausea la matriz, por medio de operaciones elementales entre filas
	//Este metodo no pivotea ni parcialmente ni parcial escaladamente
	//Devuelve la matriz origibal, ie la matriz antes de ser gausada
	//
	//Importante: Gausea in-place
	Matrix<T> Gauss();

	//Gausea la matriz, por medio de operaciones elementales entre filas
	//Este metodo pivotea parcialmente, por esto es mas preciso que el metodo Gauss
	//Devuelve la matriz origibal, ie la matriz antes de ser gausada
	//
	//Importante: Gausea in-place
	//Nombre Completo: Gauss Pivoteo Parcial
	Matrix<T> Gauss_PP();

	//Este metodo resuelve el sistema lineal
	//Este metodo no pivotea ni parcialmente ni parcial escaladamente para la resolucion
	//Importante: Este metodo considera que la matriz en la que se la aplique ya esta aumentada	
	//y gausea la matriz que lo llama
	//Devuelve Un vector que contiene las soluciones
	Vector<T> Resolve();

	//Este metodo resuelve el sistema lineal
	//Este metodo pivotea parcialmente para la resolucion
	//Importante: Este metodo considera que la matriz en la que se la aplique ya esta aumentada	
	//y gausea la matriz que lo llama
	//Devuelve Un vector que contiene las soluciones
	//Nombre Completo: Resolucion Pivoteo Parcial
	Vector<T> Resolve_PP();

	//Hace la sustitucion para atras considerando que la ultima columna es la independiente
	//Y adeamas la matriz se supone ya gauseada por algun metodo
	//No supone cambios a la matriz que llama este metodo
	inline Store::Vector<T> BackwardSustitution();

	//Hace la sustitucion para atras
	//Recibe:
	//-La matrix NO aumentada
	//-El vector independiente, de incognitas
	//No supone cambios a los parametros
	inline static Store::Vector<T> BackwardSustitution( Store::Matrix<T>& , Store::Vector<T>& );

	//Hace la sustitucion para atras
	//Recibe:
	//-La matrix NO aumentada
	//-El vector independiente con formato Matrix, que contiene las incognitas
	//No supone cambios a los parametros
	inline static Store::Vector<T> BackwardSustitution( Store::Matrix<T>& , Store::Matrix<T>& );

	//Este metodo gausea la matriz, y va mostrando paso a paso como se va modificando
	//la matriz, y que operacion se realizo. Las salidas son por el parametro ostream que se le pase
	//Pero tener en cuenta que apesar de Tener resultados parecidos a el metodo Gauss
	//este los va mostrando a medida que lo hace, por eso solo se debe usar para ver los pasos
	//y no para calcular, utilizar metodo Gauss para eso
	//Recibe:
	//-Un ostream por donde se hara la salida
	//Por defecto el ostream es el flujo estandar de salida cout
	//Devuelve la matriz original, ie la matriz antes de ser gauseada
	//Importante: para el desarrollo con getch(), acelera el proceso si se oprime suprimir
	//Si permite omitir los el mostrar los pasos siguientes
	//
	//Importante: Gausea in-place
	Matrix<T> Gauss_View( std::ostream& = std::cout );

	//Este metodo gausea la matriz, y va mostrando paso a paso como se va modificando
	//la matriz, y que operacion se realizo. Las salidas son por el fujo estandar cout
	//Pero tener en cuenta que apesar de Tener resultados parecidos a el metodo Gauss
	//este los va mostranod a medida que lo hace, por eso solo se debe usar para ver los pasos
	//y no para calcular, utilizar metodo Gauss para eso
	//Devuelve la matriz origibal, ie la matriz antes de ser gausada
	//Importante: para el desarrollo con system("pause"), por esto solo sirve para la consola
	//No permite omitir los el mostrar los pasos siguientes
	//
	//Importante: Gausea in-place
	Matrix<T> Gauss_View2();

	//Este metodo gausea la matriz, y va mostrando paso a paso como se va modificando
	//la matriz, y que operacion se realizo. Las salidas son por el parametro ostream que se le pase
	//Pero esta funcion no espera a que se presione una tecla para seguir resolviendo 
	//y mostrando sino que lo hace sin esperas, por esto esta funcion es especialmente util
	//para sacar los pasos a archivos externos
	//Recibe:
	//-Un ostream por donde se hara la salida
	//Por defecto el ostream es el flujo estandar de salida cout
	//Devuelve la matriz original, ie la matriz antes de ser gauseada
	//Importante: No tiene interrupciones, ni getch ni system("pause")
	//
	//Importante: Gausea in-place
	Matrix<T> Gauss_View_Instantaniusly( std::ostream& = std::cout );

	//Muestra la matriz por el flujo que se pase por parametro
	//Recibe:
	//-Un entero que establece el valor de la propiedad setw o width, ie el espacio en el que se coloca una salida
	//-Un entero que establece el valor de la propiedad setprecision o precision, ie el numero de decimales despues de la coma decimal
	//-Un ostream por donde se hara la salida
	//Por defecto setw wa 5
	//Por defecto setprecision es 2
	//Por defecto es el flujo estandar de salida cout
	//Devuelve void
	void View( int=7, int=2, std::ostream& = std::cout);

	//Muestra la matriz por el flujo que se pase por parametro
	//Recibe:
	//-Un ostream por donde se hara la salida
	//-Un entero que establece el valor de la propiedad setw o width, ie el espacio en el que se coloca una salida
	//-Un entero que establece el valor de la propiedad setprecision o precision, ie el numero de decimales despues de la coma decimal
	//Por defecto setw wa 5
	//Por defecto setprecision es 2
	//Devuelve void
	void View( std::ostream& , int=7, int=2);
	//Existen dos view variado el orden de los parametros para que sea mas comodo usarlo, si se quire cambiar solo el setw y la presicion, pero no
	//el ostream se puede usar el primero y no pasarle el ostream, va por defecto
	//Si se quiere modificar el ostream pero no el setw ni la presicion entonces se puede usar este segundo se le pasa el ostream
	//y el setw y la presicion van por defecto
	//Si se desea cambiar todo caulquera de las dos servirian
	//Si no se desea cambiar nada entonces se hara una llamada a la primer view, poruqe tiene todos los parametros por defecto
	//y no habra ambiguedad en la llamada, notar que ostream de la segunda funcion no tiene valor por defecto

	
	//Muestra el valor de una componente de la matriz.
	//Recibe:
	//-Un entero que determina el i de la componente
	//-Un entero que determina el j de la componente
	//-Un ostream por el que saldra el resultado
	//Por defecto la salida es por el flujo estandar cout
	//Devuelve 0 si no se pudo ejecutar o 1 si pudo
	//
	//Nombre Completo: View Componente
	int View_Component(int,int, std::ostream& = std::cout);
	//En este caso el view_C no es nesesario otr5o como en el view, poruqe aca solo ostream tiene valores por defecto
	
	//Combierte todas las componentes de la matriz al valor 0 o equivalente.
	//IE hace 0 la matriz
	//Devuelve void
	inline void clean();

	//Combierte todas las componentes de la matriz al valor que se pasa por parametro
	//IE hace (parametro) la matriz
	//Devuelve void
	inline void fill( T );

	//Este metodo llena la matriz con datos aleatorios, utilizando el metodo rand
	//Recibe:
	//-Un dato que es el valor minimo
	//-Un dato que es el valor maximo
	//Devuelve void 
	void Random( T, T);

	//Tranforma la matriz a su transpuesta
	//Devuelve la matriz antes de transponerla
	Matrix<T> trans();
	
	//Transforma la matriz en la matriz identidad correpondiente. Pero teniendo en cuenta que una matriz
	//identidad siempre es cuadrada, de no cumplir con esta condicion la matriz, entonces n se hara nada en la matriz
	//Devuelve 0 si no se pudo ejecutar poruqe la matriz no era cuadrada, o 1 si es que la matriz
	//era cuadrada y se pudo ejecutar la transformacion
	int ident();
	
	//Inserta o mas bien modifica una componente de la matriz, asignandole un nuevo valor.
	//Recibe:
	//-Un valor del tipo que sea la plantilla de la matriz, para que se asigne a la componente
	//-Un entero que determina el i de la componente a modificar
	//-Un entero que determina el j de la componente a modificar
	
	//Inserta un valor en una de las componentres de la matriz
	//Recibe:
	//-El dato que se ingresara
	//-Un entero que determina el valor de la componente i donde se ingresara
	//-Un entero que determina el valor de la componente j donde se ingresara
	//Devuelve 0 si no se pudo ejecutar, o 1 si pudo ejecutar
	int insert(T,int,int);
	
	//Este metodo es muy similar a la funcion de un constructor de copia. Pero no es nesesario que
	//sea una variable nueva para utilizarla. Lo que hace es recibir un arreglo de punteros a punteros
	//como el MC de una matriz, donde se contiene las componentes ordenadas de la matriz. Luego
	//de ser del mismo tamaño la matriz que llama y el arreglo se copia el arreglo del parametro a la matriz
	//que llamo la funcion.
	//Recibe:
	//-Un puntero a punteros, ie MC de una matriz, que es el que sera copiado a la matriz que llama
	//-Un entero que determina las filas del primer parametro
	//-Un entero que determina las columnas del primer parametro
	//
	//IMPORTANTE: la matriz debe ser exactamente del mismo tamaño para que se pueda ejecutar
	//
	//Devuelve 0 si no se pudo ejecutar, o 1 si s pudo ejecutar
	int insert(T**,int,int);
	
	//Multiiplica la matriz por un sierto valor que se pasa por parametro, ie multiplica cada
	//componente de la matriz por ese valor

	//Por defecto el valor es 1 o equivalente

	//Devuelve void
	//
	//Nombre Completo: Producto por un Escalar
	void PDes(T=1 );
	
	//Sobrecarga el operador + como esta definido matematicamente, componente a componente
	Matrix<T> operator +(const Matrix<T> &);//Sobrecargo el operador + para las matrices
	
	//Sobrecarga el operador - multiplicando la segunda matriz por -1 o equivalente, y luego las suma
	Matrix<T> operator -(const Matrix<T> &);//Sobrecarga del operador - para matrices

	//Sobrecarga el operador * para las matrices. Este metodo se encarga del producto
	//en todos los casos definidos por la condicion   Columnas de A = Filas de B
	//La unica exepcion a esto es cuando el producto es entre dos vectores o fila o columna, 
	//es esos casos no hac diferencia y resuelve correctamente el producto
	Matrix<T> operator *(const Matrix<T> &);

	//Esta funcion calcula el producto matricial de la forma tradicional
	//Las matrices deben cumplir:	Columnas de A = Filas de B
	//La unica exepcion a esto es cuando el producto es entre dos vectores o fila o columna, 
	//es esos casos no hac diferencia y resuelve correctamente el producto
	//Recibe:
	//-La matriz por la que se multiplicara la que llame la funcion
	//Devuelve la matriz resultado
	Matrix<T> Product(const Matrix<T> &);

	//Esta funcion calcula el producto matricial de la forma tradicional
	//Las matrices deben cumplir:	Columnas de A = Filas de B
	//La unica exepcion a esto es cuando el producto es entre dos vectores o fila o columna, 
	//es esos casos no hac diferencia y resuelve correctamente el producto
	//Recibe:
	//-La matriz A que se multiplicara por B		
	//-La matriz B que se multiplicara por A		
	//											A*B
	//Devuelve la matriz resultado
	static Matrix<T> Product(const Matrix<T> &, const Matrix<T> &);

	//Esta funcion realiza un producto componente a componente
	//Las matrices deben ser de la misma dimension
	//Recibe:
	//-Una matriz que se multiplicara a la que llame el metodo
	//Devuelve la matriz producto
	Matrix<T> Per_Component_Product(const Matrix<T> &);

	//Esta funcion recibe las dos matrices que seran los operando
	//luego las multiplica componente a componente
	//Recibe:
	//-La primer matriz a multiplicar
	//-La segunda matriz a multiplicar
	//Devuelve la matriz producto
	static Matrix<T> Per_Component_Product(const Matrix<T> & , const Matrix<T> &);
	
	//Este operador multimplicacion * convencional,
	//la diferencia es que este operador soluciona la multiplicacion de matrices por
	//recursividad, que es claramente mas costosa. El motivo de la existencia de este operador es
	//solamente para visualzar el bajo rendimiento de este con respecto a la solucion por iteraciones
	//
	//IMPORTANTE: Este operador no se debe utilizar para cuestiones practicas, solo para prueba,
	//utilizar para estos casos el operador *
	Matrix<T> operator /(const Matrix<T> &);
	
	//Esta funcion realiza una division componente a componente
	//Las matrices deben ser de la misma dimension
	//Recibe:
	//-Una matriz que se dividira a la que llame el metodo, la matriz denominador
	//Devuelve la matriz cociente
	Matrix<T> Per_Component_Division(const Matrix<T> &);

	//Esta funcion recibe las dos matrices que seran los operando
	//luego las divide componente a componente
	//Recibe:
	//-La primer matriz a dividir, el numerador
	//-La segunda matriz a dividir, el denominador
	//Devuelve la matriz cociente
	static Matrix<T> Per_Component_Division(const Matrix<T> & , const Matrix<T> &);

	//Este operador devuelve el producto cruz entre dos vectores, que deben ser vectores columna o fila, 
	//indistintamente, pero si o si deben ser vectores de 3 componentes, asi calcula el poducto 
	//vectorial de ellos... pero si no son vectores, con cardinalidad adecuada,
	//devuelve un numero 	absolutamente absurdo que es el vector [(-9999),(-9999),(-9999)]
	//En resumen los vecotres deben:
	//-Ser vectores(valga la rebundancia)
	//-Ser ambos de 3 componentes
	//
	//+ De lo contrario se devolvera el vector absurdo [(-9999),(-9999),(-9999)]
	Matrix<T> operator %(const Matrix<T> &);

	//Este operador devuelve el producto cruz entre dos vectores, que deben ser vectores columna o fila, 
	//indistintamente, pero si o si deben ser vectores de 3 componentes, asi calcula el poducto 
	//vectorial de ellos... pero si no son vectores, con cardinalidad adecuada,
	//devuelve un numero 	absolutamente absurdo que es el vector [(-9999),(-9999),(-9999)]
	//En resumen los vecotres deben:
	//-Ser vectores(valga la rebundancia)
	//-Ser ambos de 3 componentes
	//Recibe:
	//-El segundo operando del producto cruz
	//
	//+ De lo contrario se devolvera el vector absurdo [(-9999),(-9999),(-9999)]
	Matrix<T> Cross( const Matrix<T> &);

	//Este operador devuelve el producto cruz entre dos vectores, que deben ser vectores columna o fila, 
	//indistintamente, pero si o si deben ser vectores de 3 componentes, asi calcula el poducto 
	//vectorial de ellos... pero si no son vectores, con cardinalidad adecuada,
	//devuelve un numero 	absolutamente absurdo que es el vector [(-9999),(-9999),(-9999)]
	//En resumen los vecotres deben:
	//-Ser vectores(valga la rebundancia)
	//-Ser ambos de 3 componentes
	//Recibe:
	//-El primer operando del producto cruz
	//-El segundo operando del producto cruz
	//
	//+ De lo contrario se devolvera el vector absurdo [(-9999),(-9999),(-9999)]
	static Matrix<T> Cross(const Matrix<T> &, const Matrix<T> &);
	
};