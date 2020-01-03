using System;
using System.Collections.Generic;
using System.Text;

namespace LevelModification
{
	public interface ILevelManager
	{
		void SetData(string dirXName, string fileName);

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
			fileManager.Load(textName);
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

		public IDictionary<int, int> Tiles { get; private set; }
		
	}
}
