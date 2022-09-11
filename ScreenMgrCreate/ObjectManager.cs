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
				var nameL = manager.ToLower();
				var file1 = nameL + "_manager";

				var header1 = $"_{manager.ToUpper()}_MANAGER_H_";
				var lines10 = new List<string>
				{
					"#ifndef " + header1,
					"#define " + header1,
					"",

					"#endif//" + header1,
				};

				File.WriteAllLines("Managers/" + file1 + ".h", lines10.ToArray());

				var lines11 = new List<string>
				{
					"#ifndef " + header1,
					"#define " + header1,
					"",
					"#include \"../object/" + nameL + "_object.h",
					"",
					"// Global variable.",
					"extern struct_" + nameL + "_object global_" + nameL + "_object;\"",
					"",
					"#endif//" + header1,
				};

				File.WriteAllLines("Managers2/" + file1 + ".h", lines11.ToArray());

				var line1 = "#include \"" + file1 + ".h" + "\"";
				File.WriteAllText("Managers/" + file1 + ".c", line1);

				var lines21 = new List<string>
				{
					"#include \"" + file1 + ".h" + "\"",
					"",
					"// Global variable.",
					"struct_" + nameL + "_object global_" + nameL + "_object;",
				};

				File.WriteAllLines("Managers2/" + file1 + ".c", lines21.ToArray());


				// Objects.
				var file2 = nameL + "_object";

				var header2 = $"_{manager.ToUpper()}_OBJECT_H_";
				var lines20 = new List<string>
				{
					"#ifndef " + header2,
					"#define " + header2,
					"",

					"#endif//" + header2,
				};

				File.WriteAllLines("Objects/" + file2 + ".h", lines20.ToArray());

				var line2 = "#include \"" + file2 + ".h" + "\"";
				File.WriteAllText("Objects/" + file2 + ".c", line2);
			}
		}

	}
}
