using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2019._10_18_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] a = new int[2, 2];
            a[0, 0] = int.Parse(Console.ReadLine());
            a[0, 1] = int.Parse(Console.ReadLine());
            a[1, 0] = int.Parse(Console.ReadLine());
            a[1, 1] = int.Parse(Console.ReadLine());

            int min1 = a[0, 0];
            for(int i = 0; i < 2 ; i++)
            {
                if(a[0,1]<min1)
                {
                    min1 = a[0,1];
                }
                            
            }

            int min2 = a[1, 0];
            for(int i = 0; i < 2; i++)
            {
                if(a[1,1]<min2)
                {
                    min2 = a[1, 1];
                }
            }
            Console.WriteLine(min1);
            Console.WriteLine(min2);
        }
    }
}
