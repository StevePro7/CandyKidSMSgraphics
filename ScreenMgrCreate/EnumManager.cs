using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class EnumManager
	{
		public void Build(string[] screens)
		{
			var lines = new List<string>
			{
				"#ifndef _ENUM_MANAGER_H_",
				"#define _ENUM_MANAGER_H_",
				"",

				"typedef enum tag_enum_screen_type",
				"{"
			};

			var index = 0;
			foreach(var screen in screens)
			{
				lines.Add($"	screen_type_{screen} = {index++},");
			}

			lines.Add("");
			lines.Add("}");

			lines.Add("");
			lines.Add("#endif//_ENUM_MANAGER_H_");

			File.WriteAllLines("Managers/enum_manager.h", lines.ToArray());
		}
	}
}
