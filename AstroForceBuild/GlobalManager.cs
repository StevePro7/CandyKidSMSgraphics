using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class GlobalManager
	{
		public void Build(string[] screens)
		{
			var lines = new List<string>
			{
				"#ifndef _GLOBAL_MANAGER_H_",
				"#define _GLOBAL_MANAGER_H_",
				"",

				$"#define MAX_SCREEENS			{screens.Length}",
				"",
			};

			File.WriteAllLines("ManagersX/global_manager.h", lines.ToArray());
		}

	}
}
