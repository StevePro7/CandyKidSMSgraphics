﻿using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	public class ScreenManager
	{
		public void Build(string[] screens)
		{
			var lines = new List<string>
			{
				"#include \"screen_manager.h\"",
				"#include \"global_manager.h\"",
				"#include \"enum_manager.h\"",

				"",
				"// Screens"
			};

			foreach(var screen in screens)
			{
				lines.Add($"#include \"..\\screen\\{screen.ToLower()}_screen.h\"");
			}

			lines.Add("");
			lines.Add("static void( *load_method[ MAX_SCREEENS ] )( );");
			lines.Add("static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );");

			lines.Add("");
			lines.Add("static unsigned char curr_screen_type;");
			lines.Add("static unsigned char next_screen_type;");

			lines.Add("");
			lines.Add("void engine_screen_manager_init(unsigned char open_screen_type)");

			lines.Add("{");
			lines.Add("	next_screen_type = open_screen_type;");
			lines.Add("	curr_screen_type = screen_type_none;");

			lines.Add("");
			lines.Add("	// Set load methods.");

			foreach(var screen in screens)
			{
				lines.Add($"	load_method[ screen_type_{screen.ToLower()} ] = screen_{screen.ToLower()}_screen_load;");
			}

			lines.Add("");
			lines.Add("	// Set update methods.");

			foreach(var screen in screens)
			{
				lines.Add($"	update_method[ screen_type_{screen.ToLower()} ] = screen_{screen.ToLower()}_screen_update;");
			}
			lines.Add("}");


			lines.Add("");
			lines.Add("void engine_screen_manager_update()");

			lines.Add("{");

			lines.Add("	if( curr_screen_type != next_screen_type )");
			lines.Add("	{");
			lines.Add("		curr_screen_type = next_screen_type;");
			lines.Add("		load_method[ curr_screen_type ]();");
			lines.Add("	}");

			lines.Add("");
			lines.Add("	update_method[ curr_screen_type ]( &next_screen_type );");
			lines.Add("}");

			File.WriteAllLines("Managers/screen_manager.c", lines.ToArray());
		}

		public void Construct(string[] screens)
		{
			var screen = screens[0];
			ConstructH(screen);
			ConstructC(screen);
		}

		private void ConstructH(string screen)
		{
			var lines = new List<string>
			{
				"#ifndef _NONE_SCREEN_H_",
				"#define _NONE_SCREEN_H_",
				"",

				$"void screen_{screen.ToLower()}_screen_load();",
				$"void screen_{screen.ToLower()}_screen_update( unsigned char *screen_type );",

				"",
				"#endif//_NONE_SCREEN_H_",
			};

			var path = $"Screens/{screen.ToLower()}_screen.h";
			File.WriteAllLines(path, lines.ToArray());
		}

		private void ConstructC(string screen)
		{
			var lines = new List<string>
			{
				$"#include \"{screen.ToLower()}_screen.h\"",
				"#include \"..\\engine\\enum_manager.h\"",
				"",
				$"void screen_{screen.ToLower()}_screen_load()",
				"{",
				"}",
				"",
				$"void screen_{screen.ToLower()}_screen_update( unsigned char *screen_type )",
				"{",
				$"	*screen_type = screen_type_{screen.ToLower()};",
				"}",
			};

			var path = $"Screens/{screen.ToLower()}_screen.c";
			File.WriteAllLines(path, lines.ToArray());
		}
	}
}