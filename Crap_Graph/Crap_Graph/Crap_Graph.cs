using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Net;
using Microsoft.Xna.Framework.Storage;

namespace Crap_Graph
{
    
    public class Crap_Graph : Microsoft.Xna.Framework.Game
    {
        public enum FunctionDestination { XY, XYZ }

        public enum WindowMode { Tiny, Big, Full }
        public enum Mode { Intro, Normal }

        //Para cambiar si comenzar con la Intro o en modo normal
        private static Mode _M = Mode.Normal;
        public static Mode M
        {
            get { return _M; }
            set { _M = value; }

        }

        //para cambiar estados y configuracion de la ventana
        WindowMode Win = WindowMode.Tiny;

        //Dice si es que el pograma arranca en fullscreen o no
        static public bool IsFullScreen = false;


        private GraphicsDeviceManager graphics;

        SpriteBatch spriteBatch;
        SpriteFont font;
        Texture2D icon;
        //El icono que animado se hace con postprocesamiento
        RenderTarget2D iconEffect;
        //Esta matriz dice la rotacion del icono animado
        Matrix IconRotationPosition = Matrix.Identity;
        //Fuerza con la que se rota
        static public new Vector2 IconMouseRotationForce = new Vector2(0f, 0.005f);
        //Dimensiones del icono animado
        static public int IconWidth = 128;
        static public int IconHeigth = 128;
        
        //Componentes
        FPS fps;
        InPutHandler input;
        Camera_Manager camera;

        //VertexDeclaration para funciones etc
        VertexDeclaration VD;
        //VertexDeclaration para postprocesing
        VertexDeclaration VDP;

        //Hay un VertexBuffer para cada funcion a dibujar
        private static VertexBuffer[] VB;
        public static VertexBuffer[] VertexB
        {
            get { return VB; }
            set { VB = value; }
        }
        
        public static VertexPositionColor[] Numbers;

        private BasicEffect fx;
        

        //Este efecto dibuja el icono animado
        //Este effecto es mio, hace que el cornflowerblue se torne totalmente transparente
        private BasicEffect IconEffect;


        //Contenedor de funciones
        public class FunctionsXY
        {
            //cantidad de valores de la terna X e Y
            private static int _XYAmount;
            public static int XYAmount
            {
                get { return _XYAmount; }
                set { _XYAmount = value; }
            }
            public static void Increment_XYAmount()
            {
                _XYAmount++;
            }
            
            private double[] _Y;
            public double[] Y
            {
                get { return this._Y; }
                set { this._Y = value; }

            }

            public void ResizeY(int dim){
                _Y = new double[dim];

            }
            private double[] _X;
            public double[] X
            {
                get { return this._X; }
                set { this._X = value; }

            }
            public void ResizeX(int dim)
            {
                _X = new double[dim];

            }

            static public Color XYC;

        }//Fin del contenedor de funcionesXY

        //Ampliacion para funciones de 3 variables
        public class FunctionsXYZ: FunctionsXY
        {
            private double[] _Z;
            public double[] Z
            {
                get { return this._Z; }
                set { this._Z = value; }

            }

            public void ResizeZ(int dim)
            {
                _Z = new double[dim];

            }

            static public Color XYZC;


        }//Fin del contenedor de funcionesXYZ

        //Esta clase ayuda a llevar el orden de algunas cosas
        //como dice el nombre es un vector sobredimenisonado, y lleva la cuenta de cuantos elementos se 
        //guardaron
                    //Importante, el aumento del contador se sdebe hacer manuealmente!!!
        public class ContentVectorOverDimensioned
        {
            //contiene los datos, los elemntos no cargados se llenan de -9999
            private int[] _Data;
            //Este miembro lleva la cuenta de cuantos elementos hay exactamente cargados
            private int _Cont;
            private readonly int _NeverTouchFlag;


            public ContentVectorOverDimensioned(int dim)
            {
                _Data = new int[dim];
                _Cont = 0;
                _NeverTouchFlag = (-9999);

                for (int i = 0; (i < dim); i++)
                {
                    _Data[i] = -9999;
                }

            }

