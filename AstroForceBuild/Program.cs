using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace AstroForceBuild
{
	internal class Program
	{
		private static void Main()
		{
			var lm = new ListManager();
			var dirs = new string[] { "Enemies", "Fortresses", "General", "Intros", "Monsters", "Players", "Spaces", "Stages", "Vulcans", "Wars" };
			
			lm.Process(dirs);
			//lm.ProcessLines("dev/Wars/", "dev/Wars/ww2ship.h");

			var bob = lm.Characters;
			foreach (var b in bob)
			{
				Console.WriteLine(b);
			}
			Console.WriteLine();
		}
	}
}
