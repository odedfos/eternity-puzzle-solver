using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Collections;
using System.IO;

namespace PuzzleViewer
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(String[] args)
        {
            
            /*ArrayList pieceArr = new ArrayList();
            Random randInt = new Random();
            StreamWriter SW = File.CreateText("C:\\Documents and Settings\\IBM\\Desktop\\Puzzle\\puzz2.lay");
            for (int i = 0; i < 16; i++)
            {
                String line = "";
                for (int j = 0; j < 16; j++)
                {
                    if (!line.Equals(""))
                        line += "\t";
                    int val = randInt.Next(256) + 1;
                    int rotate = randInt.Next(4);
                    line += val + "\t" + rotate;
                    pieceArr.Add(val);
                }
                SW.WriteLine(line);
            }
            SW.Close();*/

            if (args.Length > 0)
            {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                Application.Run(new ViewerForm(args[0]));
            }
        }

    }
}