            public ContentVectorOverDimensioned(int dim, int nevertouchflag)
            {
                _Data = new int[dim];
                _Cont = 0;
                _NeverTouchFlag = nevertouchflag;

                for(int i= 0;(i < dim);i++){
                    _Data[i] = nevertouchflag;
                }

            }

            public int NeverTouchFlag
            {
                get { return this._NeverTouchFlag; } 
            }

            public int Cont
            {
                get { return this._Cont; }
                set { this._Cont = value; }

            }
            public int[] Data
            {
                get { return this._Data; }
                set { this._Data = value; }

            }

            public void Increment_Cont()
            {
                Cont++;
            }

        }


        //Arreglos para contner los datos
        //Como Y e X deben tene rel mismo tamaño suelo utilizar Y.Length()
        //pero me refiero al tamaño de cualquiera de los dos cuado utilizo este
        static private FunctionsXY[] _FXY;
        //Este metodo permite que Data_Loader y otros cs puedan ver leer esta variable y escribirla
        static public FunctionsXY[] FXY
        {
            get { return _FXY; }
            set { _FXY = value; }

        }

        //Esta variable dice si es que se grafican funciones de tres variables en este momento
        public static bool ThreeVariablesFuncitons = false;

        static private FunctionsXYZ[] _FXYZ;
        //Este metodo permite que Data_Loader y otros cs puedan ver leer esta variable y escribirla
        static public FunctionsXYZ[] FXYZ
        {
            get { return _FXYZ; }
            set { _FXYZ = value; }

        }

        
        //Color del eje X   Azul
        Color XC = new Color(0, 0, 255,255);

        //Color del eje Y   Rojo
        Color YC = new Color(255, 0, 0,255);

        //Color del eje Z   Verde
        Color ZC = new Color(0, 255, 0, 255);

        Intro I;

        public Crap_Graph()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
            
            fps = new FPS(this);
            this.Components.Add(fps);

            input = new InPutHandler(this);
            this.Components.Add(input);

            camera = new Camera_Manager(this);
            this.Components.Add(camera);

            graphics.PreferredBackBufferWidth = 768;
            graphics.PreferredBackBufferHeight = 512;
                       
            
            graphics.IsFullScreen = IsFullScreen;
            
        }


        protected override void Initialize()
        {
            I = new Intro(this);

            FunctionsXY.XYC = Color.White;
            FunctionsXYZ.XYZC = Color.Black;

            Window.Title = "Crap Grapher";

            //Esto leer y asigna todo a las variables correspondientes
            Data_Loader.Loader.Load_All_Data_from_Folder();



            base.Initialize();
        }


