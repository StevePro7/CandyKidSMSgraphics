using MonoGameManager;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace MonoGameManager
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			CreateDirectory("Managers");
			//CreateDirectory("Screens");
			CreateDirectory("TheGame");
			if (File.Exists("Registration.cs")) { File.Delete("Registration.cs"); }

			var myManager = new MyManager();
			var newManager = new GameManager();
			var iocBinding = new IoCBinding();

			var managers = File.ReadAllLines("managers.txt");
			managers = GetManagers(managers);

			myManager.ProcessAll(managers);
			newManager.ProcessAll(managers);
			iocBinding.ProcessAll(managers);
			Console.WriteLine();
		}

		private static void CreateDirectory(string directory)
		{
			if (Directory.Exists(directory))
			{
				var files = Directory.GetFiles(directory);
				foreach(var file in files)
				{
					File.Delete(file);
				}
			}
			if (!Directory.Exists(directory))
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

				newManagers.Add(manager.Trim());
			}

			return newManagers.ToArray();
		}
	}
}
