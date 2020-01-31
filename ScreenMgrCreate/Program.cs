using System;
using System.IO;

namespace ScreenMgrCreate
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			CreateDirectory("Managers");
			CreateDirectory("Screens");

			var enumManager = new EnumManager();
			var screenManager = new ScreenManager();

			var screens = File.ReadAllLines("Levels.txt");

			//enumManager.Build(screens);
			screenManager.Build(screens);

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
