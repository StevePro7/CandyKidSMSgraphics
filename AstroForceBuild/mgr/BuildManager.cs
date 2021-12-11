using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace AstroForceBuild
{
	public class BuildManager
	{
		private bool skip;

		public BuildManager()
		{
			OutLines = new List<string>();
			skip = false;
		}
		public void Initialize()
		{
			if (!Directory.Exists(Constants.SAVE_ROOT))
			{
				Directory.CreateDirectory(Constants.SAVE_ROOT);
			}
		}

		public void Process(string dir)
		{
		}

		public void Save(string dir)
		{
			var path = $"{Constants.SAVE_ROOT}/{dir}";
			if (!Directory.Exists(path))
			{
				Directory.CreateDirectory(path);
			}
		}

		public void SaveH(string dir, string list_file)
		{
			var list_path = $"{Constants.LIST_ROOT}/{dir}/";
			var head_file = list_file.Replace(list_path, String.Empty);
			var impl_file = head_file.Replace(".h", ".c");
			var head_type = head_file.Replace(".", "_");
			head_type = $"_{head_type.ToUpper()}_";

			OutLines.Clear();
			OutLines.Add($"#ifndef {head_type}");
			OutLines.Add($"#define {head_type}");
			OutLines.Add(String.Empty);

			// Process file contents.
			var open_lines = File.ReadAllLines(list_file);
			bool flag = false;
			foreach (var open_line in open_lines)
			{
				if (open_line.Length == 0)
				{
					flag = true;
				}
				else
				{
					// https://stackoverflow.com/questions/7187570/how-can-i-check-if-the-first-character-of-my-string-is-a-space-or-tab-character
					if (char.IsWhiteSpace(open_line[0]))
					{
						flag = true;
					}
					else
					{
						if (!char.IsLetter(open_line[0]))
						{
							flag = true;
						}
					}
				}

				var text_line = open_line;
				if (flag)
				{
					text_line = "//" + text_line;
					if (!skip)
					{
						OutLines.Add(text_line);
					}
				}
				else
				{
					text_line = text_line + ";";
					OutLines.Add(text_line);
				}
			}

			OutLines.Add(String.Empty);
			OutLines.Add($"#endif//{head_type}");

			var save_path = $"{Constants.SAVE_ROOT}/{dir}/{head_file}";
			var contents = OutLines.ToArray();
			if (File.Exists(save_path))
			{
				File.Delete(save_path);
			}

			File.WriteAllLines(save_path, contents);
		}

		public void SaveC(string dir, string list_path, string list_file)
		{
			var head_file = list_file.Replace(list_path, String.Empty);
			var impl_file = head_file.Replace(".h", ".c");
			var head_type = head_file.Replace(".", "_");
			head_type = $"_{head_type.ToUpper()}_";

			OutLines.Clear();

		}

		public IList<string> OutLines { get; private set; }
	}
}
