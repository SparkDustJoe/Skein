namespace SkeinTester
{
    partial class frmDeluxe
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ssMain = new System.Windows.Forms.StatusStrip();
            this.tslblStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.btnRunTests = new System.Windows.Forms.Button();
            this.txtResults = new System.Windows.Forms.TextBox();
            this.btnClearSelections = new System.Windows.Forms.Button();
            this.lstTests = new System.Windows.Forms.ListBox();
            this.btnClearResults = new System.Windows.Forms.Button();
            this.chk256 = new System.Windows.Forms.CheckBox();
            this.chk512 = new System.Windows.Forms.CheckBox();
            this.chk1024 = new System.Windows.Forms.CheckBox();
            this.rbKATS = new System.Windows.Forms.RadioButton();
            this.rbAS = new System.Windows.Forms.RadioButton();
            this.chkMAC = new System.Windows.Forms.CheckBox();
            this.chkTree = new System.Windows.Forms.CheckBox();
            this.btnSelectAll = new System.Windows.Forms.Button();
            this.rbASLM = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.chkIncrementing = new System.Windows.Forms.CheckBox();
            this.chkZeros = new System.Windows.Forms.CheckBox();
            this.chkRandom = new System.Windows.Forms.CheckBox();
            this.ssMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // ssMain
            // 
            this.ssMain.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.ssMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tslblStatus});
            this.ssMain.Location = new System.Drawing.Point(0, 665);
            this.ssMain.Name = "ssMain";
            this.ssMain.Padding = new System.Windows.Forms.Padding(1, 0, 19, 0);
            this.ssMain.Size = new System.Drawing.Size(1036, 25);
            this.ssMain.TabIndex = 0;
            this.ssMain.Text = "ssMain";
            // 
            // tslblStatus
            // 
            this.tslblStatus.Name = "tslblStatus";
            this.tslblStatus.Size = new System.Drawing.Size(53, 20);
            this.tslblStatus.Text = "Ready.";
            // 
            // btnRunTests
            // 
            this.btnRunTests.BackColor = System.Drawing.Color.Lime;
            this.btnRunTests.Location = new System.Drawing.Point(13, 373);
            this.btnRunTests.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnRunTests.Name = "btnRunTests";
            this.btnRunTests.Size = new System.Drawing.Size(835, 28);
            this.btnRunTests.TabIndex = 2;
            this.btnRunTests.Text = "RUN SELECTED TESTS";
            this.btnRunTests.UseVisualStyleBackColor = false;
            this.btnRunTests.Click += new System.EventHandler(this.btnRunTests_Click);
            // 
            // txtResults
            // 
            this.txtResults.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtResults.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtResults.Location = new System.Drawing.Point(13, 409);
            this.txtResults.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtResults.Multiline = true;
            this.txtResults.Name = "txtResults";
            this.txtResults.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtResults.Size = new System.Drawing.Size(1003, 247);
            this.txtResults.TabIndex = 3;
            this.txtResults.WordWrap = false;
            // 
            // btnClearSelections
            // 
            this.btnClearSelections.BackColor = System.Drawing.Color.Yellow;
            this.btnClearSelections.Location = new System.Drawing.Point(856, 15);
            this.btnClearSelections.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnClearSelections.Name = "btnClearSelections";
            this.btnClearSelections.Size = new System.Drawing.Size(160, 28);
            this.btnClearSelections.TabIndex = 5;
            this.btnClearSelections.Text = "CLEAR SELECTED";
            this.btnClearSelections.UseVisualStyleBackColor = false;
            this.btnClearSelections.Click += new System.EventHandler(this.btnClearSelections_Click);
            // 
            // lstTests
            // 
            this.lstTests.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.lstTests.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lstTests.FormattingEnabled = true;
            this.lstTests.ItemHeight = 17;
            this.lstTests.Location = new System.Drawing.Point(13, 124);
            this.lstTests.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.lstTests.Name = "lstTests";
            this.lstTests.ScrollAlwaysVisible = true;
            this.lstTests.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
            this.lstTests.Size = new System.Drawing.Size(1003, 238);
            this.lstTests.Sorted = true;
            this.lstTests.TabIndex = 6;
            // 
            // btnClearResults
            // 
            this.btnClearResults.BackColor = System.Drawing.Color.Yellow;
            this.btnClearResults.Location = new System.Drawing.Point(857, 373);
            this.btnClearResults.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnClearResults.Name = "btnClearResults";
            this.btnClearResults.Size = new System.Drawing.Size(160, 28);
            this.btnClearResults.TabIndex = 7;
            this.btnClearResults.Text = "CLEAR RESULTS";
            this.btnClearResults.UseVisualStyleBackColor = false;
            this.btnClearResults.Click += new System.EventHandler(this.btnClearResults_Click);
            // 
            // chk256
            // 
            this.chk256.AutoSize = true;
            this.chk256.Checked = true;
            this.chk256.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chk256.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chk256.Location = new System.Drawing.Point(13, 65);
            this.chk256.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chk256.Name = "chk256";
            this.chk256.Size = new System.Drawing.Size(94, 21);
            this.chk256.TabIndex = 8;
            this.chk256.Text = "Skein256";
            this.chk256.UseVisualStyleBackColor = true;
            this.chk256.CheckedChanged += new System.EventHandler(this.chk256_CheckedChanged);
            // 
            // chk512
            // 
            this.chk512.AutoSize = true;
            this.chk512.Checked = true;
            this.chk512.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chk512.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chk512.Location = new System.Drawing.Point(131, 65);
            this.chk512.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chk512.Name = "chk512";
            this.chk512.Size = new System.Drawing.Size(94, 21);
            this.chk512.TabIndex = 9;
            this.chk512.Text = "Skein512";
            this.chk512.UseVisualStyleBackColor = true;
            this.chk512.CheckedChanged += new System.EventHandler(this.chk512_CheckedChanged);
            // 
            // chk1024
            // 
            this.chk1024.AutoSize = true;
            this.chk1024.Checked = true;
            this.chk1024.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chk1024.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chk1024.Location = new System.Drawing.Point(248, 65);
            this.chk1024.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chk1024.Name = "chk1024";
            this.chk1024.Size = new System.Drawing.Size(102, 21);
            this.chk1024.TabIndex = 10;
            this.chk1024.Text = "Skein1024";
            this.chk1024.UseVisualStyleBackColor = true;
            this.chk1024.CheckedChanged += new System.EventHandler(this.chk1024_CheckedChanged);
            // 
            // rbKATS
            // 
            this.rbKATS.AutoSize = true;
            this.rbKATS.Checked = true;
            this.rbKATS.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbKATS.Location = new System.Drawing.Point(13, 15);
            this.rbKATS.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbKATS.Name = "rbKATS";
            this.rbKATS.Size = new System.Drawing.Size(213, 21);
            this.rbKATS.TabIndex = 11;
            this.rbKATS.TabStop = true;
            this.rbKATS.Text = "NIST Known Answer Tests";
            this.rbKATS.UseVisualStyleBackColor = true;
            this.rbKATS.CheckedChanged += new System.EventHandler(this.rbKATS_CheckedChanged);
            // 
            // rbAS
            // 
            this.rbAS.AutoSize = true;
            this.rbAS.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbAS.Location = new System.Drawing.Point(13, 36);
            this.rbAS.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbAS.Name = "rbAS";
            this.rbAS.Size = new System.Drawing.Size(149, 21);
            this.rbAS.TabIndex = 12;
            this.rbAS.Text = "Strings of \'a\'s";
            this.rbAS.UseVisualStyleBackColor = true;
            this.rbAS.CheckedChanged += new System.EventHandler(this.rbAS_CheckedChanged);
            // 
            // chkMAC
            // 
            this.chkMAC.AutoSize = true;
            this.chkMAC.Checked = true;
            this.chkMAC.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkMAC.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkMAC.Location = new System.Drawing.Point(356, 95);
            this.chkMAC.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chkMAC.Name = "chkMAC";
            this.chkMAC.Size = new System.Drawing.Size(54, 21);
            this.chkMAC.TabIndex = 13;
            this.chkMAC.Text = "MAC";
            this.chkMAC.UseVisualStyleBackColor = true;
            this.chkMAC.CheckedChanged += new System.EventHandler(this.chkMAC_CheckedChanged);
            // 
            // chkTree
            // 
            this.chkTree.AutoSize = true;
            this.chkTree.Checked = true;
            this.chkTree.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkTree.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkTree.Location = new System.Drawing.Point(427, 95);
            this.chkTree.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chkTree.Name = "chkTree";
            this.chkTree.Size = new System.Drawing.Size(62, 21);
            this.chkTree.TabIndex = 14;
            this.chkTree.Text = "Tree";
            this.chkTree.UseVisualStyleBackColor = true;
            this.chkTree.CheckedChanged += new System.EventHandler(this.chkTree_CheckedChanged);
            // 
            // btnSelectAll
            // 
            this.btnSelectAll.BackColor = System.Drawing.Color.Lime;
            this.btnSelectAll.Location = new System.Drawing.Point(688, 15);
            this.btnSelectAll.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnSelectAll.Name = "btnSelectAll";
            this.btnSelectAll.Size = new System.Drawing.Size(160, 28);
            this.btnSelectAll.TabIndex = 15;
            this.btnSelectAll.Text = "SELECT ALL";
            this.btnSelectAll.UseVisualStyleBackColor = false;
            this.btnSelectAll.Click += new System.EventHandler(this.btnSelectAll_Click);
            // 
            // rbASLM
            // 
            this.rbASLM.AutoSize = true;
            this.rbASLM.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbASLM.Location = new System.Drawing.Point(195, 36);
            this.rbASLM.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbASLM.Name = "rbASLM";
            this.rbASLM.Size = new System.Drawing.Size(301, 21);
            this.rbASLM.TabIndex = 16;
            this.rbASLM.Text = "Strings of \'a\'s (low memory/32bit)";
            this.rbASLM.UseVisualStyleBackColor = true;
            this.rbASLM.CheckedChanged += new System.EventHandler(this.rbASLM_CheckedChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(605, 66);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(352, 17);
            this.label1.TabIndex = 17;
            this.label1.Text = "All elapsed times are formated H:MM:SS:FFFF";
            // 
            // chkIncrementing
            // 
            this.chkIncrementing.AutoSize = true;
            this.chkIncrementing.Checked = true;
            this.chkIncrementing.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkIncrementing.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkIncrementing.Location = new System.Drawing.Point(103, 95);
            this.chkIncrementing.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chkIncrementing.Name = "chkIncrementing";
            this.chkIncrementing.Size = new System.Drawing.Size(126, 21);
            this.chkIncrementing.TabIndex = 19;
            this.chkIncrementing.Text = "Incrementing";
            this.chkIncrementing.UseVisualStyleBackColor = true;
            this.chkIncrementing.CheckedChanged += new System.EventHandler(this.chkIncrementing_CheckedChanged);
            // 
            // chkZeros
            // 
            this.chkZeros.AutoSize = true;
            this.chkZeros.Checked = true;
            this.chkZeros.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkZeros.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkZeros.Location = new System.Drawing.Point(13, 95);
            this.chkZeros.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chkZeros.Name = "chkZeros";
            this.chkZeros.Size = new System.Drawing.Size(70, 21);
            this.chkZeros.TabIndex = 18;
            this.chkZeros.Text = "Zeros";
            this.chkZeros.UseVisualStyleBackColor = true;
            this.chkZeros.CheckedChanged += new System.EventHandler(this.chkZeros_CheckedChanged);
            // 
            // chkRandom
            // 
            this.chkRandom.AutoSize = true;
            this.chkRandom.Checked = true;
            this.chkRandom.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkRandom.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkRandom.Location = new System.Drawing.Point(257, 95);
            this.chkRandom.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chkRandom.Name = "chkRandom";
            this.chkRandom.Size = new System.Drawing.Size(78, 21);
            this.chkRandom.TabIndex = 20;
            this.chkRandom.Text = "Random";
            this.chkRandom.UseVisualStyleBackColor = true;
            this.chkRandom.CheckedChanged += new System.EventHandler(this.chkRandom_CheckedChanged);
            // 
            // frmDeluxe
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1036, 690);
            this.Controls.Add(this.chkRandom);
            this.Controls.Add(this.chkIncrementing);
            this.Controls.Add(this.chkZeros);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.rbASLM);
            this.Controls.Add(this.btnSelectAll);
            this.Controls.Add(this.chkTree);
            this.Controls.Add(this.chkMAC);
            this.Controls.Add(this.rbAS);
            this.Controls.Add(this.rbKATS);
            this.Controls.Add(this.chk1024);
            this.Controls.Add(this.chk512);
            this.Controls.Add(this.chk256);
            this.Controls.Add(this.btnClearResults);
            this.Controls.Add(this.lstTests);
            this.Controls.Add(this.btnClearSelections);
            this.Controls.Add(this.txtResults);
            this.Controls.Add(this.btnRunTests);
            this.Controls.Add(this.ssMain);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MaximizeBox = false;
            this.Name = "frmDeluxe";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Skein Tester and Debug Interface";
            this.Load += new System.EventHandler(this.frmDeluxe_Load);
            this.ssMain.ResumeLayout(false);
            this.ssMain.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip ssMain;
        private System.Windows.Forms.ToolStripStatusLabel tslblStatus;
        private System.Windows.Forms.Button btnRunTests;
        private System.Windows.Forms.TextBox txtResults;
        private System.Windows.Forms.Button btnClearSelections;
        private System.Windows.Forms.ListBox lstTests;
        private System.Windows.Forms.Button btnClearResults;
        private System.Windows.Forms.CheckBox chk256;
        private System.Windows.Forms.CheckBox chk512;
        private System.Windows.Forms.CheckBox chk1024;
        private System.Windows.Forms.RadioButton rbKATS;
        private System.Windows.Forms.RadioButton rbAS;
        private System.Windows.Forms.CheckBox chkMAC;
        private System.Windows.Forms.CheckBox chkTree;
        private System.Windows.Forms.Button btnSelectAll;
        private System.Windows.Forms.RadioButton rbASLM;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox chkIncrementing;
        private System.Windows.Forms.CheckBox chkZeros;
        private System.Windows.Forms.CheckBox chkRandom;
    }
}