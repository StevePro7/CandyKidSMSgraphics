using System;
using System.IO;

namespace GraphicsSave_BinaryFile
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            DisplayValues("output.ssm");
            Console.WriteLine("Hello World!");
        }

        private static void DisplayValues(string fileName)
        {
            if(File.Exists(fileName))
            {
                var bytes = File.ReadAllBytes(fileName);
                //using(var reader = new BinaryReader(File.Open(fileName, FileMode.Open)))
                //{
                //    aspectRatio = reader.ReadByte();
                //}


            }
        }
    }
}
