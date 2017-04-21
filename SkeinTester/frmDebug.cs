using System;
using System.Windows.Forms;
using Skein;

namespace SkeinTester
{
    public partial class frmDebug : Form
    {
        public frmDebug()
        {
            InitializeComponent();
        }

        private void tmrExecute_Tick(object sender, EventArgs e)
        {
            tmrExecute.Enabled = false;
            Skein256Ex mySkein = new Skein256Ex(256, null);
            mySkein.Initialize();
            byte[] result = mySkein.ComputeHash(new byte[] { 0}, 0);
            txtOutput1.Text = Bytes2HexString(result);


            mySkein = new Skein256Ex(256, null);
            result = mySkein.ComputeHash(new byte[] { 0}, 0);
            txtOutput2.Text = Bytes2HexString(result);

        }


        private string Bytes2HexString(byte[] data)
        {
            if (data == null)
                return "*Bytes2HexString:*NULL OBJECT*";
            string result = string.Empty;
            for (int i = 0; i < data.Length; i++)
            {
                result += data[i].ToString("X2");
            }
            return result;
        }
    }
}
