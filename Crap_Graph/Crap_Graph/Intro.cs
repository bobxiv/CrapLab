using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using System.IO;


namespace Crap_Graph
{
          
    public struct VertexPositionNormalColor
        {
            public Vector3 Position;

            public Color Color;

            public Vector3 Normal;

            public static int Size = (sizeof(float) * 7);

            public static VertexElement[] VE = new VertexElement[]{
                new VertexElement(0,0,VertexElementFormat.Vector3,VertexElementMethod.Default,VertexElementUsage.Position,0),
                new VertexElement(0,sizeof(float)*3,VertexElementFormat.Color,VertexElementMethod.Default,VertexElementUsage.Color,0),
                new VertexElement(0,sizeof(float)*4,VertexElementFormat.Vector3,VertexElementMethod.Default,VertexElementUsage.Normal,0),
            
            };

    }


    class Intro
    {
        public Intro(Game game){

            device = game.GraphicsDevice;

            Read_Heigthmap();

            int[] Index = Load_IBuffer();
            IB = new IndexBuffer(device , typeof(int), (W - 1) * (H - 1) * 6, BufferUsage.WriteOnly );
            IB.SetData(Index);

            VertexPositionNormalColor[] Vertex = Load_VBuffer();
            VB = new VertexBuffer(device, VertexPositionNormalColor.Size * W * H, BufferUsage.WriteOnly);
            VB.SetData<VertexPositionNormalColor>(Vertex);

            device.Vertices[0].SetSource(VB, 0, VertexPositionNormalColor.Size);
            device.Indices = IB;
            

        }
        private GraphicsDevice device;

        public void Draw_Logo()
        {
            
            device.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, W * H, 0, (W - 1) * (H - 1) * 2);
            

        }

        private VertexPositionNormalColor[] Load_VBuffer()
        {
            VertexPositionNormalColor[] vertices;

            vertices = new VertexPositionNormalColor[W * H];

            // VertexPositionColor[] vertices;

            //vertices = new VertexPositionColor[W*H];

            //la estructura linealiza el arreglo 'pensado para una matriz'            
            for (int x = 0; x < W; x++)
            {
                for (int y = 0; y < H; y++)
                {
                    //como la posicion tiene que ver con los valores que tomasn los auxiliares del for, son todos quidistantes entre si
                    //a exepcion por la modificacion que hace el hei
                    //con hei se carga los valores de altura, que determino el archivo bmp
                    vertices[x + y * W].Position = new Vector3(x, y, hei[x, y]);
                    //vertices[x + y * W].Normal = new Vector3(0f, 0f, 1f);
                    //aca elige segun la altura
                    /*Se divide en 4 etapas la imagen, correspodientes o mejor dicho de igual tamaño,
                     * considerando el maximo y minimo del dibujo, maximo y minimo de altura
                     * entonces el primer escalafon va azul
                     * el segundo escalafon va vere
                     * el tercer escalafon va marron
                     * y el mas alto y ultimo va blanco
                     * 
                     * esto es, por nieve, arriba, tierra abajo, pasto, ams abajo, y un lago abajo de todo
                     
                     * Notar que si entro en alguna, ya esat que no siga preguntando por las otras, poruqe va a ser siertas las de abajo, si lo es
                     * la de arriba, y entonces quedaria todo blanco
                     */
                    if (hei[x, y] < min + ((max - min) / 4))
                    {
                        vertices[x + y * W].Color = Color.CornflowerBlue;
                    }
                    else
                    {
                        if (hei[x, y] < min + ((max - min) * 2 / 4))
                        {
                            vertices[x + y * W].Color = new Color(0, 150, 0, 255);
                        }
                        else
                        {
                            if (hei[x, y] < (min + (max - min) * 3 / 4))
                            {
                                vertices[x + y * W].Color = Color.Black;
                            }
                            else
                            {
                                vertices[x + y * W].Color = new Color(0, 255, 0, 255);
                            }
                        }

                    }
                }
            }



            //Aca cargo als normales
            for (int x = 1; x < W - 1; x++)//notar que en los dos empiezio del segundo y termino en el enteultimo
            {
                for (int y = 1; y < H - 1; y++)
                {
                    Vector3 normX = new Vector3((vertices[x - 1 + y * W].Position.Z - vertices[x + 1 + y * W].Position.Z) / 2, 0, 1);
                    Vector3 normY = new Vector3(0, (vertices[x + (y - 1) * W].Position.Z - vertices[x + (y + 1) * W].Position.Z) / 2, 1);
                    vertices[x + y * W].Normal = normX + normY;
                    vertices[x + y * W].Normal.Normalize();

                }
            }




            //vertices[x + y * W].Color = Color.White;



            //este de aca abajo dibuja dos triangulitos chotos nomas, el e arriba una serie de 6 triangulos
            /*

            vertices[0].Position =new Vector3(-1f,0f,0f);
            vertices[0].Color = Color.White;

            vertices[1].Position =new Vector3(0f,0f,0f);
            vertices[1].Color = Color.White;

            vertices[2].Position =new Vector3(1f,0f,0f);
            vertices[2].Color = Color.White;

            vertices[3].Position =new Vector3(0f,1f,0f);
            vertices[3].Color = Color.White;

            vertices[4].Position = new Vector3(1f, 1f, 0f);
            vertices[4].Color = Color.White;
            */

            return vertices;

        }

