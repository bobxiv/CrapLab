
#region Using Statements
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace Crap_Graph
{
    /// <summary>
    /// This is a game component that implements IUpdateable.
    /// </summary>
    public class FPS : Microsoft.Xna.Framework.DrawableGameComponent 
    {

        private float fps;
        private float UpdateInterval = 1f;
        private float TimeSinceLastUpdate = 0f;
        private float FrameCount=0;

        GraphicsDeviceManager graphics;
        Game game;
        
              
        public FPS(Game game)
            : this(game,false,false, game.TargetElapsedTime) { }
       
        public FPS(Game game,bool IsSyncronizedWithVerticalRetrace, bool IsFixedTimeStep,TimeSpan TargetElapsedTime  ):base(game )
        {

            this.game = (Game)game;
           graphics = (GraphicsDeviceManager)game.Services.GetService(typeof(IGraphicsDeviceManager));

            graphics.SynchronizeWithVerticalRetrace = IsSyncronizedWithVerticalRetrace;

            Game.IsFixedTimeStep = IsFixedTimeStep;

            Game.TargetElapsedTime = TargetElapsedTime;


        }

        public FPS(Game game, bool IsSyncronizedWithVerticalRetrace, bool IsFixedTimeStep) : this(game, IsSyncronizedWithVerticalRetrace, IsFixedTimeStep, game.TargetElapsedTime) { }
        


        /// <summary>
        /// Allows the game component to perform any initialization it needs to before starting
        /// to run.  This is where it can query for any required services and load content.
        /// </summary>
        public override void Initialize()
        {




            // TODO: Add your initialization code here

            base.Initialize();
        }


        /// <summary>
        /// Allows the game component to update itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        public override void Update(GameTime gameTime)
        {
            // TODO: Add your update code here

            base.Update(gameTime);
        }


        //aca se mete cada vez que dibuja
        public sealed override void Draw(GameTime gameTime)
        {
                     //notar qeu gametime.elapsedtime mide la cantidad de timepod esde el ultimo update, y
            //como el update y el draw lo hacen pegados me da igual 
            //pido el timepo en segundos poruqe estoy midiendo frames por segundo    
        float elapsed = (float)gameTime.ElapsedRealTime.TotalSeconds;
            //aumentan los frames dibujados
        FrameCount++;
            //incremento el timepo que ocurrio desde el ultimo update
        TimeSinceLastUpdate += elapsed;

            //si ocurrio mas tiempo que el intervalo en el que estoy midiendo los fps... claro aca sonn segundos
        if (TimeSinceLastUpdate > UpdateInterval)
        {
            //acas eria frames/1 o cercano a 1, capaz que se paso un  poqquito el inteval, despuesd etodo no va a 
            //cerrar siempre entero elñ intevalo en la realidad!!! :D
            fps = (FrameCount / TimeSinceLastUpdate);
        
            //lo muestro dependiendo de la consola donde lo dese ver
        #if XBOX360
        System.Diagnostics.Debug.WriteLine(“FPS: “ + fps.ToString());
        #else
        
        Game.Window.Title = "FPS: " + fps.ToString();
        #endif
        
            //reinicia el contador de frames
        FrameCount = 0;
            //le resto al tiempo desde el ultimo update el espacio de intervalo
        TimeSinceLastUpdate -= UpdateInterval;

        }

          /*  
        SpriteBatch a = new SpriteBatch(graphics.GraphicsDevice);
        SpriteFont b=game.content.Load<SpriteFont>("SpriteFont1");
        a.Begin();
        a.DrawString(b, fps.ToString(), new Vector2(0,0), Color.Black);
        a.End();
            */

        base.Draw(gameTime);
            
        }


    }

}