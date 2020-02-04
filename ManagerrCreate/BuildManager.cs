using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class BuildManager
	{
		public void Compile(string[] managers)
		{
			var lines = new List<string>
			{
				"cd engine"
			};
			foreach(var manager in managers)
			{
				lines.Add($"sdcc -c -mz80 --opt-code-speed --peep-file ..\\peep-rules.txt --std-c99 {manager.ToLower()}_manager.c");
			}
			lines.Add("cd ..");

			lines.Add("");
			lines.Add("");

			var index = 0;
			var count = 0;
			var line = "";

			while(true)
			{
				var manager = managers[index];
				line += $"engine\\{manager.ToLower()}_manager.rel ";

				count++;
				if(count >= managers.Length)
				{
					line += "^";
					lines.Add(line);
					break;
				}

				index++;
				if(index >= 5)
				{
					line += "^";
					lines.Add(line);
					line = "";
					index = 0;
				}
			}

			File.WriteAllLines("build.bat", lines.ToArray());
		}

	}
}
