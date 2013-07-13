using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;


namespace PuzzleViewer
{
    //public partial class puzzleTab : UserControl
    public partial class puzzleTab : TabPage
    {
        private System.Windows.Forms.PictureBox[,] m_PuzzleMatrix;
        private int m_PieceSize;
        private String m_PiecePath = "C:\\Documents and Settings\\IBM\\Desktop\\Puzzle\\Pieces\\";

        public puzzleTab()
        {
            InitializeComponent();
            m_PuzzleMatrix = new System.Windows.Forms.PictureBox[16,16];
            this.BackColor = Color.Black;
            m_PieceSize = 40;
        }

        public int[,,] getPuzzleFromFile(String filename)
        {
            int[,,] puzzleMatrix = new int[16,16,2];
            StreamReader SR = new StreamReader(filename);
            for (int i = 0; i < 16; i++)
            {
                String line = SR.ReadLine();
                String[] splitLine = line.Split('\t');
                for (int j = 0; j < 16; j++)
                {
                    puzzleMatrix[i,j,0] = int.Parse(splitLine[j * 2]);
                    puzzleMatrix[i,j,1] = int.Parse(splitLine[j * 2 + 1]);
                }
            }
            SR.Close();
            return puzzleMatrix;
        }

        public void fillMatrix(String filename)
        {
            int[,,] pieceMatrix = getPuzzleFromFile(filename);
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    Bitmap piece = new Bitmap(m_PiecePath + pieceMatrix[i, j, 0] + ".JPG");
                    int rotate = pieceMatrix[i,j,1];
                    for (int k = 0; k < rotate; k++)
                        piece.RotateFlip(RotateFlipType.Rotate270FlipNone);
                    m_PuzzleMatrix[i, j] = new System.Windows.Forms.PictureBox();
                    m_PuzzleMatrix[i, j].Image = piece;
                    m_PuzzleMatrix[i, j].SizeMode = PictureBoxSizeMode.StretchImage;
                    m_PuzzleMatrix[i, j].Location = new Point(m_PieceSize * j, m_PieceSize * i);
                    m_PuzzleMatrix[i, j].Size = new Size(m_PieceSize, m_PieceSize);
                    m_PuzzleMatrix[i, j].Visible = true;
                    panel1.Controls.Add(m_PuzzleMatrix[i, j]);
                }
            }


        }
    }
}
