namespace DisplayOLED
{
    partial class DisplayOLED
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
            this.messageBox = new System.Windows.Forms.TextBox();
            this.sendMessageBtn = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.comPort = new System.Windows.Forms.ComboBox();
            this.serialConnectionBtn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.messageBoxSerial = new System.Windows.Forms.TextBox();
            this.serialMonitorBtn = new System.Windows.Forms.Button();
            this.serialMonitorGB = new System.Windows.Forms.GroupBox();
            this.serialClear = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.spProgramTwo = new System.Windows.Forms.CheckBox();
            this.spProgramOne = new System.Windows.Forms.CheckBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.sInfraredSensor = new System.Windows.Forms.RadioButton();
            this.sSonicSensor = new System.Windows.Forms.RadioButton();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.bmSuperMario = new System.Windows.Forms.CheckBox();
            this.bmStarWars = new System.Windows.Forms.CheckBox();
            this.customLabel = new System.Windows.Forms.Label();
            this.sCustomizeGB = new System.Windows.Forms.GroupBox();
            this.scSendBtn = new System.Windows.Forms.Button();
            this.buzzerCB = new System.Windows.Forms.CheckBox();
            this.label5 = new System.Windows.Forms.Label();
            this.cmL = new System.Windows.Forms.Label();
            this.scMessageTB = new System.Windows.Forms.TextBox();
            this.rangeTB = new System.Windows.Forms.TextBox();
            this.rangeL = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.serialMonitorGB.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.sCustomizeGB.SuspendLayout();
            this.SuspendLayout();
            // 
            // messageBox
            // 
            this.messageBox.Location = new System.Drawing.Point(6, 19);
            this.messageBox.Multiline = true;
            this.messageBox.Name = "messageBox";
            this.messageBox.Size = new System.Drawing.Size(121, 66);
            this.messageBox.TabIndex = 0;
            this.messageBox.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // sendMessageBtn
            // 
            this.sendMessageBtn.Location = new System.Drawing.Point(6, 91);
            this.sendMessageBtn.Name = "sendMessageBtn";
            this.sendMessageBtn.Size = new System.Drawing.Size(121, 23);
            this.sendMessageBtn.TabIndex = 1;
            this.sendMessageBtn.Text = "Send";
            this.sendMessageBtn.UseVisualStyleBackColor = true;
            this.sendMessageBtn.Click += new System.EventHandler(this.sendMessage_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.messageBox);
            this.groupBox1.Controls.Add(this.sendMessageBtn);
            this.groupBox1.Location = new System.Drawing.Point(12, 21);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(133, 120);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "OLED 128X64";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.comPort);
            this.groupBox2.Controls.Add(this.serialConnectionBtn);
            this.groupBox2.Location = new System.Drawing.Point(154, 90);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(197, 51);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Serial Connection";
            // 
            // comPort
            // 
            this.comPort.FormattingEnabled = true;
            this.comPort.Location = new System.Drawing.Point(107, 21);
            this.comPort.Name = "comPort";
            this.comPort.Size = new System.Drawing.Size(84, 21);
            this.comPort.TabIndex = 3;
            this.comPort.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // serialConnectionBtn
            // 
            this.serialConnectionBtn.Location = new System.Drawing.Point(6, 21);
            this.serialConnectionBtn.Name = "serialConnectionBtn";
            this.serialConnectionBtn.Size = new System.Drawing.Size(95, 23);
            this.serialConnectionBtn.TabIndex = 2;
            this.serialConnectionBtn.Text = "Connect";
            this.serialConnectionBtn.UseVisualStyleBackColor = true;
            this.serialConnectionBtn.Click += new System.EventHandler(this.serialConnectionBtn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.MediumBlue;
            this.label1.Location = new System.Drawing.Point(172, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(173, 34);
            this.label1.TabIndex = 4;
            this.label1.Text = "Sends message to OLED \r\nDisplay via the Serial port ";
            // 
            // messageBoxSerial
            // 
            this.messageBoxSerial.Location = new System.Drawing.Point(6, 19);
            this.messageBoxSerial.Multiline = true;
            this.messageBoxSerial.Name = "messageBoxSerial";
            this.messageBoxSerial.ReadOnly = true;
            this.messageBoxSerial.Size = new System.Drawing.Size(121, 276);
            this.messageBoxSerial.TabIndex = 3;
            this.messageBoxSerial.TextChanged += new System.EventHandler(this.messageBoxSerial_TextChanged);
            // 
            // serialMonitorBtn
            // 
            this.serialMonitorBtn.Location = new System.Drawing.Point(272, 68);
            this.serialMonitorBtn.Name = "serialMonitorBtn";
            this.serialMonitorBtn.Size = new System.Drawing.Size(79, 23);
            this.serialMonitorBtn.TabIndex = 6;
            this.serialMonitorBtn.Text = "Serial Monitor";
            this.serialMonitorBtn.UseVisualStyleBackColor = true;
            this.serialMonitorBtn.Click += new System.EventHandler(this.serialMonitor_Click);
            // 
            // serialMonitorGB
            // 
            this.serialMonitorGB.Controls.Add(this.serialClear);
            this.serialMonitorGB.Controls.Add(this.messageBoxSerial);
            this.serialMonitorGB.Location = new System.Drawing.Point(369, 21);
            this.serialMonitorGB.Name = "serialMonitorGB";
            this.serialMonitorGB.Size = new System.Drawing.Size(134, 334);
            this.serialMonitorGB.TabIndex = 7;
            this.serialMonitorGB.TabStop = false;
            this.serialMonitorGB.Text = "Serial Monitor";
            // 
            // serialClear
            // 
            this.serialClear.Location = new System.Drawing.Point(6, 301);
            this.serialClear.Name = "serialClear";
            this.serialClear.Size = new System.Drawing.Size(121, 23);
            this.serialClear.TabIndex = 19;
            this.serialClear.Text = "Clear";
            this.serialClear.UseVisualStyleBackColor = true;
            this.serialClear.Click += new System.EventHandler(this.serialClear_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.spProgramTwo);
            this.groupBox4.Controls.Add(this.spProgramOne);
            this.groupBox4.Location = new System.Drawing.Point(12, 147);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(133, 69);
            this.groupBox4.TabIndex = 8;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Sample Programs";
            // 
            // spProgramTwo
            // 
            this.spProgramTwo.AutoSize = true;
            this.spProgramTwo.Location = new System.Drawing.Point(7, 43);
            this.spProgramTwo.Name = "spProgramTwo";
            this.spProgramTwo.Size = new System.Drawing.Size(89, 17);
            this.spProgramTwo.TabIndex = 1;
            this.spProgramTwo.Text = "Program Two";
            this.spProgramTwo.UseVisualStyleBackColor = true;
            this.spProgramTwo.CheckedChanged += new System.EventHandler(this.spProgramTwo_CheckedChanged);
            // 
            // spProgramOne
            // 
            this.spProgramOne.AutoSize = true;
            this.spProgramOne.Location = new System.Drawing.Point(7, 20);
            this.spProgramOne.Name = "spProgramOne";
            this.spProgramOne.Size = new System.Drawing.Size(88, 17);
            this.spProgramOne.TabIndex = 0;
            this.spProgramOne.Text = "Program One";
            this.spProgramOne.UseVisualStyleBackColor = true;
            this.spProgramOne.CheckedChanged += new System.EventHandler(this.spProgramOne_CheckedChanged);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.sInfraredSensor);
            this.groupBox5.Controls.Add(this.sSonicSensor);
            this.groupBox5.Location = new System.Drawing.Point(154, 147);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(197, 69);
            this.groupBox5.TabIndex = 9;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Sensors";
            // 
            // sInfraredSensor
            // 
            this.sInfraredSensor.AutoSize = true;
            this.sInfraredSensor.Location = new System.Drawing.Point(3, 39);
            this.sInfraredSensor.Name = "sInfraredSensor";
            this.sInfraredSensor.Size = new System.Drawing.Size(97, 17);
            this.sInfraredSensor.TabIndex = 1;
            this.sInfraredSensor.TabStop = true;
            this.sInfraredSensor.Text = "Infrared Sensor";
            this.sInfraredSensor.UseVisualStyleBackColor = true;
            this.sInfraredSensor.CheckedChanged += new System.EventHandler(this.sInfraredSensor_CheckedChanged);
            // 
            // sSonicSensor
            // 
            this.sSonicSensor.AutoSize = true;
            this.sSonicSensor.Location = new System.Drawing.Point(3, 16);
            this.sSonicSensor.Name = "sSonicSensor";
            this.sSonicSensor.Size = new System.Drawing.Size(88, 17);
            this.sSonicSensor.TabIndex = 0;
            this.sSonicSensor.TabStop = true;
            this.sSonicSensor.Text = "Sonic Sensor";
            this.sSonicSensor.UseVisualStyleBackColor = true;
            this.sSonicSensor.CheckedChanged += new System.EventHandler(this.sSonicSensor_CheckedChanged);
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.bmSuperMario);
            this.groupBox6.Controls.Add(this.bmStarWars);
            this.groupBox6.Location = new System.Drawing.Point(12, 222);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(133, 72);
            this.groupBox6.TabIndex = 10;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Buzzer Music";
            // 
            // bmSuperMario
            // 
            this.bmSuperMario.AutoSize = true;
            this.bmSuperMario.Location = new System.Drawing.Point(6, 44);
            this.bmSuperMario.Name = "bmSuperMario";
            this.bmSuperMario.Size = new System.Drawing.Size(83, 17);
            this.bmSuperMario.TabIndex = 4;
            this.bmSuperMario.Text = "Super Mario";
            this.bmSuperMario.UseVisualStyleBackColor = true;
            this.bmSuperMario.CheckedChanged += new System.EventHandler(this.bmSuperMario_CheckedChanged);
            // 
            // bmStarWars
            // 
            this.bmStarWars.AutoSize = true;
            this.bmStarWars.Location = new System.Drawing.Point(6, 23);
            this.bmStarWars.Name = "bmStarWars";
            this.bmStarWars.Size = new System.Drawing.Size(73, 17);
            this.bmStarWars.TabIndex = 3;
            this.bmStarWars.Text = "Star Wars";
            this.bmStarWars.UseVisualStyleBackColor = true;
            this.bmStarWars.CheckedChanged += new System.EventHandler(this.bmStarWars_CheckedChanged);
            // 
            // customLabel
            // 
            this.customLabel.AutoSize = true;
            this.customLabel.BackColor = System.Drawing.Color.Transparent;
            this.customLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.customLabel.ForeColor = System.Drawing.Color.Crimson;
            this.customLabel.Location = new System.Drawing.Point(199, 245);
            this.customLabel.Name = "customLabel";
            this.customLabel.Size = new System.Drawing.Size(103, 24);
            this.customLabel.TabIndex = 12;
            this.customLabel.Text = "Have Fun! ";
            this.customLabel.Click += new System.EventHandler(this.label3_Click);
            // 
            // sCustomizeGB
            // 
            this.sCustomizeGB.Controls.Add(this.scSendBtn);
            this.sCustomizeGB.Controls.Add(this.buzzerCB);
            this.sCustomizeGB.Controls.Add(this.label5);
            this.sCustomizeGB.Controls.Add(this.cmL);
            this.sCustomizeGB.Controls.Add(this.scMessageTB);
            this.sCustomizeGB.Controls.Add(this.rangeTB);
            this.sCustomizeGB.Controls.Add(this.rangeL);
            this.sCustomizeGB.Location = new System.Drawing.Point(154, 222);
            this.sCustomizeGB.Name = "sCustomizeGB";
            this.sCustomizeGB.Size = new System.Drawing.Size(197, 133);
            this.sCustomizeGB.TabIndex = 13;
            this.sCustomizeGB.TabStop = false;
            this.sCustomizeGB.Text = "Sensor Customize";
            // 
            // scSendBtn
            // 
            this.scSendBtn.Location = new System.Drawing.Point(59, 100);
            this.scSendBtn.Name = "scSendBtn";
            this.scSendBtn.Size = new System.Drawing.Size(75, 23);
            this.scSendBtn.TabIndex = 18;
            this.scSendBtn.Text = "Send";
            this.scSendBtn.UseVisualStyleBackColor = true;
            this.scSendBtn.Click += new System.EventHandler(this.scSendBtn_Click);
            // 
            // buzzerCB
            // 
            this.buzzerCB.AutoSize = true;
            this.buzzerCB.Location = new System.Drawing.Point(60, 77);
            this.buzzerCB.Name = "buzzerCB";
            this.buzzerCB.Size = new System.Drawing.Size(58, 17);
            this.buzzerCB.TabIndex = 17;
            this.buzzerCB.Text = "Buzzer";
            this.buzzerCB.UseVisualStyleBackColor = true;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(3, 48);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(56, 13);
            this.label5.TabIndex = 16;
            this.label5.Text = "Message :";
            // 
            // cmL
            // 
            this.cmL.AutoSize = true;
            this.cmL.Location = new System.Drawing.Point(89, 23);
            this.cmL.Name = "cmL";
            this.cmL.Size = new System.Drawing.Size(23, 13);
            this.cmL.TabIndex = 15;
            this.cmL.Text = "CM";
            // 
            // scMessageTB
            // 
            this.scMessageTB.Location = new System.Drawing.Point(60, 45);
            this.scMessageTB.Multiline = true;
            this.scMessageTB.Name = "scMessageTB";
            this.scMessageTB.Size = new System.Drawing.Size(112, 26);
            this.scMessageTB.TabIndex = 2;
            // 
            // rangeTB
            // 
            this.rangeTB.Location = new System.Drawing.Point(60, 19);
            this.rangeTB.MaxLength = 3;
            this.rangeTB.Name = "rangeTB";
            this.rangeTB.Size = new System.Drawing.Size(27, 20);
            this.rangeTB.TabIndex = 14;
            this.rangeTB.TextChanged += new System.EventHandler(this.rangeTB_TextChanged);
            this.rangeTB.Leave += new System.EventHandler(this.rangeTB_Leave);
            // 
            // rangeL
            // 
            this.rangeL.AutoSize = true;
            this.rangeL.Location = new System.Drawing.Point(3, 22);
            this.rangeL.Name = "rangeL";
            this.rangeL.Size = new System.Drawing.Size(57, 13);
            this.rangeL.TabIndex = 13;
            this.rangeL.Text = "Range     :";
            // 
            // DisplayOLED
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(360, 363);
            this.Controls.Add(this.customLabel);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.serialMonitorGB);
            this.Controls.Add(this.serialMonitorBtn);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.sCustomizeGB);
            this.Name = "DisplayOLED";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.DisplayOLED_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.serialMonitorGB.ResumeLayout(false);
            this.serialMonitorGB.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.sCustomizeGB.ResumeLayout(false);
            this.sCustomizeGB.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox messageBox;
        private System.Windows.Forms.Button sendMessageBtn;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ComboBox comPort;
        private System.Windows.Forms.Button serialConnectionBtn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox messageBoxSerial;
        private System.Windows.Forms.Button serialMonitorBtn;
        private System.Windows.Forms.GroupBox serialMonitorGB;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.RadioButton sInfraredSensor;
        private System.Windows.Forms.RadioButton sSonicSensor;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Label customLabel;
        private System.Windows.Forms.GroupBox sCustomizeGB;
        private System.Windows.Forms.Label rangeL;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label cmL;
        private System.Windows.Forms.TextBox scMessageTB;
        private System.Windows.Forms.TextBox rangeTB;
        private System.Windows.Forms.Button scSendBtn;
        private System.Windows.Forms.CheckBox buzzerCB;
        private System.Windows.Forms.CheckBox spProgramTwo;
        private System.Windows.Forms.CheckBox spProgramOne;
        private System.Windows.Forms.CheckBox bmSuperMario;
        private System.Windows.Forms.CheckBox bmStarWars;
        private System.Windows.Forms.Button serialClear;
    }
}

