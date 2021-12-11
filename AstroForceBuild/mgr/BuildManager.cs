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
			OutLinesH = new List<string>();
			OutLinesC = new List<string>();
			//skip = false;
			skip = true;
		}
		public void Initialize()
		{
			if (!Directory.Exists(Constants.SAVE_ROOT))
			{
				Directory.CreateDirectory(Constants.SAVE_ROOT);
			}
		}

		public void Process(string[] dirs)
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

		public void SaveFile(string dir, string list_file)
		{
			var list_path = $"{Constants.LIST_ROOT}/{dir}/";
			var head_file = list_file.Replace(list_path, String.Empty);
			var impl_file = head_file.Replace(".h", ".c");
			var head_type = head_file.Replace(".", "_");
			head_type = $"_{head_type.ToUpper()}_";

			OutLinesC.Clear();
			OutLinesC.Add($"#include \"{head_file}\"");
			OutLinesC.Add(String.Empty);

			OutLinesH.Clear();
			OutLinesH.Add($"#ifndef {head_type}");
			OutLinesH.Add($"#define {head_type}");
			OutLinesH.Add(String.Empty);

			// Process file contents.
			var open_lines = File.ReadAllLines(list_file);
			foreach (var open_line in open_lines)
			{
				bool flag = false;
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
						OutLinesH.Add(text_line);
					}
				}
				else
				{
					text_line = text_line + ";";
					OutLinesH.Add(text_line);
				}

				OutLinesC.Add(open_line);
			}

			OutLinesH.Add(String.Empty);
			OutLinesH.Add($"#endif//{head_type}");

			var saveH_path = $"{Constants.SAVE_ROOT}/{dir}/{head_file}";
			var saveC_path = $"{Constants.SAVE_ROOT}/{dir}/{impl_file}";
			if (File.Exists(saveH_path))
			{
				File.Delete(saveH_path);
			}
			if (File.Exists(saveC_path))
			{
				File.Delete(saveC_path);
			}

			File.WriteAllLines(saveH_path, OutLinesH.ToArray());
			File.WriteAllLines(saveC_path, OutLinesC.ToArray());
		}

		public IList<string> OutLinesH { get; private set; }
		public IList<string> OutLinesC { get; private set; }
	}
}
