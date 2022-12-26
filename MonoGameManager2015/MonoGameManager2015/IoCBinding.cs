using System.Collections.Generic;

namespace MonoGameManager
{
	public class IoCBinding
	{
		private List<string> lines;

		public IoCBinding()
		{
			lines = new List<string>();
		}

		public void ProcessAll(string[] managers)
		{
			lines.Clear();
			lines.Add("using WindowsGame.Master;");
			lines.Add("");
			lines.Add("namespace WindowsGame.Common");
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
			lines.Add("			IoCContainer.Initialize<IFileProxy, RealFileProxy>();");
			lines.Add("			IoCContainer.Initialize<IFileManager, FileManager>();");
			lines.Add("			IoCContainer.Initialize<ILogger, RealLogger>();");
			lines.Add("		}");
			lines.Add("");
			lines.Add("	}");
			lines.Add("}");

			var path = "Registration.cs";
			var content = lines.ToArray();
			System.IO.File.WriteAllLines(path, content);

		}
	}
}