        private VertexBuffer VB;

        private int[] Load_IBuffer()
        {
            int[] indices = new int[(W - 1) * (H - 1) * 6];


            for (int x = 0; x < W - 1; x++)
            {
                for (int y = 0; y < H - 1; y++)
                {
                    indices[(x + y * (W - 1)) * 6] = (x + 1) + (y + 1) * W;
                    indices[(x + y * (W - 1)) * 6 + 1] = (x + 1) + y * W;
                    indices[(x + y * (W - 1)) * 6 + 2] = x + y * W;

                    indices[(x + y * (W - 1)) * 6 + 3] = (x + 1) + (y + 1) * W;
                    indices[(x + y * (W - 1)) * 6 + 4] = x + y * W;
                    indices[(x + y * (W - 1)) * 6 + 5] = x + (y + 1) * W;
                }
            }

            return indices;


        }

        private IndexBuffer IB;

        private int offset;

        private int max = 0;
        private int min = 255;

        //Estos son las dimensiones de la imagen
        private int W;
        private int H;

        //Aca s guarda la info de la imagen
        private int[,] hei;

        private void Read_Heigthmap()
        {
            FileStream fs;
            fs = new FileStream("./Content/Images/IntroPI.bmp", System.IO.FileMode.Open, System.IO.FileAccess.Read);

            BinaryReader r = new BinaryReader(fs);

            r.BaseStream.Seek(10, SeekOrigin.Current);

            offset = (int)r.ReadUInt32();

            r.BaseStream.Seek(4, SeekOrigin.Current);



            W = (int)r.ReadUInt32();

            H = (int)r.ReadUInt32();


            r.BaseStream.Seek(offset - 26, SeekOrigin.Current);

            hei = new int[W, H];





            for (int x = 0; (x < H); x++)
            {

                for (int y = 0; (y < W); y++)
                {

                    //Importante aca leo bytes, no ints, el bmp tiene sus valores como
                    //como  char o valores ASCII


                    int val = (int)r.ReadByte();

                    val += (int)r.ReadByte();

                    val += (int)r.ReadByte();

                    //segun el tipejo lo normalizo con esto???
                    val /= 30;

                    //aca no da cambios visibles este orden de llenado del arreglo???

                    hei[y, x] = val;
                    //hei[W-1-y,H-1-x]=val;

                    //con esto puedo ver cuales son los maximos y los minimos de mi imagen en particular
                    if (max < val)
                    {
                        max = val;
                    }
                    if (min > val)
                    {
                        min = val;

                    }




                }




            }
        }



    }
}


