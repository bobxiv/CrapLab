using System.IO;
using Microsoft.Xna.Framework.Graphics;

namespace Data_Loader
{

    	    //Formato del encabezado de los .crap u demas archivos de exportacion de Vectores o Matrices
    //para algunos casos no todos los valores son nesesarios
    struct Header{
    //Guarda:
    //- 'M' si es matriz
    //- 'V' si es vector
    private char _Kind;
        public char Kind
        {
            get { return this._Kind; }
            set { this._Kind = (char)value; }
        }

        //Guarda:
    //- Numero de componentes si es Vector
    //- Numero de filas si es Matriz
    //Abreviaicon de First Dimension
    private int _First_D;
        public int First_D
       {
           get { return this._First_D; }
           set { this._First_D = (int)value; }
       }

    //Guarda:
    //- Nimero de columnas si es Matriz
    //Abreviaicon de Second Dimension
    private int _Second_D;
        public int Second_D
        {
            get { return this._Second_D; }
            set { this._Second_D = (char)value; }
        }

    //Guarda:
    //- Tipo de dato que contiene el vector o matriz
    private char _Type;
        public char Type
        {
            get { return this._Type; }
            set { this._Type = (char)value; }
        }

    //Guarda:
    //- si el tipo de dato es complejo esto dice que contienen los complejos
    //Abreviaicon de Complex Type
    private char _CType;
        public char CType
        {
            get { return this._CType; }
            set { this._CType = (char)value; }
        }

    //Guarda:
    //- si el tipo de dato es complejo esto dice si se los guardo polar o binomicamente
    private char _Mode;
        public char Mode
        {
            get { return this._Mode; }
            set { this._Mode = (char)value; }
        }

    public Header(char K,int F,int S,char T,char CT,char M){ _Kind = K; _First_D = F; _Second_D = S; _Type = T; _CType = CT; _Mode = M; }

    //Este constructor inicializa todo con el char que se le pase
        //Y las dimensiones se mantienen en 0 ambas
    public Header( char all ){
    _Kind = all; 
    _First_D = 0;
    _Second_D = 0;
    _Type = all;
    _CType = all;
    _Mode = all;
    }
    
    //Este operador devuelve verdadero si dos Headers son de la misma clase, peor no completamente iguales
    //es decir que son del mismo tipo, pero pueden variar en las dimensiones
       //El operador && no puede ser sobrecargado, por eso utilizo el de short-circuit and
    public static  bool operator &(Header A, Header B)
        {

	    return ( (A._Kind == B._Kind) && (A._Type == B._Type) && (A._CType == B._CType) && (A._Mode == B._Mode) );


    }

    //Este operador devuelve verdadero si dos Headers son completamente iguales
    public static bool operator ==(Header A, Header B)
        {

	    return ( (A._Kind == B._Kind) && (A._Type == B._Type) && (A._CType == B._CType) && (A._Mode == B._Mode) && 
	    	(A._First_D == B._First_D) && (A._Second_D == B._Second_D) );


    }

    public static bool operator !=(Header A, Header B)
     {

        return  (!((A._Kind == B._Kind) && (A._Type == B._Type) && (A._CType == B._CType) && (A._Mode == B._Mode) &&
            (A._First_D == B._First_D) && (A._Second_D == B._Second_D)) );


     }

  

    };

       
  

    static class Loader
    {  
        
        //Es para devolver una respuesta y saber que paso leyendo
        public struct resp
       {
           public char Type;

           public char Fnc;

           public resp(char T, char F)
           {
               Type = T;
               Fnc = F;
           }
        }
                //KindOfData dice si es un archivo X,Y,Z, V o P
                //FD dice si es que se debe almacenar en un FXY o en un FXYZ
        private static resp From_Binary(string NAME, int num, char KindOfData, Crap_Graph.Crap_Graph.FunctionDestination FD)
        {
            return From_Binary(NAME, "", num, KindOfData, FD);

        }


