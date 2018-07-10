using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;

namespace DisplayOLED
{
    public partial class DisplayOLED : Form
    {
        bool isConnected = false;
        string[] ports;
        SerialPort port;
        string textReceived = null;
        System.Windows.Forms.Timer t;
        int fSize           = 0;
        int sButton         = 0;
        int srlButton       = 0;
        int regexTrue       = 0;
        //frame Default size = 376, 402

        public DisplayOLED()
        {
            InitializeComponent();
            disableControls();
            getAvailablePorts();
            this.Size = new Size(375, 341);
            sCustomizeGB.Hide();

            foreach (string port in ports)
            {
                comPort.Items.Add(port);
                
                if(ports[0] != null)
                {
                    comPort.SelectedItem = ports[0];
                }
            }
        }

        private void getAvailablePorts()
        {
            ports = SerialPort.GetPortNames();
        }

        private void enableControls()
        {
            messageBox.Enabled          = true;
            sendMessageBtn.Enabled      = true;
            serialMonitorBtn.Enabled    = true;
            spProgramOne.Enabled        = true;
            spProgramTwo.Enabled        = true;
            bmSuperMario.Enabled        = true;
            bmStarWars.Enabled          = true;
            sSonicSensor.Enabled        = true;
            sInfraredSensor.Enabled     = true;
            rangeTB.Enabled             = true;
            buzzerCB.Enabled            = true;
            scSendBtn.Enabled           = true;
            serialClear.Enabled         = true;
            messageBoxSerial.Enabled    = true;
            scMessageTB.Enabled         = true;
        }

        private void disableControls()
        {
            messageBox.Enabled          = false;
            sendMessageBtn.Enabled      = false;
            serialMonitorBtn.Enabled    = false;
            spProgramOne.Enabled        = false;
            spProgramTwo.Enabled        = false;
            bmSuperMario.Enabled        = false;
            bmStarWars.Enabled          = false;
            sSonicSensor.Enabled        = false;
            sInfraredSensor.Enabled     = false;
            rangeTB.Enabled             = false;
            buzzerCB.Enabled            = false;
            scSendBtn.Enabled           = false;
            serialClear.Enabled         = false;
            messageBoxSerial.Enabled    = false;
            scMessageTB.Enabled         = false;
        }

        private void connectArduino()
        {
            string selectedPort = comPort.SelectedItem.ToString();

            try
            {
                isConnected = true;
                port = new SerialPort(selectedPort, 9600, Parity.None, 8, StopBits.One);
                Console.WriteLine(selectedPort);
                port.Open();
                port.Write("#STAR*");
                serialConnectionBtn.Text = "Disconnect";
                comPort.Enabled = false;
                enableControls();
            }
            catch(Exception e)
            {
                MessageBox.Show(e.GetBaseException().ToString());
            }
        }

        private void disconnectArduino()
        {
            try
            {
                isConnected = false;
                port.Write("#STOP*");
                port.Close();
                serialConnectionBtn.Text = "Connect";
                comPort.Enabled = true;
                disableControls();
            }
            catch (Exception e)
            {
                MessageBox.Show(e.GetBaseException().ToString());
            }
        }



        //Controls
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void sendMessage_Click(object sender, EventArgs e)
        { //384
            port.ReadTimeout    = 3000;
            port.WriteTimeout   = 500;
            textReceived        = null;
            int textCount       = messageBox.Text.Length;

            if (isConnected)
            {

                sendMessageBtn.Enabled = false;
                port.Write("#TEXT" + messageBox.Text + "*");
                Console.WriteLine("#TEXT" + messageBox.Text + "*");
                port.DataReceived += new SerialDataReceivedEventHandler(Port_DataReceived);

                t = new System.Windows.Forms.Timer();
                t.Tick += new EventHandler(OnTimedEvent);
                t.Interval = 500;
                t.Start();          
            } 
        }

        private void OnTimedEvent(object sender, EventArgs e)
        {
            sendMessageBtn.Enabled = true;
            returnSerialOutput();
            t.Stop();
            Console.WriteLine("From Timer");
            //textReceived = null;
        }

        private void Port_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
                textReceived += (string)port.ReadExisting();
                //sendMessageBtn.Enabled = true;
        }

