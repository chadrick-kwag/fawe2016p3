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
using System.Threading;




namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {



        
        int bgmflag = 1;
        Thread othread; 


        public Form1()
        {
            InitializeComponent();
            othread = new Thread(new ThreadStart(serial_thread));

        }


        public void serial_thread()
        {
            MediaPlayer player_kick=new MediaPlayer();

            MediaPlayer player_snare = new MediaPlayer();

            MediaPlayer player_scratch = new MediaPlayer();


            //player_kick.Open(new Uri(@"C:\musictemp\kick.wav"));
            player_kick.Open(new Uri(@".\kick.wav"));
            player_snare.Open(new Uri(@"C:\musictemp\snare.wav"));
            player_snare.Volume = 1;
            player_scratch.Open(new Uri(@"C:\musictemp\scratch.wav"));

           

            int firsttime = 1;


            SerialPort myserial = new SerialPort("COM3", 9600);
            try
            {
                myserial.Open();


            }
            catch (IOException ex)
            {
                Console.WriteLine(ex);
                Console.WriteLine("error occured while opening port");
            }

            myserial.DiscardInBuffer();



            while (true)
            {
                if (myserial.BytesToRead > 0)
                {
                    char read = (char)myserial.ReadByte();
                    if (read == '1')
                    {
                        if (firsttime==1)
                        {
                            player_scratch.Play();
                            firsttime = 0;
                        }
                        
                        
                        player_kick.Stop();
                        player_kick.Play();
                    }
                    else if (read == '2')
                    {
                        player_snare.Stop();
                        player_snare.Play();
                        
                    }
                    
                }
            }
            


        }

        


        private void button1_Click(object sender, EventArgs e)
        {

            //Thread othread = new Thread(new ThreadStart(serial_thread));
            othread.Start();
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
            //if (bgmflag == 0)
            //{
            //    return;
            //}
            //bgmflag = 0;
            //MediaPlayer player1 = new MediaPlayer();
            //player1.Open(new Uri(@"C:\musictemp\bgm1.wav"));
            //player1.Volume = 0.1;
            //player1.Play();


        }
    }
}
