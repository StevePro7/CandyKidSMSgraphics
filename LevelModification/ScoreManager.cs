using System;
using System.Collections.Generic;
using System.Text;

namespace LevelModification
{
	public interface IScoreManager
	{
		void Process(IDictionary<int, int> tiles, string fileName, int level);

		IDictionary<int, int> Scores { get; }
	}

	public class ScoreManager
	{
		private int[] values = new[] { 0, 10, 0, 100, 200, 400, 800 };

		public ScoreManager()
		{
			Scores = new Dictionary<int, int>();
		}

		public void Process(IDictionary<int, int> tiles, string fileName, int level)
		{
			int scores = 0;
			int total = 0;

			foreach (var tile in tiles)
			{
				int key = tile.Key;
				int value = tile.Value;

				int point = values[key];
				int score = value * point;

				scores += score;
				total += tile.Value;
			}

			if (100 != total)
			{
				throw new ArgumentException(fileName);
			}

			if (!Scores.ContainsKey(level))
			{
				Scores.Add(level, scores);
			}
		}

		public IDictionary<int, int> Scores { get; private set; }
	}
}
