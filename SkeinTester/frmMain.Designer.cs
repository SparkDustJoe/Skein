namespace SkeinTester
{
    partial class frmMain
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
            this.txtOutput1 = new System.Windows.Forms.TextBox();
            this.txtOutput2 = new System.Windows.Forms.TextBox();
            this.txtOutput3 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // txtOutput1
            // 
            this.txtOutput1.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtOutput1.Location = new System.Drawing.Point(12, 12);
            this.txtOutput1.Multiline = true;
            this.txtOutput1.Name = "txtOutput1";
            this.txtOutput1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtOutput1.ShortcutsEnabled = false;
            this.txtOutput1.Size = new System.Drawing.Size(905, 153);
            this.txtOutput1.TabIndex = 0;
            this.txtOutput1.WordWrap = false;
            // 
            // txtOutput2
            // 
            this.txtOutput2.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtOutput2.Location = new System.Drawing.Point(12, 172);
            this.txtOutput2.Multiline = true;
            this.txtOutput2.Name = "txtOutput2";
            this.txtOutput2.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtOutput2.ShortcutsEnabled = false;
            this.txtOutput2.Size = new System.Drawing.Size(905, 153);
            this.txtOutput2.TabIndex = 1;
            this.txtOutput2.WordWrap = false;
            // 
            // txtOutput3
            // 
            this.txtOutput3.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtOutput3.Location = new System.Drawing.Point(12, 331);
            this.txtOutput3.Multiline = true;
            this.txtOutput3.Name = "txtOutput3";
            this.txtOutput3.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtOutput3.ShortcutsEnabled = false;
            this.txtOutput3.Size = new System.Drawing.Size(905, 153);
            this.txtOutput3.TabIndex = 2;
            this.txtOutput3.WordWrap = false;
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(929, 496);
            this.Controls.Add(this.txtOutput3);
            this.Controls.Add(this.txtOutput2);
            this.Controls.Add(this.txtOutput1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "SKEIN TESTER";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtOutput1;
        private System.Windows.Forms.TextBox txtOutput2;
        private System.Windows.Forms.TextBox txtOutput3;
    }
}

