using System;
using System.Collections.Generic;

namespace MonoGameManager
{
	public class GameManager
	{
		private List<string> lines;

		public GameManager()
		{
			lines = new List<string>();
		}

		// Reference: https://stackoverflow.com/questions/42310727/convert-string-to-camelcase-from-titlecase-c-sharp
		public void ProcessAll(string[] managers)
		{
			lines.Clear();
			lines.Add("using WindowsGame.Master;");
			//lines.Add("using WindowsGame.Common.Managers;");
			lines.Add("");
			lines.Add("namespace WindowsGame.Common");
			lines.Add("{");
			lines.Add("	public interface IGameManager");
			lines.Add("	{");
			foreach (var manager1 in managers)
			{
				lines.Add("		I" + manager1 + " " + manager1 + " { get; }");
			}
			lines.Add("		IFileManager FileManager { get; }");
			lines.Add("		ILogger Logger { get; }");
			lines.Add("	}");
			lines.Add("");

			lines.Add("	public class GameManager : IGameManager");
			lines.Add("	{");
			lines.Add("		public GameManager");
			lines.Add("		(");
			for (var idx = 0; idx < managers.Length; idx++)
			{
				var manager2 = managers[idx];
				var manager2x = Char.ToLowerInvariant(manager2[0]) + manager2.Substring(1);
				lines.Add("			I" + manager2 + " " + manager2x + "," );
			}
			lines.Add("			IFileManager fileManager,");
			lines.Add("			ILogger logger");
			lines.Add("		)");
			lines.Add("		{");
			foreach (var manager3 in managers)
			{
				var manager3x = Char.ToLowerInvariant(manager3[0]) + manager3.Substring(1);
				lines.Add("			" + manager3 + " = " + manager3x + ";");
			}
			lines.Add("			FileManager = fileManager;");
			lines.Add("			Logger = logger;");
			lines.Add("		}");

			lines.Add("");

			foreach (var manager4 in managers)
			{
				lines.Add("		public I" + manager4 + " " + manager4 + " { get; private set; }");
			}
			lines.Add("		public IFileManager FileManager { get; private set; }");
			lines.Add("		public ILogger Logger { get; private set; }");

			lines.Add("	}");
			lines.Add("");
			lines.Add("}");

			var path = "TheGame/GameManager.cs";
			var content = lines.ToArray();
			System.IO.File.WriteAllLines(path, content);
		}
	}
}
