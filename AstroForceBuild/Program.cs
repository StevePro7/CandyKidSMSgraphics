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
			//lm.Process();
			lm.ProcessLines("dev/Wars/", "dev/Wars/ww2ship.h");

			var bob = lm.Characters;
			Console.WriteLine();
		}
	}
}
