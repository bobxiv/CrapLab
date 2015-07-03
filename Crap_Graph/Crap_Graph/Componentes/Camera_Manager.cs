using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Storage;
using Microsoft.Xna.Framework.Content;

namespace Crap_Graph
{

    public class Camera_Manager : Microsoft.Xna.Framework.GameComponent
    {
        GraphicsDeviceManager graphics;
        InPutHandler Input;

        //Esto es lo maximo a lo que se puede acercar la camara a una funcion con el wheel del mouse
        const float MaxClose = 0.001f;

        private Matrix proy;
        private Matrix view;
        //Mide la rotacion sobre el eje X
        public float XRotation= 0;
        private Matrix world = Matrix.Identity;
        private Vector3 CameraPosition = new Vector3(0f, 0f, 1f);
        private Vector3 CameraTarget = Vector3.Zero;
        private Vector3 VectorUp = Vector3.Up;

        private Vector3 MovDir;
        float MovSpeed = 1;

        private Vector3 CameraReference = new Vector3(0f, 0f, -1f);

        //la velocidad es funcion de cunto se puede acercar la camara
        private float Wheelspeed = MaxClose*10000;

        //Velocidad de moviemientos Con Leaft y Rigth
        private float ParallaxScroll = 0.5f;

        //esta bandera determina si se puede girar o no el icono
        bool IconMov = false;

        //Constantes para graduar el giro del Icono
            //Fuerza maxima del icono girando
            const float MAXFORCE = 0.05f;
            //Porcentaje que pierde cada turno
            const float ForceLoseinPercent = 90;
            //Esta constante modifica la velocidad de obtencion de velocidad
            //Originalmente es de la diferencia entre lo que se avance con el mouse, pero este factor lo modifica
            const float FORCEGAIN = 0.03f;
            //No es propiamente dicha el minimo de fuerza, ya que no hay uno, sino que este valor determina
            //hasta que punto el icono pierde velocidad. Llegado este punto deja de perder la aceleracion
            const float MINFORCE = 0.005f;

        
        public Camera_Manager(Game game)
            : base(game)
        {
            graphics = (GraphicsDeviceManager)game.Services.GetService(typeof(IGraphicsDeviceManager));

            Input = (InPutHandler)game.Services.GetService(typeof(IInputHandler));
           
        }


        public override void Initialize()
        {         

            base.Initialize();

            InitializeCamera();

        }

        private void InitializeCamera()
        {

            float aspectratio = ((float)graphics.GraphicsDevice.Viewport.Width / (float)graphics.GraphicsDevice.Viewport.Height);

            Matrix.CreatePerspectiveFieldOfView(MathHelper.PiOver4, aspectratio, MaxClose, 10000f, out  proy);

            switch (Crap_Graph.M)
            {


                case Crap_Graph.Mode.Intro:
                    {

                        CameraPosition = new Vector3(0f, 53, 165f);
                        CameraTarget = new Vector3(0f, 53, 1000f);
                        Matrix.CreateLookAt(ref CameraPosition, ref CameraTarget, ref VectorUp, out view);

                        break;
                    }
                case Crap_Graph.Mode.Normal:
                    {

                        if (!Crap_Graph.ThreeVariablesFuncitons)
                        {

                            Matrix.CreateLookAt(ref CameraPosition, ref CameraTarget, ref VectorUp, out view);

                        }
                        else
                        {   //Si agrego el eje Z no quiero que se confundan los ejes cuando arranque la camara
                            CameraPosition += new Vector3(0.1f, 0f, 0f);
                            CameraTarget += new Vector3(0.1f, 0f, 0f);
                            Matrix.CreateLookAt(ref CameraPosition, ref CameraTarget, ref VectorUp, out view);
                            XRotation = 2.5f;

                        }

                        break;

                    }

            }


        }

        private void ReInicialize_View()
        {

            CameraPosition = new Vector3(0f, 0f, 1f);
            CameraTarget = Vector3.Zero;

            if (!Crap_Graph.ThreeVariablesFuncitons)
            {

                Matrix.CreateLookAt(ref CameraPosition, ref CameraTarget, ref VectorUp, out view);

            }
            else
            {   //Si agrego el eje Z no quiero que se confundan los ejes cuando arranque la camara
                CameraPosition += new Vector3(0.1f, 0f, 0f);
                CameraTarget += new Vector3(0.1f, 0f, 0f);
                Matrix.CreateLookAt(ref CameraPosition, ref CameraTarget, ref VectorUp, out view);
                XRotation = 2.5f;

            }

        }


