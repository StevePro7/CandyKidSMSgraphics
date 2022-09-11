using System.Collections.Generic;

namespace MonoGameManager
{
	public class GerManager
	{
		private List<string> lines;

		public GerManager()
		{
			lines = new List<string>();
		}

		public void ProcessAll(string[] managers)
		{
			lines.Clear();
			lines.Add("namespace WindowsGame.Common.Static");
			lines.Add("{");
			lines.Add("	public static class Registration");
			lines.Add("	{");
			lines.Add("		public static void Initialize()");
			lines.Add("		{");
			lines.Add("			IoCContainer.Initialize<IGameManager, GameManager>();");
			lines.Add("");
			foreach (var manager in managers)
			{
				lines.Add("			IoCContainer.Initialize<I" + manager + ", " + manager + ">();");
			}
			lines.Add("		}");
			lines.Add("");
			lines.Add("	}");
			lines.Add("");
			lines.Add("}");

			var path = "Registration.cs";
			var content = lines.ToArray();
			System.IO.File.WriteAllLines(path, content);

		}
	}
}
