using System;
using System.Collections.Generic;
using System.Text;

namespace LevelCompare
{
    public class CompareManager
    {
        public Boolean Process(string[] data1, string[] data2)
        {
            bool result = false;
            if (data1.Length != data2.Length)
            {
                return result;
            }

            int count = data1.Length;
            for (int index = 0; index < count; index++)
            {
                var line1 = data1[index];
                var line2 = data2[index];
                if (line1.Length != line2.Length)
                {
                    return result;
                }

                int chars = line1.Length;
                for (int i = 0; i < chars; i++)
                {
                    char c1 = line1[i];
                    char c2 = line2[i];
                    if (c1 != c2)
                    {
                        return result;
                    }
                }
            }

            return true;
        }
    }
}