           //Devuelve la info nesesaria para saber que se leyo
        private static resp From_Binary(string NAME, string PATH, int num, char KindOfData,
            Crap_Graph.Crap_Graph.FunctionDestination FD)
        {

            int aux;

            aux = NAME.LastIndexOf('.', NAME.Length - 1, NAME.Length);
            
            if (aux == -1)
            {

                NAME += ".crap";


            }

            //concateno todo el nombre del archivo
            PATH += NAME;

            FileStream file = new FileStream(PATH, FileMode.Open, FileAccess.Read);

            if (!file.CanRead)
            {
                
                //no se pudo abrir, devuelvo resp en '?'
                return new resp('?', '?');
                
            }

            BinaryReader reader = new BinaryReader(file);

            //Leo el Encabezado

            Header H;

            H = ReadHeader(ref reader);

            //Fin de la lectura del encabezado

            //Ahora empiezo a leer los datos

            resp dev= new resp(H.Type,'?');
                     
            //no solo los leo, sino que tambien los asigno a las variables globales correspondientes
            switch( KindOfData ){
                case 'X':
            {

                dev = Read_Data(ref H, ref reader, 'X', num, FD);
                break;
            }
                case 'Y':
            {

                dev = Read_Data(ref H, ref reader, 'Y', num, FD);
                break;
            }
                case 'Z':
            {

                dev = Read_Data(ref H, ref reader, 'Z', num, FD);
                break;
            }
                case 'V':
            {

                dev = Read_Data(ref H, ref reader, 'V', num, FD);
                break;
            }
                case 'P':
            {

                dev = Read_Data(ref H, ref reader, 'Z', num, FD);
                break;
            }
        }
                    //Importante, si no hay archivos con el nombre con X, Y, Z, V o P no lee nada

            //Ya esta todo guardado


            file.Close();

            return dev;


        }

        private static Header ReadHeader(ref BinaryReader input)
        {

            Header H = new Header('?');

            H.Kind = input.ReadChar();

            H.First_D = input.ReadInt32();

            if (H.Kind == 'M')
            {

                H.Second_D = input.ReadInt32(); 

            }
            else
            {

                H.Second_D = 0;
            }

            H.Type = input.ReadChar();

            if (H.Type == 'C')
            {

               H.CType = input.ReadChar();          
               H.Mode = input.ReadChar();

            }
            else
            {

                H.CType = '-';
                H.Mode = '-';

            }

            return H;


        }


        //KindOfData dice que se esta leyendo si un X, Y, Z, V o P
        private static resp Read_Data(ref Header H, ref BinaryReader input, char KindOfData, int num,Crap_Graph.Crap_Graph.FunctionDestination FD )
        {
            
    	        //Simples

	        if( H & (new Header('V',0,0,'I','-','-') )  )
            {

                int[] V = new int[H.First_D];

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
                    V[i] = input.ReadInt32();
                }

                switch (KindOfData)
                {
                    case 'X':
                        {
                            switch (FD)
                            {
                                case Crap_Graph.Crap_Graph.FunctionDestination.XY:
                                    {
                                        Crap_Graph.Crap_Graph.FXY[num].X = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXY[num].X[j] = (double)V[j];
                                        }
                                        break;
                                    }
                                case Crap_Graph.Crap_Graph.FunctionDestination.XYZ:
                                    {
                                        Crap_Graph.Crap_Graph.FXYZ[num].X = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXYZ[num].X[j] = (double)V[j];
                                        }
                                        break;
                                    }
                            }
                            break;
                        }
                    case 'Y':
                        {
                            switch (FD)
                            {
                                case Crap_Graph.Crap_Graph.FunctionDestination.XY:
                                    {
                                        Crap_Graph.Crap_Graph.FXY[num].Y = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXY[num].Y[j] = (double)V[j];
                                        }
                                        break;
                                    }
                                case Crap_Graph.Crap_Graph.FunctionDestination.XYZ:
                                    {
                                        Crap_Graph.Crap_Graph.FXYZ[num].Y = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXYZ[num].Y[j] = (double)V[j];
                                        }
                                        break;
                                    }
                            }
                            
