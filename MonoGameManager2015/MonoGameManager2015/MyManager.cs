using System.Collections.Generic;

namespace MonoGameManager
{
	public class MyManager
	{
		private List<string> lines;

		public MyManager()
		{
			lines = new List<string>();
		}

		public void ProcessAll(string[] managers)
		{
			foreach(var manager in managers)
			{
				Process(manager);
			}
		}

		public void Process(string manager)
		{
			lines.Clear();
			lines.Add("using System;");
			lines.Add("using WindowsGame.Common.Data;");
			lines.Add("using WindowsGame.Common.Static;");
			lines.Add("");
			lines.Add("namespace WindowsGame.Common.Managers");
			lines.Add("{");
			lines.Add("	public interface I" + manager);
			lines.Add("	{");
			lines.Add("		void Initialize();");
			lines.Add("		void LoadContent();");
			lines.Add("	}");
			lines.Add("");
			lines.Add("	public class " + manager + " : I" + manager);
			lines.Add("	{");
			lines.Add("		public void Initialize()");
			lines.Add("		{");
			lines.Add("		}");
			lines.Add("");
			lines.Add("		public void LoadContent()");
			lines.Add("		{");
			lines.Add("		}");
			lines.Add("	}");
			lines.Add("");
			lines.Add("}");

			var path = "Managers/" + manager + ".cs";
			var content = lines.ToArray();
			System.IO.File.WriteAllLines(path, content);
		}
	}
}
