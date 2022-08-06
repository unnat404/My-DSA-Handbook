import java.io.DataOutputStream;
import java.util.Scanner;
import java.io.*;
import java.net.*;
 
public class sender_thread implements Runnable{
    private DataOutputStream dout;
    Scanner scan;
    public sender_thread(DataOutputStream dout)
    {
        scan = new Scanner(System.in);
        this.dout = dout;
    }
    @Override
    public void run()
    {
        while(true)
        {
            try
            {
                System.out.print("Message: ");
                String str = scan.nextLine();
                dout.writeUTF(str);
                if(str.equals("bye"))
                   break;
            }catch(Exception e)
            {
                System.out.println("Error has occured in sending the message");
            }
        }
 
 
    }
 
}