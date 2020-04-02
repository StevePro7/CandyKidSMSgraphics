using System;
using System.IO;

namespace LevelCompare
{
	public interface IFileManager
	{
		void Read(string path);
		void Write(string path, string[] contents);

		String[] Contents { get; }
	}

	public class FileManager : IFileManager
	{
		public void Read(string path)
		{
			Contents = File.ReadAllLines(path);
		}

		public void Write(string path, string[] contents)
		{
			File.WriteAllLines(path, contents);
		}

		public String[] Contents { get; private set; }
	}
}