        protected override void LoadContent()
        {   
            graphics.GraphicsDevice.RenderState.AlphaBlendEnable = true;
            graphics.GraphicsDevice.RenderState.DestinationBlend = Blend.DestinationAlpha;
            graphics.GraphicsDevice.RenderState.SourceBlend = Blend.SourceAlpha;


            fx = new BasicEffect(graphics.GraphicsDevice, null);
            IconEffect = new BasicEffect(graphics.GraphicsDevice, null);

            fx.VertexColorEnabled = true;
            fx.World = Matrix.Identity;
            fx.Projection = camera.Get_Proyection();

            //Cargo el effect para el icono
            icon = Content.Load<Texture2D>(@"Images\pi");
            IconEffect.Texture = icon;
            IconEffect.TextureEnabled = true;
            IconEffect.LightingEnabled = true;
            IconEffect.AmbientLightColor = new Vector3(255,255,255);
            IconEffect.View = Matrix.CreateLookAt(new Vector3(0f, 0f, 3.7f), Vector3.Zero, Vector3.Up);
            IconEffect.World = Matrix.Identity;
            IconEffect.Projection = Matrix.CreatePerspectiveFieldOfView(MathHelper.PiOver4,
                (float)graphics.GraphicsDevice.Viewport.Width / (float)graphics.GraphicsDevice.Viewport.Height,
                 0.001f, 10000f);

            //Fin de cargar el effect para el icon
            
            spriteBatch = new SpriteBatch(GraphicsDevice);
            font = Content.Load<SpriteFont>(@"Fonts\Reference");
            iconEffect = new RenderTarget2D(graphics.GraphicsDevice, graphics.GraphicsDevice.Viewport.Width,
                graphics.GraphicsDevice.Viewport.Height, 1, graphics.GraphicsDevice.DisplayMode.Format,
                GraphicsDevice.PresentationParameters.MultiSampleType,
                GraphicsDevice.PresentationParameters.MultiSampleQuality);
                                       
            VD = new VertexDeclaration(graphics.GraphicsDevice, VertexPositionColor.VertexElements);
            VDP = new VertexDeclaration(graphics.GraphicsDevice, VertexPositionNormalTexture.VertexElements);

             
            //si es que hay funciones d etres variables
            if (ThreeVariablesFuncitons)
            {

                for (int i = 0; i < (_FXYZ.Length); i++)
                {
                    if (i == 0)
                    {
                        //El primero tiene los ejes tambien, en el caso de haber FXYZ son los ejes X,Y y Z
                        VB[i] = new VertexBuffer(graphics.GraphicsDevice, VertexPositionColor.SizeInBytes * (_FXYZ[0].Y.Length + 6),
                            BufferUsage.WriteOnly);
                    }
                    else
                    {
                        //solo las funciones
                        VB[i] = new VertexBuffer(graphics.GraphicsDevice, VertexPositionColor.SizeInBytes * (_FXYZ[i].Y.Length),
                            BufferUsage.WriteOnly);
                    }

                }

                for (int i = 0; i < (_FXY.Length); i++)
                {

                    //solo las funciones
                    VB[i + (_FXYZ.Length)] = new VertexBuffer(graphics.GraphicsDevice, VertexPositionColor.SizeInBytes * (_FXY[i].Y.Length),
                        BufferUsage.WriteOnly);

                }
            }
            else//si no hay funciones de tres variables
            {
                for (int i = 0; i < (_FXY.Length); i++)
                {
                    if ((i == 0))
                    {
                        //El primero tiene los ejes tambien, en caso de no haber FXY son los ejes X e Y
                        VB[i] = new VertexBuffer(graphics.GraphicsDevice, VertexPositionColor.SizeInBytes * (_FXY[0].Y.Length + 4),
                            BufferUsage.WriteOnly);
                    }
                    else
                    {
                        //solo las funciones
                        VB[i] = new VertexBuffer(graphics.GraphicsDevice, VertexPositionColor.SizeInBytes * (_FXY[i].Y.Length),
                            BufferUsage.WriteOnly);
                    }
                }
            }

            
            Load_Vertex();

                        
        }


        protected override void UnloadContent()
        {
            


        }


        protected override void Update(GameTime gameTime)
        {

            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            if (input.KeyState.WasPress(Keys.Tab))
            {
                graphics.ToggleFullScreen();

            }


            if (input.KeyState.WasPress(Keys.V))
            {
                Win = WindowMode.Tiny;
                
            }
            if (input.KeyState.WasPress(Keys.B))
            {
                Win = WindowMode.Big;

            }
            if (input.KeyState.WasPress(Keys.C))
            {
                Window.AllowUserResizing = !Window.AllowUserResizing;

            }
            

                        switch( Win ){
                case WindowMode.Tiny:{

                    break;
                }

                case WindowMode.Big:{

                    break;
                }




            }

            //Entra y recarga toda la informacion si es que
            //Hay una cantidad diferente de archivos de la que habia antes
            //Algun archivo cambio de nombre
            if (Data_Loader.Loader.IsTheresomethingnew())
            {
                //reinicializo los contadores de cantidad de elemntos en FXY y FXYZ
                Data_Loader.Loader.Re_InitializeVariables();
                Data_Loader.Loader.Load_All_Data_from_Folder();
               
            }
                      



            base.Update(gameTime);
        }


