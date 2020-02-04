using System;
using System.IO;

namespace ScreenMgrCreate
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			CreateDirectory("Managers");

			var buildManager = new BuildManager();
			var fileManager = new FileManager();

			var managers = File.ReadAllLines("Managers.txt");

			buildManager.Compile(managers);
			fileManager.Build(managers);

			Console.WriteLine();
		}

		private static void CreateDirectory(string directory)
		{
			if(!Directory.Exists(directory))
			{
				Directory.CreateDirectory(directory);
			}
		}
	}
}
