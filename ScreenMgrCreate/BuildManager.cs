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

			var index = 0;
			var halve = 0;
			var count = 0;
			var line = "";

			while(true)
			{
				var screen = screens[index];
				line += $"screen\\{screen.ToLower()}_screen.rel ";

				count++;
				if(count >= screens.Length)
				{
					line += "^";
					lines.Add(line);
					break;
				}

				index++;
				halve++;
				if(halve >= 5)
				{
					line += "^";
					lines.Add(line);
					line = "";
					halve = 0;
				}
			}

			File.WriteAllLines("build.bat", lines.ToArray());
		}

	}
}
