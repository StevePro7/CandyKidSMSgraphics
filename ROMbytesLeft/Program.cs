using System;

namespace ROMbytesLeft
{
	internal class Program
	{
		private static void Main()
		{
			var fileManager = new FileManager();
			fileManager.Build("output.sms");

			Console.WriteLine("32 KB : 32,768 bytes");
			Console.WriteLine("Total : " + fileManager.Total.ToString("N0") + " bytes free");
			Console.WriteLine("Count : " + fileManager.Count.ToString("N0") + " bytes ends" );
			//Console.WriteLine("Diff  : " + (fileManager.Total - fileManager.Count).ToString("N0") + " bytes diff");
			Console.WriteLine("Index : 0x" + fileManager.Index.ToString("X2")+ " bytes last" );

			Console.WriteLine();
		}

	}
}
