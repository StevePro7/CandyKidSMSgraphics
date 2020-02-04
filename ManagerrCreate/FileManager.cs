using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class FileManager
	{
		public void Build(string[] managers)
		{
			foreach (var manager in managers)
			{
				BuildH(manager);
				BuildC(manager);
			}
		}

		private void BuildH(string manager)
		{
			var lines = new List<string>();
			lines.Clear();

			lines.Add($"#ifndef _{manager.ToUpper()}_MANAGER_H_");
			lines.Add($"#define _{manager.ToUpper()}_MANAGER_H_");

			lines.Add("");
			lines.Add($"void engine_{manager.ToLower()}_manager_init();");
			lines.Add($"void engine_{manager.ToLower()}_manager_load();");
			lines.Add($"void engine_{manager.ToLower()}_manager_update();");
			lines.Add("");

			lines.Add($"#endif//_{manager.ToUpper()}_MANAGER_H_");


			var path = $"Managers/{manager.ToLower()}_manager.h";
			File.WriteAllLines(path, lines.ToArray());
		}

		private void BuildC(string manager)
		{
			var lines = new List<string>();
			lines.Clear();

			lines.Add($"#include \"{manager.ToLower()}_manager.h\"");
			lines.Add("");

			lines.Add($"void engine_{manager.ToLower()}_manager_init()");
			lines.Add("{");
			lines.Add("}");
			lines.Add("");

			lines.Add($"void engine_{manager.ToLower()}_manager_load()");
			lines.Add("{");
			lines.Add("}");
			lines.Add("");

			lines.Add($"void engine_{manager.ToLower()}_manager_update()");
			lines.Add("{");
			lines.Add("}");
			lines.Add("");

			var path = $"Managers/{manager.ToLower()}_manager.c";
			File.WriteAllLines(path, lines.ToArray());
		}
	}
}
