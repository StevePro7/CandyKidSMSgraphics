using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ScreenMgrCreate
{
	public class BuildManager
	{
		public void Compile(string[] managersX, string[] screensX)
		{
			var managers = managersX.OrderBy(x => x).ToArray();
			var screens = screensX.OrderBy(x => x).ToArray();
			var lines = new List<string>();

			var lines1 = new List<string>
			{
				"cd engine"
			};
			foreach (var manager in managers)
			{
				lines1.Add($"sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 {manager.ToLower()}_manager.c");
			}
			lines1.Add("cd ..");
			lines1.Add("");
			lines1.Add("");
			lines1.Add("");


			var lines2 = new List<string>
			{
				"cd object"
			};
			foreach (var manager in managers)
			{
				lines2.Add($"sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 {manager.ToLower()}_object.c");
			}
			lines2.Add("cd ..");
			lines2.Add("");
			lines2.Add("");
			lines2.Add("");


			var lines3 = new List<string>
			{
				"cd screen"
			};
			foreach(var screen in screens)
			{
				lines3.Add($"sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 {screen.ToLower()}_screen.c");
			}
			lines3.Add("cd ..");
			lines3.Add("");
			lines3.Add("");
			lines3.Add("");

			lines.AddRange(lines1);
			lines.AddRange(lines2);
			lines.AddRange(lines3);



			var maxim = 5;
			var index = 0;
			var halve = 0;
			var count = 0;
			var line = "";


			// Managers.
			while(true)
			{
				var manager = managers[index];
				line += $"engine/{manager.ToLower()}_manager.rel ";

				count++;
				if(count >= screens.Length)
				{
					line += "^";
					lines.Add(line);
					break;
				}

				index++;
				halve++;
				if(halve >= maxim)
				{
					line += "^";
					lines.Add(line);
					line = "";
					halve = 0;
				}
			}

			lines.Add("");
			lines.Add("");
			lines.Add("");

			// Objects.
			index = 0;
			halve = 0;
			count = 0;
			line = "";
			while (true)
			{
				var manager = managers[index];
				line += $"object/{manager.ToLower()}_object.rel ";

				count++;
				if (count >= screens.Length)
				{
					line += "^";
					lines.Add(line);
					break;
				}

				index++;
				halve++;
				if (halve >= maxim)
				{
					line += "^";
					lines.Add(line);
					line = "";
					halve = 0;
				}
			}

			lines.Add("");
			lines.Add("");
			lines.Add("");

			// Screens.
			index = 0;
			halve = 0;
			count = 0;
			line = "";
			while (true)
			{
				var screen = screens[index];
				line += $"screen/{screen.ToLower()}_screen.rel ";

				count++;
				if (count >= screens.Length)
				{
					line += "^";
					lines.Add(line);
					break;
				}

				index++;
				halve++;
				if (halve >= maxim)
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
