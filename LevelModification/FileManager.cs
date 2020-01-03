using System;
using System.IO;

namespace LevelModification
{
	public interface IFileManager
	{
		void Load(string fileName);

		String[] Contents { get; }
	}

	public class FileManager : IFileManager
	{
		public void Load(string fileName)
		{
			Contents = File.ReadAllLines(fileName);
		}

		public String[] Contents { get; private set; }
	}
}
