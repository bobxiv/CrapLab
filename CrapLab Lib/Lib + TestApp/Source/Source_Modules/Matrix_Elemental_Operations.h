	//OPERACION ELEMENTAL
		template <class T>
	void Matrix<T>::prod_ma (FILACOLUMNA rc,int FC,T esc ){
	
		// si es por renglon o por columna
	switch(rc)
	{
	case 0://en el caso que sea por renglones
		{
		
		for(int i=0;(i<C);i++)
		this->MC[FC-1][i] *= esc;
				
		break;
		
		}
	case 1://en el caso que sea por columnas
		{
		for(int i=0;(i<F);i++)
		this->MC[i][FC-1] *= esc;
		
		break;
		
		}
		
	}
	
	
	
}
	
	
	//FCS, es la abreviacion de Fila/Columna Source
	//FCT, es la abreviacion de Fila/Columna Target
		template <class T>
	inline void Matrix<T>::sum_ma(FILACOLUMNA rc,int FCS,int FCT,T esc)
	{
		
		// si es por renglon o por columna
	switch(rc)
	{
	
		
		case 0://si la suma es entre filas
		{
		//crea un vector, que tendra los datos para sumar a FCT, la fila que se modificara
			
		T* aux=new T[C];
		
		//guardo el vector Source con el producto escalar en aux
		for(int j=0;(j<C);j++)
		aux[j] = (esc * this->MC[FCS-1][j]);
	
		//le sumo a Target aux
		for(int j=0;(j<C);j++)
		this->MC[FCT-1][j] += aux[j];//aca por fin suma el vector auxiliar a la fila de la matriz
	
	
		break;
		}

		case 1://se la suma es entre columnas
		{
		//crea un vector, que tendra los datos para sumar a FCT, la columna que se modificara
		
		T* aux2=new T[F];
	
		//guardo vctor Source con el producto escalar en aux2
		for(int i=0;(i<F);i++)
		aux2[i] = (esc*this->MC[i][FCS-1]);
		
		//le sumo a Target aux
		for(int i=0;(i<F);i++)
		this->MC[i][FCT-1] += aux2[i];//aca por fin suma el vector auxiliar a la columna de la matriz
	
	
		break;
		}

	}



}

//FCS, es la abreviacion de Fila/Columna Source
//FCT, es la abreviacion de Fila/Columna Target
	//Nota: no se utiliza sum_ma utilizando el opuesto del escalar, para evitar hacer muchas llamadas a funciones inesesarias
	//Aunque se genere mas codigo
	template<class T>
inline void Matrix<T>::res_ma(FILACOLUMNA rc,int FCS,int FCT,T esc){

// si es por renglon o por columna
	switch(rc)
	{
	
		
		case 0://si la resta es entre filas
		{
		//crea un vector, que tendra los datos para restar a FCT, la fila que se modificara
			
		T* aux=new T[C];
		
		//guardo el vector Source con el producto escalar en aux
		for(int j=0;(j<C);j++)
		aux[j] = (esc * this->MC[FCS-1][j]);
	
		//le sumo a Target aux
		for(int j=0;(j<C);j++)
		this->MC[FCT-1][j] -= aux[j];//aca por fin resta el vector auxiliar a la fila de la matriz
	
	
		break;
		}

		case 1://se la resta es entre columnas
		{
		//crea un vector, que tendra los datos para restar a FCT, la columna que se modificara
			//aux2 no tiene el mismo nombre que aux, apesar de esatr a distintos niveles y no generar conflictos, porque es mas
			//facil confundir case 2 con case 2 si no cambia el nombre de las variables, solo por eso
		T* aux2=new T[F];
	
		//guardo vector Source con el producto escalar en aux2
		for(int i=0;(i<F);i++)
		aux2[i] = (esc*this->MC[i][FCS-1]);
		
		//le resto a Target aux
		for(int i=0;(i<F);i++)
		this->MC[i][FCT-1] -= aux2[i];//aca por fin resta el vector auxiliar a la columna de la matriz
	
	
		break;
		}

	}


}



//FCO, es la abreviacion de Fila/Columna Origen
//FCD, es la abreviacion de Fila/Columna Destino
	template <class T>
inline void Matrix<T>::int_ma(FILACOLUMNA rc,int FCO,int FCD)
{
	
		// si es por renglon o por columna
	switch(rc)
	{	
		
		case fila://intercambio de renglones
		{
		T* aux = new T[C];
		
		
		for(int j=0;(j<C);j++)
		aux[j] = this->MC[FCD-1][j];//copia al vector auxiliar, la fila de destino
		
		for(int j=0;(j<C);j++)
		this->MC[FCD-1][j] = this->MC[FCO-1][j];//copia la fila origen a la fila destino
		
		for(int j=0;(j<C);j++)
		this->MC[FCO-1][j] = aux[j];//copia el vector auxiliar, que tenia la fila destino, a la fila origen
		
		break;
		}

		case columna://intercambio de columnas
		{
		
		T* aux2=new T[F];
		
		
		for(int i=0;(i<F);i++)
		aux2[i] = this->MC[i][FCD-1];//copia al vector auxiliar, la columna de destino
		
		for(int i=0;(i<F);i++)
		this->MC[i][FCD-1] = this->MC[i][FCO-1];//copia la columna origen a la columna destino
		
		for(int i=0;(i<F);i++)
		this->MC[i][FCO-1] = aux2[i];//copia el vector auxiliar, que tenia la columna destino, a la columna origen
		
		break;
		}
		
		
	}
	
	
	
	
	
}