                            break;
                        }
                    case 'Z':
                        {
                            Crap_Graph.Crap_Graph.FXYZ[num].Z = new double[H.First_D];
                            //Si tiene zeta seguro va para un FXYZ
                            for (int j = 0; (j < H.First_D); j++)
                            {
                                Crap_Graph.Crap_Graph.FXYZ[num].Z[j] = (double)V[j];
                            }
                            break;
                        }
                    case 'V':
                        {

                            break;
                        }
                    case 'P':
                        {

                            break;
                        }
                }

                return new resp('I', KindOfData);

	        }

            if( H & new Header('V',0,0,'F','-','-') ){

                float[] V = new float[H.First_D];

                for (int i = 0; (i < H.First_D); i++)
                {
                    V[i] = input.ReadSingle();
                }

                switch (KindOfData)
                {
                    case 'X':
                        {
                            switch (FD)
                            {
                                case Crap_Graph.Crap_Graph.FunctionDestination.XY:
                                    {
                                        Crap_Graph.Crap_Graph.FXY[num].X = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            
                                            Crap_Graph.Crap_Graph.FXY[num].X[j] = (double)V[j];
                                        }
                                        break;
                                    }
                                case Crap_Graph.Crap_Graph.FunctionDestination.XYZ:
                                    {
                                        Crap_Graph.Crap_Graph.FXYZ[num].X = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXYZ[num].X[j] = (double)V[j];
                                        }
                                        break;
                                    }
                            }
                            break;
                        }
                    case 'Y':
                        {
                            switch (FD)
                            {
                                case Crap_Graph.Crap_Graph.FunctionDestination.XY:
                                    {
                                        Crap_Graph.Crap_Graph.FXY[num].Y = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXY[num].Y[j] = (double)V[j];
                                        }
                                        break;
                                    }
                                case Crap_Graph.Crap_Graph.FunctionDestination.XYZ:
                                    {
                                        Crap_Graph.Crap_Graph.FXYZ[num].Y = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXYZ[num].Y[j] = (double)V[j];
                                        }
                                        break;
                                    }
                            }

                            break;
                        }
                    case 'Z':
                        {
                            Crap_Graph.Crap_Graph.FXYZ[num].Z = new double[H.First_D];
                            //Si tiene zeta seguro va para un FXYZ
                            for (int j = 0; (j < H.First_D); j++)
                            {
                                Crap_Graph.Crap_Graph.FXYZ[num].Z[j] = (double)V[j];
                            }
                            break;
                        }
                    case 'V':
                        {

                            break;
                        }
                    case 'P':
                        {

                            break;
                        }
                }
                return new resp('F', KindOfData);

	        }
        	
	        if( H & new Header('V',0,0,'D','-','-') ){

                double[] V = new double[H.First_D];

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
                    V[i] = input.ReadDouble();
                }

                switch (KindOfData)
                {
                    case 'X':
                        {
                            switch (FD)
                            {
                                case Crap_Graph.Crap_Graph.FunctionDestination.XY:
                                    {
                                        Crap_Graph.Crap_Graph.FXY[num].X = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXY[num].X[j] = (double)V[j];
                                        }
                                        break;
                                    }
                                case Crap_Graph.Crap_Graph.FunctionDestination.XYZ:
                                    {
                                        Crap_Graph.Crap_Graph.FXYZ[num].X = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXYZ[num].X[j] = (double)V[j];
                                        }
                                        break;
                                    }
                            }
                            break;
                        }
                    case 'Y':
                        {
                            switch (FD)
                            {
                                case Crap_Graph.Crap_Graph.FunctionDestination.XY:
                                    {
                                        Crap_Graph.Crap_Graph.FXY[num].Y = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXY[num].Y[j] = (double)V[j];
                                        }
                                        break;
                                    }
                                case Crap_Graph.Crap_Graph.FunctionDestination.XYZ:
                                    {
                                        Crap_Graph.Crap_Graph.FXYZ[num].Y = new double[H.First_D];
                                        for (int j = 0; (j < H.First_D); j++)
                                        {
                                            Crap_Graph.Crap_Graph.FXYZ[num].Y[j] = (double)V[j];
                                        }
                                        break;
                                    }
                            }

                            break;
                        }
                    case 'Z':
                        {
                            Crap_Graph.Crap_Graph.FXYZ[num].Z = new double[H.First_D];
                            //Si tiene zeta seguro va para un FXYZ
                            for (int j = 0; (j < H.First_D); j++)
                            {
                                Crap_Graph.Crap_Graph.FXYZ[num].Z[j] = (double)V[j];
                            }
                            break;
                        }
                    case 'V':
                        {

                            break;
                        }
                    case 'P':
                        {

                            break;
                        }
                }

                return new resp('D', KindOfData);

	        }

            return new resp('?', '?');

	        //Complejos


        /*
	        if( H && Store::Header('V',0,0,'C','I','B') ){

		        int AUX;

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].R_M(AUX);
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].I_A(AUX);
		        }
		        this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Vectorial_Binomical );

        		
	        }

        	
	        if( H && Store::Header('V',0,0,'C','I','P') ){

		        int AUX;

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].R_M(AUX);
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].I_A(AUX);
		        }
		        this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Polar );

        		
	        }

	        if( H && Store::Header('V',0,0,'C','F','B') ){

		        float AUX;

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].R_M(AUX);
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].I_A(AUX);
		        }
		        this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Vectorial_Binomical );

        		
	        }

	        if( H && Store::Header('V',0,0,'C','F','P') ){

		        float AUX;

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].R_M(AUX);
			        input.read( (char*)(&AUX) , 4 );
			        this->MC[0][i].I_A(AUX);
		        }
		        this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Polar );

        		
	        }

	        if( H && Store::Header('V',0,0,'C','D','B') ){

		        double AUX;

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			        input.read( (char*)(&AUX) , 8 );
			        this->MC[0][i].R_M(AUX);
			        input.read( (char*)(&AUX) , 8 );
			        this->MC[0][i].I_A(AUX);
		        }
		        this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Vectorial_Binomical );

        		
	        }

	        if( H && Store::Header('V',0,0,'C','D','P') ){

		        double AUX;

		        for( int i = 0 ; ( i < H.First_D ) ; i++ ){
			        input.read( (char*)(&AUX) , 8 );
			        this->MC[0][i].R_M(AUX);
			        input.read( (char*)(&AUX) , 8 );
			        this->MC[0][i].I_A(AUX);
		        }
		        this->MC[0][0].Arbitrari_Set_Mode( Numeric::VecBin_Polar::Polar );

        		
	        }
        */



        }

        private static string[] FilesRead;

        public static bool IsTheresomethingnew()
        {
            return (IsTheresomethingnew("./Content/") );
        }

        public static bool IsTheresomethingnew(string pat)
        {
            string[] AUX;

            AUX = System.IO.Directory.GetFiles(pat);

            if (FilesRead.Length != AUX.Length)
            {
                return true;

            }

            for (int i = 0; i < FilesRead.Length; i++)
            {
                if ( !(FilesRead[i] == AUX[i]) )
                {
                    return true;
                }

            }

            return false;

        }

        public static void Load_All_Data_from_Folder()
        {

            Load_All_Data_from_Folder("./Content/",100);

        }

        public static void Load_All_Data_from_Folder(string pat, int MaxFuncions){



            //Guardo el arreglo de nombres de archivo en la carpeta
            FilesRead = System.IO.Directory.GetFiles(pat);

            /*  Ejemplo para graficar el sistema
             * 
             *    XIndex       YIndex      ZIndex
             *      2             3           11            Hay dos Funciones de dos variables
             *      4      |----- 2-----      12            Hay solo una Funcion de tres variables
             *      1 -----|----- 1    |----- 2
             *      2 ------      0           0
             *      0             0           0
             *     ...           ...         ...
             */

            //Estos arreglos guardan los numeros(IDs) de los archivos d funciones
            //Con estos viendo similitudes, puedo ver que tipos de funciones puedo graficar
            //nunca va haber 100 funciones graficadas juntas, asi qeu esta instanciado por exeso
            Crap_Graph.Crap_Graph.ContentVectorOverDimensioned XIndex = new Crap_Graph.Crap_Graph.ContentVectorOverDimensioned(MaxFuncions);
            Crap_Graph.Crap_Graph.ContentVectorOverDimensioned YIndex = new Crap_Graph.Crap_Graph.ContentVectorOverDimensioned(MaxFuncions);
            Crap_Graph.Crap_Graph.ContentVectorOverDimensioned ZIndex = new Crap_Graph.Crap_Graph.ContentVectorOverDimensioned(MaxFuncions);

            
            //Cuento cuantos archivos hay legibles
            //Se considera en cuanto a funciones que hay un X y un Y siempre de a pares
            foreach (string name in FilesRead)
            {
                switch (name[pat.Length])
                {
                    case 'X':
                        {
                            int point = name.LastIndexOfAny(".".ToCharArray());
                            string number = name.Substring((pat.Length + 1), point - (pat.Length + 1));
                            XIndex.Data[XIndex.Cont] = int.Parse(number);
                            XIndex.Increment_Cont();
                            break;
                        }

                    case 'Y':
                        {
                            int point = name.LastIndexOfAny(".".ToCharArray());
                            string number = name.Substring((pat.Length + 1), point - (pat.Length + 1));
                            YIndex.Data[YIndex.Cont] = int.Parse(number);
                            YIndex.Increment_Cont();
                            break;
                        }
                    case 'Z':
                        {
                            int point = name.LastIndexOfAny(".".ToCharArray());
                            string number = name.Substring((pat.Length + 1), point - (pat.Length + 1));
                            ZIndex.Data[ZIndex.Cont] = int.Parse(number);
                            ZIndex.Increment_Cont();
                            break;
                        }
                    case 'P':
                        {

                            break;
                        }
                    case 'V':
                        {

                            break;
                        }


                }
            }

            //Como se mostro en el ejemplo, si tengo coincidencia en XIndex e YIndex puedo tener una 
            //TwoDimFuncs... lueo se vera si esta no puede pasar a ser una ThreeDimFunc

            Crap_Graph.Crap_Graph.ContentVectorOverDimensioned TwoDimFuncs = new Crap_Graph.Crap_Graph.ContentVectorOverDimensioned(MaxFuncions);
           
            for (int i = 0; (i < XIndex.Cont); i++)
            {
                for (int j = 0; (j < YIndex.Cont); j++)
                {
                    if ((XIndex.Data[i] == YIndex.Data[j]))
                    {
                        TwoDimFuncs.Data[TwoDimFuncs.Cont] = XIndex.Data[i];
                        TwoDimFuncs.Increment_Cont();

                    }

                }

            }

            Crap_Graph.Crap_Graph.ContentVectorOverDimensioned ThreeDimFuncs = new Crap_Graph.Crap_Graph.ContentVectorOverDimensioned(MaxFuncions);

            for (int i = 0; (i < TwoDimFuncs.Cont); i++)
            {
                for (int j = 0; (j < ZIndex.Cont); j++)
                {
                    if ((TwoDimFuncs.Data[i] == ZIndex.Data[j]))
                    {
                        ThreeDimFuncs.Data[ThreeDimFuncs.Cont] = XIndex.Data[i];
                        ThreeDimFuncs.Increment_Cont();

                    }

                }

            }

            //Que es la listanegra? Bueno si una funcion de tres variables esta y se dibuja
            //por este sistema, yambien se considera como una posible funcion de dos variables
            //Como hacemos para no leer las dos veces, una para dos y otra para tres variables
            //Bueno lo que hacemos es meter a las que tienen tres variables en la lista negra
            //y las que tienen dos variables solo se cragan si no estan en la lista negra
            Crap_Graph.Crap_Graph.ContentVectorOverDimensioned BlackList = new Crap_Graph.Crap_Graph.ContentVectorOverDimensioned(MaxFuncions);

            Crap_Graph.Crap_Graph.FXYZ = new Crap_Graph.Crap_Graph.FunctionsXYZ[ThreeDimFuncs.Cont];
            for (int k = 0; (k < ThreeDimFuncs.Cont); k++)
            {
                Crap_Graph.Crap_Graph.FXYZ[k] = new Crap_Graph.Crap_Graph.FunctionsXYZ();

            }


            //Aca solo ejecuto el codigo de carga preguntando por los archivos X
            //porque ya se que los Y y Z existen por estar en ThreeDiemensionFuncs, 
            //ademas si ejecutaria el codigo para Y y Z tambien, me leeria varias veces los archivos
            foreach (string name in FilesRead)
            {
                if (name[10] == 'X')
                {
                    int point = name.LastIndexOfAny(".".ToCharArray());
                    string number = name.Substring((pat.Length + 1), point - (pat.Length + 1));

                    for (int j = 0; (j < ThreeDimFuncs.Cont); j++)
                    {
                        if (int.Parse(number) == ThreeDimFuncs.Data[j])
                        {
                            //Cargo el archivo X en el arreglo FXYZ numero j
                            Data_Loader.Loader.From_Binary(name, j, 'X', Crap_Graph.Crap_Graph.FunctionDestination.XYZ);
                            //Cargo el archivo Y en el arreglo FXYZ numero j
                            Data_Loader.Loader.From_Binary(name.Replace('X', 'Y'), j, 'Y', Crap_Graph.Crap_Graph.FunctionDestination.XYZ);
                            //Cargo el archivo Z en el arreglo FXYZ numero j
                            Data_Loader.Loader.From_Binary(name.Replace('X', 'Z'), j, 'Z', Crap_Graph.Crap_Graph.FunctionDestination.XYZ);
                            //Se aumenta la lista negra con esta funcion asi no se almacena tambien en 
                            //las funciones de dos variables
                            BlackList.Data[BlackList.Cont] = ThreeDimFuncs.Data[j];
                            BlackList.Increment_Cont();
                        }

                    }


                }

            }

            //Particularidad aca va a haber solo la cantidad de funciones con dos variables menos las que son
            //tambien de tres variables que se contaron, ese numero esta almacenado en BlackList
            Crap_Graph.Crap_Graph.FXY = new Crap_Graph.Crap_Graph.FunctionsXY[TwoDimFuncs.Cont - BlackList.Cont];
            for (int k = 0; (k < Crap_Graph.Crap_Graph.FXY.Length); k++)
            {
                Crap_Graph.Crap_Graph.FXY[k] = new Crap_Graph.Crap_Graph.FunctionsXY();

            }

            //Si esta en la lista negra, entonces es malo, y no se carga... ya se cargo en ThreeDimFuncs
            //este es el objetivo de la listanegra
            bool ISBAD;

            //Como las funciones de tres variables se leen los X, y en base a eso se leen los Y aca
            foreach (string name in FilesRead)
            {

                if (name[10] == 'X')
                {   //En un comienzo se supone que no esta en la lista negra
                    ISBAD = false;

                    int point = name.LastIndexOfAny(".".ToCharArray());
                    string number = name.Substring((pat.Length + 1), point - (pat.Length + 1));

                    for (int i = 0; (i < TwoDimFuncs.Cont); i++)
                    {
                        //Pregunto si esta en TwoDimensionFunction
                        if (int.Parse(number) == TwoDimFuncs.Data[i])
                        {
                            //Pregunto si acaso no esta en la lista negra
                            for (int l = 0; (l < BlackList.Cont); l++)
                            {
                                if (int.Parse(number) == BlackList.Data[l])
                                {
                                    ISBAD = true;
                                    l = BlackList.Cont;//Hago esto para que termine el for

                                }
                            }
                            //Si no esta en la lista negra lo leo, si esta no lo leo
                            if (ISBAD == false)
                            {
                                //Leo el archivo X y lo guardo en el _FXY numero i
                                From_Binary(name, Crap_Graph.Crap_Graph.FunctionsXY.XYAmount, 'X', Crap_Graph.Crap_Graph.FunctionDestination.XY);
                                //Leo el archivo Y y lo guardo en el _FXY numero i
                                From_Binary(name.Replace('X', 'Y'), Crap_Graph.Crap_Graph.FunctionsXY.XYAmount, 'Y', Crap_Graph.Crap_Graph.FunctionDestination.XY);
                                //Esto lleva en donde debo ingresar el proximo archivo... leer al comienzo 
                                //del foreach para comprender, conflicto con funciones de tres variables 
                                //y listanegra con funciones de dos variables
                                Crap_Graph.Crap_Graph.FunctionsXY.Increment_XYAmount();
                            }

                        }

                    }


                }

                

                //El vertexBuffer debe tener dimension para almacenar los _FXY + _FXYZ
                //lo que es lo mismo la de las funciones de dos variables + las de tres
                Crap_Graph.Crap_Graph.VertexB = new VertexBuffer[Crap_Graph.Crap_Graph.FunctionsXY.XYAmount + ThreeDimFuncs.Cont];
                //El VertexBuffer se inicializa mas abajo en loadcontent

                //Si es que hay alguna funcion de tres variables cargada, entonces todo tiene que 
                //funcionar para tres variables, de lo contrario solo para dos variables
                if (Crap_Graph.Crap_Graph.FXYZ.Length > 0)
                {
                    Crap_Graph.Crap_Graph.ThreeVariablesFuncitons = true;

                }



            }





        }

        public static void Re_InitializeVariables()
        {

            Crap_Graph.Crap_Graph.FunctionsXY.XYAmount = 0;
            Crap_Graph.Crap_Graph.FunctionsXYZ.XYAmount = 0;
            
        }


    }



}