// package byte_stuff_udp;
import java.io.*;
import java.net.*;
public class ByteStuffServer {
    public static void main(String[] args) throws IOException {
        final int PORT = 8000 , Radix = 1024;
        byte[] recieve = new byte[Radix];
        DatagramSocket ds =new DatagramSocket(PORT);
        DatagramPacket packetReceived  = new DatagramPacket(recieve,recieve.length);
        boolean running = true;
        System.out.println("Up and running on "+PORT);
        while(running){
           String unstuffed = "";
           ds.receive(packetReceived);
           String data = new String(packetReceived.getData(),0,packetReceived.getLength());
            System.out.println("Data recieved from Server "+data);
            for(int i = 1;i<data.length()-1;i++){
                if(data.charAt(i)=='E') i++;
                unstuffed+= data.charAt(i);
            }
            System.out.println("Unstuffed Data "+unstuffed);
            recieve = new byte[Radix];
        }
        ds.close();
    }
}
