using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using System.Windows.Media;
using System.Windows;
using System.Windows.Threading;




namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {

        //System.Media.SoundPlayer player1 = new System.Media.SoundPlayer(@"C:\musictemp\kick2.wav");
        //System.Media.SoundPlayer player2 = new System.Media.SoundPlayer(@"C:\musictemp\snare.wav");

        //System.Media.SoundPlayer bgm_player = new System.Media.SoundPlayer(@"C:\musictemp\bgm1.wav");

        //MediaPlayer player1 = new System.Windows.Media.MediaPlayer();
        //player1.



        public static MediaPlayer player_kick;

        public static MediaPlayer player_snare; 

        

        int bgmflag = 1;

        

        public Form1()
        {
            InitializeComponent();
            player_kick = new MediaPlayer();
            player_snare = new MediaPlayer();
            
            player_kick.Play();
        }


        public void serial_thread()
        {


            

            SerialPort myserial = new SerialPort("COM8", 9600);
            myserial = new SerialPort("COM8", 9600);
            try
            {
                myserial.Open();


            }
            catch (IOException ex)
            {
                Console.WriteLine(ex);
                Console.WriteLine("error occured while opening port");
            }
            textBox1.Text = "serial connected!";
            Console.WriteLine("serial connected");
            myserial.DiscardInBuffer();

            //myserial.DataReceived += new SerialDataReceivedEventHandler(myserial_datarx);

            while (true)
            {
                if (myserial.BytesToRead > 0)
                {
                    char read = (char)myserial.ReadByte();
                    if (read == '1')
                    {
                        Console.WriteLine("1 detected");
                        player_kick.Stop();
                        player_kick.Play();
                    }
                    else if (read == '2')
                    {
                        player_snare.Stop();
                        player_snare.Play();
                    }
                    Console.WriteLine(read);
                }
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //MediaPlayer player_kick = new MediaPlayer();
            //player_kick.Open(new Uri(@"C:\musictemp\kick2.wav"));

            
            


            myserial = new SerialPort("COM8", 9600);
            try
            {
                myserial.Open();
               

            }
            catch(IOException ex)
            {
                Console.WriteLine(ex);
                Console.WriteLine("error occured while opening port");
            }
            textBox1.Text = "serial connected!";
            Console.WriteLine("serial connected");
            myserial.DiscardInBuffer();

            myserial.DataReceived += new SerialDataReceivedEventHandler(myserial_datarx);

            //while ( true)
            //{
            //    if(myserial.BytesToRead > 0)
            //    {
            //        char read = (char)myserial.ReadByte();
            //        if (read == '1')
            //        {
            //            Console.WriteLine("1 detected");
            //            player_kick.Stop();
            //            player_kick.Play();
            //        }
            //        else if (read == '2')
            //        {
            //            player_snare.Stop();
            //            player_snare.Play();
            //        }
            //        Console.WriteLine(read);
            //    }
            //}
            
            textBox1.Text = "serial connected!";

        }

        public static void func1()
        {
            Console.Write("whatup");

            //Dispatcher disp = new Dispatcher(
            //this.Dispatcher.Invoke(DispatcherPriority.Normal, new Action(delegate
            //{
            //    player_kick.Stop();
            //    player_kick.Play();
            //}));

            //Dispatcher.CurrentDispatcher.Invoke(DispatcherPriority.Normal, new Action(delegate
            //{
            //    player_kick.Stop();
            //    player_kick.Play();
            //}));
            MediaPlayer player3 = new MediaPlayer();
            player3.Open(new Uri(@"C:\musictemp\kick2.wav"));
            player3.Stop();
            player3.Play();

        }

        private static void myserial_datarx(object sender, SerialDataReceivedEventArgs e)
        {

            func1();

                char read = (char)myserial.ReadByte();
                if (read == '1')
                {
                    Console.WriteLine("1 detected");
                    MediaPlayer player3 = new MediaPlayer();
                    player3.Open(new Uri(@"C:\musictemp\boom.wav"));
                    player3.Stop();
                    player3.Play();


            }
                else if (read == '2')
                {
                    Console.WriteLine("2 detected");
                    //player_snare.Stop();
                    //player_snare.Play();

                    MediaPlayer player4 = new MediaPlayer();
                    player4.Open(new Uri(@"C:\musictemp\snare.wav"));
                    player4.Stop();
                    player4.Play();

            }
            
        }

        private void quitbtn_Click(object sender, EventArgs e)
        {
            
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //try
            //{
            //    System.Media.SoundPlayer player = new System.Media.SoundPlayer(@"c:musictemp\kick2.wav");
            //}
            //catch(IOException err)
            //{
            //    Console.WriteLine(err);
            //    return;
            //}

            //Console.WriteLine("audio play continued");

            //player.play();

            //System.Media.SoundPlayer player = new System.Media.SoundPlayer(@"C:\musictemp\kick2.wav");

            

        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (bgmflag == 0)
            {
                return;
            }
            bgmflag = 0;
            MediaPlayer player1 = new MediaPlayer();
            player1.Open(new Uri(@"C:\musictemp\bgm1.wav"));
            player1.Volume = 0.1;
            player1.Play();
        }
    }
}
