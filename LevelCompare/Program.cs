using System;

namespace LevelCompare
{
	class Program
	{
		static void Main(string[] args)
		{
			var fileManager1 = new FileManager();
			var fileManager2 = new FileManager();
			var compareMgr = new CompareManager();

			// bank2
			for (int world = 1; world <= 10; world++)
			{
				for(int round = 1; round <= 10; round++)
				{
					var fileName1 = String.Format("level{0}{1}.txt", (world+ 0).ToString().PadLeft(2, '0'), round.ToString().PadLeft(2, '0'));
					var fileName2 = String.Format("level{0}{1}.txt", (world+10).ToString().PadLeft(2, '0'), round.ToString().PadLeft(2, '0'));

					fileManager1.Read("Levels/bank4/" + fileName1);
					fileManager2.Read("Levels/bank5/" + fileName2);

					var contents1 = fileManager1.Contents;
					var contents2 = fileManager2.Contents;

					var result = compareMgr.Process(contents1, contents2);
					if (!result)
					{
						Console.WriteLine(fileName1 + " => " + fileName2);
						Console.WriteLine();
					}

				}
			}

			// hiScore = 828,070 points
			// Bonuses = 5k * 100 levels = 500,000
			Console.WriteLine();
		}
	}
}
