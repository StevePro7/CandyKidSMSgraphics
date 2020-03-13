using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CsvToCde
{
    public class FileManager
    {
        public void OpenFile(string name)
        {
            Lines = File.ReadAllLines(name);
        }

        public void BuildData()
        {
            var start = 1;
            ProTotalN = ParseData(Lines[start + 0], "ProNormal");
            ProTotalB = ParseData(Lines[start + 1], "ProBoostX");
            AdiTotalN = ParseData(Lines[start + 2], "AdiNormal");
            AdiTotalB = ParseData(Lines[start + 3], "AdiBoostX");
            SuzTotalN = ParseData(Lines[start + 4], "SuzNormal");
            SuzTotalB = ParseData(Lines[start + 5], "SuzBoostX");
        }

        public void TotalData()
        {
            ProSpeedN = ParseSpeed(ProTotalN);
            ProSpeedB = ParseSpeed(ProTotalB);
            AdiSpeedN = ParseSpeed(AdiTotalN);
            AdiSpeedB = ParseSpeed(AdiTotalB);
            SuzSpeedN = ParseSpeed(SuzTotalN);
            SuzSpeedB = ParseSpeed(SuzTotalB);

            ProDelayN = ParseDelay(ProTotalN);
            ProDelayB = ParseDelay(ProTotalB);
            AdiDelayN = ParseDelay(AdiTotalN);
            AdiDelayB = ParseDelay(AdiTotalB);
            SuzDelayN = ParseDelay(SuzTotalN);
            SuzDelayB = ParseDelay(SuzTotalB);
        }

        public void PrintData()
        {
            var lines = new List<string>();

            lines.Add("const unsigned char enemy_object_speed[] =");
            lines.Add("{");
            lines.Add("//Pro: ES,EF,HS,HF.");
            lines.Add(GetLine(ProSpeedN, "Normal"));
            lines.Add(GetLine(ProSpeedB, "Boost!"));
            lines.Add("//Adi: ES,EF,HS,HF.");
            lines.Add(GetLine(AdiSpeedN, "Normal"));
            lines.Add(GetLine(AdiSpeedB, "Boost!"));
            lines.Add("//Suz: ES,EF,HS,HF.");
            lines.Add(GetLine(SuzSpeedN, "Normal"));
            lines.Add(GetLine(SuzSpeedB, "Boost!"));
            lines.Add("};");

            lines.Add("const unsigned char enemy_object_delay[] =");
            lines.Add("{");
            lines.Add("//Pro: ES,EF,HS,HF.");
            lines.Add(GetLine(ProDelayN, "Normal"));
            lines.Add(GetLine(ProDelayB, "Boost!"));
            lines.Add("//Adi: ES,EF,HS,HF.");
            lines.Add(GetLine(AdiDelayN, "Normal"));
            lines.Add(GetLine(AdiDelayB, "Boost!"));
            lines.Add("//Suz: ES,EF,HS,HF.");
            lines.Add(GetLine(SuzDelayN, "Normal"));
            lines.Add(GetLine(SuzDelayB, "Boost!"));
            lines.Add("};");
            File.WriteAllLines("output.txt", lines.ToArray());
        }

        private int[] ParseData(string line, string title)
        {
            var data = new int[4];

            var text = line.Trim();
            text = text.Replace(title +",", string.Empty);

            var splitText = text.Split(new char[] { ',' });
            data[0] = int.Parse(splitText[0]);
            data[1] = int.Parse(splitText[1]);
            data[2] = int.Parse(splitText[2]);
            data[3] = int.Parse(splitText[3]);
            return data;
        }

        private int[] ParseSpeed(int[] totals)
        {
            var speeds = new int[4];

            var matrix = new int[4, 4]
            {
               { 16, 32, 48, 64, },
               { 8, 0, 24, 0, },
               { 6, 12, 18, 0 },
               { 4, 0, 0, 0, },
            };

            for (int index = 0; index < 4; index++)
            {
                var total = totals[index];
                for(int r = 0; r < 4; r++)
                {
                    for(int c = 0; c < 4; c++)
                    {
                        int v = matrix[r, c];
                        if (total == v)
                        {
                            speeds[index] = r + 1;
                        }
                    }
                }
            }

            return speeds;
        }

        private int[] ParseDelay(int[] totals)
        {
            var delays = new int[4];

            var matrix = new int[4, 4]
            {
               { 16, 32, 48, 64, },
               { 8, 0, 24, 0, },
               { 6, 12, 18, 0 },
               { 4, 0, 0, 0, },
            };

            for(int index = 0; index < 4; index++)
            {
                var total = totals[index];
                for(int r = 0; r < 4; r++)
                {
                    for(int c = 0; c < 4; c++)
                    {
                        int v = matrix[r, c];
                        if(total == v)
                        {
                            delays[index] = c + 1;
                        }
                    }
                }
            }

            return delays;
        }

        private string GetLine(int[] speeds, string suffix)
        {
            string line = string.Empty;

            line += "\t";
            for (var index = 0; index < 4; index++)
            {
                line += speeds[index];
                line += ", ";
            }

            line += "\t\t// ";
            line += suffix;

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
