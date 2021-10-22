using System;
using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class ObjectManager
	{
		public void BuildObjects(string[] managers)
		{
			var manager = managers[0];
			var header = $"_{manager.ToUpper()}_MANAGER_H_";

			var lines = new List<string>
			{
				"#ifndef " + header,
				"#define " + header,
				"",
				"",
				"",

				"##endif//" + header,
			};

		}
	}
}
