using System;
using System.Collections.Generic;
using System.Linq;

namespace LevelModification
{
	public interface ILevelManager
	{
		void SetData(string dirXName, string fileName);
		void UpdateLevel(string dirXName, string fileName);

		IDictionary<int, int> Tiles { get; }
	}

	public class LevelManager : ILevelManager
	{
		private readonly IFileManager fileManager;

		public LevelManager(IFileManager fileManager)
		{
			this.fileManager = fileManager;
			Tiles = new Dictionary<int, int>();
		}

		public void SetData(string dirXName, string fileName)
		{
			var textName = "Levels/" + dirXName + "/" + fileName;
			fileManager.Read(textName);
			var contents = fileManager.Contents;

			if (10 != contents.Length)
			{
				throw new ArgumentException(fileName);
			}

			Tiles.Clear();
			foreach (var line in contents)
			{
				foreach (var c in line)
				{
					var s = c.ToString();
					var i = Int32.Parse(s);

					if (!Tiles.ContainsKey(i))
					{
						Tiles.Add(i, 1);
					}
					else
					{
						Tiles[i]++;
					}
				}
			}
		}

		public void UpdateLevel(string dirXName, string fileName)
		{
			var inputXName = "Levels/" + dirXName + "/" + fileName;
			var outputName = "Output/" + dirXName + "/" + fileName;
			fileManager.Read(inputXName);
			var contents = fileManager.Contents;

			IList<string> outLines = new List<string>();
			if(10 != contents.Length)
			{
				throw new ArgumentException(fileName);
			}

			foreach(var inpLine in contents)
			{
				string outLine = String.Empty;
				foreach(var c in inpLine)
				{
					var s = c.ToString();
					var i = Int32.Parse(s);

					var t = i;
					if (1 == i)
					{
						t = 2;
					}
					else if (2 == i)
					{
						t = 1;
					}

					outLine += t;
				}

				outLines.Add(outLine);
			}

			fileManager.Write(outputName, outLines.ToArray());
		}

		public IDictionary<int, int> Tiles { get; private set; }
		
	}
}
