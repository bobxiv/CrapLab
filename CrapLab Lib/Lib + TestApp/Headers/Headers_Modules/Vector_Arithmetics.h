	template<class A, class T>
inline Store::Expression<Store::EpV, T> operator+( const Store::Expression<A , T>& ONE , const Vector<T>& TWO){

	Store::Expression<Store::EpV , T> RES( Store::EpV(ONE , TWO) );

	return RES;

}

	template<class A, class B, class T>
inline Store::Expression<Store::EpE, T> operator+( const Store::Expression<A , T>& ONE , const Store::Expression<B , T>& TWO){

	Store::Expression<Store::EpE , T> RES( Store::EpE(ONE , TWO) );

	return RES;

}


	template<class T>
inline Store::Expression< Store::VpV , T > Store::Vector<T>::operator+( const Store::Vector<T>& TWO ){
	
		Store::Expression< Store::VpV , T > RES( Store::VpV(*this,TWO) );
		
		return RES;
	
}

	template<class T,class B>
inline Store::Expression< Store::VpE , T > operator+( const Store::Expression<B , T>& TWO ){

		Store::Expression< Store::VpE , T > RES( Store::VpE(*this,TWO) );

		return RES;

}


	template<class A, class T>
inline Store::Expression< Store::ExV , T> operator*( const Store::Expression<A , T>& ONE , const Store::Vector<T>& TWO ){

		Store::Expression< Store::ExV , T > RES( Store::ExV(ONE,TWO) );

		return RES;

}

	template<class A, class B, class T>
inline Store::Expression< Store::ExE, T> operator*( const Store::Expression<A , T>& ONE , const Store::Expression<B , T>& TWO){

	Store::Expression<Store::ExE , T> RES( Store::ExE(ONE , TWO) );

	return RES;

}

	template<class A, class T>
inline Store::Expression< Store::ExV , T> operator/( const Store::Expression<A , T>& ONE , const Store::Vector<T>& TWO ){

		Store::Expression< Store::EdV , T > RES( Store::EdV(ONE,TWO) );
		
		return RES;

}

	template<class A, class B, class T>
inline Store::Expression< Store::ExE, T> operator/( const Store::Expression<A , T>& ONE , const Store::Expression<B , T>& TWO){

	Store::Expression<Store::EdE , T> RES( Store::EdE(ONE , TWO) );

	return RES;

}



	template<class A, class T>
inline Store::Expression<Store::ExV, T> Per_Component_Product( const Store::Expression<A , T>& ONE , const Vector<T>& TWO){

	Store::Expression<Store::ExV , T> RES( Store::ExV(ONE , TWO) );

	return RES;

}

	template<class A, class B, class T>
inline Store::Expression<Store::ExE, T> Per_Component_Product( const Store::Expression<A , T>& ONE , const Store::Expression<B , T>& TWO){

	Store::Expression<Store::ExE , T> RES( Store::ExE(ONE , TWO) );

	return RES;

}


	template<class T>
inline Store::Expression< Store::VxV , T > Store::Vector<T>::Per_Component_Product( const Store::Vector<T>& TWO ){
	
		Store::Expression< Store::VxV , T > RES( Store::VxV(*this,TWO) );
		
		return RES;
	
}

	template<class T,class B>
inline Store::Expression< Store::VxE , T > Per_Component_Product( const Store::Expression<B , T>& TWO ){

		Store::Expression< Store::VxE , T > RES( Store::VxE(*this,TWO) );

		return RES;

}




	template<class A, class T>
inline Store::Expression<Store::EdV , T> Per_Component_Division( const Store::Expression<A , T>& ONE , const Vector<T>& TWO ){

		Store::Expression< Store::ExV , T > RES( Store::ExV(ONE,TWO) );

		return RES;

}

	template<class A, class B, class T>
inline Store::Expression<Store::EdE , T> Per_Component_Division( const Store::Expression<A , T>& ONE , const Store::Expression<B , T>& TWO ){

		Store::Expression< Store::ExE , T > RES( Store::ExE(ONE,TWO) );

		return RES;

}