        protected override void Draw(GameTime gameTime)
        {
            switch (_M)
            {
                case Mode.Intro:
                    {
                        graphics.GraphicsDevice.Clear(Color.CornflowerBlue);

                        fx.World = Matrix.CreateRotationY(MathHelper.ToRadians(180)) * Matrix.CreateTranslation(new Vector3(30f,0f,180));
                        fx.View = camera.Get_View();

                        fx.Begin();
                        graphics.GraphicsDevice.VertexDeclaration = VD;
                        foreach (EffectPass pass in fx.CurrentTechnique.Passes)
                        {

                            pass.Begin();

                            I.Draw_Logo();

                            pass.End();

                        }


                        fx.End();

                        break;
                    }
                case Mode.Normal:
                    {
                        
                        Load_PostProccesing();


                        //Limpio el backbuffer
                        graphics.GraphicsDevice.Clear(Color.CornflowerBlue);


                        Draw_IconANDSprites(gameTime);

                        Draw_Axisvalues(gameTime);
                        
                        //Esta la cambio con el input
                        fx.View = camera.Get_View();
                        fx.World = camera.Get_World();

                        fx.Begin();
                        //Aca se utiliza otra vertexdeclaration que en postprocessing
                        graphics.GraphicsDevice.VertexDeclaration = VD;
                        //No cargo el VertexDeclaration, porque ya lo cargue en Load_Postproccesing
                        foreach (EffectPass pass in fx.CurrentTechnique.Passes)
                        {

                            pass.Begin();

                            for (int j = 0; (j < (_FXY.Length + _FXYZ.Length)); j++)
                            {
                                if (j == 0)
                                {
                                    //Le tengo que asignar el buffer, porque si lo pongo en LoadVertex, lo cargaria la primera vez
                                    //pero para la proxima vulta no entra ahi, y no seasignaria el VB[0]
                                    graphics.GraphicsDevice.Vertices[0].SetSource(VB[0], 0, VertexPositionColor.SizeInBytes);
                                    //Si es que hay tres funciones d etres variables dibujo los ejes X,Y y Z
                                    if (ThreeVariablesFuncitons == true)
                                    {
                                        graphics.GraphicsDevice.DrawPrimitives(PrimitiveType.LineList, 0, 3);
                                        graphics.GraphicsDevice.DrawPrimitives(PrimitiveType.LineStrip, 6, _FXYZ[0].Y.Length - 1);
                                    }
                                    else//si solo hay funciones de dos variables solo dibujo los ejes X e Y
                                    {
                                        graphics.GraphicsDevice.DrawPrimitives(PrimitiveType.LineList, 0, 2);
                                        graphics.GraphicsDevice.DrawPrimitives(PrimitiveType.LineStrip, 4, _FXY[0].Y.Length - 1);
                                    }


                                }
                                else
                                {
                                    graphics.GraphicsDevice.Vertices[0].SetSource(VB[j], 0, VertexPositionColor.SizeInBytes);
                                    graphics.GraphicsDevice.DrawPrimitives(PrimitiveType.LineStrip, 0, _FXY[j - _FXYZ.Length].Y.Length - 1);
                                }

                            }
                            pass.End();

                        }

                        
                        spriteBatch.DrawString(font,"A",);


                        fx.End();

                        //Sobre lo anterior dibujo los sprites, de leyenda y el Icono animado


                        break;
                    }

            }



            base.Draw(gameTime);
        }

        
        void Load_Vertex()
        {
            //Cargo primero las funciones
            if (ThreeVariablesFuncitons)
            {
                //Sirve para cragar primero a FXYZ y luego a FXY
                VertexPositionColor[] V;
                                
                for (int j = 0; (j < _FXYZ.Length); j++)
                {

                    if (j == 0)
                    {
                        //Los cuatro restantes son los ejes
                        V = new VertexPositionColor[_FXY[0].Y.Length + 6];
                        //solo el primero tiene los ejes

                        //Ejes X e Y solo
                        //float TENpercent = (float)((_F[j].X[_F[j].X.Length - 1] - _F[j].X[0]) * 10 / 100);

                        //Eje X
                        V[0] = new VertexPositionColor(new Vector3(-500f, 0f, 0f), XC);

                        V[1] = new VertexPositionColor(new Vector3(500f, 0f, 0f), XC);

                        //TENpercent = (float)((_F[j].Y[_F[j].Y.Length - 1] - _F[j].Y[0]) * 10 / 100);

                        //Eje Y
                        V[2] = new VertexPositionColor(new Vector3(0f, -500f, 0f), YC);

                        V[3] = new VertexPositionColor(new Vector3(0f, 500f, 0f), YC);

                        //Eje Z
                        V[4] = new VertexPositionColor(new Vector3(0f, 0f, -500f), ZC);

                        V[5] = new VertexPositionColor(new Vector3(0f, 0f, 500f), ZC);


                        for (int i = 6; (i < (_FXY[0].Y.Length + 6)); i++)
                        {
                            V[i] = new VertexPositionColor(new Vector3((float)(_FXYZ[0].X[i - 6]), (float)(_FXYZ[0].Y[i - 6]), (float)_FXYZ[0].Z[i-6]), FunctionsXYZ.XYZC);

                        }

                    }
                    else
                    {
                        V = new VertexPositionColor[_FXYZ[j].Y.Length];


                        for (int i = 0; (i < _FXYZ[j].Y.Length); i++)
                        {
                            V[i] = new VertexPositionColor(new Vector3((float)(_FXYZ[j].X[i]), (float)(_FXYZ[j].Y[i]), (float)_FXYZ[j].Z[i]), FunctionsXYZ.XYZC);

                        }


                    }


                    VB[j].SetData<VertexPositionColor>(V);
                    


                }

                for (int j = 0; (j < _FXY.Length); j++)
                {

                    V = new VertexPositionColor[_FXY[j].Y.Length];


                    for (int i = 0; (i < _FXY[j].Y.Length); i++)
                    {
                        V[i] = new VertexPositionColor(new Vector3((float)(_FXY[j].X[i]), (float)(_FXY[j].Y[i]), 0f), FunctionsXY.XYC);

                    }

                    VB[j+(FXYZ.Length)].SetData<VertexPositionColor>(V);

                }

            }
            else
            {

                for (int j = 0; (j < _FXY.Length); j++)
                {

                    VertexPositionColor[] V;
                    if (j == 0)
                    {
                        //Los cuatro restantes son los ejes
                        V = new VertexPositionColor[_FXY[0].Y.Length + 4];
                        //solo el primero tiene los ejes

                        //Ejes X e Y solo
                        //float TENpercent = (float)((_F[j].X[_F[j].X.Length - 1] - _F[j].X[0]) * 10 / 100);

                        //Eje X
                        V[0] = new VertexPositionColor(new Vector3(-500f, 0f, 0f), XC);

                        V[1] = new VertexPositionColor(new Vector3(500f, 0f, 0f), XC);

                        //TENpercent = (float)((_F[j].Y[_F[j].Y.Length - 1] - _F[j].Y[0]) * 10 / 100);

                        //Eje Y
                        V[2] = new VertexPositionColor(new Vector3(0f, -500f, 0f), YC);

                        V[3] = new VertexPositionColor(new Vector3(0f, 500f, 0f), YC);


                        for (int i = 4; (i < (_FXY[0].Y.Length + 4)); i++)
                        {
                            V[i] = new VertexPositionColor(new Vector3((float)(_FXY[0].X[i - 4]), (float)(_FXY[0].Y[i - 4]), 0f), FunctionsXY.XYC);

                        }

                    }
                    else
                    {
                        V = new VertexPositionColor[_FXY[j].Y.Length];


                        for (int i = 0; (i < _FXY[j].Y.Length); i++)
                        {
                            V[i] = new VertexPositionColor(new Vector3((float)(_FXY[j].X[i]), (float)(_FXY[j].Y[i]), 0f), FunctionsXY.XYC);

                        }
                    }


                    VB[j].SetData<VertexPositionColor>(V);


                }

            }

            //cargo los planos
            Load_Plains();
                       

        }

