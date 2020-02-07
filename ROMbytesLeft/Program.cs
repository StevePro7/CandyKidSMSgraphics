using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Numerics;

namespace ScreenMgrCreate
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			var scatterTiles_ = scatterTilesInky;

			List<Point> orderedTiles = scatterTiles_.ToList();
			orderedTiles.Sort((a, b) => Vector2.Distance(new Vector2(18, 11),
														 new Vector2(a.X, a.Y)).
										CompareTo(
										Vector2.Distance(new Vector2(18, 11),
														 new Vector2(b.X, b.Y))));

			var list = new List<int>();
			var srce = new Vector2(18, 11);

			int ax = 0;
			int ay = 0;
			int az = 0;
			foreach (var orderedTile in orderedTiles)
			{
				int bz = (((int)srce.X - orderedTile.X) * ((int)srce.X - orderedTile.X)) + (((int)srce.Y - orderedTile.Y) * ((int)srce.Y - orderedTile.Y));
				list.Add(bz);
				var cz = Math.Sqrt(bz);

				if (bz > az)
				{
					ax = orderedTile.X;
					ay = orderedTile.Y;
				}

				var dest = new Vector2(orderedTile.X, orderedTile.Y);
				var vec = Vector2.Distance(srce, dest);
				var vec2 = Vector2.DistanceSquared(srce, dest);
				//list.Add((int)vec2);
			}

			Console.WriteLine();
		}


		public static readonly List<Point> scatterTilesInky = new List<Point> {   new Point(18, 23),  new Point(21, 23),
																			new Point(21, 26),  new Point(26, 26),
																			new Point(26, 29),  new Point(15, 29),
																			new Point(15, 26),  new Point(18, 26)
		};
	}
}
