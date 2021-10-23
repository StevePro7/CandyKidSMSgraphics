using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class ObjectManager
	{
		public void Build(string[] managers)
		{
			//var manager = managers[0];
			foreach (var manager in managers)
			{
				// Managers.
				var file1 = manager.ToLower() + "_manager";

				var header1 = $"_{manager.ToUpper()}_OBJECT_H_";
				var lines = new List<string>
			{
				"#ifndef " + header1,
				"#define " + header1,
				"",
				//"",
				//"",

				"#endif//" + header1,
			};

				File.WriteAllLines("Managers/" + file1 + ".h", lines.ToArray());

				var line1 = "#include \"" + file1 + ".h" + "\"";
				File.WriteAllText("Managers/" + file1 + ".c", line1);


				// Objects.
				var file2 = manager.ToLower() + "_object";

				var header2 = $"_{manager.ToUpper()}_OBJECT_H_";
				var lines2 = new List<string>
			{
				"#ifndef " + header2,
				"#define " + header2,
				"",
				//"",
				//"",

				"#endif//" + header2,
			};

				File.WriteAllLines("Objects/" + file2 + ".h", lines.ToArray());

				var line2 = "#include \"" + file2 + ".h" + "\"";
				File.WriteAllText("Objects/" + file2 + ".c", line2);
			}
		}

	}
}
