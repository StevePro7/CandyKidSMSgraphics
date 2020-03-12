using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CdeToCsv
{
    public class FileManager
    {
        public void OpenFile(string name)
        {
            Lines = File.ReadAllLines(name);
        }

        public void BuildData()
        {
            var start = 3;
            ProSpeedN = ParseData(Lines[start + 0]);
            ProSpeedB = ParseData(Lines[start + 1]);
            AdiSpeedN = ParseData(Lines[start + 3]);
            AdiSpeedB = ParseData(Lines[start + 4]);
            SuzSpeedN = ParseData(Lines[start + 6]);
            SuzSpeedB = ParseData(Lines[start + 7]);

            start = 15;
            ProDelayN = ParseData(Lines[start + 0]);
            ProDelayB = ParseData(Lines[start + 1]);
            AdiDelayN = ParseData(Lines[start + 3]);
            AdiDelayB = ParseData(Lines[start + 4]);
            SuzDelayN = ParseData(Lines[start + 6]);
            SuzDelayB = ParseData(Lines[start + 7]);
        }

        public void TotalData()
        {
            ProTotalN = ParseTotal(ProSpeedN, ProDelayN);
            ProTotalB = ParseTotal(ProSpeedB, ProDelayB);
            AdiTotalN = ParseTotal(AdiSpeedN, AdiDelayN);
            AdiTotalB = ParseTotal(AdiSpeedB, AdiDelayB);
            SuzTotalN = ParseTotal(SuzSpeedN, SuzDelayN);
            SuzTotalB = ParseTotal(SuzSpeedB, SuzDelayB);
        }

        public void PrintData()
        {
            var lines = new List<string>
            {
                ",ES,EF,HS,HF",
                PrintText("ProNormal", ProTotalN),
                PrintText("ProBoostX", ProTotalB),
                PrintText("AdiNormal", AdiTotalN),
                PrintText("AdiBoostX", AdiTotalB),
                PrintText("SuzNormal", SuzTotalN),
                PrintText("SuzBoostX", SuzTotalB)
            };

            File.WriteAllLines("output.csv", lines.ToArray());
        }

        private int[] ParseData(string line)
        {
            var data = new int[4];

            var text = line.Trim();
            text = text.Replace("// Normal", string.Empty);
            text = text.Replace("// Boost!", string.Empty);

            var splitText = text.Split(new char[] { ',' });
            data[0] = int.Parse(splitText[0]);
            data[1] = int.Parse(splitText[1]);
            data[2] = int.Parse(splitText[2]);
            data[3] = int.Parse(splitText[3]);
            return data;
        }

        private int[] ParseTotal(int[] speeds, int[] delays)
        {
            var totals = new int[4];
            for(var index = 0; index < 4; index++)
            {
                totals[index] = GetTotal(speeds[index], delays[index]);
            }
            return totals;
        }

        private int GetTotal(int speed, int delay)
        {
            var matrix = new int[4, 4]
            {
               { 16, 32, 48, 64, },
               { 8, 0, 24, 0, },
               { 6, 12, 18, 0 },
               { 4, 0, 0, 0, },
            };

            var index = (speed - 1) * 4 + (delay - 1);
            var total = matrix[(speed - 1), (delay - 1)];
            //int total = 0;
            return total;
        }

        private string PrintText(string title, int[] totals)
        {
            var line = title + ",";
            foreach(var total in totals)
            {
                line += total + ",";
            }

            line = line.Substring(0, line.Length - 1);
            return line;
        }

        public int[] ProSpeedN { get; private set; }
        public int[] ProSpeedB { get; private set; }
        public int[] AdiSpeedN { get; private set; }
        public int[] AdiSpeedB { get; private set; }
        public int[] SuzSpeedN { get; private set; }
        public int[] SuzSpeedB { get; private set; }

        public int[] ProDelayN { get; private set; }
        public int[] ProDelayB { get; private set; }
        public int[] AdiDelayN { get; private set; }
        public int[] AdiDelayB { get; private set; }
        public int[] SuzDelayN { get; private set; }
        public int[] SuzDelayB { get; private set; }

        public int[] ProTotalN { get; private set; }
        public int[] ProTotalB { get; private set; }
        public int[] AdiTotalN { get; private set; }
        public int[] AdiTotalB { get; private set; }
        public int[] SuzTotalN { get; private set; }
        public int[] SuzTotalB { get; private set; }

        public string[] Lines { get; private set; }
    }
}
