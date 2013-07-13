using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace PuzzleViewer
{
    public partial class ViewerForm : Form
    {
        public ViewerForm(String filename)
        {
            InitializeComponent();
            
            puzzleTab tab = new puzzleTab();
            tab.Text = filename;
            tab.fillMatrix(filename);
            this.puzzleTabControl.TabPages.Clear();
            this.puzzleTabControl.TabPages.Add(tab);
            this.puzzleTabControl.SelectedTab = tab;

        }

    }
}
