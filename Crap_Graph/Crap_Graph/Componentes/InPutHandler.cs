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
    public interface IInputHandler{
        Keyboardhandler KeyState { get;}
        MouseState CurrentMouseState{ get;}
        MouseState PreviusMouseState{ get;}
        
    }



    //Este componente contiene una clase que se encarga de actualizar y controlar los eventos del teclado
    //Ademas contiene los estados del mouse
    //Es un servicio ie es posible utilizarlo desde otros componentes
    public class InPutHandler : Microsoft.Xna.Framework.GameComponent, IInputHandler
    {
        //Cierra la ventana si se presiona escape
        private Game Main;

        //Mantiene los estados del mouse
        private MouseState CMouseState;
        private MouseState PMouseState;

        //Se encarga de actualizar los estados e interpretar los eventos del teclado
        private Keyboardhandler Press;


        public InPutHandler(Game game)
            : base(game)
        {
            game.Services.AddService(typeof(IInputHandler), this);
            Main = game;

            game.IsMouseVisible = true;
            PMouseState = Mouse.GetState();

            Press = new Keyboardhandler();
            
        }


        public override void Initialize()
        {
            

            base.Initialize();
        }


        public override void Update(GameTime gameTime)
        {
            //Actualizo el estado del mouse
            PMouseState = CMouseState;
            CMouseState = Mouse.GetState();

            //Actualizo el KeyboardHandler
            Press.Update();


            if (Press.IsPress(Keys.Escape))
            {

                Main.Exit();

            }
           
            base.Update(gameTime);
        }





                #region Miembros de IInPutHandler
        public Keyboardhandler KeyState
        {
            get { return (Press); }
        }

          #endregion

         #region Miembros de IInPutHandler

        public MouseState CurrentMouseState
        {
            get { return (CMouseState) ; }
        }

        public MouseState PreviusMouseState
        {
            get { return (PMouseState) ; }
        }

            #endregion

    }


    //Esta clase se encarga de interpretar los estados del tectado y sus eventos
    public class Keyboardhandler
    {
        //el valor anterior
        KeyboardState PreviusState;

        //el valor actual
        KeyboardState CurrentState;

        public Keyboardhandler()
        {

            CurrentState = Keyboard.GetState();


        }

        public void Update()
        {

            PreviusState = CurrentState;

            CurrentState = Keyboard.GetState();


        }

        public bool IsPress(Keys key)
        {

            return (CurrentState.IsKeyDown(key));

        }

        public bool IsHoldingPress(Keys key)
        {

            return (CurrentState.IsKeyDown(key) && PreviusState.IsKeyDown(key));

        }

        public bool WasPress(Keys key)
        {

            return (CurrentState.IsKeyDown(key) && PreviusState.IsKeyUp(key));

        }

        public bool HasRelese(Keys key)
        {

            return (CurrentState.IsKeyUp(key) && PreviusState.IsKeyDown(key));

        }



    }


}