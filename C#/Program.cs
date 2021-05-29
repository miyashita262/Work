using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MinNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] prices = new int[3];
            prices[0] = int.Parse(Console.ReadLine());
            prices[1] = int.Parse(Console.ReadLine());
            prices[2] = int.Parse(Console.ReadLine());

            int max = 0;　//＋の値しか入れないため
            for (int i = 0; i < prices.Length; i ++)
                if(prices[i]>max)
                {
                    max = prices[i];
                }

            int min =prices[0]; //最初の値と比較するため
            for (int i = 0; i < prices.Length; i ++)
                if(prices[i]<min)
                {
                    min = prices[i];
                }

            int answer = max - min;
            Console.WriteLine(answer);



        }
    }
}
