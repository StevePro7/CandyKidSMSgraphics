using System;
using System.Collections.Generic;
using System.Text;

namespace LevelModification
{
	public interface IScoreManager
	{
		void Process(IDictionary<int, int> tiles, string fileName, int level);

		IDictionary<int, int> Scores { get; }
		int HiScore { get; }
	}

	public class ScoreManager
	{
		private int[] values = new[] { 0, 10, 0, 100, 200, 400, 800 };

		public ScoreManager()
		{
			Scores = new Dictionary<int, int>();
			Scores.Clear();
		}

		public void Process(IDictionary<int, int> tiles, string fileName, int level)
		{
			int scores = 0;
			int total = 0;

			foreach(var tile in tiles)
			{
				int key = tile.Key;
				int value = tile.Value;

				int point = values[key];
				int score = value * point;

				if(level > 70)
				{
					if(key > 2)
					{
						score *= 2;
					}
				}
				scores += score;
				total += tile.Value;
			}

			if(100 != total)
			{
				throw new ArgumentException(fileName);
			}

			if(!Scores.ContainsKey(level))
			{
				Scores.Add(level, scores);
			}
		}


		public void CalcHiScore(IDictionary<int, int> scores)
		{
			HiScore = 0;
			foreach(var score in scores)
			{
				var value = score.Value;
				HiScore += value;
			}
		}

		public IDictionary<int, int> Scores { get; private set; }
		public int HiScore { get; private set; }
	}
}