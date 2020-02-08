using System;
using System.Collections.Generic;
using System.IO;

namespace ROMbytesLeft
{
	public class FileManager
	{
		public void Build(string path)
		{
			byte[] bytes = File.ReadAllBytes(path);

			//var index = 0x7F95;
			Index = 0x7F95;

			//int count = 0;
			Count = 0;
			Total = 0;
			var test = 0;
			test = bytes[0];

			while (true)
			{
				Index--;
				if (0 == Index)
				{
					break;
				}

				test = bytes[Index];
				if (0 != test)
				{
					break;
				}

				Count++;
			}

			for (int i = 0; i < 0x7FFF; i++)
			{
				test = bytes[i];
				if (0 == test)
				{
					Total++;
				}
			}

		}

		public int Index { get; private set; }
		public int Count { get; private set; }
		public int Total { get; private set; }
	}
}
