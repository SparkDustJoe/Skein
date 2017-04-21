using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace BuildThreeFishCPP
{
    public partial class Form1 : Form
    {

        //*X += *Y; *Y= _rotl64(*Y, N); *Y ^= *X;

        //*Y ^= *X; *Y = _rotr64(*Y, N); *X -= *Y;

              private const string MixFormatStringCS = "MIX(ref buf{0}, ref buf{1}, {2});";
        private const string InvMixFormatStringCS = "INVMIX(ref buf{0}, ref buf{1}, {2});";

        //      private const string MixFormatStringCS = "MIX(ref buf[{0}], ref buf[{1}], {2});";
        //private const string InvMixFormatStringCS = "INVMIX(ref buf[{0}], ref buf[{1}], {2});";

              private const string MixFormatStringCPP = "MIX(&(buf{0}), &(buf{1}), {2});";
        private const string InvMixFormatStringCPP = "INVMIX(&(buf{0}), &(buf{1}), {2});";

        //      private const string MixFormatStringCPP = "MIX(&(buf[{0}]), &(buf[{1}]), {2});";
        //private const string InvMixFormatStringCPP = "INVMIX(&(buf[{0}]), &(buf[{1}]), {2});";

        private const string KeyFormatString = "locKey{0}";
        private const string TweakFormatString = "locTweak{1}";
        //private const string KeyFormatString = "locKey[{0}]";
        //private const string TweakFormatString = "locTweak[{1}]";

        byte[] tf256rcon = new byte[] { 14, 16, 
                                            52, 57, 
                                            23, 40, 
                                            5, 37, 
                                            25, 33, 
                                            46, 12, 
                                            58, 22, 
                                            32, 32 };

        byte[] tf256invrcon = new byte[] { 32, 32,
                                            58, 22, 
                                            46, 12, 
                                            25, 33, 
                                            5, 37, 
                                            23, 40, 
                                            52, 57, 
                                            14, 16};

        byte[] tf256mixpat = new byte[] { 0x0, 0x1, 0x2, 0x3, 
                                              0x0, 0x3, 0x2, 0x1, 
                                              0x0, 0x1, 0x2, 0x3, 
                                              0x0, 0x3, 0x2, 0x1 };

        byte[] tf256invmixpat = new byte[] { 0x0, 0x3, 0x2, 0x1,
                                              0x0, 0x1, 0x2, 0x3, 
                                              0x0, 0x3, 0x2, 0x1, 
                                              0x0, 0x1, 0x2, 0x3};

        byte[] tf512rcon = new byte[] { 46, 36, 19, 37, 
                                            33, 27, 14, 42, 
                                            17, 49, 36, 39, 
                                            44, 9, 54, 56, 
                                            39, 30, 34, 24, 
                                            13, 50, 10, 17, 
                                            25, 29, 39, 43, 
                                            8, 35, 56, 22 };

        byte[] tf512invrcon = new byte[] {8, 35, 56, 22,
                                            25, 29, 39, 43,
                                            13, 50, 10, 17,
                                            39, 30, 34, 24,
                                            44, 9, 54, 56,
                                            17, 49, 36, 39,
                                            33, 27, 14, 42,
                                            46, 36, 19, 37};

        byte[] tf512mixpat = new byte[] { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 
                                          0x2, 0x1, 0x4, 0x7, 0x6, 0x5, 0x0, 0x3, 
                                          0x4, 0x1, 0x6, 0x3, 0x0, 0x5, 0x2, 0x7, 
                                          0x6, 0x1, 0x0, 0x7, 0x2, 0x5, 0x4, 0x3};
                                            
        byte[] tf512invmixpat = new byte[] {0x6, 0x1, 0x0, 0x7, 0x2, 0x5, 0x4, 0x3,
                                            0x4, 0x1, 0x6, 0x3, 0x0, 0x5, 0x2, 0x7, 
                                            0x2, 0x1, 0x4, 0x7, 0x6, 0x5, 0x0, 0x3,
                                            0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
                                            
        byte[] tf1024rcon = new byte[] {24, 13, 8, 47, 8, 17, 22, 37,
                                        38, 19, 10, 55, 49, 18, 23, 52, 
                                        33, 4, 51, 13, 34, 41, 59, 17, 
                                        5, 20, 48, 41, 47, 28, 16, 25, 
                                        41, 9, 37, 31, 12, 47, 44, 30, 
                                        16, 34, 56, 51, 4, 53, 42, 41, 
                                        31, 44, 47, 46, 19, 42, 44, 25, 
                                        9, 48, 35, 52, 23, 31, 37, 20 };

        byte[] tf1024invrcon = new byte[] {9, 48, 35, 52, 23, 31, 37, 20,
                                            31, 44, 47, 46, 19, 42, 44, 25,
                                            16, 34, 56, 51, 4, 53, 42, 41,
                                            41, 9, 37, 31, 12, 47, 44, 30, 
                                            5, 20, 48, 41, 47, 28, 16, 25,
                                            33, 4, 51, 13, 34, 41, 59, 17,
                                            38, 19, 10, 55, 49, 18, 23, 52,
                                            24, 13, 8, 47, 8, 17, 22, 37};

        byte[] tf1024mixpat = new byte[] { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF,                                         
                                           0x0, 0x9, 0x2, 0xD, 0x6, 0xB, 0x4, 0xF, 0xA, 0x7, 0xC, 0x3, 0xE, 0x5, 0x8, 0x1,
                                           0x0, 0x7, 0x2, 0x5, 0x4, 0x3, 0x6, 0x1, 0xC, 0xF, 0xE, 0xD, 0x8, 0xB, 0xA, 0x9,
                                           0x0, 0xF, 0x2, 0xB, 0x6, 0xD, 0x4, 0x9, 0xE, 0x1, 0x8, 0x5, 0xA, 0x3, 0xC, 0x7};

        byte[] tf1024invmixpat = new byte[] { 0x0, 0xF, 0x2, 0xB, 0x6, 0xD, 0x4, 0x9, 0xE, 0x1, 0x8, 0x5, 0xA, 0x3, 0xC, 0x7,
                                              0x0, 0x7, 0x2, 0x5, 0x4, 0x3, 0x6, 0x1, 0xC, 0xF, 0xE, 0xD, 0x8, 0xB, 0xA, 0x9,
                                              0x0, 0x9, 0x2, 0xD, 0x6, 0xB, 0x4, 0xF, 0xA, 0x7, 0xC, 0x3, 0xE, 0x5, 0x8, 0x1,
                                              0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
        
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            
        }

        private void BuildTF256(string MixString, string KeyString, string TweakString, bool forward)
        {
            txtOutput.Visible = false;
            int rconIndex = 0;
            int mixPatIndex = 0;
            string tabs = new string('\t', tbTabCount.Value);
            if (forward)
            {
                txtOutput.AppendText(tabs + "// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
                txtOutput.AppendText(tabs + "//==256========================================================================================\r\n");      
                for (int i = 0; i <= 18; i++)
                {
                    //key injection
                    txtOutput.AppendText(tabs + "//KEYINJECT " + i.ToString("0") + "\r\n");
                    txtOutput.AppendText(tabs + string.Format("buf0 += " + KeyString + ";\r\n", i % 5));
                    txtOutput.AppendText(tabs + string.Format("buf1 += " + KeyString + " + " + TweakString + ";\r\n", (i + 1) % 5, i % 3));
                    txtOutput.AppendText(tabs + string.Format("buf2 += " + KeyString + " + " + TweakString + ";\r\n", (i + 2) % 5, (i + 1) % 3));
                    txtOutput.AppendText(tabs + string.Format("buf3 += " + KeyString + " + {1};\r\n", (i + 3) % 5, i));
                    if (i == 18)
                        break; //if we just did the final key injection, no point in going on.
                    //mixing
                    txtOutput.AppendText(tabs + "//Rounds " + (i * 4).ToString() + " through " + ((i * 4) + 3).ToString() + "\r\n");
                    for (int ri = 0; ri < 4; ri++)
                    {
                        txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                            tf256mixpat[mixPatIndex++], tf256mixpat[mixPatIndex++], tf256rcon[rconIndex++]));
                        txtOutput.AppendText(tabs + string.Format(MixString + "\r\n",
                            tf256mixpat[mixPatIndex++], tf256mixpat[mixPatIndex++], tf256rcon[rconIndex++]));
                        mixPatIndex %= tf256mixpat.Length;
                        rconIndex %= tf256rcon.Length;
                    }
                }// end 256 for loop
                txtOutput.AppendText(tabs + "//==END 256====================================================================================\r\n");
                txtOutput.AppendText(tabs + "// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
            }
            else
            {
                txtOutput.AppendText(tabs + "// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
                txtOutput.AppendText(tabs + "//==256========================================================================================\r\n");

                for (int i = 18; i >= 0; i--)
                {
                    //key injection
                    txtOutput.AppendText(tabs + "//KEYINJECT " + i.ToString("0") + "\r\n");
                    txtOutput.AppendText(tabs + string.Format("buf0 -= " + KeyString + ";\r\n", i % 5));
                    txtOutput.AppendText(tabs + string.Format("buf1 -= (" + KeyString + " + " + TweakString + ");\r\n", (i + 1) % 5, i % 3));
                    txtOutput.AppendText(tabs + string.Format("buf2 -= (" + KeyString + " + " + TweakString + ");\r\n", (i + 2) % 5, (i + 1) % 3));
                    txtOutput.AppendText(tabs + string.Format("buf3 -= (" + KeyString + " + {1});\r\n", (i + 3) % 5, i));
                    if (i == 0)
                        break; //if we just did the final key injection, no point in going on.
                    //mixing
                    txtOutput.AppendText(tabs + "//Rounds " + (i * 4).ToString() + " through " + ((i * 4) + 3).ToString() + "\r\n");
                    for (int ri = 0; ri < 4; ri++)
                    {
                        txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                            tf256invmixpat[mixPatIndex++], tf256invmixpat[mixPatIndex++], tf256invrcon[rconIndex++]));
                        txtOutput.AppendText(tabs + string.Format(MixString + "\r\n",
                            tf256invmixpat[mixPatIndex++], tf256invmixpat[mixPatIndex++], tf256invrcon[rconIndex++]));
                        mixPatIndex %= tf256invmixpat.Length;
                        rconIndex %= tf256invrcon.Length;
                    }
                }// end 256 for loop
                txtOutput.AppendText(tabs + "//==END 256====================================================================================\r\n");
                txtOutput.AppendText(tabs + "// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
            }
            txtOutput.Visible = true;
        }

        private void BuildTF512(string MixString, string KeyString, string TweakString, bool forward)
        {
            txtOutput.Visible = false;
            int rconIndex = 0;
            int mixPatIndex = 0;
            string tabs = new string('\t', tbTabCount.Value);
            if (forward)
            {
                txtOutput.AppendText(tabs + "// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
                txtOutput.AppendText(tabs + "//==512========================================================================================\r\n");
                for (int i = 0; i <= 18; i++)
                {
                    //key injection
                    txtOutput.AppendText(tabs + "//KEYINJECT " + i.ToString("0") + "\r\n");
                    txtOutput.AppendText(tabs + string.Format("buf0 += " + KeyString + ";\r\n", i % 9));
                    txtOutput.AppendText(tabs + string.Format("buf1 += " + KeyString + ";\r\n", (i + 1) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf2 += " + KeyString + ";\r\n", (i + 2) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf3 += " + KeyString + ";\r\n", (i + 3) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf4 += " + KeyString + ";\r\n", (i + 4) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf5 += " + KeyString + " + " + TweakString + ";\r\n", (i + 5) % 9, i % 3));
                    txtOutput.AppendText(tabs + string.Format("buf6 += " + KeyString + " + " + TweakString + ";\r\n", (i + 6) % 9, (i + 1) % 3));
                    txtOutput.AppendText(tabs + string.Format("buf7 += " + KeyString + " + {1};\r\n", (i + 7) % 9, i));
                    if (i == 18)
                        break; //if we just did the final key injection, no point in going on.
                    //mixing
                    txtOutput.AppendText(tabs + "//Rounds " + (i * 4).ToString() + " through " + ((i * 4) + 3).ToString() + "\r\n");
                    for (int ri = 0; ri < 4; ri++)
                    {
                        txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                            tf512mixpat[mixPatIndex++], tf512mixpat[mixPatIndex++], tf512rcon[rconIndex++]));
                        txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                            tf512mixpat[mixPatIndex++], tf512mixpat[mixPatIndex++], tf512rcon[rconIndex++]));
                        txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                            tf512mixpat[mixPatIndex++], tf512mixpat[mixPatIndex++], tf512rcon[rconIndex++]));
                        txtOutput.AppendText(tabs + string.Format(MixString + "\r\n",
                            tf512mixpat[mixPatIndex++], tf512mixpat[mixPatIndex++], tf512rcon[rconIndex++]));
                        mixPatIndex %= tf512mixpat.Length;
                        rconIndex %= tf512rcon.Length;
                    }
                }// end 512 for loop
                txtOutput.AppendText(tabs + "//==END 512====================================================================================\r\n");
                txtOutput.AppendText(tabs + "// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
            }
            else
            {
                txtOutput.AppendText(tabs + "// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
                txtOutput.AppendText(tabs + "//==512========================================================================================\r\n");

                for (int i = 18; i >= 0; i--)
                {
                    if (i < 18)
                    {
                        //mixing
                        txtOutput.AppendText(tabs + "//Rounds " + ((i * 4) + 3).ToString() + " through " + (i * 4).ToString() + "\r\n");
                        for (int ri = 0; ri < 4; ri++)
                        {
                            txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                                tf512invmixpat[mixPatIndex++], tf512invmixpat[mixPatIndex++], tf512invrcon[rconIndex++]));
                            txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                                tf512invmixpat[mixPatIndex++], tf512invmixpat[mixPatIndex++], tf512invrcon[rconIndex++]));
                            txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                                tf512invmixpat[mixPatIndex++], tf512invmixpat[mixPatIndex++], tf512invrcon[rconIndex++]));
                            txtOutput.AppendText(tabs + string.Format(MixString + "\r\n",
                                tf512invmixpat[mixPatIndex++], tf512invmixpat[mixPatIndex++], tf512invrcon[rconIndex++]));
                            mixPatIndex %= tf512invmixpat.Length;
                            rconIndex %= tf512invrcon.Length;
                        }
                    }
                    //key injection
                    txtOutput.AppendText(tabs + "//KEYINJECT " + i.ToString("0") + "\r\n");
                    txtOutput.AppendText(tabs + string.Format("buf0 -= " + KeyString + ";\r\n", i % 9));
                    txtOutput.AppendText(tabs + string.Format("buf1 -= " + KeyString + ";\r\n", (i + 1) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf2 -= " + KeyString + ";\r\n", (i + 2) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf3 -= " + KeyString + ";\r\n", (i + 3) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf4 -= " + KeyString + ";\r\n", (i + 4) % 9));
                    txtOutput.AppendText(tabs + string.Format("buf5 -= (" + KeyString + " + " + TweakString + ");\r\n", (i + 5) % 9, i % 3));
                    txtOutput.AppendText(tabs + string.Format("buf6 -= (" + KeyString + " + " + TweakString + ");\r\n", (i + 6) % 9, (i + 1) % 3));
                    txtOutput.AppendText(tabs + string.Format("buf7 -= (" + KeyString + " + {1});\r\n", (i + 7) % 9, i));
                }// end 512 for loop
                txtOutput.AppendText(tabs + "//==END 512====================================================================================\r\n");
                txtOutput.AppendText(tabs + "// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
            }
            txtOutput.Visible = true;
        }

        private void BuildTF1024(string MixString, string KeyString, string TweakString, bool forward)
        {
            txtOutput.Visible = false;
            int rconIndex = 0;
            int mixPatIndex = 0;
            string tabs = new string('\t', tbTabCount.Value);
            if (forward)
            {
                txtOutput.AppendText(tabs + "// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
                txtOutput.AppendText(tabs + "//==1024========================================================================================\r\n");    
                for (int i = 0; i <= 20; i++)
                {
                    //key injection
                    txtOutput.AppendText(tabs + "//KEYINJECT " + i.ToString("0") + "\r\n");
                    txtOutput.AppendText(tabs + string.Format("buf0 += " + KeyString + ";\r\n", i % 17));
                    txtOutput.AppendText(tabs + string.Format("buf1 += " + KeyString + ";\r\n", (i + 1) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf2 += " + KeyString + ";\r\n", (i + 2) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf3 += " + KeyString + ";\r\n", (i + 3) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf4 += " + KeyString + ";\r\n", (i + 4) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf5 += " + KeyString + ";\r\n", (i + 5) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf6 += " + KeyString + ";\r\n", (i + 6) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf7 += " + KeyString + ";\r\n", (i + 7) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf8 += " + KeyString + ";\r\n", (i + 8) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf9 += " + KeyString + ";\r\n", (i + 9) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf10 += " + KeyString + ";\r\n", (i + 10) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf11 += " + KeyString + ";\r\n", (i + 11) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf12 += " + KeyString + ";\r\n", (i + 12) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf13 += " + KeyString + " + " + TweakString + ";\r\n", (i + 13) % 17, i % 3));
                    txtOutput.AppendText(tabs + string.Format("buf14 += " + KeyString + " + " + TweakString + ";\r\n", (i + 14) % 17, (i + 1) % 3));
                    txtOutput.AppendText(tabs + string.Format("buf15 += " + KeyString + " + {1};\r\n", (i + 15) % 17, i));
                    if (i == 20)
                        break; //if we just did the final key injection, no point in going on.
                    //mixing
                    txtOutput.AppendText(tabs + "//Rounds " + (i * 4).ToString() + " through " + ((i * 4) + 3).ToString() + "\r\n");
                    for (int ri = 0; ri < 4; ri++)
                    {
                        txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        txtOutput.AppendText(string.Format(MixString + "\t",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        txtOutput.AppendText(string.Format(MixString + "\t",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        txtOutput.AppendText(string.Format(MixString + "\r\n",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        txtOutput.AppendText(string.Format(MixString + "\t",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        txtOutput.AppendText(string.Format(MixString + "\t",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        txtOutput.AppendText(string.Format(MixString + "\r\n" + tabs + "//===\r\n",
                            tf1024mixpat[mixPatIndex++], tf1024mixpat[mixPatIndex++], tf1024rcon[rconIndex++]));
                        mixPatIndex %= tf1024mixpat.Length;
                        rconIndex %= tf1024rcon.Length;
                    }
                }// end 1024 for loop
                txtOutput.AppendText(tabs + "//==END 1024====================================================================================\r\n");
                txtOutput.AppendText(tabs + "// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
            }
            else
            {
                txtOutput.AppendText(tabs + "// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
                txtOutput.AppendText(tabs + "//==1024========================================================================================\r\n");
                for (int i = 20; i >= 0; i--)
                {
                    if (i < 20)
                    {
                        //mixing
                        txtOutput.AppendText(tabs + "//Rounds " + ((i * 4) + 3).ToString() + " through " + (i * 4).ToString() + "\r\n");
                        for (int ri = 0; ri < 4; ri++)
                        {
                            txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            txtOutput.AppendText(string.Format(MixString + "\t",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            txtOutput.AppendText(string.Format(MixString + "\t",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            txtOutput.AppendText(string.Format(MixString + "\r\n",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            txtOutput.AppendText(tabs + string.Format(MixString + "\t",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            txtOutput.AppendText(string.Format(MixString + "\t",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            txtOutput.AppendText(string.Format(MixString + "\t",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            txtOutput.AppendText(string.Format(MixString + "\r\n" + tabs + "//===\r\n",
                                tf1024invmixpat[mixPatIndex++], tf1024invmixpat[mixPatIndex++], tf1024invrcon[rconIndex++]));
                            mixPatIndex %= tf1024invmixpat.Length;
                            rconIndex %= tf1024invrcon.Length;
                        }
                    }
                    //key injection
                    txtOutput.AppendText(tabs + "//KEYINJECT " + i.ToString("0") + "\r\n");
                    txtOutput.AppendText(tabs + string.Format("buf0 -= " + KeyString + ";\r\n", i % 17));
                    txtOutput.AppendText(tabs + string.Format("buf1 -= " + KeyString + ";\r\n", (i + 1) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf2 -= " + KeyString + ";\r\n", (i + 2) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf3 -= " + KeyString + ";\r\n", (i + 3) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf4 -= " + KeyString + ";\r\n", (i + 4) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf5 -= " + KeyString + ";\r\n", (i + 5) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf6 -= " + KeyString + ";\r\n", (i + 6) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf7 -= " + KeyString + ";\r\n", (i + 7) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf8 -= " + KeyString + ";\r\n", (i + 8) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf9 -= " + KeyString + ";\r\n", (i + 9) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf10 -= " + KeyString + ";\r\n", (i + 10) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf11 -= " + KeyString + ";\r\n", (i + 11) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf12 -= " + KeyString + ";\r\n", (i + 12) % 17));
                    txtOutput.AppendText(tabs + string.Format("buf13 -= (" + KeyString + " + " + TweakString + ");\r\n", (i + 13) % 17, i % 3));
                    txtOutput.AppendText(tabs + string.Format("buf14 -= (" + KeyString + " + " + TweakString + ");\r\n", (i + 14) % 17, (i + 1) % 3));
                    txtOutput.AppendText(tabs + string.Format("buf15 -= (" + KeyString + " + {1});\r\n", (i + 15) % 17, i));
                }// end 1024 for loop

                txtOutput.AppendText(tabs + "//==END 1024====================================================================================\r\n");
                txtOutput.AppendText(tabs + "// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** \r\n");
            }
            txtOutput.Visible = true;
        }

        private void but256_Click(object sender, EventArgs e)
        {
            Button thing = sender as Button;
            PrintOutput(thing.Text);
            thing = null;
        }

        private void but512_Click(object sender, EventArgs e)
        {
            Button thing = sender as Button;
            PrintOutput(thing.Text);
            thing = null;
        }

        private void but1024_Click(object sender, EventArgs e)
        {
            Button thing = sender as Button;
            PrintOutput(thing.Text);
            thing = null;
        }

        private void butInv256_Click(object sender, EventArgs e)
        {
            Button thing = sender as Button;
            PrintOutput(thing.Text);
            thing = null;
        }

        private void butInv512_Click(object sender, EventArgs e)
        {
            Button thing = sender as Button;
            PrintOutput(thing.Text);
            thing = null;
        }

        private void butInv1024_Click(object sender, EventArgs e)
        {
            Button thing = sender as Button;
            PrintOutput(thing.Text);
            thing = null;
        }

        private void rbCS_CheckedChanged(object sender, EventArgs e)
        {
            txtOutput.Text = "";
        }

        private void rbCPP_CheckedChanged(object sender, EventArgs e)
        {
            txtOutput.Text = "";
        }

        private void PrintOutput(string which)
        {
            txtOutput.Text = "";
            string MixString;
            Enabled = false;
            switch (which)
            {
                case "256":
                    MixString = (rbCS.Checked == true ? MixFormatStringCS : MixFormatStringCPP);
                    BuildTF256(MixString, KeyFormatString, TweakFormatString, true);
                    break;
                case "512":
                    MixString = (rbCS.Checked == true ? MixFormatStringCS : MixFormatStringCPP);
                    BuildTF512(MixString, KeyFormatString, TweakFormatString, true);
                    break;
                case "1024":
                    MixString = (rbCS.Checked == true ? MixFormatStringCS : MixFormatStringCPP);
                    BuildTF1024(MixString, KeyFormatString, TweakFormatString, true);
                    break;
                case "INV 256":
                    MixString = (rbCS.Checked == true ? InvMixFormatStringCS : InvMixFormatStringCPP);
                    BuildTF256(MixString, KeyFormatString, TweakFormatString, false);
                    break;
                case "INV 512":
                    MixString = (rbCS.Checked == true ? InvMixFormatStringCS : InvMixFormatStringCPP);
                    BuildTF512(MixString, KeyFormatString, TweakFormatString, false);
                    break;
                case "INV 1024":
                    MixString = (rbCS.Checked == true ? InvMixFormatStringCS : InvMixFormatStringCPP);
                    BuildTF1024(MixString, KeyFormatString, TweakFormatString, false);
                    break;
            }
            Enabled = true;
        }

        private void tbTabCount_Scroll(object sender, EventArgs e)
        {

        }
    }
}
