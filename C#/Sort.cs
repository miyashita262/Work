using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace xy
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> c = new List<int>();
            int[] b = new int[5];
            b[0] = int.Parse(Console.ReadLine());
            b[1] = int.Parse(Console.ReadLine());
            b[2] = int.Parse(Console.ReadLine());
            b[3] = int.Parse(Console.ReadLine());
            b[4] = int.Parse(Console.ReadLine());


            for(int i =0; i<5;i++)
            {
                if (b[i] % 2 == 0) 
                {
                    c.Add(b[i]);
                }
                
            }
            c.Sort();
            c.Reverse();

            Console.WriteLine(c[1]);
           




        }
    }
}
