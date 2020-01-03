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

			//int world = 1;
			//int round = 1;

			//int level = (world - 1) * 10 + round;
			//var fileName = String.Format("level{0}{1}.txt", world.ToString().PadLeft(2, '0'), round.ToString().PadLeft(2, '0'));

			//levelManager.UpdateLevel("bank2", fileName);
			////levelManager.SetData("bank2", fileName);
			//var tiles = levelManager.Tiles;


			// bank2
			for(int world = 1; world <= 5; world++)
			{
				for(int round = 1; round <= 10; round++)
				{
					int level = (world - 1) * 10 + round;
					var fileName = String.Format("level{0}{1}.txt", world.ToString().PadLeft(2, '0'), round.ToString().PadLeft(2, '0'));

					levelManager.UpdateLevel("bank2", fileName);
					levelManager.SetData("bank2", fileName);
					var tiles = levelManager.Tiles;

					scoreManager.Process(tiles, fileName, level);
				}
			}

			//// bank3
			for(int world = 6; world <= 10; world++)
			{
				for(int round = 1; round <= 10; round++)
				{
					int level = (world - 1) * 10 + round;
					var fileName = String.Format("level{0}{1}.txt", world.ToString().PadLeft(2, '0'), round.ToString().PadLeft(2, '0'));

					levelManager.UpdateLevel("bank3", fileName);
					levelManager.SetData("bank3", fileName);
					var tiles = levelManager.Tiles;

					scoreManager.Process(tiles, fileName, level);
				}
			}

			var scores = scoreManager.Scores;
			scoreManager.CalcHiScore(scores);
			var hiScore = scoreManager.HiScore;

			// hiScore = 828,070 points
			// Bonuses = 5k * 100 levels = 500,000
			Console.WriteLine("Hi Score : " + hiScore);
			Console.WriteLine();
		}
	}
}
