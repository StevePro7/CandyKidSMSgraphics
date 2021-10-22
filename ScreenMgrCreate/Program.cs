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
			CreateDirectory("Objects");
			CreateDirectory("Screens");

			var buildManager = new BuildManager();
			var enumManager = new EnumManager();
			var globalManager = new GlobalManager();
			var objectManager = new ObjectManager();
			var screenManager = new ScreenManager();

			var screens = File.ReadAllLines("Levels.txt");
			screens = GetScreens(screens);

			var managers = File.ReadAllLines("engine.txt");
			managers = GetManagers(managers);

			objectManager.Build(managers);

			/*
			buildManager.Compile(screens);
			enumManager.Build(screens);
			globalManager.Build(screens);
			screenManager.Build(screens);
			screenManager.Construct(screens);
			//screenManager.Switch(screens);
			*/
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
		private static string[] GetManagers(string[] managers)
		{
			IList<string> newManagers = new List<string>();
			foreach (var manager in managers)
			{
				if (manager.StartsWith("--"))
				{
					continue;
				}

				newManagers.Add(manager);
			}

			return newManagers.ToArray();
		}
	}
}
