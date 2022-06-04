// public class bit_stuff__reverseUDP {
    
// }
// ============================================================
// BitStuffing Server
 
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.*;
import java.util.Scanner;
 
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/**
 *
 * @author student
 */
public class BitStuffing_Server_092 {
    String unstuffing(String s){
        String unstuffed="";//"01111110" 0123456 7-3=4
        String rs=s.substring(8,s.length()-8);//excludes last index ??
        int count=0;
        for(int i=0;i<rs.length();i++){
            if(rs.charAt(i)=='1'){
                count++;
            }
            unstuffed+=rs.charAt(i);
            if(count==5){
                count=0;i++;//skip stuffed 0
            }
        }
        return unstuffed;
    }
    public static void main(String args[])throws IOException{
 
        try{
            BitStuffing_Server_092 ob = new BitStuffing_Server_092();
//            Scanner sc= new Scanner(System.in);
//            ServerSocket skt = new ServerSocket(8000);
//            System.out.println("Server is up and running ...");
            String clientInput,unstuffedData;//,outToClient;
//            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
           
           while(true){
               ServerSocket skt = new ServerSocket(8000);
               System.out.println("Server is up and running ...");
                Socket connectionSocket = skt.accept();
                System.out.println("connected to client....");
                BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
                DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
                clientInput = inFromClient.readLine();
                System.out.println("Received Stuffed Data : "+clientInput);
    //            stuffedData = clientInput.toUpperCase()+"\n";
                unstuffedData = ob.unstuffing(clientInput);
    //            stuffedData = sc.nextLine();
                unstuffedData +="\n";
                System.out.println("Un-Stuffed Data : "+unstuffedData);
                outToClient.writeBytes(unstuffedData);
            }
//            ServerSocket cs = new Se
 
        }
        catch(Exception e){}
 
        
    }
}
 
 
//============================================================================
 
// BitStuffing Client
 
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
 
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/**
 *
 * @author student
 */
//import java.net.*
        
public class BitStuffing_Client_092 {
    String stuffing(String s){
        String flag = "01111110";
        String stuffed = flag;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='1'){
                count++;
                stuffed+='1';
            }
            else{
                stuffed+='0';
            }
            if(count==5){
                stuffed+="0";
                count=0;
            }
        }
        stuffed+=flag;
        return stuffed;
    }
    public static void main(String args[])throws IOException{
        try{
            BitStuffing_Client_092 ob = new BitStuffing_Client_092 ();
            String input, unstuffedData;
            System.out.println("Client connected...");
            Socket clientSocket = new Socket("localhost",8000);
            System.out.println("Connected to serevrr");
            DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
            BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter binary data to be sent:");
            input = sc.nextLine();
            String send = ob.stuffing(input);
    //        input+="\n";
            outToServer.writeBytes(send+"\n");
            unstuffedData = inFromServer.readLine();
            System.out.println("Unstuffed Data from server :: "+unstuffedData);
            clientSocket.close();
//            ServerSocket ss = new ServerSocket(45221);
//            String inFromClient,outToclient;
//            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//            while(true){
////                Socket 
//            }
////            ServerSocket cs = new Se
 
        }
        catch(Exception e){}
 
        
    }    
}
 
 
//==========================================================================================
 
 
// Udp Reverse Server
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
 
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/**
 *
 * @author student
 */
public class UdpServer {
    String reverse(String s){
        int i,n=s.length();
        String rev="";
        for(i=n-1;i>=0;i--){
            rev+=s.charAt(i);
        }
        return rev;
    }
    public static void main(String[] args) throws IOException {
            UdpServer ob =new UdpServer();
            final int PORT = 8000;
            final int sizee = 1024;
            DatagramSocket ds = new DatagramSocket(8000);     
            byte[] receiveData = new byte[sizee];
            byte[] sendData = new byte[sizee];     
            BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
            System.out.println("Server Up and Running on PORT "+PORT);
            boolean running = true;
            
            while(running)
            {
                DatagramPacket receiveDP = new DatagramPacket(receiveData,receiveData.length);
                ds.receive(receiveDP);
                String clientMessage = new String(receiveDP.getData(),0,receiveDP.getLength());
                System.out.println("From Client: "+clientMessage.trim());
                if(clientMessage.toUpperCase().equals("BYE")){
                    System.out.println("Client Disconnected");
                    continue;
                }
                InetAddress ip = receiveDP.getAddress();
//                System.out.print("From Server : ");
                String serverMessage = ob.reverse(clientMessage);
//                String serverMessage = br.readLine();
                sendData = serverMessage.getBytes();
                DatagramPacket sendDP = new DatagramPacket(sendData, sendData.length, ip, receiveDP.getPort());
                ds.send(sendDP);
     
                receiveData = new byte[sizee];
            };
     
        }
}
 
//=====================================================
 
 
// Udp Reverse Client
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
/**
 *
 * @author student
 */
public class UdpClient {
    public static void main(String[] args) throws IOException { 
                DatagramSocket ds = new DatagramSocket();
                final int Radix = 1024;
                byte[] receiveData = new byte[Radix];
                byte[] sendData = new byte[Radix];     
                BufferedReader br = new BufferedReader( new InputStreamReader(System.in));     
                System.out.println("Client Connected , waiting for server ");
                InetAddress ip = InetAddress.getLocalHost();     
                do
                {
                    System.out.print("Enter Client Message/String: ");
                    String clientMessage = br.readLine();
                    sendData = clientMessage.getBytes();
                    DatagramPacket sendDP = new DatagramPacket(sendData, sendData.length, ip, 8000);
                    ds.send(sendDP);
                    if(clientMessage.toUpperCase().equals("BYE")){
                        System.out.println("Exiting");
                        break;
                    }
                    DatagramPacket receiveDP = new DatagramPacket(receiveData,receiveData.length);
                    ds.receive(receiveDP);
     
                    String serverMessage = new String(receiveDP.getData(),0,receiveDP.getLength());
                    System.out.println("Server Message:"+serverMessage.trim());
                }while(true);
        }
}
 
 
// =====================================================================================
 
 
 
 