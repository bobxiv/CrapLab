		template <class T>
	class Vector:public CustomStorage<T>
	{
	private:
		
		int Componentes;

		inline void Dispose_Array();

		inline void Renew_Array(int size);

		inline void Read_Data( Store::Header& , std::ifstream& );

	public:

		friend class Matrix<T>;

		Vector();

		Vector( const Vector<T>& B);
		
		Vector( const Matrix<T>& M );

			template<typename E>
		Vector( Store::Expression<E,T>& Res );

		Vector( int size );

		Vector( const int , const T& );
	
		void Resize(int newsize);

		inline void clean();

		inline void fill( T& newvalue );

		inline void fill( T );

		inline void Fill_Stair(T from,T to,T steep);

		void View(int=7,int=2, std::ostream& = std::cout);

		int To_Bynary( std::string& , std::string& = std::string(".\\Data\\") );

		int From_Binary( std::string& , std::string& = std::string(".\\Data\\") );

		int View_Component( int , std::ostream& = std::cout );

		void Show_C( std::ostream& = std::cout );

		inline T Get_Component( int ) const;

		inline int Get_C() const;

		inline int Length() const;

		int insert(T,int);

		inline Store::Expression< Store::VpV , T > operator+( const Store::Vector<T>& );
		
			template<class B>
		inline Store::Expression< Store::VpE , T > operator+( const Store::Expression< B, T >& );
		
			template<class A>
		inline friend Store::Expression<Store::EpV, T> operator+( const Store::Expression<A , T> & , const Vector<T> &);
		
			template<class A, class B>
		inline friend Store::Expression<Store::EpE, T> operator+( const Store::Expression<A , T>& , const Store::Expression<B , T>&);

		inline Store::Expression< Store::VmV , T > operator-( const Store::Vector<T>& TWO);

			template<class B>
		inline Store::Expression< Store::VmE , T > operator-( const Store::Expression< B, T >& TWO);

			template<class A>
		inline friend Store::Expression<Store::EmV, T> operator-( const Store::Expression<A , T>& ONE , const Vector<T>& TWO);
		
			template<class A, class B>
		inline friend Store::Expression<Store::EmE, T> operator-( const Store::Expression<A , T>& ONE, const Store::Expression<B , T>& TWO);
		
		inline Store::Expression< Store::VxV , T> operator*( const Store::Vector<T>& TWO );

			template<class B>
		inline Store::Expression< Store::VxE , T> operator*( const Store::Expression< B , T >& TWO );

			template<class A>
		inline friend Store::Expression< Store::ExV , T> operator*( const Store::Expression<A , T>& , const Store::Vector<T>& );

			template<class A, class B>
		inline friend Store::Expression< Store::ExE , T> operator*( const Store::Expression<A , T>& , const Store::Expression<B , T>& ); 
		
		inline Store::Expression< Store::VxT , T> operator*( const T TWO );

			template<class A>
		inline friend Store::Expression< Store::ExT , T> operator*( const Store::Expression< A , T >& ONE , const T TWO );
		
		inline friend Store::Expression< Store::TxV , T> operator*( const T ONE , const Store::Vector<T>& TWO );

			template<class B>
		inline friend Store::Expression< Store::TxE , T> operator*( const T ONE , const Store::Expression<B , T>& TWO );

		inline bool operator==( const Store::Vector<T>& TWO )const;

		inline Store::Expression<Store::VxV , T> Per_Component_Product( const Vector<T>& );

			template<class B>
		inline Store::Expression<Store::VxE , T> Per_Component_Product( const Store::Expression<B , T>& );

			template<class A>
		inline friend Store::Expression<Store::ExV , T> Per_Component_Product( const Store::Expression<A , T>& , const Store::Vector<T>& );

			template<class A, class B>
		inline friend Store::Expression<Store::ExE , T> Per_Component_Product( const Store::Expression<A , T>& , const Store::Expression<B , T>& );

		inline static Store::Expression<Store::VxV , T> Per_Component_Product( const Store::Vector<T>& ONE, const Store::Vector<T>& TWO );

			template<class B>
		inline static Store::Expression<Store::VxE , T> Per_Component_Product( const Store::Vector<T>& ONE, const Store::Expression<B , T>& TWO );

			template<class A>
		inline static Store::Expression<Store::ExV , T> Per_Component_Product( const Store::Expression<A , T>& ONE, const Store::Vector<T>& TWO );

			template<class A, class B>
		inline static Store::Expression<Store::ExE , T> Per_Component_Product( const Store::Expression<A , T>& , const Store::Expression<B , T>& );

		inline Store::Expression<Store::VdV , T> Per_Component_Division( const Vector<T>& TWO );

			template<class B>
		inline Store::Expression<Store::VdE , T> Per_Component_Division( const Store::Expression<B , T>& TWO );

			template<class A>
		inline friend Store::Expression<Store::EdV , T> Per_Component_Division( const Store::Expression<A , T>& , const Vector<T>& );

			template<class A, class B>
		inline friend Store::Expression<Store::EdE , T> Per_Component_Division( const Store::Expression<A , T>& , const Store::Expression<B , T>& );

		static Vector<T> Per_Component_Division( const Vector<T> & , const Vector<T> & );

		T Point_Product( const Vector<T> & );

		static T Point_Product( const Vector<T> &, const Vector<T> & );

		Vector<T> operator%( const Vector<T> & );

		Vector<T> Cross( const Vector<T> & );

		static Vector<T> Cross( const Vector<T> & A , const Vector<T> & B );

		inline T& operator[](int) const;

		Store::Vector<T> operator&&(const Store::Vector<T>&);

		inline Store::Vector<T>& operator=( const Store::Plus<Store::Vector<T>,Store::Vector<T>,T,T>& );

		inline Store::Vector<T>& operator=( const Store::Minus<Store::Vector<T>,Store::Vector<T>,T,T>& );


			template<class B>
		inline Store::Vector<T>& operator=( const Store::Expression< B , T >& E );

		inline Store::Vector<T>& operator=( const Store::Vector<T>& V );

		void Random( T, T);

		Store::Header Get_Type();

		
		
	};

	//-------------------------------------------------------------------------------------------------------------




	template<class A, class T>
