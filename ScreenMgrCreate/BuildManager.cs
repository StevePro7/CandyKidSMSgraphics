using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class BuildManager
	{
		public void Compile(string[] screens)
		{
			var lines = new List<string>
			{
				"cd screen"
			};
			foreach(var screen in screens)
			{
				lines.Add($"sdcc -c -mz80 --opt-code-speed --peep-file ..\\peep-rules.txt --std-c99 {screen.ToLower()}_screen.c");
			}
			lines.Add("cd ..");

			lines.Add("");
			lines.Add("");
			lines.Add("");

			foreach(var screen in screens)
			{
				lines.Add($"screen\\{screen.ToLower()}_screen.rel ^");
			}


			File.WriteAllLines("build.bat", lines.ToArray());
		}

	}
}