        private void serialConnectionBtn_Click(object sender, EventArgs e)
        {
            if(!isConnected)
            {
                connectArduino();
            }
            else
            {
                disconnectArduino();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
           
        }

        private void messageBoxSerial_TextChanged(object sender, EventArgs e)
        {

        }

        private void returnSerialOutput()
        {
            messageBoxSerial.Text = textReceived;
            Console.WriteLine("Received: "+ textReceived);
        }

        private void serialMonitor_Click(object sender, EventArgs e)
        { 
            port.WriteTimeout = 500;

            if (isConnected)
            {
                ++fSize;

                if (fSize % 2 == 1)  // SerialGB = 273 ---> 334  Frame = 341 ---> 403  button_Loca ---> 6, 241  textAreaSize ---> 121, 216
                {
                    DialogResult promtUser = MessageBox.Show("Turning on the Serial monitor will cause the Display to be turned off. Are you sure?", "Serial Monitor", MessageBoxButtons.YesNo);
                    srlButton = 1;

                    if (promtUser == DialogResult.Yes)
                    {
                        if (sButton == 1)
                        {
                            this.Size = new Size(532, 403);
                            serialMonitorGB.Size    = new Size(132, 334);
                            messageBoxSerial.Size   = new Size(121, 276);
                            serialClear.Location    = new Point(6, 301);
                            customLabel.Location    = new Point(27, 308);

                            port.Write("#SRMN*");
                            Console.WriteLine("#SRMN*");
                        }
                        else
                        {
                            this.Size = new Size(532, 341);
                            serialMonitorGB.Size    = new Size(132, 273);
                            messageBoxSerial.Size   = new Size(121, 216);
                            serialClear.Location    = new Point(6, 241);
                            customLabel.Location    = new Point(199, 245);

                            sCustomizeGB.Hide();
                            port.Write("#SRMN*");
                            Console.WriteLine("#SRMN*");
                        }

                    }
                }
                else
                    if (fSize % 2 == 0)
                    {
                        srlButton = 0;

                        if (sButton == 0)
                        {
                            this.Size               = new Size(375, 341);
                            customLabel.Location    = new Point(199, 245);

                            port.Write("#SRMF*");
                            Console.WriteLine("#SRMF*");
                        }
                        else
                        {
                            this.Size               = new Size(375, 403);
                            customLabel.Location    = new Point(27, 308);

                            sCustomizeGB.Show();
                            port.Write("#SRMF*");
                            Console.WriteLine("#SRMF*");
                        }
                    }
                
            }
        

        }

        private void DisplayOLED_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void sSonicSensor_CheckedChanged(object sender, EventArgs e)
        {
            if (sSonicSensor.Checked == true)
            {
                sButton = 1;
                spProgramOne.Checked    = false;
                spProgramTwo.Checked    = false;
                bmSuperMario.Checked    = false;
                sInfraredSensor.Checked = false;
                bmStarWars.Checked      = false;
                rangeL.Show();
                rangeTB.Show();
                cmL.Show();

                if (srlButton == 1)
                {
                    if (sButton == 1)
                    {
                        this.Size               = new Size(532, 403);
                        serialMonitorGB.Size    = new Size(132, 334);
                        messageBoxSerial.Size   = new Size(121, 276);
                        serialClear.Location    = new Point(6, 301);
                        customLabel.Location    = new Point(27, 308);
                        sCustomizeGB.Show();
                    }
                    else
                    {
                        customLabel.Location    = new Point(199, 245);
                        this.Size               = new Size(532, 341);
                        serialMonitorGB.Size    = new Size(132, 273);
                    }
                }
                else
                    if (srlButton == 0)
                    {
                        if (sButton == 0)
                        {
                            customLabel.Location    = new Point(199, 245);
                            this.Size               = new Size(375, 341);
                        }
                        else
                        {
                            this.Size               = new Size(375, 403);
                            customLabel.Location    = new Point(27, 308);
                            sCustomizeGB.Show();
                        }
                    }
            }
        }
        private void sInfraredSensor_CheckedChanged(object sender, EventArgs e)
        {
            if (sInfraredSensor.Checked == true)
            {
                sButton = 1;
                spProgramOne.Checked = false;
                spProgramTwo.Checked = false;
                bmSuperMario.Checked = false;
                bmStarWars.Checked = false;
                sSonicSensor.Checked = false;
                rangeL.Hide();
                rangeTB.Hide();
                cmL.Hide();

                if (srlButton == 1)
                {
                    if (sButton == 1)
                    {
                        this.Size = new Size(532, 403);
                        serialMonitorGB.Size = new Size(132, 334);
                        messageBoxSerial.Size = new Size(121, 276);
                        serialClear.Location = new Point(6, 301);
                        customLabel.Location = new Point(27, 308);
                        sCustomizeGB.Show();
                    }
                    else
                    {
                        customLabel.Location = new Point(199, 245);
                        this.Size = new Size(532, 341);
                        serialMonitorGB.Size = new Size(132, 273);
                    }
                }
                else
                    if (srlButton == 0)
                    {
                        if (sButton == 0)
                        {
                            customLabel.Location = new Point(199, 245);
                            this.Size = new Size(375, 341);
                        }
                        else
                        {
                            this.Size = new Size(375, 403);
                            customLabel.Location = new Point(27, 308);
                            sCustomizeGB.Show();
                        }
                    }
            }
            
        }

        private void bmStarWars_CheckedChanged(object sender, EventArgs e)
        {
            if(bmStarWars.Checked == true)
            {
                port.Write("#MSWS*");
                spProgramOne.Checked = false;
                spProgramTwo.Checked = false;
                bmSuperMario.Checked = false;
                sInfraredSensor.Checked = false;
                sSonicSensor.Checked = false;
            }
            else
            {
                port.Write("#MSWE*");
            }
        }

        private void bmSuperMario_CheckedChanged(object sender, EventArgs e)
        {
            if (bmSuperMario.Checked == true)
            {
                port.Write("#MSMS*");
                spProgramOne.Checked = false;
                spProgramTwo.Checked = false;
                bmStarWars.Checked = false;
                sInfraredSensor.Checked = false;
                sSonicSensor.Checked = false;
            }
            else
            {
                port.Write("#MSME*");
            }
        }

        private void spProgramOne_CheckedChanged(object sender, EventArgs e)
        {
            if (spProgramOne.Checked == true)
            {
                port.Write("#PP1S*");
                Console.WriteLine("#PP1S");

                spProgramTwo.Checked = false;
                bmStarWars.Checked = false;
                bmSuperMario.Checked = false;
                sInfraredSensor.Checked = false;
                sSonicSensor.Checked = false;
            }
            else
                if (spProgramOne.Checked == false)
                {
                    port.Write("#PP1E*");
                    Console.WriteLine("#PP1E");
                }

        }

        private void spProgramTwo_CheckedChanged(object sender, EventArgs e)
        {
            if (spProgramTwo.Checked == true)
            {
                spProgramOne.Checked = false;
                bmStarWars.Checked = false;
                bmSuperMario.Checked = false;
                sInfraredSensor.Checked = false;
                sSonicSensor.Checked = false;
            }
        }

        private void serialClear_Click(object sender, EventArgs e)
        {
            messageBoxSerial.Clear();
        }

        private void scSendBtn_Click(object sender, EventArgs e)
        {
            if(sSonicSensor.Checked == true)
            {
                if(regexTrue == 1)
                {
                    string temp = rangeTB.Text;
                    string[] rangeTBTxt= new string[3];

                    if (rangeTB.TextLength == 1)
                    {
                        rangeTBTxt[0] = "0";
                        rangeTBTxt[1] = "0";
                    }
                    else
                        if (rangeTB.TextLength == 2)    
                        {
                            rangeTBTxt[2] = "0";    
                        }

                    if (buzzerCB.Checked == true)
                    {
                        string tempp = string.Concat(rangeTBTxt) + temp;
                        port.Write("#SSSS1" + tempp + "" + scMessageTB.Text+ "*");
                        Console.WriteLine(tempp);
                    }
                    else
                        if(buzzerCB.Checked == false)
                        {
                            string tempp = string.Concat(rangeTBTxt) + temp;
                            port.Write("#SSSS0" + tempp + "" + scMessageTB.Text + "*");
                            Console.WriteLine(tempp);
                        }
                }
            }
            else
                if (sInfraredSensor.Checked == true)
                {
                    if (buzzerCB.Checked == true)
                    {
                        port.Write("#SISS1"+ scMessageTB.Text + "*");
                        Console.WriteLine("#SISS1");
                    }
                    else
                        if (buzzerCB.Checked == false)
                        {
                            port.Write("#SISS0" + scMessageTB.Text + "*");
                            Console.WriteLine("#SISS0");
                        }
                }
        }

        private void rangeTB_TextChanged(object sender, EventArgs e)
        {

        }

        private void rangeTB_Leave(object sender, EventArgs e)
        {
            try
            {
                if (Regex.IsMatch(rangeTB.Text, @"^[0-9]"))
                {
                    if (Convert.ToInt16(rangeTB.Text) > 2 && Convert.ToInt16(rangeTB.Text) <= 300)
                    {
                        regexTrue = 1;
                    }
                    else
                    {
                        rangeTB.Clear();
                        MessageBox.Show("Range should be between \"3-300\"?");
                    }
                }
                else
                {
                    rangeTB.Clear();
                    MessageBox.Show("Range should be in numbers?");
                }
            }
            catch (Exception)
            {
                MessageBox.Show("Range should be in numbers?");
                rangeTB.Clear();
            }
        }
    }
}
