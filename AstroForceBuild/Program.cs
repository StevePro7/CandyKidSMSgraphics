﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace AstroForceBuild
{
	internal class Program
	{
		private static void Main()
		{
			//var lm = new ListManager();
			//var bm = new BuildManager();
			var sm = new ScriptManager();
			var cm = new CommentManager();
			//bm.Initialize();
			//bm.Save("Wars");
			//bm.SaveFile("Wars", "dev/Wars/ww2plane.h");

			//var dirs = new string[] { "base" };
			var dirs = new string[] { "Enemies", "Fortresses", "General", "Intros", "Monsters", "Players", "Spaces", "Stages", "Vulcans", "Wars" };
			//bm.Process(dirs);
			//sm.Process(dirs);
			cm.Process(dirs);

			//lm.Process(dirs);
			//lm.ProcessLines("dev/Wars/", "dev/Wars/ww2ship.h");

			Console.WriteLine();
		}
	}
}
