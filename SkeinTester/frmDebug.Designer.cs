namespace SkeinTester
{
    partial class frmDebug
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
            this.components = new System.ComponentModel.Container();
            this.txtOutput1 = new System.Windows.Forms.TextBox();
            this.txtOutput2 = new System.Windows.Forms.TextBox();
            this.tmrExecute = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // txtOutput1
            // 
            this.txtOutput1.Location = new System.Drawing.Point(12, 12);
            this.txtOutput1.Multiline = true;
            this.txtOutput1.Name = "txtOutput1";
            this.txtOutput1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtOutput1.Size = new System.Drawing.Size(669, 162);
            this.txtOutput1.TabIndex = 0;
            this.txtOutput1.WordWrap = false;
            // 
            // txtOutput2
            // 
            this.txtOutput2.Location = new System.Drawing.Point(12, 180);
            this.txtOutput2.Multiline = true;
            this.txtOutput2.Name = "txtOutput2";
            this.txtOutput2.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtOutput2.Size = new System.Drawing.Size(669, 162);
            this.txtOutput2.TabIndex = 1;
            this.txtOutput2.WordWrap = false;
            // 
            // tmrExecute
            // 
            this.tmrExecute.Enabled = true;
            this.tmrExecute.Interval = 250;
            this.tmrExecute.Tick += new System.EventHandler(this.tmrExecute_Tick);
            // 
            // frmDebug
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(693, 360);
            this.Controls.Add(this.txtOutput2);
            this.Controls.Add(this.txtOutput1);
            this.Name = "frmDebug";
            this.Text = "frmDebug";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtOutput1;
        private System.Windows.Forms.TextBox txtOutput2;
        private System.Windows.Forms.Timer tmrExecute;
    }
}