        void Load_Plains(){





        }


        void Load_PostProccesing()
        {
                 
            graphics.GraphicsDevice.SetRenderTarget(0, iconEffect);
            graphics.GraphicsDevice.Clear( Color.CornflowerBlue );
            
            VertexPositionNormalTexture[] V = new VertexPositionNormalTexture[4];
            
            V[0] = new VertexPositionNormalTexture(new Vector3(-1f, 1f, 0f), new Vector3(0f, 0f, 1f), new Vector2(0f, 0f));
            V[1] = new VertexPositionNormalTexture(new Vector3(1f, 1f, 0f), new Vector3(0f, 0f, 1f), new Vector2(1f, 0f));
            V[2] = new VertexPositionNormalTexture(new Vector3(-1f, -1f, 0f), new Vector3(0f, 0f, 1f), new Vector2(0f, 1f));
            V[3] = new VertexPositionNormalTexture(new Vector3(1f, -1f, 0f), new Vector3(0f, 0f, 1f), new Vector2(1f, 1f));

            int[] IB = new int[6];

            IB[0] = 0;
            IB[1] = 1;
            IB[2] = 2;
            IB[3] = 2;
            IB[4] = 1;
            IB[5] = 3;
                //si pongo el culling en la inicializacion, no afecta a este GraphicDevice con este 
                //RenderTarget
                graphics.GraphicsDevice.RenderState.CullMode = CullMode.None;
            
            IconRotationPosition *= Matrix.CreateRotationX(IconMouseRotationForce.X) * Matrix.CreateRotationY(IconMouseRotationForce.Y);
            IconEffect.World = IconRotationPosition;
            IconEffect.Texture = icon;
            
            graphics.GraphicsDevice.VertexDeclaration = VDP;
            IconEffect.Begin();
            foreach (EffectPass pass in IconEffect.CurrentTechnique.Passes)
            {
                pass.Begin();
                graphics.GraphicsDevice.DrawUserIndexedPrimitives<VertexPositionNormalTexture>(PrimitiveType.TriangleList,
                     V, 0, 4, IB, 0, 2);
                pass.End();

            }
            IconEffect.End();

            graphics.GraphicsDevice.SetRenderTarget(0, null);

        }