        public override void Update(GameTime gameTime)
        {
            float timedelta = (float)gameTime.ElapsedGameTime.TotalSeconds;

            switch (Crap_Graph.M)
            {
                case Crap_Graph.Mode.Intro:
                    {
                        if ( (CameraPosition.Y < 40) && (CameraPosition.Y  > 35) )
                        {

                            Vector3.Transform( VectorUp,Matrix.CreateRotationX(MathHelper.ToRadians(
                                CameraPosition.Y - 35) * 1.2f ));
                            
                        }

                        //Este paso sale de la parte dearriba:
                        //Empieza alejandose vertiginosamente de pi
                        //Deciende a un nivel constante todo el timepo
                        //Empieza a alejarse cada vez mas lento, de na forma abrupta
                        /*  Forma de la de la Caida
                         *     ======| -------
                         *    |      |        ----
                         *    |      |            --
                         *    |      |              -
                         *    |      |
                         *    |      |
                         *    |      |
                         * 
                         * Importante al modificar la velocidad se modificara la forma en la que 
                         * deciende
                         */
                        if (CameraPosition.Y > 30)
                        {
                            MovDir = new Vector3(0f, - 1f, (CameraPosition.Z*CameraPosition.Z*CameraPosition.Z)/(4492125) *-10);
                            CameraPosition += MovDir * MovSpeed *timedelta;
                            CameraTarget += MovDir * MovSpeed*timedelta;
                        }

                        if (CameraPosition.Y <= 30)
                        {
                            MovDir = new Vector3(0f, 100f, 150 * -1f);
                            CameraTarget+= MovDir* MovSpeed *timedelta;

                            if (CameraTarget.Z < 0)
                            {
                                Crap_Graph.M = Crap_Graph.Mode.Normal;
                                ReInicialize_View();
                                
                            }

                        }

                        if (Input.KeyState.WasPress(Keys.Space))
                        {
                            MovSpeed++;
                        }
                        
                        Matrix.CreateLookAt(ref CameraPosition, ref CameraTarget, ref VectorUp, out view);

                        break;
                    }

                case Crap_Graph.Mode.Normal:
                    {


                        if (!(Input.CurrentMouseState.ScrollWheelValue == Input.PreviusMouseState.ScrollWheelValue))
                        {

                            if (Input.CurrentMouseState.ScrollWheelValue > Input.PreviusMouseState.ScrollWheelValue)
                            {
                                CameraPosition -= new Vector3(0f, 0f, Wheelspeed * timedelta);

                                if (CameraPosition.Z < MaxClose)
                                    CameraPosition.Z = MaxClose;

                            }
                            else
                            {

                                CameraPosition += new Vector3(0f, 0f, Wheelspeed * timedelta);

                            }

                        }

                        if (Input.KeyState.IsPress(Keys.Left))
                        {
                            Vector3 aux = new Vector3(ParallaxScroll * timedelta, 0f, 0f);
                            CameraPosition -= aux;
                            CameraTarget -= aux;
                        }
                        if (Input.KeyState.IsPress(Keys.Right))
                        {
                            Vector3 aux = new Vector3(ParallaxScroll * timedelta, 0f, 0f);
                            CameraPosition += aux;
                            CameraTarget += aux;
                        }



                        //Si se presiona el boton en el rectangulo se activa para girarlo
                        if ((Input.CurrentMouseState.X > 4) && (Input.CurrentMouseState.X < (Crap_Graph.IconWidth + 6)) &&
                            (Input.CurrentMouseState.Y > 4) && (Input.CurrentMouseState.Y < (Crap_Graph.IconHeigth + 6)) &&
                            (Input.CurrentMouseState.LeftButton == ButtonState.Pressed))
                        {
                            IconMov = true;
                        }
                        //Si se suelta el boton se desactiva para girarlo
                        if (Input.CurrentMouseState.LeftButton == ButtonState.Released)
                        {
                            IconMov = false;
                        }


                        //Si esta activado el para girarlo se gira
                        //Aumento de la fuerza por usuario
                        if (IconMov == true)
                        {
                            if (Input.CurrentMouseState.X > Input.PreviusMouseState.X)
                            {
                                Crap_Graph.IconMouseRotationForce.Y += ((Input.CurrentMouseState.X - Input.PreviusMouseState.X) * timedelta * FORCEGAIN);

                            }
                            if (Input.CurrentMouseState.X < Input.PreviusMouseState.X)
                            {
                                Crap_Graph.IconMouseRotationForce.Y -= ((Input.PreviusMouseState.X - Input.CurrentMouseState.X) * timedelta * FORCEGAIN);

                            }



                            if (Input.CurrentMouseState.Y > Input.PreviusMouseState.Y)
                            {
                                Crap_Graph.IconMouseRotationForce.X += ((Input.CurrentMouseState.Y - Input.PreviusMouseState.Y) * timedelta * FORCEGAIN);

                            }
                            if (Input.CurrentMouseState.Y < Input.PreviusMouseState.Y)
                            {
                                Crap_Graph.IconMouseRotationForce.X -= ((Input.PreviusMouseState.Y - Input.CurrentMouseState.Y) * timedelta * FORCEGAIN);

                            }


                        }


                        //Establesco un tope de Fuerza
                        if (Crap_Graph.IconMouseRotationForce.X > MAXFORCE)
                        {
                            Crap_Graph.IconMouseRotationForce.X = MAXFORCE;
                        }
                        if (Crap_Graph.IconMouseRotationForce.Y > MAXFORCE)
                        {
                            Crap_Graph.IconMouseRotationForce.X = MAXFORCE;
                        }

                        //Perdida gradual de la fuerza
                        if (Math.Abs(Crap_Graph.IconMouseRotationForce.X) > MINFORCE)
                            Crap_Graph.IconMouseRotationForce.X -= (Crap_Graph.IconMouseRotationForce.X * ForceLoseinPercent / 100) * timedelta;

                        if (Math.Abs(Crap_Graph.IconMouseRotationForce.Y) > MINFORCE)
                            Crap_Graph.IconMouseRotationForce.Y -= (Crap_Graph.IconMouseRotationForce.Y * ForceLoseinPercent / 100) * timedelta;



                        //Movimientos para Tres Variables
                        if (Crap_Graph.ThreeVariablesFuncitons)
                        {

                            if (Input.CurrentMouseState.MiddleButton == ButtonState.Pressed)
                            {
                                //Parece que esta contra la coherencia ese -, pero acordarse que la posicion X e Y del mouse
                                //Estan "invertidas" como la de las texturas
                                //Mientras menos Y mas arriba, mientas mas Y mas abajo
                                XRotation -= (Input.CurrentMouseState.Y - Input.PreviusMouseState.Y) * timedelta * 2;


                            }

                            //Mantienen la rotacio limitada
                            if (XRotation > 90)
                            {
                                XRotation = 90;
                            }
                            if (XRotation < 0)
                            {
                                XRotation = 0;
                            }




                        }
                        //Fin de movimientos para Tres Variables

                        if (Input.CurrentMouseState.RightButton == ButtonState.Pressed)
                        {
                            ReInicialize_View();

                        }

                        world = Matrix.CreateRotationX(MathHelper.ToRadians(XRotation));

                        //crea un vector apuntando en la direccion en la que camara mira
                        //Vector3 TransformedReference;
                        //Vector3.Transform(ref CameraReference, ref rotationmatrix, out TransformedReference);
                        //calcula la posicion en la que la camara esta mirando
                        //Vector3.Add(ref CameraPosition, ref TransformedReference, out CameraTarget);
                        //CameraTarget = TransformedReference;

                        Matrix.CreateLookAt(ref CameraPosition, ref CameraTarget, ref VectorUp, out view);


                        break;


                    }


            }



            base.Update(gameTime);
        }



        //Metodos para sacqar datos a Crap_Graph
        public Matrix Get_View()
        {
            return view;


        }

        public Matrix Get_Proyection()
        {

            return proy;

        }

        public Matrix Get_World()
        {

            return world;

        }



    }
}