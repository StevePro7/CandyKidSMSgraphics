using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CsvToCde
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			var fileMgr = new FileManager();
			fileMgr.OpenFile("input.csv");
			fileMgr.BuildData();
			fileMgr.TotalData();
			fileMgr.PrintData();
			Console.WriteLine();
		}

	}
}
