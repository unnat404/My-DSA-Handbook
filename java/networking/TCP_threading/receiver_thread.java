// public class receiver_thread {
    
// }

import java.io.DataInputStream;
import java.util.Scanner;
import java.io.*;
import java.net.*;
public class receiver_thread implements Runnable
{
    private DataInputStream din;
    Scanner scan;
    public receiver_thread(DataInputStream din)
    {
        this.din = din;
        scan = new Scanner(System.in);
    }
    @Override
    public void run()
    {
        while(true)
        {
            try
            {
                String str = din.readUTF();
                if(str.equals("bye"))
                    break;
                System.out.println("Message received : "+str);
            }catch(Exception e) {
                System.out.println("Error has occured in sending the message");
            }
        }
 
    }
}