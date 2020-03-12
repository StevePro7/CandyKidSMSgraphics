using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CdeToCsv
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			var fileMgr = new FileManager();
			fileMgr.OpenFile("Input.txt");
			fileMgr.BuildData();
			fileMgr.TotalData();
			fileMgr.PrintData();
			Console.WriteLine();
		}

	}
}
