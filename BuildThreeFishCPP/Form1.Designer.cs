namespace BuildThreeFishCPP
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.txtOutput = new System.Windows.Forms.TextBox();
            this.but256 = new System.Windows.Forms.Button();
            this.but512 = new System.Windows.Forms.Button();
            this.but1024 = new System.Windows.Forms.Button();
            this.butInv256 = new System.Windows.Forms.Button();
            this.butInv512 = new System.Windows.Forms.Button();
            this.butInv1024 = new System.Windows.Forms.Button();
            this.rbCS = new System.Windows.Forms.RadioButton();
            this.rbCPP = new System.Windows.Forms.RadioButton();
            this.tbTabCount = new System.Windows.Forms.TrackBar();
            this.lblDescription = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.tbTabCount)).BeginInit();
            this.SuspendLayout();
            // 
            // txtOutput
            // 
            this.txtOutput.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtOutput.Location = new System.Drawing.Point(13, 167);
            this.txtOutput.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtOutput.Multiline = true;
            this.txtOutput.Name = "txtOutput";
            this.txtOutput.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtOutput.Size = new System.Drawing.Size(1322, 813);
            this.txtOutput.TabIndex = 0;
            this.txtOutput.WordWrap = false;
            // 
            // but256
            // 
            this.but256.Location = new System.Drawing.Point(13, 118);
            this.but256.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.but256.Name = "but256";
            this.but256.Size = new System.Drawing.Size(112, 35);
            this.but256.TabIndex = 1;
            this.but256.Text = "256";
            this.but256.UseVisualStyleBackColor = true;
            this.but256.Click += new System.EventHandler(this.but256_Click);
            // 
            // but512
            // 
            this.but512.Location = new System.Drawing.Point(135, 118);
            this.but512.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.but512.Name = "but512";
            this.but512.Size = new System.Drawing.Size(112, 35);
            this.but512.TabIndex = 2;
            this.but512.Text = "512";
            this.but512.UseVisualStyleBackColor = true;
            this.but512.Click += new System.EventHandler(this.but512_Click);
            // 
            // but1024
            // 
            this.but1024.Location = new System.Drawing.Point(256, 118);
            this.but1024.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.but1024.Name = "but1024";
            this.but1024.Size = new System.Drawing.Size(112, 35);
            this.but1024.TabIndex = 3;
            this.but1024.Text = "1024";
            this.but1024.UseVisualStyleBackColor = true;
            this.but1024.Click += new System.EventHandler(this.but1024_Click);
            // 
            // butInv256
            // 
            this.butInv256.Location = new System.Drawing.Point(405, 118);
            this.butInv256.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.butInv256.Name = "butInv256";
            this.butInv256.Size = new System.Drawing.Size(112, 35);
            this.butInv256.TabIndex = 4;
            this.butInv256.Text = "INV 256";
            this.butInv256.UseVisualStyleBackColor = true;
            this.butInv256.Click += new System.EventHandler(this.butInv256_Click);
            // 
            // butInv512
            // 
            this.butInv512.Location = new System.Drawing.Point(526, 118);
            this.butInv512.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.butInv512.Name = "butInv512";
            this.butInv512.Size = new System.Drawing.Size(112, 35);
            this.butInv512.TabIndex = 5;
            this.butInv512.Text = "INV 512";
            this.butInv512.UseVisualStyleBackColor = true;
            this.butInv512.Click += new System.EventHandler(this.butInv512_Click);
            // 
            // butInv1024
            // 
            this.butInv1024.Location = new System.Drawing.Point(647, 118);
            this.butInv1024.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.butInv1024.Name = "butInv1024";
            this.butInv1024.Size = new System.Drawing.Size(112, 35);
            this.butInv1024.TabIndex = 6;
            this.butInv1024.Text = "INV 1024";
            this.butInv1024.UseVisualStyleBackColor = true;
            this.butInv1024.Click += new System.EventHandler(this.butInv1024_Click);
            // 
            // rbCS
            // 
            this.rbCS.AutoSize = true;
            this.rbCS.Location = new System.Drawing.Point(862, 121);
            this.rbCS.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.rbCS.Name = "rbCS";
            this.rbCS.Size = new System.Drawing.Size(54, 24);
            this.rbCS.TabIndex = 7;
            this.rbCS.Text = "C#";
            this.rbCS.UseVisualStyleBackColor = true;
            this.rbCS.CheckedChanged += new System.EventHandler(this.rbCS_CheckedChanged);
            // 
            // rbCPP
            // 
            this.rbCPP.AutoSize = true;
            this.rbCPP.Checked = true;
            this.rbCPP.Location = new System.Drawing.Point(930, 121);
            this.rbCPP.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.rbCPP.Name = "rbCPP";
            this.rbCPP.Size = new System.Drawing.Size(63, 24);
            this.rbCPP.TabIndex = 8;
            this.rbCPP.TabStop = true;
            this.rbCPP.Text = "C++";
            this.rbCPP.UseVisualStyleBackColor = true;
            this.rbCPP.CheckedChanged += new System.EventHandler(this.rbCPP_CheckedChanged);
            // 
            // tbTabCount
            // 
            this.tbTabCount.AutoSize = false;
            this.tbTabCount.Location = new System.Drawing.Point(1045, 97);
            this.tbTabCount.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tbTabCount.Maximum = 5;
            this.tbTabCount.Name = "tbTabCount";
            this.tbTabCount.Size = new System.Drawing.Size(156, 61);
            this.tbTabCount.TabIndex = 9;
            this.tbTabCount.TickStyle = System.Windows.Forms.TickStyle.Both;
            this.tbTabCount.Value = 2;
            this.tbTabCount.Scroll += new System.EventHandler(this.tbTabCount_Scroll);
            // 
            // lblDescription
            // 
            this.lblDescription.Location = new System.Drawing.Point(12, 9);
            this.lblDescription.Name = "lblDescription";
            this.lblDescription.Size = new System.Drawing.Size(1323, 94);
            this.lblDescription.TabIndex = 10;
            this.lblDescription.Text = resources.GetString("lblDescription.Text");
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1360, 1048);
            this.Controls.Add(this.lblDescription);
            this.Controls.Add(this.tbTabCount);
            this.Controls.Add(this.rbCPP);
            this.Controls.Add(this.rbCS);
            this.Controls.Add(this.butInv1024);
            this.Controls.Add(this.butInv512);
            this.Controls.Add(this.butInv256);
            this.Controls.Add(this.but1024);
            this.Controls.Add(this.but512);
            this.Controls.Add(this.but256);
            this.Controls.Add(this.txtOutput);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Shown += new System.EventHandler(this.Form1_Shown);
            ((System.ComponentModel.ISupportInitialize)(this.tbTabCount)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtOutput;
        private System.Windows.Forms.Button but256;
        private System.Windows.Forms.Button but512;
        private System.Windows.Forms.Button but1024;
        private System.Windows.Forms.Button butInv256;
        private System.Windows.Forms.Button butInv512;
        private System.Windows.Forms.Button butInv1024;
        private System.Windows.Forms.RadioButton rbCS;
        private System.Windows.Forms.RadioButton rbCPP;
        private System.Windows.Forms.TrackBar tbTabCount;
        private System.Windows.Forms.Label lblDescription;
    }
}