inline Store::Expression<Store::EpV, T> operator+( const Store::Expression<A , T> & , const Vector<T> &);

	template<class A, class B, class T>
inline Store::Expression<Store::EpE, T> operator+( const Store::Expression<A , T>& , const Store::Expression<B , T>&);

	template<class A, class T>
inline Store::Expression<Store::EmV, T> operator-( const Store::Expression<A , T> & , const Vector<T> &);

	template<class A, class B, class T>
inline Store::Expression<Store::EmE, T> operator-( const Store::Expression<A , T>& , const Store::Expression<B , T>&);

	template<class A, class T>
inline Store::Expression< Store::ExV , T> operator*( const Store::Expression<A , T>& , const Store::Vector<T>& );

	template<class A, class B, class T>
inline Store::Expression< Store::ExE , T> operator*( const Store::Expression<A , T>& , const Store::Expression<B , T>& ); 

	template<class A, class T>
inline Store::Expression< Store::ExV , T> operator/( const Store::Expression<A , T>& , const Store::Vector<T>& );

	template<class A, class B, class T>
inline Store::Expression< Store::ExE , T> operator/( const Store::Expression<A , T>& , const Store::Expression<B , T>& ); 

	template<class A, class T>
inline Store::Expression<Store::EdV , T> Per_Component_Division( const Store::Expression<A , T>& , const Vector<T>& );

	template<class A, class B, class T>
inline Store::Expression<Store::EdE , T> Per_Component_Division( const Store::Expression<A , T>& , const Store::Expression<B , T>& );

	template<class A, class T>
inline Store::Expression< Store::ExT , T> operator*( const Store::Expression< A , T >& , const T );
		
	template<class T>
inline Store::Expression< Store::TxV , T> operator*( const T , const Store::Vector<T>& );

	template<class B, class T>
inline Store::Expression< Store::TxE , T> operator*( const T , const Store::Expression<B , T>& ); 

	template<class A, class T>
inline Store::Expression< Store::ExT , T> operator/( const Store::Expression< A , T >& , const T );
		
	template<class T>
inline Store::Expression< Store::TxV , T> operator/( const T , const Store::Vector<T>& );

	template<class B, class T>
inline Store::Expression< Store::TxE , T> operator/( const T , const Store::Expression<B , T>& ); 

