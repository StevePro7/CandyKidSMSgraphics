using System;

namespace LevelModification
{
	class Program
	{
		static void Main(string[] args)
		{
			var fileManager = new FileManager();
			var levelManager = new LevelManager(fileManager);
			var scoreManager = new ScoreManager();

			int world = 1;
			int round = 1;
			int level = (world - 1) * 10 + round;
			var fileName = String.Format("level{0}{1}.txt", world.ToString().PadLeft(2, '0'), round.ToString().PadLeft(2, '0'));

			levelManager.SetData("bank2", fileName);
			var tiles = levelManager.Tiles;

			scoreManager.Process(tiles, fileName, level);
		}
	}
}
