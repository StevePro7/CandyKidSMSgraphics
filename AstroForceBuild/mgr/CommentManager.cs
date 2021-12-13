using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace AstroForceBuild
{
	public class CommentManager
	{
		public CommentManager()
		{
			OutLines = new List<string>();
			OutLines.Clear();
		}

		public void Process(string[] dirs)
		{
			string dir = dirs[0];
			//foreach (var dir in dirs)
			{
				Comment(dir);
			}

			//SaveFiles();
		}

		public void Comment(string dir)
		{
			var list_path = $"{Constants.TOOL_ROOT}/{dir}/";
			var save_path = $"{Constants.SAVE_ROOT}/{dir}/";
			var list_files = Directory.GetFiles(list_path);
			//var list_file = list_files[0];
			foreach (var list_file in list_files)
			{
				if (!Directory.Exists(save_path))
				{
					Directory.CreateDirectory(save_path);
				}

				if (list_file.EndsWith(".h"))
				{
					CommentFileH(dir, list_file);
				}
				if (list_file.EndsWith(".c"))
				{
					CommentFileC(dir, list_file);
				}
			}
		}

		public void CommentFileC(string dir, string list_file)
		{
			OutLines.Clear();

			var list_path = $"{Constants.TOOL_ROOT}/{dir}/";
			var impl_file = list_file.Replace(list_path, String.Empty);
			var temp_file = impl_file.Replace(".c", String.Empty);

			var open_lines = File.ReadAllLines(list_file);
			var counter = open_lines.Length;
			OutLines.Add(open_lines[0]);
			OutLines.Add(String.Empty);
			OutLines.Add($"void {temp_file}_foo()");
			OutLines.Add("{");
			OutLines.Add("}");
			OutLines.Add(String.Empty);

			for (int index = 2; index < counter; index++)
			{
				var text_line = open_lines[index];
				var temp_line = "//" + text_line;
				OutLines.Add(temp_line);
			}

			//OutLines.Add(open_lines[counter - 2]);
			//OutLines.Add(open_lines[counter - 1]);

			var save_path = $"{Constants.SAVE_ROOT}/{dir}/{impl_file}";
			if (File.Exists(save_path))
			{
				File.Delete(save_path);
			}

			var lines = OutLines.ToArray();
			File.WriteAllLines(save_path, lines);
		}


		public void CommentFileH(string dir, string list_file)
		{
			OutLines.Clear();

			var list_path = $"{Constants.TOOL_ROOT}/{dir}/";
			var head_file = list_file.Replace(list_path, String.Empty);
			var temp_file = head_file.Replace(".h", String.Empty);

			var open_lines = File.ReadAllLines(list_file);
			var counter = open_lines.Length;
			OutLines.Add(open_lines[0]);
			OutLines.Add(open_lines[1]);
			OutLines.Add(String.Empty);
			OutLines.Add($"void {temp_file}_foo();");
			OutLines.Add(String.Empty);

			for (int index = 3; index < counter - 2; index++)
			{
				var text_line = open_lines[index];
				var temp_line = "//" + text_line;
				OutLines.Add(temp_line);
			}

			OutLines.Add(open_lines[counter - 2]);
			OutLines.Add(open_lines[counter - 1]);

			var save_path = $"{Constants.SAVE_ROOT}/{dir}/{head_file}";
			if (File.Exists(save_path))
			{
				File.Delete(save_path);
			}

			var lines = OutLines.ToArray();
			File.WriteAllLines(save_path, lines);
		}

		public IList<string> OutLines { get; private set; }
	}
}
