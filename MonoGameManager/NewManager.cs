using System;
using System.Collections.Generic;
using System.Text;

namespace MonoGameManager
{
	public class NewManager
	{
		private List<string> lines;

		public NewManager()
		{
			lines = new List<string>();
		}

		// Reference: https://stackoverflow.com/questions/42310727/convert-string-to-camelcase-from-titlecase-c-sharp
		public void ProcessAll(string[] managers)
		{
			lines.Clear();
			lines.Add("using WindowsGame.Master.Interfaces;");
			lines.Add("using WindowsGame.Common.Managers;");
			lines.Add("");
			lines.Add("namespace WindowsGame.Common.TheGame");
			lines.Add("{");
			lines.Add("	public interface IGameManager");
			lines.Add("	{");
			foreach (var manager1 in managers)
			{
				lines.Add("		I" + manager1 + " " + manager1 + " { get; }");
			}
			lines.Add("	}");
			lines.Add("");

			lines.Add("	public class GameManager : IGameManager");
			lines.Add("	{");
			lines.Add("		public GameManager");
			lines.Add("		(");
			for (var idx = 0; idx < managers.Length-2; idx++)
			{
				var manager2 = managers[idx];
				var manager2x = Char.ToLowerInvariant(manager2[0]) + manager2.Substring(1);
				lines.Add("			I" + manager2 + " " + manager2x + "," );
			}

			var manager = managers[managers.Length - 1];
			lines.Add("			I" + manager + " " + manager.ToLower() + ",");
			lines.Add("		)");
			lines.Add("		{");
			foreach (var manager3 in managers)
			{
				var manager3x = Char.ToLowerInvariant(manager3[0]) + manager3.Substring(1);
				lines.Add("			" + manager3 + " = " + manager3x + ",");
			}
			lines.Add("		}");

			lines.Add("");

			foreach (var manager4 in managers)
			{
				lines.Add("		public I" + manager4 + " " + manager4 + " { get; private set; }");
			}

			lines.Add("	}");
			lines.Add("");
			lines.Add("}");

			var path = "TheGame/GameManager.cs";
			var content = lines.ToArray();
			System.IO.File.WriteAllLines(path, content);
		}
	}
}
