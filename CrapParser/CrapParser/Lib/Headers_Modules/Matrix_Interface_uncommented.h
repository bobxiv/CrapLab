	enum FILACOLUMNA{fila,columna};

	

		template <class T>
	class Matrix : public CustomStorage<T>{
protected:

	int F;

	int C;

	T producto_componente(int,int,int,const Matrix<T>&);

	void Show_sum_ma(Store::FILACOLUMNA , int,int, T = 1, std::ostream& = std::cout);

	void Show_res_ma(Store::FILACOLUMNA ,int,int, T = 1, std::ostream& = std::cout);

	void Show_int_ma(Store::FILACOLUMNA, int,int, std::ostream& = std::cout);
		
public:

	friend class Vector<T>;

	Matrix<T> inv();
	
	Matrix<T> adj();
	
	Matrix<T> menor(int, int);
	
	T cofac(int,int);
	
	T det(FILACOLUMNA, int,int = 1);
	
	int Fout(int);
	
	int Cout(int);

	inline int Get_F()const;

	inline int Get_C()const;

	inline T& Get_Component( int, int ) const;
	
	void Show_F( std::ostream& = std::cout );

	void Show_C( std::ostream& = std::cout );

	void prod_ma (FILACOLUMNA,int,T = 1);
	
	inline void sum_ma(FILACOLUMNA,int,int,T=1);

	inline void res_ma(FILACOLUMNA,int,int,T=1);

	inline void int_ma(FILACOLUMNA,int,int);

	Matrix();
	
	Matrix(int,int);
	
	Matrix(const Matrix &);

	Matrix(const Vector<T> &V);
	
	Matrix(int);
	
	Matrix<T> Gauss();

	Matrix<T> Gauss_PP();

	Vector<T> Resolve();

	Vector<T> Resolve_PP();

	inline Store::Vector<T> BackwardSustitution();

	inline static Store::Vector<T> BackwardSustitution( Store::Matrix<T>& , Store::Vector<T>& );

	inline static Store::Vector<T> BackwardSustitution( Store::Matrix<T>& , Store::Matrix<T>& );

	Matrix<T> Gauss_View( std::ostream& = std::cout );

	Matrix<T> Gauss_View2();

	Matrix<T> Gauss_View_Instantaniusly( std::ostream& = std::cout );

	void View( int=7, int=2, std::ostream& = std::cout);

	void View( std::ostream& , int=7, int=2);

	int View_Component(int,int, std::ostream& = std::cout);

	inline void clean();

	inline void fill( T );

	void Random( T, T);

	Matrix<T> trans();
	
	int ident();

	int insert(T,int,int);

	int insert(T**,int,int);

	void PDes(T=1 );

	Matrix<T> operator +(const Matrix<T> &);

	Matrix<T> operator -(const Matrix<T> &);

	Matrix<T> operator *(const Matrix<T> &);

	Matrix<T> operator *(const T );

	friend Matrix<T> operator*(const T , const Matrix<T> &);

	Matrix<T> Product(const Matrix<T> &);

	static Matrix<T> Product(const Matrix<T> &, const Matrix<T> &);

	Matrix<T> Per_Component_Product(const Matrix<T> &);

	static Matrix<T> Per_Component_Product(const Matrix<T> & , const Matrix<T> &);

	Matrix<T> operator /(const Matrix<T> &);

	Matrix<T> Per_Component_Division(const Matrix<T> &);

	static Matrix<T> Per_Component_Division(const Matrix<T> & , const Matrix<T> &);

	Matrix<T> Per_Component_Potence(const Matrix<T> &);
	
	Matrix<T> operator %(const Matrix<T> &);

	Matrix<T> Cross( const Matrix<T> &);

	static Matrix<T> Cross(const Matrix<T> &, const Matrix<T> &);
	
};