        void Draw_IconANDSprites(GameTime gameTime)
        {

            //Ahora dibujo el Icono con el effecto de rotacion
                 
            spriteBatch.Begin(SpriteBlendMode.AlphaBlend,SpriteSortMode.Immediate,SaveStateMode.None);


            spriteBatch.Draw( iconEffect.GetTexture(), new Rectangle(5, 5, IconWidth, IconHeigth), Color.White);
                 
                /*Estas lineas muestran los valores de las fuerzas sobre el Icono
                 spriteBatch.DrawString(font, "La fuerza de rotacio X es " + IconMouseRotationForce.X.ToString(),
                     new Vector2(250, 250), Color.White);
                 spriteBatch.DrawString(font, "La fuerza de rotacio Y es " + IconMouseRotationForce.Y.ToString(),
                          new Vector2(250, 350), Color.White);
                 */
                spriteBatch.DrawString(font, "Funciones de dos variables: Blanco" ,
                           new Vector2(480, 10), Color.White);
                 spriteBatch.DrawString(font, "Funciones de tres variables: Negro" ,
                           new Vector2(480, 35), Color.White);
            
            spriteBatch.End();
            //Ya dibuje el icono con effecto d rotacion
                        

        }

        void Draw_Axisvalues(GameTime gameTime)
        {
            spriteBatch.Begin(SpriteBlendMode.AlphaBlend, SpriteSortMode.Immediate, SaveStateMode.None);

            Rectangle Value=new Rectangle();
            Value.Width=0.5;
            Value.Height=0.5;


            Numbers[0]= new VertexPositionColor(new Vector3(0,0,0),new Color(255,255,255));
            Numbers[1]= new VertexPositionColor(new Vector3(0.2,0,0),new Color(255,255,255));
            Numbers[2]= new VertexPositionColor(new Vector3(0.2,0.2,0),new Color(255,255,255));
            Numbers[3]= new VertexPositionColor(new Vector3(0, 0.2, 0), new Color(255, 255, 255));
                     


            for (int Xvalue = new int(); Xvalue < 768; Xvalue += 50)
            {
                spriteBatch.DrawString(font, string.Format("{0:N0}", Xvalue), new Vector2(Xvalue, 265), Color.WhiteSmoke);
                
            }
            

            spriteBatch.End();
        

        }




    }
}
