using System;
using System.IO;

namespace ScreenMgrCreate
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			string path = @"E:\GitHub\StevePro8\SegaMasterSystemLinux\ExamplesIII\10-Skazka\dev\screen";
			var files = Directory.GetFiles(path, "*.c");
			foreach (var file in files)
			{
				Console.WriteLine(file);
				var lines = File.ReadAllLines(file);
				for (int index = 1; index < lines.Length; index++)
				{
					var line = lines[index];

					if (line.Contains("enum_manager") || line.Contains("hack_manager") || line.Contains("global_manager"))
					{
						continue;
					}
					if (!line.StartsWith("#include"))
					{
						break;
					}
					if (!line.Contains("_manager.h"))
					{
						break;
					}

					var mgr = line.Replace("\"", "");
					mgr = mgr.Replace("#include ", "");
					mgr = mgr.Replace("../", "");
					mgr = mgr.Replace("engine", "");
					mgr = mgr.Replace("devkit", "");
					mgr = mgr.Replace("banks", "");
					mgr = mgr.Replace(".h", "");
					mgr = mgr.Replace("/", "");
					if (mgr.StartsWith("_"))
					{
						mgr = "devkit_SMS";
					}

					if (mgr == "locale_manager")
					{
						mgr = "LOCALE_";
					}

					bool found = false;
					for (int codes = 0; codes < lines.Length; codes++)
					{
						var code = lines[codes];
						if (code.StartsWith("#include"))
						{
							continue;
						}
						if (mgr == "audio_manager")
						{
							if (code.Contains("music_manager") || code.Contains("sound_manager"))
							{
								found = true;
								break;
							}
						}
						else
						{
							if (code.Contains(mgr))
							{
								found = true;
								break;
							}
						}
					}

					if (!found)
					{
						Console.WriteLine("NOT Found:" + mgr);
					}
				}

				Console.WriteLine();
			}

			Console.WriteLine();
		}
	}
}
