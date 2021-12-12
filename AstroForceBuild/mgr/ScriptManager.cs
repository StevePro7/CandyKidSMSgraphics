using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace AstroForceBuild
{
	public class ScriptManager
	{
		public ScriptManager()
		{
			Compile = new List<string>();
			Linking = new List<string>();

			Compile.Clear();
			Linking.Clear();
		}

		public void Process(string[] dirs)
		{
			Compile.Add(String.Empty);
			Linking.Add(String.Empty);

			string dir = dirs[0];
			//foreach (var dir in dirs)
			{
				Compile.Add($"cd {dir}");
				Script(dir);
				Compile.Add("cd ..");
				Compile.Add(String.Empty);
			}

			SaveFiles();
		}

		public void Script(string dir)
		{
			string list_path = $"{Constants.LIST_ROOT}/{dir}/";
			var list_files = Directory.GetFiles(list_path);
			//var list_file = list_files[0];
			foreach (var list_file in list_files)
			{
				ScriptFile(dir, list_file);
			}
		}

		public void ScriptFile(string dir, string list_file)
		{
			var list_path = $"{Constants.LIST_ROOT}/{dir}/";
			var head_file = list_file.Replace(list_path, String.Empty);
			var impl_file = head_file.Replace(".h", ".c");
			var link_file = head_file.Replace(".h", ".rel");
			Compile.Add($"sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 {impl_file}");
			Linking.Add($"{dir}/{link_file} ^");
		}

		private void SaveFiles()
		{
			var save_path = $"{Constants.SAVE_ROOT}/build.bat";
			if (File.Exists(save_path))
			{
				File.Delete(save_path);
			}

			var lines = Compile.Concat(Linking);
			File.WriteAllLines(save_path, lines.ToArray());
		}

		public IList<string> Compile { get; private set; }
		public IList<string> Linking { get; private set; }

	}
}
