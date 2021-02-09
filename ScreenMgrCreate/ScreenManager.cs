using System.Collections.Generic;
using System.IO;

namespace ScreenMgrCreate
{
	// Sega  MegaDrive
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

			foreach (var screen in screens)
			{
				lines.Add($"#include \"{screen.ToLower()}_screen.h\"");
			}

			lines.Add("");
			lines.Add("static unsigned char curr_screen_type;");
			lines.Add("static unsigned char next_screen_type;");

			lines.Add("");
			lines.Add("static void( *load_method[ MAX_SCREEENS ] )( );");
			lines.Add("static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );");

			lines.Add("");
			lines.Add("void engine_screen_manager_init( unsigned char open_screen_type )");

			lines.Add("{");
			lines.Add("	next_screen_type = open_screen_type;");
			lines.Add("	curr_screen_type = screen_type_none;");

			lines.Add("");
			lines.Add("	// Set load methods.");
			foreach (var screen in screens)
			{
				lines.Add($"	load_method[ screen_type_{screen.ToLower()} ] = screen_{screen.ToLower()}_screen_load;");
			}

			lines.Add("");
			lines.Add("	// Set update methods.");
			foreach (var screen in screens)
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

			//lines.Add("");
			//lines.Add("		/*");
			//lines.Add("		switch( curr_screen_type )");
			//lines.Add("		{");

			//foreach (var screen in screens)
			//{
			//	lines.Add($"		case screen_type_{screen.ToLower()}:");
			//	lines.Add($"			screen_{screen.ToLower()}_screen_load();");
			//	lines.Add("				break;");
			//}

			//lines.Add("		}");
			//lines.Add("		*/");
			lines.Add("	}");

			lines.Add("");
			//lines.Add("");
			lines.Add("	update_method[ curr_screen_type ]( &next_screen_type );");
			//lines.Add("");

			//lines.Add("	/*");
			//lines.Add("	switch( curr_screen_type )");
			//lines.Add("	{");
			//foreach (var screen in screens)
			//{
			//	lines.Add($"	case screen_type_{screen.ToLower()}:");
			//	lines.Add($"		screen_{screen.ToLower()}_screen_update( &next_screen_type );");
			//	lines.Add("			break;");
			//}

			//lines.Add("	}");
			//lines.Add("	*/");
			lines.Add("}");

			File.WriteAllLines("Managers/screen_manager.c", lines.ToArray());
		}

		public void Construct(string[] screens)
		{
			foreach (var screen in screens)
			{
				ConstructH(screen);
				ConstructC(screen);
			}
		}

		private void ConstructH(string screen)
		{
			var underscore = "__";
			var lines = new List<string>
			{
				$"#ifndef {underscore}{screen.ToUpper()}_SCREEN_H{underscore}",
				$"#define {underscore}{screen.ToUpper()}_SCREEN_H{underscore}",
				"",

				$"void screen_{screen.ToLower()}_screen_load();",
				$"void screen_{screen.ToLower()}_screen_update( unsigned char *screen_type );",

				"",
				$"#endif//{underscore}{screen.ToUpper()}_SCREEN_H{underscore}",
			};

			var path = $"Screens/{screen.ToLower()}_screen.h";
			File.WriteAllLines(path, lines.ToArray());
		}

		private void ConstructC(string screen)
		{
			var lines = new List<string>
			{
				$"#include \"{screen.ToLower()}_screen.h\"",
				"#include \"enum_manager.h\"",
				"#include \"font_manager.h\"",
				"",
				$"void screen_{screen.ToLower()}_screen_load()",
				"{",
				$"	engine_font_manager_text( \"{screen.ToUpper()} SCREEN!!\", 10, 2 );",
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

		private void ConstructCX(string screen)
		{
			var lines = new List<string>
			{
				$"#include \"{screen.ToLower()}_screen.h\"",
				"#include \"enum_manager.h\"",
				"#include \"font_manager.h\"",
				"",
				$"void screen_{screen.ToLower()}_screen_load()",
				"{",
				$"	engine_font_manager_draw_text( \"{screen.ToUpper()} SCREEN!!\", 10, 2 );",
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
