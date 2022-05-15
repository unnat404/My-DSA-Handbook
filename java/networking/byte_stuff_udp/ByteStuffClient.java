// package byte_stuff_udp; 
import java.io.*;
import java.net.*;
import java.util.Scanner;
 
public class ByteStuffClient   {
    public static void main(String[] args) throws IOException {
        final int PORT = 8000 , Radix = 1024;
        byte[] send = new byte[Radix];
        DatagramSocket ds =new DatagramSocket();
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("Press X to Exit or Enter any  Data");
            String data = sc.nextLine();
            if(data.equals("X")){
                System.out.println("Exiting");
                break;
            }
            String stuffed = "F";
            for(int i = 0;i<data.length();i++) {
                if(data.charAt(i)!='D') stuffed+='E';
                stuffed+= data.charAt(i);
            }
            send = stuffed.getBytes();
            DatagramPacket packetSend= new DatagramPacket(send,send.length,InetAddress.getByName("localhost"),PORT);
            ds.send(packetSend);
        }
    }
}