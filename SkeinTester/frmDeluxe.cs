using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SkeinTester
{
    public partial class frmDeluxe : Form
    {
        const string BASEWORKINGDIR = @"C:\DOTNET Programs\Skein\";
        #region "KAT Specific Byte Arrays"
        // these are defined in "skein_golden_kat_internals.txt" in the NIST submission CD
        byte[] RandomDataSrc = new byte[] { 0xFB, 0xD1, 0x7C, 0x26, 0xB6, 0x1A, 0x82, 0xE1, 0x2E, 0x12, 0x5F, 0xD, 0x45, 0x9B, 0x96, 0xC9, 0x1A, 0xB4, 0x83, 0x7D, 0xFF, 0x22, 0xB3, 0x9B, 0x78, 0x43, 0x94, 0x30, 0xCD, 0xFC, 0x5D, 0xC8, 0x78, 0xBB, 0x39, 0x3A, 0x1A, 0x5F, 0x79, 0xBE, 0xF3, 0x9, 0x95, 0xA8, 0x5A, 0x12, 0x92, 0x33, 0x39, 0xBA, 0x8A, 0xB7, 0xD8, 0xFC, 0x6D, 0xC5, 0xFE, 0xC6, 0xF4, 0xED, 0x22, 0xC1, 0x22, 0xBB, 0xE7, 0xEB, 0x61, 0x98, 0x18, 0x92, 0x96, 0x6D, 0xE5, 0xCE, 0xF5, 0x76, 0xF7, 0x1F, 0xC7, 0xA8, 0xD, 0x14, 0xDA, 0xB2, 0xD0, 0xC0, 0x39, 0x40, 0xB9, 0x5B, 0x9F, 0xB3, 0xA7, 0x27, 0xC6, 0x6A, 0x6E, 0x1F, 0xF0, 0xDC, 0x31, 0x1B, 0x9A, 0xA2, 0x1A, 0x30, 0x54, 0x48, 0x48, 0x2, 0x15, 0x4C, 0x18, 0x26, 0xC2, 0xA2, 0x7A, 0x9, 0x14, 0x15, 0x2A, 0xEB, 0x76, 0xF1, 0x16, 0x8D, 0x44, 0x10, 0xE1, 0x14, 0xAA, 0x47, 0xF7, 0xC5, 0xC6, 0x15, 0x43, 0xC4, 0xD9, 0x59, 0x18, 0x82, 0x34, 0xF7, 0x97, 0xF4, 0x5A, 0x1D, 0x16, 0x65, 0xE3, 0x76, 0x46, 0xD8, 0x12, 0x9A, 0x45, 0xEE, 0x70, 0x78, 0x9, 0x91, 0xBB, 0x6B, 0x10, 0x2, 0x39, 0xE4, 0x66, 0xD5, 0x8D, 0x4C, 0xDD, 0x9D, 0x9D, 0x1, 0x90, 0xAB, 0x64, 0x47, 0xD, 0xDC, 0x87, 0xF5, 0xE5, 0x9, 0xE9, 0xA8, 0xCF, 0x82, 0x4F, 0x58, 0xEF, 0x4, 0x73, 0x2E, 0xAB, 0x28, 0x9, 0x2D, 0x18, 0xA5, 0xAD, 0xA4, 0x5B, 0x6D, 0x49, 0xFB, 0xF, 0x33, 0xF4, 0xCC, 0x7, 0xE3, 0x9E, 0xC6, 0x44, 0x9E, 0x8C, 0xA, 0xBB, 0x17, 0xC6, 0x58, 0x66, 0x0, 0x9A, 0x3D, 0x9C, 0x31, 0xC0, 0xD7, 0x65, 0xE4, 0xAF, 0x88, 0xB8, 0x60, 0x23, 0xE9, 0xA0, 0x67, 0xE3, 0x32, 0xC, 0x9, 0x24, 0x6A, 0x3F, 0xAE, 0x8A, 0x3F, 0xD9, 0x7C, 0x48, 0x7E, 0x4E };
        byte[] RandomMACDataSrc = new byte[] { 0xD3, 0x9, 0xC, 0x72, 0x16, 0x75, 0x17, 0xF7, 0xC7, 0xAD, 0x82, 0xA7, 0xC, 0x2F, 0xD3, 0xF6, 0x44, 0x3F, 0x60, 0x83, 0x1, 0x59, 0x1E, 0x59, 0x8E, 0xAD, 0xB1, 0x95, 0xE8, 0x35, 0x71, 0x35, 0xBA, 0x26, 0xFE, 0xDE, 0x2E, 0xE1, 0x87, 0x41, 0x7F, 0x81, 0x60, 0x48, 0xD0, 0xF, 0xC2, 0x35, 0x12, 0x73, 0x7A, 0x21, 0x13, 0x70, 0x9A, 0x77, 0xE4, 0x17, 0xC, 0x49, 0xA9, 0x4B, 0x7F, 0xDF, 0xF4, 0x5F, 0xF5, 0x79, 0xA7, 0x22, 0x87, 0x74, 0x31, 0x2, 0xE7, 0x76, 0x6C, 0x35, 0xCA, 0x5A, 0xBC, 0x5D, 0xFE, 0x2F, 0x63, 0xA1, 0xE7, 0x26, 0xCE, 0x5F, 0xBD, 0x29, 0x26, 0xDB, 0x3, 0xA2, 0xDD, 0x18, 0xB0, 0x3F, 0xC1, 0x50, 0x8A, 0x9A, 0xAC, 0x45, 0xEB, 0x36, 0x24, 0x40, 0x20, 0x3A, 0x32, 0x3E, 0x9, 0xED, 0xEE, 0x63, 0x24, 0xEE, 0x2E, 0x37, 0xB4, 0x43, 0x2C, 0x18, 0x67, 0xED, 0x69, 0x6E, 0x6C, 0x9D, 0xB1, 0xE6, 0xAB, 0xEA, 0x2, 0x62, 0x88, 0x95, 0x4A, 0x9C, 0x2D, 0x57, 0x58, 0xD7, 0xC5, 0xDB, 0x7C, 0x9E, 0x48, 0xAA, 0x3D, 0x21, 0xCA, 0xE3, 0xD9, 0x77, 0xA7, 0xC3, 0x92, 0x60, 0x66, 0xAA, 0x39, 0x3D, 0xBD, 0x53, 0x8D, 0xD0, 0xC3, 0xD, 0xA8, 0x91, 0x6C, 0x87, 0x57, 0xF2, 0x4C, 0x18, 0x48, 0x80, 0x14, 0x66, 0x8A, 0x26, 0x27, 0x16, 0x3A, 0x37, 0xB2, 0x61, 0x83, 0x3D, 0xC2, 0xF8, 0xC3, 0xC5, 0x6B, 0x1B, 0x2E, 0xB, 0xE2, 0x1F, 0xD3, 0xFB, 0xDB, 0x50, 0x7B, 0x29, 0x50, 0xB7, 0x7A, 0x6C, 0xC0, 0x2E, 0xFB, 0x39, 0x3E, 0x57, 0x41, 0x93, 0x83, 0xA9, 0x20, 0x76, 0x7B, 0xCA, 0x2C, 0x97, 0x21, 0x7, 0xAA, 0x61, 0x38, 0x45, 0x42, 0xD4, 0x7C, 0xBF, 0xB8, 0x2C, 0xFE, 0x5C, 0x41, 0x53, 0x89, 0xD1, 0xB0, 0xA2, 0xD7, 0x4E, 0x2C, 0x5D, 0xA8, 0x51, 0xFD };
        byte[] MACKey = new byte[] { 0xCB, 0x41, 0xF1, 0x70, 0x6C, 0xDE, 0x9, 0x65, 0x12, 0x3, 0xC2, 0xD0, 0xEF, 0xBA, 0xDD, 0xF8, 0x47, 0xA0, 0xD3, 0x15, 0xCB, 0x2E, 0x53, 0xFF, 0x8B, 0xAC, 0x41, 0xDA, 0x0, 0x2, 0x67, 0x2E, 0x92, 0x2, 0x44, 0xC6, 0x6E, 0x2, 0xD5, 0xF0, 0xDA, 0xD3, 0xE9, 0x4C, 0x42, 0xBB, 0x65, 0xF0, 0xD1, 0x41, 0x57, 0xDE, 0xCF, 0x41, 0x5, 0xEF, 0x56, 0x9, 0xD5, 0xB0, 0x98, 0x44, 0x57, 0xC1, 0x93, 0x5D, 0xF3, 0x6, 0x1F, 0xF0, 0x6E, 0x9F, 0x20, 0x41, 0x92, 0xBA, 0x11, 0xE5, 0xBB, 0x2C, 0xAC, 0x4, 0x30, 0xC1, 0xC3, 0x70, 0xCB, 0x3D, 0x11, 0x3F, 0xEA, 0x5E, 0xC1, 0x2, 0x1E, 0xB8, 0x75, 0xE5, 0x94, 0x6D, 0x7A, 0x96, 0xAC, 0x69, 0xA1, 0x62, 0x6C, 0x62, 0x6, 0xB7, 0x25, 0x27, 0x36, 0xF2, 0x42, 0x53, 0xC9, 0xEE, 0x9B, 0x85, 0xEB, 0x85, 0x2D, 0xFC, 0x81, 0x46, 0x31, 0x34, 0x6C, 0x4, 0x2E, 0xB4, 0x18, 0x7A, 0xA1, 0xC0, 0x15, 0xA4, 0x76, 0x70, 0x32, 0xC0, 0xBB, 0x28, 0xF0, 0x76, 0xB6, 0x64, 0x85, 0xF5, 0x15, 0x31, 0xC1, 0x2E, 0x94, 0x8F, 0x47, 0xDB, 0xC2, 0xCB, 0x90, 0x4A, 0x4B, 0x75, 0xD1, 0xE8, 0xA6, 0xD9, 0x31, 0xDA, 0xB4, 0xA0, 0x7E, 0xA, 0x54, 0xD1, 0xBB, 0x5B, 0x55, 0xE6, 0x2, 0x14, 0x17, 0x46, 0xBD, 0x9, 0xFB, 0x15, 0xE8, 0xF0, 0x1A, 0x8D, 0x74, 0xE9, 0xE6, 0x39, 0x59, 0xCB, 0x37, 0x33, 0x6B, 0xC1, 0xB8, 0x96, 0xEC, 0x78, 0xDA, 0x73, 0x4C, 0x15, 0xE3, 0x62, 0xDB, 0x4, 0x36, 0x8F, 0xBB, 0xA2, 0x80, 0xF2, 0xA, 0x4, 0x3E, 0xD, 0x9, 0x41, 0xE9, 0xF5, 0x19, 0x3E, 0x1B, 0x36, 0xA, 0x33, 0xC4, 0x3B, 0x26, 0x65, 0x24, 0x88, 0x1, 0x25, 0x22, 0x2E, 0x64, 0x8F, 0x5, 0xF2, 0x8B, 0xE3, 0x4B, 0xA3, 0xCA, 0xBF, 0xC9, 0xC5, 0x44 };
        byte[] IncrementingDataSrc = new byte[257]; // initialized on Form Load
        byte[] ZeroDataSrc = new byte[257];
        byte[] TreeDataSrc256 = new byte[508]; // initialized on Form Load
        byte[] TreeDataSrc512 = new byte[1019]; // initialized on Form Load
        byte[] TreeDataSrc1k = new byte[2043]; // initialized on Form Load

        #endregion

        public frmDeluxe()
        {
            InitializeComponent();
        }

        private void frmDeluxe_Load(object sender, EventArgs e)
        {

            InitKatsArrays();

            //THESE ONLY NEED TO BE RUN ONCE TO GENERATE THE FILES!
            //Source control may make the files read-only and will crash.  Bear this in mind!  
            //Check out the files before running or manually set non-readonly
            //=================
            //ParseKats();
            //ParseKatFiles();
            //=================
            PopulateKATTests();


            //PopulateATests();

        }//end of frmDeluxe_Load()

        #region "NIST KATs tests and setup."

        private void InitKatsArrays()
        {
            for (int i = 0; i < IncrementingDataSrc.Length; i++)
                IncrementingDataSrc[i] = (byte)(255 - i);
            IncrementingDataSrc[256] = 255;

            // build the data structure for the tree hashing tests

            int BLOCKNUM = 1; // mod 2
            for (int i = 0; i < TreeDataSrc256.Length; i += 16)
            {
                int ROWNUM = (i / 16) % 16;
                if (ROWNUM == 0 && i > 0)
                    BLOCKNUM = (BLOCKNUM + 1) % 2;
                for (int j = 0; j < 16; j++)
                {
                    if (i + j >= TreeDataSrc256.Length)
                        break;
                    if (j % 2 == 0)
                    {
                        TreeDataSrc256[i + j] = (byte)(j + (ROWNUM << 4));
                    }
                    else
                    {
                        TreeDataSrc256[i + j] = (byte)(BLOCKNUM);
                    }
                }

            }
            BLOCKNUM = 2; // mod 4
            for (int i = 0; i < TreeDataSrc512.Length; i += 16)
            {
                int ROWNUM = (i / 16) % 16;
                if (ROWNUM == 0 && i > 0)
                    BLOCKNUM = (BLOCKNUM + 1) % 4;
                for (int j = 0; j < 16; j++)
                {
                    if (i + j >= TreeDataSrc512.Length)
                        break;
                    if (j % 2 == 0)
                    {
                        TreeDataSrc512[i + j] = (byte)(j + (ROWNUM << 4));
                    }
                    else
                    {
                        TreeDataSrc512[i + j] = (byte)(BLOCKNUM);
                    }
                }

            }
            BLOCKNUM = 4; // mod 8
            for (int i = 0; i < TreeDataSrc1k.Length; i += 16)
            {
                int ROWNUM = (i / 16) % 16;
                if (ROWNUM == 0 && i > 0)
                    BLOCKNUM = (BLOCKNUM + 1) % 8;
                for (int j = 0; j < 16; j++)
                {
                    if (i + j >= TreeDataSrc1k.Length)
                        break;
                    if (j % 2 == 0)
                    {
                        TreeDataSrc1k[i + j] = (byte)(j + (ROWNUM << 4));
                    }
                    else
                    {
                        TreeDataSrc1k[i + j] = (byte)(BLOCKNUM);
                    }
                }

            }
            //end of tree test data setup
        }

        private void ParseKats()
        {
            const string SrcFile = BASEWORKINGDIR + @"skein_golden_kat_internals.txt";
            const string DestDir = BASEWORKINGDIR + @"ParsedKats\";
            try
            {
                System.IO.Directory.CreateDirectory(DestDir + "misc");
            }
            catch
            { }

            if (!System.IO.File.Exists(SrcFile))
            {
                throw new System.IO.FileNotFoundException("Source file doesn't exist:\n" + SrcFile);
            }

            string SourceTextAll = System.IO.File.ReadAllText(SrcFile);
            string[] SourceChunks = SourceTextAll.Split(new string[] { "--------------------------------" }, StringSplitOptions.None);
            foreach (string Chunk in SourceChunks)
            {
                string NewChunk = Chunk.Trim();
                if (NewChunk == "")
                {
                    continue;
                }
                string[] Lines = NewChunk.Split(new string[] { "\r\n" }, StringSplitOptions.None);
                bool AlreadyWritten = false;
                foreach (string Line in Lines)
                {
                    string NewLine = Line.Trim();
                    if (NewLine == "")
                    {
                        continue;
                    }
                    string NewFileName = string.Empty;
                    if (!AlreadyWritten)
                    {
                        NewLine = NewLine.Replace("Tree:", "Tree_");
                        NewLine = NewLine.Replace("+", "_");
                        NewLine = NewLine.Replace(":", "!");
                        if (NewLine.Contains("data = '"))
                        {
                            string FileType = NewLine.Substring(NewLine.IndexOf("data = '") + 8).Replace("'", "");
                            try
                            {
                                System.IO.Directory.CreateDirectory(DestDir + FileType);
                            }
                            catch
                            { }
                            NewLine = NewLine.Replace("! ", "^H");
                            NewLine = NewLine.Replace("!", "");
                            NewLine = NewLine.Replace("-bit hash, msgLen = ", "^L");
                            NewLine = NewLine.Replace(" bits, data = '", "");
                            NewLine = NewLine.Replace("Skein-", "S");
                            NewLine = NewLine.Replace(FileType, "");
                            NewLine = NewLine.Replace("'", "");
                            if (FileType.Contains("MAC"))
                            {
                                string MACLength = Chunk;
                                MACLength = MACLength.Substring(MACLength.IndexOf("MAC key =") + 9, 30);
                                MACLength = MACLength.Substring(0, MACLength.IndexOf("bytes"));
                                MACLength = "^MAC" + MACLength.Trim();
                                NewLine = NewLine + MACLength;
                            }
                            NewFileName = NewLine.Replace(" ", "");
                            //outStatus.AppendText(FileType + ">" + NewFileName + "\r\n");
                            System.IO.File.WriteAllLines(DestDir + FileType + @"\" + NewFileName + ".txt", Lines);
                        }
                        else if (NewLine.Contains("Tree"))
                        {
                            NewLine = NewLine.Replace("! ", "^H");
                            NewLine = NewLine.Replace("!", "");
                            NewLine = NewLine.Replace("-bit hash, msgLen = ", "^L");
                            NewLine = NewLine.Replace("bits. Tree_ ", "");
                            NewLine = NewLine.Replace("leaf=", "^LF");
                            NewLine = NewLine.Replace(", node=", "^ND");
                            NewLine = NewLine.Replace(", maxLevels=", "^ML");
                            NewLine = NewLine.Replace("Skein-", "S");
                            NewLine = NewLine.Replace("'", "");
                            NewFileName = NewLine.Replace(" ", "");
                            //txtOutput1.AppendText("tree>" + NewFileName + "\r\n");
                            System.IO.File.WriteAllLines(DestDir + @"tree\" + NewFileName + ".txt", Lines);
                        }
                        else
                        {
                            System.IO.File.WriteAllLines(DestDir + @"misc\" + NewLine + ".txt", Lines);
                        }
                        AlreadyWritten = true;
                    }
                    else
                    {
                        break;
                    }
                }//Next Line
            }//Next Chunk
        }//end ParseKats

        private void ParseKatFiles()
        {
            const string SrcDir = BASEWORKINGDIR + @"ParsedKats\";
            string[] Dirs = System.IO.Directory.GetDirectories(SrcDir);
            string MasterFile = null;

            foreach (string D in Dirs)
            {
                if (D.Contains("misc"))
                {
                    continue;
                }
                string[] Files = System.IO.Directory.GetFiles(D + @"\");
                foreach (string F in Files)
                {
                    string AllStuff = System.IO.File.ReadAllText(F);
                    string[] AllLines = AllStuff.Split(new string[] { "\r\n" }, StringSplitOptions.None);
                    string Result = string.Empty;
                    bool Snap = false;
                    for (int i = AllLines.GetLowerBound(0); i <= AllLines.GetUpperBound(0); i++)
                    {
                        if (Snap)
                        {
                            Result += AllLines[i];
                        }
                        else if (AllLines[i].Contains("Result:"))
                        {
                            System.Diagnostics.Debug.Print("POOPY!");
                            Snap = true;
                        }
                    }
                    Snap = false;
                    Result = Result.Replace("\r\n", "");
                    Result = Result.Replace(" ", "");

                    MasterFile += (F.Replace(SrcDir, "")) + "^" + Result + "\r\n";
                    MasterFile = MasterFile.Replace(@"\", "^");
                    MasterFile = MasterFile.Replace(".txt", "");
                }//Next F
            }//Next D

            System.IO.File.WriteAllText(SrcDir + "MASTER.txt", MasterFile);

        }// end ParseKatFiles

        private void PopulateKATTests()
        {
            const string SrcFile = BASEWORKINGDIR + @"ParsedKats\MASTER.txt";
            string[] SrcLines = System.IO.File.ReadAllLines(SrcFile);
            lstTests.Items.Clear();
            foreach (string Thing in SrcLines)
            {
                string[] ThingParts = Thing.Split('^');
                // TYPE 
                if (ThingParts[0].ToLower().Contains("tree") && !chkTree.Checked)
                {
                    continue;
                }
                if (ThingParts[0].ToLower().Contains("mac") && !chkMAC.Checked)
                {
                    continue;
                }
                if (ThingParts[0].ToLower().Contains("zero") && !chkZeros.Checked)
                {
                    continue;
                }
                if (ThingParts[0].ToLower().Contains("increm") && !chkIncrementing.Checked)
                {
                    continue;
                }
                if (ThingParts[0].ToLower().Contains("random") && !ThingParts[0].ToLower().Contains("mac")
                    && !chkRandom.Checked)
                {
                    continue;
                }
                // STATE SIZE
                if (ThingParts[1].ToLower().Contains("s256") && !chk256.Checked)
                {
                    continue;
                }
                if (ThingParts[1].ToLower().Contains("s512") && !chk512.Checked)
                {
                    continue;
                }
                if (ThingParts[1].ToLower().Contains("s1024") && !chk1024.Checked)
                {
                    continue;
                }
                //*/
                lstTests.Items.Add(Thing);
            }
            txtResults.Text = string.Empty;
            ssMain.Items["tslblStatus"].Text = "Ready.";
        }

        private void RunAgainstKats()
        {
            Skein.SkeinEx my256 = new Skein.Skein256Ex();
            Skein.SkeinEx my512 = new Skein.Skein512Ex();
            Skein.SkeinEx my1k = new Skein.Skein1024Ex();
            int completedTests = 0;
            int passedTests = 0;
            int failedTests = 0;
            System.Diagnostics.Stopwatch overAllSW = new System.Diagnostics.Stopwatch();
            System.Diagnostics.Stopwatch testSW = new System.Diagnostics.Stopwatch();

            overAllSW.Start();
            foreach (string Thing in lstTests.SelectedItems)
            {
                //try
                //{
                string[] ThingParts = Thing.Split('^');
                byte[] DataToUse = null;
                UInt16 HashBitLen;
                int MACInputLen;
                byte[] MACToUse = null;
                byte treeNode;
                byte treeLeaf;
                byte treeMaxLevels;

                int InputLen = int.Parse(ThingParts[3].Replace("L", String.Empty));

                if (ThingParts.Length == 8)
                {
                    treeLeaf = byte.Parse(ThingParts[4].Replace("LF", string.Empty), System.Globalization.NumberStyles.HexNumber);
                    treeNode = byte.Parse(ThingParts[5].Replace("ND", string.Empty), System.Globalization.NumberStyles.HexNumber);
                    treeMaxLevels = byte.Parse(ThingParts[6].Replace("ML", string.Empty), System.Globalization.NumberStyles.HexNumber);
                }
                else
                {
                    treeLeaf = 0;
                    treeNode = 0;
                    treeMaxLevels = 0;
                }

                //create sub-arrays of data, otherwise Skein functions will use ENTIRE array
                if (ThingParts.Length == 6)
                {
                    MACInputLen = int.Parse(ThingParts[4].Replace("MAC", String.Empty));
                    MACToUse = new byte[MACInputLen];
                    Buffer.BlockCopy(MACKey, 0, MACToUse, 0, MACInputLen);
                }
                else
                    MACToUse = null;

                if (InputLen == 0)
                    DataToUse = null;
                else
                {
                    int numBytes;
                    int numExtraBits;
                    numBytes = Math.DivRem(InputLen, 8, out numExtraBits);
                    if (numExtraBits > 0)
                        DataToUse = new byte[numBytes + 1];
                    else
                        DataToUse = new byte[numBytes];
                    System.Diagnostics.Debug.Print("INPUTLEN: " + InputLen.ToString() + " DATATOUSE.LENGTH: " + DataToUse.Length.ToString());
                    switch (ThingParts[0].ToLower())
                    {
                        case "incrementing":
                            Buffer.BlockCopy(IncrementingDataSrc, 0, DataToUse, 0, DataToUse.Length);
                            break;
                        case "random":
                            Buffer.BlockCopy(RandomDataSrc, 0, DataToUse, 0, DataToUse.Length);
                            break;
                        case "zero":
                            Buffer.BlockCopy(ZeroDataSrc, 0, DataToUse, 0, DataToUse.Length);
                            break;
                        case "random_mac":
                            Buffer.BlockCopy(RandomMACDataSrc, 0, DataToUse, 0, DataToUse.Length);
                            break;
                        case "tree":
                            switch (ThingParts[1].ToLower())
                            {
                                case "s256": Buffer.BlockCopy(TreeDataSrc256, 0, DataToUse, 0, DataToUse.Length); break;
                                case "s512": Buffer.BlockCopy(TreeDataSrc512, 0, DataToUse, 0, DataToUse.Length); break;
                                case "s1024": Buffer.BlockCopy(TreeDataSrc1k, 0, DataToUse, 0, DataToUse.Length); break;
                            }
                            break;
                        default:
                            //this.txtOutput2.AppendText("Skip UNKNOWN test:" + Thing.Substring(0, 60) + "\r\n");
                            continue;
                    }
                }
                HashBitLen = UInt16.Parse(ThingParts[2].Replace("H", String.Empty));
                byte[] Result = null;

                //try
                //{
                testSW.Start();
                switch (ThingParts[1].ToLower())
                {
                    case "s256":
                        if (Thing.ToLower().Contains("mac") && MACToUse != null)
                            my256.Initialize(HashBitLen, MACToUse, null, 0, 0, 0);
                        else
                            my256.Initialize(HashBitLen, null, null, treeLeaf, treeNode, treeMaxLevels);
                        Result = my256.ComputeHash(DataToUse, (byte)(InputLen % 8));
                        break;
                    case "s512":
                        if (Thing.ToLower().Contains("mac") && MACToUse != null)
                            my512.Initialize(HashBitLen, MACToUse, null, 0,0,0);
                        else
                            my512.Initialize(HashBitLen, null, null, treeLeaf, treeNode, treeMaxLevels);
                        Result = my512.ComputeHash(DataToUse, (byte)(InputLen % 8));
                        break;
                    case "s1024":
                        if (Thing.ToLower().Contains("mac") && MACToUse != null)
                            my1k.Initialize(HashBitLen, MACToUse, null, 0, 0, 0);
                        else
                            my1k.Initialize(HashBitLen, null, null, treeLeaf, treeNode, treeMaxLevels);
                        Result = my1k.ComputeHash(DataToUse, (byte)(InputLen % 8));
                        break;
                }
                //}
                //catch (Exception ex)
                //{
                //this.txtOutput2.AppendText("*EXCEPTION!!!!! " + Thing + "\r\n");
                //    MessageBox.Show("EXCEPTION: " + ex.Message + "\r\n" + ex.StackTrace);
                //}
                testSW.Stop();
                string ResultString = Bytes2HexString(Result);
                string testAbrvName = Thing.Replace(ThingParts[ThingParts.GetUpperBound(0)], string.Empty).Replace('^', '\t');
                string testDuration = testSW.Elapsed.ToString(@"h\:mm\:ss\.fffff");

                if (ThingParts.Length == 6)
                {
                    if (ResultString.CompareTo(ThingParts[5]) == 0)
                    {
                        passedTests++;
                        txtResults.AppendText("-PASS in " + testDuration + " " + testAbrvName + "\r\n");
                    }
                    else
                    {
                        failedTests++;
                        txtResults.AppendText("*FAIL in " + testDuration + " " + Thing + "\r\n");
                        //this.txtResults.AppendText(" EXPECTED: " + ThingParts[5] + "\r\n");
                        //this.txtResults.AppendText(" RESULT  : " + ResultString + "\r\n");
                    }
                }
                else if (ThingParts.Length == 8)
                {
                    if (ResultString.CompareTo(ThingParts[7]) == 0)
                    {
                        passedTests++;
                        txtResults.AppendText("-PASS in " + testDuration + " " + testAbrvName + "\r\n");
                    }
                    else
                    {
                        failedTests++;
                        txtResults.AppendText("*FAIL in " + testDuration + " " + Thing + "\r\n");
                        //this.txtResults.AppendText(" EXPECTED: " + ThingParts[7] + "\r\n");
                        //this.txtResults.AppendText(" RESULT  : " + ResultString + "\r\n");
                    }
                }
                else
                {
                    if (ResultString.CompareTo(ThingParts[4]) == 0)
                    {
                        passedTests++;
                        txtResults.AppendText("-PASS in " + testDuration + " " + testAbrvName + "\r\n");
                    }
                    else
                    {
                        failedTests++;
                        txtResults.AppendText("*FAIL in " + testDuration + " " + Thing + "\r\n");
                        //this.txtResults.AppendText(" EXPECTED: " + ThingParts[4] + "\r\n");
                        //this.txtResults.AppendText(" RESULT  : " + ResultString + "\r\n");
                    }
                }

                //}
                //catch (Exception ex)
                //{
                //    MessageBox.Show("'FOR-EACH' EXCEPTION: " + ex.Message + "\r\n" + ex.StackTrace);
                //}
                testSW.Reset();
                completedTests++;
                Application.DoEvents();
            } //end foreach Thing
            overAllSW.Stop();
            ssMain.Items["tslblStatus"].Text = "Done in " + overAllSW.Elapsed.Duration().ToString(@"h\:mm\:ss\.ffff")
                + "  " + completedTests.ToString() + " Tests Complete: " +
                passedTests.ToString() + " PASSED, " + failedTests.ToString() + " FAILED";

            return;
        }//end RunAgainstKats

        #endregion

        #region "Tests for string of 'a's"

        private void PopulateATests()
        {
            byte[] patterns = { 2, 3, 4, 5, 7, 8, 10, 11, 13 }; // these will be raised to the power of "p" below
            lstTests.Items.Clear();
            for (int p = 1; p <= 9; p++) // raise each "pattern" to the power of "p" for each statewidth selected
            {
                List<string> theItems = new List<string>();
                foreach (byte pattern in patterns)
                {
                    if ((pattern > 7 || p > 6) && rbASLM.Checked)
                        continue;  // stop at the higher values in low memory situations
                    if (pattern >= 10 && p > 8)
                        continue;  // don't allow rediculously large numbers, may cause out of memory errors
                    if (chk256.Checked)
                    {
                        theItems.Add(" 256,  160, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add(" 256,  256, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add(" 256,  384, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                    }
                    if (chk512.Checked)
                    {
                        theItems.Add(" 512,  160, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add(" 512,  256, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add(" 512,  384, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add(" 512,  512, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add(" 512, 1024, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                    }
                    if (chk1024.Checked)
                    {
                        theItems.Add("1024,  160, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add("1024,  256, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add("1024,  384, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add("1024,  512, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        theItems.Add("1024, 1024, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                        if (!rbASLM.Checked)
                            theItems.Add("1024, 2048, length=" + Math.Pow(pattern, p).ToString().PadLeft(10));
                    }
                    foreach (string thing in theItems)
                    {
                        if (!lstTests.Items.Contains(thing))
                            lstTests.Items.Add(thing);
                    }
                }
            }
        }

        private void RunAgainstAs()
        {
            Skein.Skein256Ex my256 = new Skein.Skein256Ex();
            Skein.Skein512Ex my512 = new Skein.Skein512Ex();
            Skein.Skein1024Ex my1k = new Skein.Skein1024Ex();
            int completedTests = 0;
            UInt64 runningByteCount = 0;
            //int passedTests = 0;
            //int failedTests = 0;
            byte[] result = null;
            System.Diagnostics.Stopwatch overAllSW = new System.Diagnostics.Stopwatch();
            System.Diagnostics.Stopwatch testSW = new System.Diagnostics.Stopwatch();

            overAllSW.Start();
            foreach (string Thing in lstTests.SelectedItems)
            {
                string[] pieces = Thing.Split(new char[] { ',' });
                string lengthParse = pieces[2].Replace("length=", "");
                int length = int.Parse(lengthParse);
                //note:
                //doing this versus "string = new string('a', length)" accomplishes the same thing.
                //the problem with the new string method is it consumes TONS of memory needlessly.
                //this method of just starting with a byte array works just as fast, and uses 1/5th the memory!!!
                byte[] source = new byte[length];
                for (int i = 0; i < length; i++)
                    source[i] = 0x61; // 'a'
                                      //end note
                runningByteCount += (ulong)source.Length;
                testSW.Start();
                switch (int.Parse(pieces[0]))
                {
                    case 256:
                        my256.Initialize(uint.Parse(pieces[1]), null, null, 0,0,0);
                        result = my256.ComputeHash(source);
                        break;
                    case 512:
                        my512.Initialize(uint.Parse(pieces[1]), null, null, 0, 0, 0);
                        result = my512.ComputeHash(source);
                        break;
                    case 1024:
                        my1k.Initialize(uint.Parse(pieces[1]), null, null, 0, 0, 0);
                        result = my1k.ComputeHash(source);
                        break;
                }
                testSW.Stop();
                string testDuration = testSW.Elapsed.Duration().ToString(@"h\:mm\:ss\.fffff");
                txtResults.AppendText(Thing + ", " + testDuration + "     RESULT(base64):\r\n");
                txtResults.AppendText(Convert.ToBase64String(result, Base64FormattingOptions.InsertLineBreaks) + "\r\n\r\n");
                result = null;
                source = null;
                //if (completedTests % 15 == 0 || testSW.Elapsed.TotalSeconds > 5)
                //    System.GC.Collect();
                completedTests++;
                if (completedTests % 10 == 0 || testSW.Elapsed.TotalSeconds > 2)
                    tslblStatus.Text = completedTests.ToString() + " tests complete... Still Running...";
                Application.DoEvents();
                testSW.Reset();
            }
            overAllSW.Stop();
            Double bytesPerSec = runningByteCount / overAllSW.Elapsed.TotalSeconds;
            ssMain.Items["tslblStatus"].Text = "Done in " + overAllSW.Elapsed.Duration().ToString(@"h\:mm\:ss\.ffff") + ". " +
                completedTests.ToString() + " Tests Complete " +
                (runningByteCount / 1024).ToString() + " KBytes processed (" + bytesPerSec.ToString("0.0") + " bytes/sec or " +
                (bytesPerSec / 1048576).ToString("0.0") + " MB/sec) "; //: " +
            //passedTests.ToString() + " PASSED, " + failedTests.ToString() + " FAILED";
        }

        #endregion

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

        private void btnRunTests_Click(object sender, EventArgs e)
        {
            if (lstTests.SelectedItems.Count == 0)
            {    //MessageBox.Show(this, "You must select at least one test to run.", "OOPS!", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                PerformCodeCoverageTests();

                return;
            }
            ssMain.Items["tslblStatus"].Text = "Running tests... Stand by...";
            Enabled = false;
            txtResults.Visible = false;
            if (rbKATS.Checked == true)
                RunAgainstKats();
            else if (rbAS.Checked == true || rbASLM.Checked)
                RunAgainstAs();
            txtResults.Visible = true;
            System.GC.Collect();
            Enabled = true;
        }

        private void PerformCodeCoverageTests()
        {

            byte[] testMe = new byte[1024];
            byte[] tweakMe = new byte[16];
            byte[] keyMe256 = new byte[32];
            byte[] keyMe512 = new byte[64];
            byte[] keyMe1024 = new byte[128];
            Random myRandom = new Random(DateTime.Now.Millisecond);
            myRandom.NextBytes(testMe);
            myRandom.NextBytes(keyMe256);
            myRandom.NextBytes(keyMe512);
            myRandom.NextBytes(keyMe1024);
            myRandom.NextBytes(tweakMe);

            testMe = new System.Security.Cryptography.PBKDF2HMACSkein512(tweakMe, keyMe256, 100).GetBytes(1024);
            //testMe = new SkeinLib.DeriveBytesEx(tweakMe, keyMe256, 100).GetBytes(1024);

            byte[] result = SkeinTester.ThreeFishWrappers.ThreeFish256Bytes(testMe, keyMe256, tweakMe);
            byte[] invResult = SkeinTester.ThreeFishWrappers.InvThreeFish256Bytes(result, keyMe256, tweakMe);
            //byte[] result = SkeinLib.ThreeFish.ThreeFish256Bytes(testMe, keyMe256, tweakMe);
            //byte[] invResult = SkeinLib.ThreeFish.InvThreeFish256Bytes(result, keyMe256, tweakMe);
            string source = Convert.ToBase64String(testMe);
            string resource = Convert.ToBase64String(invResult);
            if (source.Equals(resource))
                txtResults.AppendText("ThreeFish256 Test SUCCESSFULL!\r\n");
            else
                txtResults.AppendText("*ThreeFish256 Test FAIL!\r\n");

            myRandom.NextBytes(testMe);
            result = SkeinTester.ThreeFishWrappers.ThreeFish512Bytes(testMe, keyMe512, tweakMe);
            invResult = SkeinTester.ThreeFishWrappers.InvThreeFish512Bytes(result, keyMe512, tweakMe);
            //result = SkeinLib.ThreeFish.ThreeFish512Bytes(testMe, keyMe512, tweakMe);
            //invResult = SkeinLib.ThreeFish.InvThreeFish512Bytes(result, keyMe512, tweakMe);
            source = Convert.ToBase64String(testMe);
            resource = Convert.ToBase64String(invResult);
            if (source.Equals(resource))
                txtResults.AppendText("ThreeFish512 Test SUCCESSFULL!\r\n");
            else
                txtResults.AppendText("*ThreeFish512 Test FAIL!\r\n");

            myRandom.NextBytes(testMe);
            result = SkeinTester.ThreeFishWrappers.ThreeFish1024Bytes(testMe, keyMe1024, tweakMe);
            invResult = SkeinTester.ThreeFishWrappers.InvThreeFish1024Bytes(result, keyMe1024, tweakMe);
            //result = SkeinLib.ThreeFish.ThreeFish1024Bytes(testMe, keyMe1024, tweakMe);
            //invResult = SkeinLib.ThreeFish.InvThreeFish1024Bytes(result, keyMe1024, tweakMe);
            source = Convert.ToBase64String(testMe);
            resource = Convert.ToBase64String(invResult);
            if (source.Equals(resource))
                txtResults.AppendText("ThreeFish1024 Test SUCCESSFULL!\r\n");
            else
                txtResults.AppendText("*ThreeFish1024 Test FAIL!\r\n");

            byte[] array1 = new byte[] { 1, 1, 1, 1, 1, 1, 1 };
            byte[] array2 = new byte[] { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 };
            byte[] array1long = new byte[] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5 };
            byte[] array2long = new byte[] { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0 };



            result = new Skein.Skein256Ex().ComputeHash(array1);
            invResult = new Skein.Skein256Ex().ComputeHash(new ArraySegment<byte>(array2, 2, array1.Length));
            //result = new SkeinLib.Skein256Ex().ComputeHash(array1);
            //invResult = new SkeinLib.Skein256Ex().ComputeHash(new ArraySegment<byte>(array2, 2, array1.Length));
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("ArraySegment Test SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*ArraySegment Test FAIL!!!\r\n");
            }

            result = new Skein.Skein256Ex().ComputeHash(array1long);
            invResult = new Skein.Skein256Ex().ComputeHash(new ArraySegment<byte>(array2long, 2, array1long.Length));
            //result = new SkeinLib.Skein256Ex().ComputeHash(array1long);
            //invResult = new SkeinLib.Skein256Ex().ComputeHash(new ArraySegment<byte>(array2long, 2, array1long.Length));
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("ArraySegment Long Test SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*ArraySegment Long Test FAIL!!!\r\n");
            }

            System.Security.Cryptography.Skein256Managed testSSC = new System.Security.Cryptography.Skein256Managed();
            result = testSSC.ComputeHash(array1);
            Skein.Skein256Ex testSkeinEx = new Skein.Skein256Ex();
            //SkeinLib.Skein256Ex testSkeinEx = new SkeinLib.Skein256Ex();
            invResult = testSkeinEx.ComputeHash(array1);
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("System.Security.Crpyto.SkeinHashAlgorithm Test SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*System.Security.Crpyto.SkeinHashAlgorithm Test FAIL!!!\r\n");
            }


            testSSC = new System.Security.Cryptography.Skein256Managed();
            result = testSSC.ComputeHash(keyMe1024);
            testSkeinEx = new Skein.Skein256Ex();
            //testSkeinEx = new SkeinLib.Skein256Ex();
            invResult = testSkeinEx.ComputeHash(keyMe1024);
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("System.Security.Crpyto.SkeinHashAlgorithm Long Test SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*System.Security.Crpyto.SkeinHashAlgorithm Long Test FAIL!!!\r\n");
            }

            testMe = new System.Security.Cryptography.PBKDF2HMACSkein512(tweakMe, keyMe256, 100).GetBytes(1028);
            //testMe = new SkeinLib.DeriveBytesEx(tweakMe, keyMe256, 100).GetBytes(1028);
            testSSC = new System.Security.Cryptography.Skein256Managed();
            result = testSSC.ComputeHash(testMe);
            testSkeinEx = new Skein.Skein256Ex();
            //testSkeinEx = new SkeinLib.Skein256Ex();
            invResult = testSkeinEx.ComputeHash(testMe);
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("System.Security.Crpyto.SkeinHashAlgorithm Long Test2 SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*System.Security.Crpyto.SkeinHashAlgorithm Long Test2 FAIL!!!\r\n");
            }

            System.Security.Cryptography.HMACSkein256Managed testHSSC = new System.Security.Cryptography.HMACSkein256Managed();
            testHSSC.Key = keyMe256;
            result = testHSSC.ComputeHash(array1);
            testSkeinEx = new Skein.Skein256Ex(256, keyMe256);
            //testSkeinEx = new SkeinLib.Skein256Ex(256, keyMe256);
            invResult = testSkeinEx.ComputeHash(array1);
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("System.Security.Crpyto.HMACSkeinHashAlgorithm SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*System.Security.Crpyto.HMACSkeinHashAlgorithm FAIL!!!\r\n");
            }
       
            testHSSC = new System.Security.Cryptography.HMACSkein256Managed();
            testHSSC.Key = keyMe256;
            result = testHSSC.ComputeHash(keyMe1024);
            testSkeinEx = new Skein.Skein256Ex(256, keyMe256);
            //testSkeinEx = new SkeinLib.Skein256Ex(256, keyMe256);
            invResult = testSkeinEx.ComputeHash(keyMe1024);
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("System.Security.Crpyto.HMACSkeinHashAlgorithm Long Test SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*System.Security.Crpyto.HMACSkeinHashAlgorithm Long Test FAIL!!!\r\n");
            }

            testMe = new System.Security.Cryptography.PBKDF2HMACSkein512(tweakMe, keyMe256, 100).GetBytes(1028);
            testHSSC = new System.Security.Cryptography.HMACSkein256Managed();
            testHSSC.Key = keyMe256;
            result = testHSSC.ComputeHash(testMe);
            testSkeinEx = new Skein.Skein256Ex(256, keyMe256);
            //testSkeinEx = new SkeinLib.Skein256Ex(256, keyMe256);
            invResult = testSkeinEx.ComputeHash(testMe);
            if (Convert.ToBase64String(result) == Convert.ToBase64String(invResult))
            {
                txtResults.AppendText("System.Security.Crpyto.HMACSkeinHashAlgorithm Long Test2 SUCCESSFULL!\r\n");
            }
            else
            {
                txtResults.AppendText("*System.Security.Crpyto.HMACSkeinHashAlgorithm Long Test2 FAIL!!!\r\n");
            }

        }


        private void btnClearSelections_Click(object sender, EventArgs e)
        {
            lstTests.BeginUpdate();
            lstTests.ClearSelected();
            lstTests.EndUpdate();
            txtResults.Text = string.Empty;
            ssMain.Items["tslblStatus"].Text = "Ready.";
        }

        private void btnClearResults_Click(object sender, EventArgs e)
        {
            txtResults.Text = string.Empty;
            ssMain.Items["tslblStatus"].Text = "Ready.";
        }

        private void rbKATS_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void rbAS_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void rbASLM_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void chkMAC_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void chkTree_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void chk1024_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void chk512_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void chk256_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void UpdateTests()
        {
            Enabled = false;
            if (rbKATS.Checked)
                PopulateKATTests();
            else if (rbAS.Checked || rbASLM.Checked)
                PopulateATests();
            chkMAC.Enabled = rbKATS.Checked;
            chkTree.Enabled = rbKATS.Checked;
            chkZeros.Enabled = rbKATS.Checked;
            chkIncrementing.Enabled = rbKATS.Checked;
            chkRandom.Enabled = rbKATS.Checked;
            txtResults.Text = string.Empty;
            ssMain.Items["tslblStatus"].Text = "Ready.";
            Enabled = true;
        }

        private void btnSelectAll_Click(object sender, EventArgs e)
        {
            Enabled = false;
            lstTests.BeginUpdate();
            for (int i = 0; i < lstTests.Items.Count; i++)
                lstTests.SelectedItems.Add(lstTests.Items[i]);
            lstTests.EndUpdate();
            Enabled = true;
        }

        private void chkRandom_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void chkIncrementing_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

        private void chkZeros_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTests();
        }

    }
}
