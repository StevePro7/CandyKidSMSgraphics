using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

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

			var screens = File.ReadAllLines("Levels_BAK.txt");
			screens = GetScreens(screens);

			//buildManager.Compile(screens);
			//enumManager.Build(screens);
			//globalManager.Build(screens);
			//screenManager.Build(screens);
			//screenManager.Construct(screens);
			screenManager.Switch(screens);

			Console.WriteLine();
		}

		private static void CreateDirectory(string directory)
		{
			if(!Directory.Exists(directory))
			{
				Directory.CreateDirectory(directory);
			}
		}

		private static string[] GetScreens(string[] screens)
		{
			IList<string> newScreens = new List<string>();
			foreach (var screen in screens)
			{
				if (screen.StartsWith("--"))
				{
					continue;
				}

				newScreens.Add(screen);
			}

			return newScreens.ToArray();
		}
	}
}
