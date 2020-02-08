using System;

namespace ROMbytesLeft
{
	internal class Program
	{
		private static void Main()
		{
			var fileManager = new FileManager();
			fileManager.Build("output.sms");

			Console.WriteLine("Index : " + fileManager.Index.ToString("X2"));
			Console.WriteLine("Count : " + fileManager.Count);
			Console.WriteLine("Total : " + fileManager.Total);
			Console.WriteLine();
		}

	}
}
