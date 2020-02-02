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

			var buildManager = new BuildManager();
			var enumManager = new EnumManager();
			var globalManager = new GlobalManager();
			var screenManager = new ScreenManager();

			var screens = File.ReadAllLines("Levels.txt");

			buildManager.Compile(screens);
			enumManager.Build(screens);
			globalManager.Build(screens);
			screenManager.Build(screens);
			screenManager.Construct(screens);

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
