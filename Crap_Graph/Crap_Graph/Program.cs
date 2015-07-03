using System;

namespace Crap_Graph
{
    static class Program
    {
        

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static void Main(string[] args)
        {
            using ( Crap_Graph game = new Crap_Graph())
            {
                game.Run();
            }
        }
    }
}

