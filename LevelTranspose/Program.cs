using System;

namespace LevelModification
{
	class Program
	{
		static void Main(string[] args)
		{
			var fileManager = new FileManager();

			for(int world = 1; world <= 10; world++)
			{
				for(int round = 1; round <= 10; round++)
				{
					string w = world.ToString().PadLeft(2, '0');
					string r = round.ToString().PadLeft(2, '0');
					var inpFileName = String.Format("Levels/old/level{0}{1}.txt", w, r);
					
					fileManager.Read(inpFileName);
					var contents = fileManager.Contents;

					var outFileName = String.Format("Levels/new/level{0}{1}.txt", r, w);
					fileManager.Write(outFileName, contents);
				}
			}

			Console.WriteLine();
		}
	}
}
