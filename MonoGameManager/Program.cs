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
			CreateDirectory("TheGame");

			var myManager = new MyManager();
			var newManager = new NewManager();

			var managers = File.ReadAllLines("managers.txt");
			managers = GetManagers(managers);

			newManager.ProcessAll(managers);
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

				newManagers.Add(manager.Trim());
			}

			return newManagers.ToArray();
		}
	}
}
