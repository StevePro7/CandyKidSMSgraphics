using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace AstroForceBuild
{
	public class ListManager
	{
		public ListManager()
		{
			Characters = new List<string>();
			Characters.Clear();
		}

		public void Process(string[] dirs)
		{
			//const string list_root = "dev";
			//const string save_root = "out";

			//var dir = dirs[0];
			foreach (var dir in dirs)
			{
				string list_path = $"{Constants.LIST_ROOT}/{dir}/";
				var list_files = Directory.GetFiles(list_path);
				//var list_file = list_files[0];
				foreach (var list_file in list_files)
				{
					ProcessLines(list_file);
				}
			}
			
		}

		public void ProcessLines(string list_file)
		{
			//var head_file = list_file.Replace(list_path, String.Empty);
			//var impl_file = head_file.Replace(".h", ".c");
			//var head_type = head_file.Replace(".", "_");
			//head_type = $"_{head_type.ToUpper()}_";

			var open_lines = File.ReadAllLines(list_file);
			foreach(var open_line in open_lines)
			{
				if (open_line.Length == 0)
				{
					continue;
				}
				// https://stackoverflow.com/questions/7187570/how-can-i-check-if-the-first-character-of-my-string-is-a-space-or-tab-character
				if (char.IsWhiteSpace(open_line[0]))
				{
					continue;
				}

				var text = open_line[0].ToString();
				if (!Characters.Contains(text))
				{
					Characters.Add(text);
				}
			}
		}

		public IList<string> Characters { get; private set; }
	}
}
