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

		public void Process()
		{
			string dirX = "Wars";

			const string list_root = "dev";
			//const string save_root = "out";

			string list_path = $"{list_root}/{dirX}/";
			var list_files = Directory.GetFiles(list_path);
			var list_file = list_files[0];
		}

		public void ProcessLines(string list_path, string list_file)
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
